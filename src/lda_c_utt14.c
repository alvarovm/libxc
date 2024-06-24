/*
 Copyright (C) 2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_LDA_C_UTT14     332  /* Electron-nucleus correlation functional by Udagawa, Tsuneda, and Tachikawa   */

typedef struct {
  double q;
  double Z;
} lda_c_utt14_params;

#define N_PAR 2
static const char  *names[N_PAR]  = {"_q", "_Z"};
static const char  *desc[N_PAR]   = {"q parameter", "Nuclear charge"};

static const double par_utt14[N_PAR]   = {4.971, 1.0};

static void
lda_c_utt14_init(xc_func_type *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc(sizeof(lda_c_utt14_params));
}

#include "maple2c/lda_exc/lda_c_utt14.c"
#include "work_lda.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_lda_c_utt14 = {
  XC_LDA_C_UTT14,
  XC_CORRELATION,
  "UTT14: electron-nucleus correlation functional by Udagawa, Tsuneda, and Tachikawa",
  XC_FAMILY_LDA,
  {&xc_ref_Udagawa2014_052519, &xc_ref_MejiaRodriguez2019_174115, &xc_ref_epcnote, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {N_PAR, names, desc, par_utt14, set_ext_params_cpy},
  lda_c_utt14_init, NULL,
  &work_lda, NULL, NULL
};
