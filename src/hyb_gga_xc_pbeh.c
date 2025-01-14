/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "xc_funcs.h"

#define XC_HYB_GGA_XC_PBEH      406 /* aka PBE0 or PBE1PBE */
#define XC_HYB_GGA_XC_PBE0_13   456 /* PBE0-1/3            */
#define XC_HYB_GGA_XC_HPBEINT   472 /* hPBEint             */
#define XC_HYB_GGA_XC_PBE_MOL0  273 /* PBEmol0             */
#define XC_HYB_GGA_XC_PBE_SOL0  274 /* PBEsol0             */
#define XC_HYB_GGA_XC_PBEB0     275 /* PBEbeta0            */
#define XC_HYB_GGA_XC_PBE_MOLB0 276 /* PBEmolbeta0         */
#define XC_HYB_GGA_XC_PBE50     290 /* PBE0 with 50% exx   */
#define XC_HYB_GGA_XC_PBE_2X    392 /* PBE0 with 56% exx   */
#define XC_HYB_GGA_XC_PBE38     393 /* PBE0 with 3/8 = 37.5% exx  */
#define XC_HYB_GGA_XC_RELPBE0   325 /* PBE0 refitted for actinide compounds */

#define PBEH_N_PAR 1
static const char  *pbeh_names[PBEH_N_PAR]      = {"_beta"};
static const char  *pbeh_desc[PBEH_N_PAR]       = {"Mixing parameter"};
static const double pbeh_values[PBEH_N_PAR]     = {0.25};
static const double pbeh_13_values[PBEH_N_PAR]  = {1.0/3.0};
static const double pbeh_50_values[PBEH_N_PAR]  = {0.50};
static const double pbeh_int_values[PBEH_N_PAR] = {1.0/6.0};
static const double pbe_2x_values[PBEH_N_PAR] = {0.56};
static const double pbe38_values[PBEH_N_PAR] = {3.0/8.0};

static void
pbeh_set_ext_params(xc_func_type *p, const double *ext_params)
{
  double beta;

  assert(p != NULL);
  beta = get_ext_param(p, ext_params, 0);

  p->mix_coef[0] = 1.0 - beta;
  p->cam_alpha = beta;
}


static void
hyb_gga_xc_pbeh_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_PBE, XC_GGA_C_PBE};
  static double funcs_coef[2] = {0.0, 1.0};

  /* Note that the value of funcs_coef[0] and hyb_coeff will be set
      by set_ext_params */
  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}


#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_pbeh = {
  XC_HYB_GGA_XC_PBEH,
  XC_EXCHANGE_CORRELATION,
  "PBEH (PBE0)",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Adamo1999_6158, &xc_ref_Ernzerhof1999_5029, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {PBEH_N_PAR, pbeh_names, pbeh_desc, pbeh_values, pbeh_set_ext_params},
  hyb_gga_xc_pbeh_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_pbe50 = {
  XC_HYB_GGA_XC_PBE50,
  XC_EXCHANGE_CORRELATION,
  "PBE50",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Bernard2012_204103, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {PBEH_N_PAR, pbeh_names, pbeh_desc, pbeh_50_values, pbeh_set_ext_params},
  hyb_gga_xc_pbeh_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_pbe0_13 = {
  XC_HYB_GGA_XC_PBE0_13,
  XC_EXCHANGE_CORRELATION,
  "PBE0-1/3",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Cortona2012_086101, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {PBEH_N_PAR, pbeh_names, pbeh_desc, pbeh_13_values, pbeh_set_ext_params},
  hyb_gga_xc_pbeh_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_pbe38 = {
  XC_HYB_GGA_XC_PBE38,
  XC_EXCHANGE_CORRELATION,
  "PBE38: PBE0 with 3/8 = 37.5% exact exchange",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Grimme2010_154104, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {PBEH_N_PAR, pbeh_names, pbeh_desc, pbe38_values, pbeh_set_ext_params},
  hyb_gga_xc_pbeh_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_pbe_2x = {
  XC_HYB_GGA_XC_PBE_2X,
  XC_EXCHANGE_CORRELATION,
  "PBE-2X: PBE0 with 56% exact exchange",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Tahchieva2018_4806, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {PBEH_N_PAR, pbeh_names, pbeh_desc, pbe_2x_values, pbeh_set_ext_params},
  hyb_gga_xc_pbeh_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};

static void
hyb_gga_xc_hpbeint_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_PBEINT, XC_GGA_C_PBEINT};
  static double funcs_coef[2] = {0.0, 1.0};

  /* Note that the value of funcs_coef[0] and hyb_coeff will be set
      by set_ext_params */
  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_hpbeint = {
  XC_HYB_GGA_XC_HPBEINT,
  XC_EXCHANGE_CORRELATION,
  "hPBEint",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Fabiano2013_673, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL | XC_FLAGS_DEVELOPMENT,
  1e-15,
  {PBEH_N_PAR, pbeh_names, pbeh_desc, pbeh_int_values, pbeh_set_ext_params},
  hyb_gga_xc_hpbeint_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};


static void
hyb_gga_xc_pbemol0_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_PBE_MOL, XC_GGA_C_PBE_MOL};
  static double funcs_coef[2] = {0.0, 1.0};

  /* Note that the value of funcs_coef[0] and hyb_coeff will be set
      by set_ext_params */
  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_pbe_mol0 = {
  XC_HYB_GGA_XC_PBE_MOL0,
  XC_EXCHANGE_CORRELATION,
  "PBEmol0",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_delCampo2012_104108, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {PBEH_N_PAR, pbeh_names, pbeh_desc, pbeh_values, pbeh_set_ext_params},
  hyb_gga_xc_pbemol0_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};


static void
hyb_gga_xc_pbesol0_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_PBE_SOL, XC_GGA_C_PBE_SOL};
  static double funcs_coef[2] = {0.0, 1.0};

  /* Note that the value of funcs_coef[0] and cam_alpha will be set
      by set_ext_params */
  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_pbe_sol0 = {
  XC_HYB_GGA_XC_PBE_SOL0,
  XC_EXCHANGE_CORRELATION,
  "PBEsol0",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_delCampo2012_104108, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {PBEH_N_PAR, pbeh_names, pbeh_desc, pbeh_values, pbeh_set_ext_params},
  hyb_gga_xc_pbesol0_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};


static void
hyb_gga_xc_pbeb0_init(xc_func_type *p)
{
  static int    funcs_id  [2] = {XC_GGA_X_PBE, XC_GGA_C_PBE};
  static double funcs_coef[2] = {0.0, 1.0};

  /* 0.050044 ~ 3/4 beta_PBE */
  static double par_c_pbe[] = {0.050044, XC_EXT_PARAMS_DEFAULT, XC_EXT_PARAMS_DEFAULT};

  /* Note that the value of funcs_coef[0] and cam_alpha will be set
      by set_ext_params */
  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_func_set_ext_params(p->func_aux[1], par_c_pbe);

  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_pbeb0 = {
  XC_HYB_GGA_XC_PBEB0,
  XC_EXCHANGE_CORRELATION,
  "PBEbeta0",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_delCampo2012_104108, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {PBEH_N_PAR, pbeh_names, pbeh_desc, pbeh_values, pbeh_set_ext_params},
  hyb_gga_xc_pbeb0_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};


static void
hyb_gga_xc_pbemolb0_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_PBE_MOL, XC_GGA_C_PBE};
  static double funcs_coef[2] = {0.0, 1.0};

  /* 0.06288 ~ 3/4 beta_PBEmol */
  static double par_c_pbe[] = {0.06288, XC_EXT_PARAMS_DEFAULT, XC_EXT_PARAMS_DEFAULT};

  /* Note that the value of funcs_coef[0] and cam_alpha will be set by
      set_ext_params */
  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_func_set_ext_params(p->func_aux[1], par_c_pbe);

  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_pbe_molb0 = {
  XC_HYB_GGA_XC_PBE_MOLB0,
  XC_EXCHANGE_CORRELATION,
  "PBEmolbeta0",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_delCampo2012_104108, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {PBEH_N_PAR, pbeh_names, pbeh_desc, pbeh_values, pbeh_set_ext_params},
  hyb_gga_xc_pbemolb0_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};

#define RELPBE_N_PAR 6
static const char  *relpbe_names[RELPBE_N_PAR]      = {
  "_cx",  "_scalggac", "_scalldac",
  "_xkappa", "_cbetapbe", "_xmuepbe"};
static const char  *relpbe_desc[RELPBE_N_PAR]       = {
  "Fraction of HF exchange", "GGA correlation scaling", "LDA correlation scaling",
  "PBE exchange kappa", "PBE correlation beta", "PBE exchange mu"};
static const double relpbe_values[RELPBE_N_PAR]     = {
  0.2311865490779869,  0.39051822098129085, 0.6094817790187091,
  1.009008835630956,   0.06791249476107648, 0.04102242166916949};

static void
hyb_gga_xc_relpbe_init(xc_func_type *p)
{
  /* Note that the value of funcs_coef[0] and hyb_coeff will be set
     by set_ext_params */
  static int   funcs_id   [3] = {XC_GGA_X_PBE, XC_GGA_C_PBE, XC_LDA_C_PW_MOD};
  static double funcs_coef[3] = {0.0, 0.0, 0.0};
  xc_mix_init(p, 3, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

static void
relpbe_set_ext_params(xc_func_type *p, const double *ext_params)
{
  /* Input parameters */
  double cx;
  double scalggac;
  double scalldac;
  double xkappa;
  double cbetapbe;
  double xmuepbe;

  /* Arrays to pass parameters to internal PBE functionals */
  double xpars[2];
  double cpars[3];

  assert(p != NULL);
  cx = get_ext_param(p, ext_params, 0);
  scalggac = get_ext_param(p, ext_params, 1);
  scalldac = get_ext_param(p, ext_params, 2);
  xkappa = get_ext_param(p, ext_params, 3);
  cbetapbe = get_ext_param(p, ext_params, 4);
  xmuepbe = get_ext_param(p, ext_params, 5);

  /* Collect exchange and correlation parameters */
  xpars[0] = xkappa;
  xpars[1] = xmuepbe;
  cpars[0] = cbetapbe;
  cpars[1] = 0.031090690869654895034; /* PBE default value */
  cpars[2] = 1.0; /* PBE default value */

  /* Set x and c parameters */
  xc_func_set_ext_params(p->func_aux[0], xpars);
  xc_func_set_ext_params(p->func_aux[1], cpars);

  /* Set mixing parameters */
  p->mix_coef[0] = 1.0 - cx;
  p->mix_coef[1] = scalggac;
  p->mix_coef[2] = scalldac-scalggac;

  p->cam_alpha = cx;
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_relpbe0 = {
  XC_HYB_GGA_XC_RELPBE0,
  XC_EXCHANGE_CORRELATION,
  "relPBE0 a.k.a. relPBE: PBE0 refitted for actinide compounds",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Mitrofanov2021_161103, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {RELPBE_N_PAR, relpbe_names, relpbe_desc, relpbe_values, relpbe_set_ext_params},
  hyb_gga_xc_relpbe_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};
