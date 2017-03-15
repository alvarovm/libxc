/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/mgga_x_gvt4.mpl
  Type of functional: work_mgga_x
*/

static void 
XC(mgga_x_gvt4_enhance)(const XC(func_type) *pt, XC(mgga_work_x_t) *r)
{
  double t1, t4, t9, t10, t11, t14, t17, t20;
  double t22, t24, t29, t36, t39, t40, t41, t45;
  double t48, t51, t55, t63, t68, t73;


  t1 = r->x * r->x;
  t4 = 0.98297880522072792058e0 + 0.186726e-2 * t1 + 0.3734520e-2 * r->t;
  t9 = -0.3556788e-2 * t1 + 0.125006520e-1 * r->t - 0.56975470089836733547e-1;
  t10 = t4 * t4;
  t11 = 0.1e1 / t10;
  t14 = t1 * t1;
  t17 = 0.20e1 * r->t - 0.91155997446911942748e1;
  t20 = t17 * t17;
  t22 = -0.2354518e-4 * t14 - 0.1282732e-3 * t1 * t17 + 0.3574822e-3 * t20;
  t24 = 0.1e1 / t10 / t4;
  r->f = 0.10532414759910663819e1 / t4 - 0.10746613026776464272e1 * t9 * t11 - 0.10746613026776464272e1 * t22 * t24;

  if(r->order < 1) return;

  r->dfdrs = 0;
  t29 = t9 * t24;
  t36 = -0.9418072e-4 * t1 * r->x - 0.2565464e-3 * r->x * t17;
  t39 = t10 * t10;
  t40 = 0.1e1 / t39;
  t41 = t22 * t40;
  r->dfdx = 0.37113334939382841365e-2 * t11 * r->x + 0.80266882561514482706e-2 * t29 * r->x - 0.10746613026776464272e1 * t36 * t24 + 0.12040032384227172406e-1 * t41 * r->x;
  t45 = 0.80266882561514482706e-2 * t29;
  t48 = -0.25654640e-3 * t1 + 0.2859857600e-2 * r->t - 0.13034658604206585800e-1;
  t51 = 0.12040032384227172406e-1 * t41;
  r->dfdt = -0.17367318319558083390e-1 * t11 + t45 - 0.10746613026776464272e1 * t48 * t24 + t51;
  r->dfdu = 0;

  if(r->order < 2) return;

  r->d2fdrs2 = 0;
  t55 = t9 * t40;
  t63 = t36 * t40;
  t68 = t22 / t39 / t4;
  r->d2fdx2 = -0.84818555258005596530e-4 * t24 * t1 + 0.37113334939382841365e-2 * t11 - 0.89927483479088119787e-4 * t55 * t1 + t45 - 0.10746613026776464272e1 * (-0.28254216e-3 * t1 - 0.51309280e-3 * r->t + 0.23385742983414450029e-2) * t24 + 0.24080064768454344812e-1 * t63 * r->x - 0.17985496695817623957e-3 * t68 * t1 + t51;
  t73 = t48 * t40;
  r->d2fdt2 = -0.28433222620644192636e-2 * t24 - 0.89927483479088119787e-4 * t55 + 0.24080064768454344812e-1 * t73 - 0.17985496695817623957e-3 * t68;
  r->d2fdu2 = 0;
  r->d2fdrsx = 0;
  r->d2fdrst = 0;
  r->d2fdrsu = 0;
  r->d2fdxt = 0.62401971512559241512e-3 * t24 * r->x - 0.89927483479088119787e-4 * t55 * r->x + 0.12040032384227172406e-1 * t63 + 0.12040032384227172406e-1 * t73 * r->x - 0.17985496695817623957e-3 * t68 * r->x;
  r->d2fdxu = 0;
  r->d2fdtu = 0;

  if(r->order < 3) return;


}

#define maple2c_order 3
#define maple2c_func  XC(mgga_x_gvt4_enhance)