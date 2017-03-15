/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/lda_xc_1d_ehwlrg.mpl
  Type of functional: work_lda
*/

static void
func0(const XC(func_type) *p, XC(lda_work_t) *r)
{
  double t1, t4, t5, t10, t14, t18, t19, t24;
  double t25, t29, t32, t33, t36;

  lda_xc_1d_ehwlrg_params *params;
 
  assert(p->params != NULL);
  params = (lda_xc_1d_ehwlrg_params * )(p->params);

  t1 = 0.1e1 / r->rs;
  t4 = r->rs * r->rs;
  t5 = 0.1e1 / t4;
  t10 = pow(0.50000000000000000000e0 * t1, params->alpha);
  r->f = (params->a1 + 0.50000000000000000000e0 * params->a2 * t1 + 0.25000000000000000000e0 * params->a3 * t5) * t10;

  if(r->order < 1) return;

  t14 = 0.1e1 / t4 / r->rs;
  t18 = (-0.50000000000000000000e0 * params->a2 * t5 - 0.50000000000000000000e0 * params->a3 * t14) * t10;
  t19 = params->alpha * t1;
  r->dfdrs = t18 - 0.10000000000000000000e1 * r->f * t19;

  if(r->order < 2) return;

  t24 = t4 * t4;
  t25 = 0.1e1 / t24;
  t29 = (0.10000000000000000000e1 * params->a2 * t14 + 0.15000000000000000000e1 * params->a3 * t25) * t10;
  t32 = params->alpha * params->alpha;
  t33 = t32 * t5;
  t36 = params->alpha * t5;
  r->d2fdrs2 = t29 - 0.20000000000000000000e1 * t18 * t19 + 0.10000000000000000000e1 * r->f * t33 + 0.10000000000000000000e1 * r->f * t36;

  if(r->order < 3) return;

  r->d3fdrs3 = (-0.30000000000000000000e1 * params->a2 * t25 - 0.60000000000000000000e1 * params->a3 / t24 / r->rs) * t10 - 0.30000000000000000000e1 * t29 * t19 + 0.30000000000000000000e1 * t18 * t33 + 0.30000000000000000000e1 * t18 * t36 - 0.10000000000000000000e1 * r->f * t32 * params->alpha * t14 - 0.30000000000000000000e1 * r->f * t32 * t14 - 0.20000000000000000000e1 * r->f * params->alpha * t14;

  if(r->order < 4) return;


}

static void
func1(const XC(func_type) *p, XC(lda_work_t) *r)
{
  double t1, t4, t5, t10, t14, t18, t19, t24;
  double t25, t29, t32, t33, t36;

  lda_xc_1d_ehwlrg_params *params;
 
  assert(p->params != NULL);
  params = (lda_xc_1d_ehwlrg_params * )(p->params);

  t1 = 0.1e1 / r->rs;
  t4 = r->rs * r->rs;
  t5 = 0.1e1 / t4;
  t10 = pow(0.50000000000000000000e0 * t1, params->alpha);
  r->f = (params->a1 + 0.50000000000000000000e0 * params->a2 * t1 + 0.25000000000000000000e0 * params->a3 * t5) * t10;

  if(r->order < 1) return;

  t14 = 0.1e1 / t4 / r->rs;
  t18 = (-0.50000000000000000000e0 * params->a2 * t5 - 0.50000000000000000000e0 * params->a3 * t14) * t10;
  t19 = params->alpha * t1;
  r->dfdrs = t18 - 0.10000000000000000000e1 * r->f * t19;
  r->dfdz = 0;

  if(r->order < 2) return;

  t24 = t4 * t4;
  t25 = 0.1e1 / t24;
  t29 = (0.10000000000000000000e1 * params->a2 * t14 + 0.15000000000000000000e1 * params->a3 * t25) * t10;
  t32 = params->alpha * params->alpha;
  t33 = t32 * t5;
  t36 = params->alpha * t5;
  r->d2fdrs2 = t29 - 0.20000000000000000000e1 * t18 * t19 + 0.10000000000000000000e1 * r->f * t33 + 0.10000000000000000000e1 * r->f * t36;
  r->d2fdrsz = 0;
  r->d2fdz2 = 0;

  if(r->order < 3) return;

  r->d3fdrs3 = (-0.30000000000000000000e1 * params->a2 * t25 - 0.60000000000000000000e1 * params->a3 / t24 / r->rs) * t10 - 0.30000000000000000000e1 * t29 * t19 + 0.30000000000000000000e1 * t18 * t33 + 0.30000000000000000000e1 * t18 * t36 - 0.10000000000000000000e1 * r->f * t32 * params->alpha * t14 - 0.30000000000000000000e1 * r->f * t32 * t14 - 0.20000000000000000000e1 * r->f * params->alpha * t14;
  r->d3fdrs2z = 0;
  r->d3fdrsz2 = 0;
  r->d3fdz3 = 0;

  if(r->order < 4) return;


}

void 
XC(lda_xc_1d_ehwlrg_func)(const XC(func_type) *p, XC(lda_work_t) *r)
{
  if(p->nspin == XC_UNPOLARIZED)
    func0(p, r);
  else
    func1(p, r);
}

#define maple2c_order 3
#define maple2c_func  XC(lda_xc_1d_ehwlrg_func)