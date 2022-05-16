/*
 Copyright (C) 2006-2018 M.A.L. Marques
 Copyright (C) 2019 X. Andrade

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/**
 * @file work_hgga_inc.c
 * @brief This file is to be included in hGGA functionals.
 */

#ifdef XC_DEBUG
#define __USE_GNU 1
#include <fenv.h>
#endif

/* macro to simpligy accessing the variables */
#define VAR(var, ip, index)         var[ip*p->dim->var + index]
#define WORK_HGGA_(order, spin)     work_hgga_ ## order ## _ ## spin
#define WORK_HGGA_IP_(order, spin)  work_hgga_ip_ ## order ## _ ## spin
#define FUNC_(order, spin)          func_      ## order ## _ ## spin

/* we need double escaping of the preprocessor macros */
#define WORK_HGGA(order, spin)     WORK_HGGA_(order, spin)
#define WORK_HGGA_IP(order, spin)  WORK_HGGA_IP_(order, spin)
#define FUNC(order, spin)          FUNC_(order, spin)

#ifdef HAVE_CUDA
__global__ static void
WORK_HGGA_IP(ORDER_TXT, SPIN_TXT)
(const XC(func_type) *p, const xc_input_variables *in, xc_output_variables *out)
#else
inline static void
WORK_HGGA_IP(ORDER_TXT, SPIN_TXT)
(const XC(func_type) *p, size_t ip, const xc_input_variables *in, xc_output_variables *out)
#endif
{
  double dens;
  double my_rho[2] = {0.0, 0.0};
  double my_sigma[3] = {0.0, 0.0, 0.0};
  double my_tau[2] = {0.0, 0.0};

#ifdef HAVE_CUDA
  size_t ip = blockIdx.x*blockDim.x + threadIdx.x;
#else
#ifdef XC_DEBUG
  /* This throws an exception when floating point errors are encountered */
  /* feenableexcept(FE_DIVBYZERO | FE_INVALID); */
#endif
#endif

  /* this check is required for the GPU kernel */
  if(ip >= in->np)
    return;
  
  /* screen small densities */
  dens = (p->nspin == XC_POLARIZED) ?
    in->VAR(rho, ip, 0) + in->VAR(rho, ip, 1) :
    in->VAR(rho, ip, 0);
  if(dens < p->dens_threshold)
    return;

  /* sanity check of input parameters */
  my_rho[0] = m_max(p->dens_threshold, in->VAR(rho, ip, 0));
  my_sigma[0] = m_max(p->sigma_threshold * p->sigma_threshold, in->VAR(sigma, ip, 0));

  /* Many functionals shamelessly divide by tau, so we set a reasonable threshold */
  /* skip all checks on tau for the kinetic functionals */
  if(p->info->flags & XC_FLAGS_NEEDS_TAU){
    my_tau[0] = m_max(p->tau_threshold, in->VAR(tau, ip, 0));
#ifdef XC_ENFORCE_FERMI_HOLE_CURVATURE
    /* The Fermi hole curvature 1 - xs^2/(8*ts) must be positive */
    my_sigma[0] = m_min(my_sigma[0], 8.0*my_rho[0]*my_tau[0]);
#endif
  }
  /* lapl can have any values */

  if(p->nspin == XC_POLARIZED){
    double s_ave;

    my_rho[1] = m_max(p->dens_threshold, in->VAR(rho, ip, 1));
    my_sigma[2] = m_max(p->sigma_threshold * p->sigma_threshold, in->VAR(sigma, ip, 2));

    if(p->info->flags & XC_FLAGS_NEEDS_TAU){
      my_tau[1] = m_max(p->tau_threshold, in->VAR(tau, ip, 1));
#ifdef XC_ENFORCE_FERMI_HOLE_CURVATURE
      /* The Fermi hole curvature 1 - xs^2/(8*ts) must be positive */
      my_sigma[2] = m_min(my_sigma[2], 8.0*my_rho[1]*my_tau[1]);
#endif
    }
      
    my_sigma[1] = in->VAR(sigma, ip, 1);
    s_ave = 0.5*(my_sigma[0] + my_sigma[2]);
    /* | grad n |^2 = |grad n_up + grad n_down|^2 > 0 */
    my_sigma[1] = (my_sigma[1] >= -s_ave ? my_sigma[1] : -s_ave);
    /* Since |grad n_up - grad n_down|^2 > 0 we also have */
    my_sigma[1] = (my_sigma[1] <= +s_ave ? my_sigma[1] : +s_ave);
  }

  /* evaluate the functional */
  FUNC(ORDER_TXT, SPIN_TXT)(p, ip, my_rho, my_sigma, &in->VAR(lapl, ip, 0),
                            my_tau, &in->VAR(exx, ip, 0), out);

#ifdef XC_DEBUG
  /* check for NaNs in the output */
  const xc_dimensions *dim = p->dim;
  int ii, is_OK = 1;

  if(out->zk != NULL)
    is_OK = is_OK & isfinite(out->VAR(zk, ip, 0));
  
  if(out->vrho != NULL){
    for(ii=0; ii < dim->vrho; ii++)
      is_OK = is_OK && isfinite(out->VAR(vrho, ip, ii));
    for(ii=0; ii < dim->vsigma; ii++)
      is_OK = is_OK && isfinite(out->VAR(vsigma, ip, ii));
    if(p->info->flags & XC_FLAGS_NEEDS_LAPLACIAN)
      for(ii=0; ii < dim->vlapl; ii++)
        is_OK = is_OK && isfinite(out->VAR(vlapl, ip, ii));
    if(p->info->flags & XC_FLAGS_NEEDS_TAU)
      for(ii=0; ii < dim->vtau; ii++)
        is_OK = is_OK && isfinite(out->VAR(vtau, ip, ii));
    for(ii=0; ii < dim->vexx; ii++)
      is_OK = is_OK && isfinite(out->VAR(vexx, ip, ii));
  }

  if(!is_OK){
    printf("Problem in the evaluation of the functional\n");
    if(p->nspin == XC_UNPOLARIZED){
      printf("./xc-get_data %d 1 ", p->info->number);
      if(p->info->flags & (XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_NEEDS_TAU))
        printf("%le 0.0 %le 0.0 0.0 %le 0.0 %le 0.0 %le 0.0\n",
               in->VAR(rho, ip, 0), in->VAR(sigma, ip, 0),
               in->VAR(lapl, ip, 0), in->VAR(tau, ip, 0), in->VAR(exx, ip, 0));
      else if(p->info->flags & XC_FLAGS_NEEDS_LAPLACIAN)
        printf("%le 0.0 %le 0.0 0.0 %le 0.0 0.0 0.0 %le 0.0\n",
               in->VAR(rho, ip, 0), in->VAR(sigma, ip, 0),
               in->VAR(lapl, ip, 0), in->VAR(exx, ip, 0));
      else
        printf("%le 0.0 %le 0.0 0.0 0.0 0.0 %le 0.0 %le 0.0\n",
               in->VAR(rho, ip, 0), in->VAR(sigma, ip, 0),
               in->VAR(tau, ip, 0), in->VAR(exx, ip, 0));
    }else{
      printf("./xc-get_data %d 2 ", p->info->number);
      if(p->info->flags & (XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_NEEDS_TAU))
        printf("%le %le %le %le %le %le %le %le %le %le %le\n",
               in->VAR(rho, ip, 0), in->VAR(rho, ip, 1),
               in->VAR(sigma, ip, 0), in->VAR(sigma, ip, 1), in->VAR(sigma, ip, 2),
               in->VAR(lapl, ip, 0), in->VAR(lapl, ip, 1),
               in->VAR(tau, ip, 0), in->VAR(tau, ip, 1),
               in->VAR(exx, ip, 0), in->VAR(exx, ip, 1)
               );
      else if(p->info->flags & XC_FLAGS_NEEDS_LAPLACIAN)
        printf("%le %le %le %le %le %le %le 0.0 0.0 %le %le\n",
               in->VAR(rho, ip, 0), in->VAR(rho, ip, 1),
               in->VAR(sigma, ip, 0), in->VAR(sigma, ip, 1), in->VAR(sigma, ip, 2),
               in->VAR(lapl, ip, 0), in->VAR(lapl, ip, 1),
               in->VAR(exx, ip, 0), in->VAR(exx, ip, 1)
               );
      else
        printf("%le %le %le %le %le 0.0 0.0 %le %le %le %le\n",
               in->VAR(rho, ip, 0), in->VAR(rho, ip, 1),
               in->VAR(sigma, ip, 0), in->VAR(sigma, ip, 1), in->VAR(sigma, ip, 2),
               in->VAR(tau, ip, 0), in->VAR(tau, ip, 1),
               in->VAR(exx, ip, 0), in->VAR(exx, ip, 1)
               );
    }
  }
#endif
}

static void
WORK_HGGA(ORDER_TXT, SPIN_TXT)
(const XC(func_type) *p, const xc_input_variables *in, xc_output_variables *out)
{
#ifdef HAVE_CUDA
  /* make a copy of 'p' and 'out' since they might be in host-only memory */
  XC(func_type) *pcuda = (XC(func_type) *) libxc_malloc(sizeof(XC(func_type)));
  xc_input_variables *incuda = (xc_input_variables *) libxc_malloc(sizeof(xc_input_variables));
  xc_output_variables *outcuda = (xc_output_variables *) libxc_malloc(sizeof(xc_output_variables));
  
  cudaMemcpy(pcuda, p, sizeof(XC(func_type)), cudaMemcpyHostToDevice);
  cudaMemcpy(incuda, in, sizeof(xc_input_variables), cudaMemcpyHostToDevice);
  cudaMemcpy(outcuda, out, sizeof(xc_output_variables), cudaMemcpyHostToDevice);

  /* determine number of blocks required */
  size_t nblocks = in->np/CUDA_BLOCK_SIZE;
  if(in->np != nblocks*CUDA_BLOCK_SIZE) nblocks++;

  /* execute kernel */
  WORK_HGGA_IP(ORDER_TXT, SPIN_TXT)<<<nblocks, CUDA_BLOCK_SIZE>>>
    (pcuda, incuda, outcuda);

  /* clean up memory */
  libxc_free(pcuda);
  libxc_free(incuda);
  libxc_free(outcuda);
#else
  size_t ip;
  
  /* simply loop over points */
  for(ip=0; ip<in->np; ip++){
    WORK_HGGA_IP(ORDER_TXT, SPIN_TXT)(p, ip, in, out);
  }
#endif
}