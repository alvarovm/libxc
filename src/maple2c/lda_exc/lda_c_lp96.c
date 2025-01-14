/*
  This file was generated automatically with scripts/maple2c.py.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2022 (X86 64 LINUX)
  Maple source      : ./maple/lda_exc/lda_c_lp96.mpl
  Type of functional: lda_exc
*/

#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)


#ifndef XC_DONT_COMPILE_EXC
GPU_DEVICE_FUNCTION static inline void
func_exc_unpol(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  double t1, t3, t4, t6, tzk0;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = POW_1_3(rho[0]);
  t3 = params->C2 / t1;
  t4 = t1 * t1;
  t6 = params->C3 / t4;
  tzk0 = params->C1 + t3 + t6;

  if(out->zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    out->zk[ip*p->dim.zk + 0] += tzk0;

}

#endif


#ifndef XC_DONT_COMPILE_VXC
GPU_DEVICE_FUNCTION static inline void
func_vxc_unpol(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  double t1, t3, t4, t6, tzk0;

  double t9, t13, tvrho0;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = POW_1_3(rho[0]);
  t3 = params->C2 / t1;
  t4 = t1 * t1;
  t6 = params->C3 / t4;
  tzk0 = params->C1 + t3 + t6;

  if(out->zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    out->zk[ip*p->dim.zk + 0] += tzk0;

  t9 = params->C2 / t1 / rho[0];
  t13 = params->C3 / t4 / rho[0];
  tvrho0 = params->C1 + t3 + t6 + rho[0] * (-t9 / 0.3e1 - 0.2e1 / 0.3e1 * t13);

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 0] += tvrho0;

}

#endif


#ifndef XC_DONT_COMPILE_FXC
GPU_DEVICE_FUNCTION static inline void
func_fxc_unpol(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  double t1, t3, t4, t6, tzk0;

  double t9, t13, tvrho0;

  double t19, t22, t26, tv2rho20;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = POW_1_3(rho[0]);
  t3 = params->C2 / t1;
  t4 = t1 * t1;
  t6 = params->C3 / t4;
  tzk0 = params->C1 + t3 + t6;

  if(out->zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    out->zk[ip*p->dim.zk + 0] += tzk0;

  t9 = params->C2 / t1 / rho[0];
  t13 = params->C3 / t4 / rho[0];
  tvrho0 = params->C1 + t3 + t6 + rho[0] * (-t9 / 0.3e1 - 0.2e1 / 0.3e1 * t13);

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 0] += tvrho0;

  t19 = rho[0] * rho[0];
  t22 = params->C2 / t1 / t19;
  t26 = params->C3 / t4 / t19;
  tv2rho20 = -0.2e1 / 0.3e1 * t9 - 0.4e1 / 0.3e1 * t13 + rho[0] * (0.4e1 / 0.9e1 * t22 + 0.1e2 / 0.9e1 * t26);

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 0] += tv2rho20;

}

#endif


#ifndef XC_DONT_COMPILE_KXC
GPU_DEVICE_FUNCTION static inline void
func_kxc_unpol(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  double t1, t3, t4, t6, tzk0;

  double t9, t13, tvrho0;

  double t19, t22, t26, tv2rho20;

  double t32, t35, t39, tv3rho30;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = POW_1_3(rho[0]);
  t3 = params->C2 / t1;
  t4 = t1 * t1;
  t6 = params->C3 / t4;
  tzk0 = params->C1 + t3 + t6;

  if(out->zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    out->zk[ip*p->dim.zk + 0] += tzk0;

  t9 = params->C2 / t1 / rho[0];
  t13 = params->C3 / t4 / rho[0];
  tvrho0 = params->C1 + t3 + t6 + rho[0] * (-t9 / 0.3e1 - 0.2e1 / 0.3e1 * t13);

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 0] += tvrho0;

  t19 = rho[0] * rho[0];
  t22 = params->C2 / t1 / t19;
  t26 = params->C3 / t4 / t19;
  tv2rho20 = -0.2e1 / 0.3e1 * t9 - 0.4e1 / 0.3e1 * t13 + rho[0] * (0.4e1 / 0.9e1 * t22 + 0.1e2 / 0.9e1 * t26);

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 0] += tv2rho20;

  t32 = t19 * rho[0];
  t35 = params->C2 / t1 / t32;
  t39 = params->C3 / t4 / t32;
  tv3rho30 = 0.4e1 / 0.3e1 * t22 + 0.1e2 / 0.3e1 * t26 + rho[0] * (-0.28e2 / 0.27e2 * t35 - 0.8e2 / 0.27e2 * t39);

  if(out->v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    out->v3rho3[ip*p->dim.v3rho3 + 0] += tv3rho30;

}

#endif


#ifndef XC_DONT_COMPILE_LXC
GPU_DEVICE_FUNCTION static inline void
func_lxc_unpol(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  double t1, t3, t4, t6, tzk0;

  double t9, t13, tvrho0;

  double t19, t22, t26, tv2rho20;

  double t32, t35, t39, tv3rho30;

  double t45, tv4rho40;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = POW_1_3(rho[0]);
  t3 = params->C2 / t1;
  t4 = t1 * t1;
  t6 = params->C3 / t4;
  tzk0 = params->C1 + t3 + t6;

  if(out->zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    out->zk[ip*p->dim.zk + 0] += tzk0;

  t9 = params->C2 / t1 / rho[0];
  t13 = params->C3 / t4 / rho[0];
  tvrho0 = params->C1 + t3 + t6 + rho[0] * (-t9 / 0.3e1 - 0.2e1 / 0.3e1 * t13);

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 0] += tvrho0;

  t19 = rho[0] * rho[0];
  t22 = params->C2 / t1 / t19;
  t26 = params->C3 / t4 / t19;
  tv2rho20 = -0.2e1 / 0.3e1 * t9 - 0.4e1 / 0.3e1 * t13 + rho[0] * (0.4e1 / 0.9e1 * t22 + 0.1e2 / 0.9e1 * t26);

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 0] += tv2rho20;

  t32 = t19 * rho[0];
  t35 = params->C2 / t1 / t32;
  t39 = params->C3 / t4 / t32;
  tv3rho30 = 0.4e1 / 0.3e1 * t22 + 0.1e2 / 0.3e1 * t26 + rho[0] * (-0.28e2 / 0.27e2 * t35 - 0.8e2 / 0.27e2 * t39);

  if(out->v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    out->v3rho3[ip*p->dim.v3rho3 + 0] += tv3rho30;

  t45 = t19 * t19;
  tv4rho40 = -0.112e3 / 0.27e2 * t35 - 0.32e3 / 0.27e2 * t39 + rho[0] * (0.28e3 / 0.81e2 * params->C2 / t1 / t45 + 0.88e3 / 0.81e2 * params->C3 / t4 / t45);

  if(out->v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    out->v4rho4[ip*p->dim.v4rho4 + 0] += tv4rho40;

}

#endif


#ifndef XC_DONT_COMPILE_EXC
GPU_DEVICE_FUNCTION static inline void
func_exc_pol(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  double t1, t2, t4, t5, t7, tzk0;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = rho[0] + rho[1];
  t2 = POW_1_3(t1);
  t4 = params->C2 / t2;
  t5 = t2 * t2;
  t7 = params->C3 / t5;
  tzk0 = params->C1 + t4 + t7;

  if(out->zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    out->zk[ip*p->dim.zk + 0] += tzk0;

}

#endif


#ifndef XC_DONT_COMPILE_VXC
GPU_DEVICE_FUNCTION static inline void
func_vxc_pol(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  double t1, t2, t4, t5, t7, tzk0;

  double t10, t14, tvrho0, tvrho1;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = rho[0] + rho[1];
  t2 = POW_1_3(t1);
  t4 = params->C2 / t2;
  t5 = t2 * t2;
  t7 = params->C3 / t5;
  tzk0 = params->C1 + t4 + t7;

  if(out->zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    out->zk[ip*p->dim.zk + 0] += tzk0;

  t10 = params->C2 / t2 / t1;
  t14 = params->C3 / t5 / t1;
  tvrho0 = params->C1 + t4 + t7 + t1 * (-t10 / 0.3e1 - 0.2e1 / 0.3e1 * t14);

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 0] += tvrho0;

  tvrho1 = tvrho0;

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 1] += tvrho1;

}

#endif


#ifndef XC_DONT_COMPILE_FXC
GPU_DEVICE_FUNCTION static inline void
func_fxc_pol(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  double t1, t2, t4, t5, t7, tzk0;

  double t10, t14, tvrho0, tvrho1;

  double t20, t23, t27, tv2rho20, tv2rho21, tv2rho22;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = rho[0] + rho[1];
  t2 = POW_1_3(t1);
  t4 = params->C2 / t2;
  t5 = t2 * t2;
  t7 = params->C3 / t5;
  tzk0 = params->C1 + t4 + t7;

  if(out->zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    out->zk[ip*p->dim.zk + 0] += tzk0;

  t10 = params->C2 / t2 / t1;
  t14 = params->C3 / t5 / t1;
  tvrho0 = params->C1 + t4 + t7 + t1 * (-t10 / 0.3e1 - 0.2e1 / 0.3e1 * t14);

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 0] += tvrho0;

  tvrho1 = tvrho0;

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 1] += tvrho1;

  t20 = t1 * t1;
  t23 = params->C2 / t2 / t20;
  t27 = params->C3 / t5 / t20;
  tv2rho20 = -0.2e1 / 0.3e1 * t10 - 0.4e1 / 0.3e1 * t14 + t1 * (0.4e1 / 0.9e1 * t23 + 0.1e2 / 0.9e1 * t27);

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 0] += tv2rho20;

  tv2rho21 = tv2rho20;

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 1] += tv2rho21;

  tv2rho22 = tv2rho21;

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 2] += tv2rho22;

}

#endif


#ifndef XC_DONT_COMPILE_KXC
GPU_DEVICE_FUNCTION static inline void
func_kxc_pol(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  double t1, t2, t4, t5, t7, tzk0;

  double t10, t14, tvrho0, tvrho1;

  double t20, t23, t27, tv2rho20, tv2rho21, tv2rho22;

  double t33, t36, t40, tv3rho30, tv3rho31, tv3rho32, tv3rho33;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = rho[0] + rho[1];
  t2 = POW_1_3(t1);
  t4 = params->C2 / t2;
  t5 = t2 * t2;
  t7 = params->C3 / t5;
  tzk0 = params->C1 + t4 + t7;

  if(out->zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    out->zk[ip*p->dim.zk + 0] += tzk0;

  t10 = params->C2 / t2 / t1;
  t14 = params->C3 / t5 / t1;
  tvrho0 = params->C1 + t4 + t7 + t1 * (-t10 / 0.3e1 - 0.2e1 / 0.3e1 * t14);

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 0] += tvrho0;

  tvrho1 = tvrho0;

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 1] += tvrho1;

  t20 = t1 * t1;
  t23 = params->C2 / t2 / t20;
  t27 = params->C3 / t5 / t20;
  tv2rho20 = -0.2e1 / 0.3e1 * t10 - 0.4e1 / 0.3e1 * t14 + t1 * (0.4e1 / 0.9e1 * t23 + 0.1e2 / 0.9e1 * t27);

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 0] += tv2rho20;

  tv2rho21 = tv2rho20;

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 1] += tv2rho21;

  tv2rho22 = tv2rho21;

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 2] += tv2rho22;

  t33 = t20 * t1;
  t36 = params->C2 / t2 / t33;
  t40 = params->C3 / t5 / t33;
  tv3rho30 = 0.4e1 / 0.3e1 * t23 + 0.1e2 / 0.3e1 * t27 + t1 * (-0.28e2 / 0.27e2 * t36 - 0.8e2 / 0.27e2 * t40);

  if(out->v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    out->v3rho3[ip*p->dim.v3rho3 + 0] += tv3rho30;

  tv3rho31 = tv3rho30;

  if(out->v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    out->v3rho3[ip*p->dim.v3rho3 + 1] += tv3rho31;

  tv3rho32 = tv3rho31;

  if(out->v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    out->v3rho3[ip*p->dim.v3rho3 + 2] += tv3rho32;

  tv3rho33 = tv3rho32;

  if(out->v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    out->v3rho3[ip*p->dim.v3rho3 + 3] += tv3rho33;

}

#endif


#ifndef XC_DONT_COMPILE_LXC
GPU_DEVICE_FUNCTION static inline void
func_lxc_pol(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  double t1, t2, t4, t5, t7, tzk0;

  double t10, t14, tvrho0, tvrho1;

  double t20, t23, t27, tv2rho20, tv2rho21, tv2rho22;

  double t33, t36, t40, tv3rho30, tv3rho31, tv3rho32, tv3rho33;

  double t46, tv4rho40, tv4rho41, tv4rho42, tv4rho43, tv4rho44;

  lda_c_lp96_params *params;

  assert(p->params != NULL);
  params = (lda_c_lp96_params * )(p->params);

  t1 = rho[0] + rho[1];
  t2 = POW_1_3(t1);
  t4 = params->C2 / t2;
  t5 = t2 * t2;
  t7 = params->C3 / t5;
  tzk0 = params->C1 + t4 + t7;

  if(out->zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    out->zk[ip*p->dim.zk + 0] += tzk0;

  t10 = params->C2 / t2 / t1;
  t14 = params->C3 / t5 / t1;
  tvrho0 = params->C1 + t4 + t7 + t1 * (-t10 / 0.3e1 - 0.2e1 / 0.3e1 * t14);

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 0] += tvrho0;

  tvrho1 = tvrho0;

  if(out->vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    out->vrho[ip*p->dim.vrho + 1] += tvrho1;

  t20 = t1 * t1;
  t23 = params->C2 / t2 / t20;
  t27 = params->C3 / t5 / t20;
  tv2rho20 = -0.2e1 / 0.3e1 * t10 - 0.4e1 / 0.3e1 * t14 + t1 * (0.4e1 / 0.9e1 * t23 + 0.1e2 / 0.9e1 * t27);

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 0] += tv2rho20;

  tv2rho21 = tv2rho20;

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 1] += tv2rho21;

  tv2rho22 = tv2rho21;

  if(out->v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    out->v2rho2[ip*p->dim.v2rho2 + 2] += tv2rho22;

  t33 = t20 * t1;
  t36 = params->C2 / t2 / t33;
  t40 = params->C3 / t5 / t33;
  tv3rho30 = 0.4e1 / 0.3e1 * t23 + 0.1e2 / 0.3e1 * t27 + t1 * (-0.28e2 / 0.27e2 * t36 - 0.8e2 / 0.27e2 * t40);

  if(out->v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    out->v3rho3[ip*p->dim.v3rho3 + 0] += tv3rho30;

  tv3rho31 = tv3rho30;

  if(out->v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    out->v3rho3[ip*p->dim.v3rho3 + 1] += tv3rho31;

  tv3rho32 = tv3rho31;

  if(out->v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    out->v3rho3[ip*p->dim.v3rho3 + 2] += tv3rho32;

  tv3rho33 = tv3rho32;

  if(out->v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    out->v3rho3[ip*p->dim.v3rho3 + 3] += tv3rho33;

  t46 = t20 * t20;
  tv4rho40 = -0.112e3 / 0.27e2 * t36 - 0.32e3 / 0.27e2 * t40 + t1 * (0.28e3 / 0.81e2 * params->C2 / t2 / t46 + 0.88e3 / 0.81e2 * params->C3 / t5 / t46);

  if(out->v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    out->v4rho4[ip*p->dim.v4rho4 + 0] += tv4rho40;

  tv4rho41 = tv4rho40;

  if(out->v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    out->v4rho4[ip*p->dim.v4rho4 + 1] += tv4rho41;

  tv4rho42 = tv4rho41;

  if(out->v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    out->v4rho4[ip*p->dim.v4rho4 + 2] += tv4rho42;

  tv4rho43 = tv4rho42;

  if(out->v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    out->v4rho4[ip*p->dim.v4rho4 + 3] += tv4rho43;

  tv4rho44 = tv4rho43;

  if(out->v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    out->v4rho4[ip*p->dim.v4rho4 + 4] += tv4rho44;

}

#endif

