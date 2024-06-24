/*
 Copyright (C) 2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_LDA_C_NSF07     333  /* Non-singular electron-nucleus correlation functional by Imamura, Kiryu and Nakai  */

typedef struct {
  double Z;
} lda_c_nsf07_params;

#define N_PAR 1
static const char  *names[N_PAR]  = {"_Z"};
static const char  *desc[N_PAR]   = {"Nuclear charge"};

static const double par_nsf07[N_PAR]   = {1.0};

static void
lda_c_nsf07_init(xc_func_type *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc(sizeof(lda_c_nsf07_params));
}

#include "maple2c/lda_exc/lda_c_nsf07.c"
#include "work_lda.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_lda_c_nsf07 = {
  XC_LDA_C_NSF07,
  XC_CORRELATION,
  "NSF07: electron-nucleus correlation functional by Udagawa, Tsuneda, and Tachikawa",
  XC_FAMILY_LDA,
  {&xc_ref_Imamura2008_735, &xc_ref_epcnote, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {N_PAR, names, desc, par_nsf07, set_ext_params_cpy},
  lda_c_nsf07_init, NULL,
  &work_lda, NULL, NULL
};
