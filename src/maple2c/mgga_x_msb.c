/* 
  This file was generated automatically with ./maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2017 (X86 64 LINUX)
  Maple source      : ../maple/mgga_x_msb.mpl
  Type of functional: work_mgga_x
*/

static void 
xc_mgga_x_msb_enhance(const xc_func_type *pt, xc_mgga_work_x_t *r)
{
  double t1, t2, t3, t4, t6, t7, t9, t10;
  double t14, t16, t17, t18, t21, t22, t23, t25;
  double t26, t27, t28, t29, t30, t32, t34, t35;
  double t37, t39, t40, t41, t42, t47, t49, t50;
  double t52, t53, t54, t56, t57, t58, t59, t62;
  double t63, t64, t65, t69, t70, t73, t74, t76;
  double t78, t81, t84, t85, t89, t92, t95, t98;
  double t107, t109, t111, t112, t113, t114, t118, t119;
  double t137, t138, t145, t149, t166, t180, t194, t213;

  mgga_x_msb_params *params;
 
  assert(pt->params != NULL);
  params = (mgga_x_msb_params * ) (pt->params);

  t1 = M_CBRT6;
  t2 = 0.31415926535897932385e1 * 0.31415926535897932385e1;
  t3 = POW_1_3(t2);
  t4 = t3 * t3;
  t6 = t1 / t4;
  t7 = r->x * r->x;
  t9 = 0.5e1 / 0.972e3 * t6 * t7;
  t10 = params->kappa + t9;
  t14 = params->kappa * (0.1e1 - params->kappa / t10);
  t16 = r->t - t7 / 0.8e1;
  t17 = t16 * t16;
  t18 = t1 * t1;
  t21 = r->t - 0.3e1 / 0.10e2 * t18 * t4;
  t22 = t21 * t21;
  t23 = 0.1e1 / t22;
  t25 = -t17 * t23 + 0.1e1;
  t26 = t25 * t25;
  t27 = t26 * t25;
  t28 = t17 * t16;
  t29 = t22 * t21;
  t30 = 0.1e1 / t29;
  t32 = t17 * t17;
  t34 = params->b * t32 * t17;
  t35 = t22 * t22;
  t37 = 0.1e1 / t35 / t22;
  t39 = t28 * t30 + t34 * t37 + 0.1e1;
  t40 = 0.1e1 / t39;
  t41 = t27 * t40;
  t42 = params->kappa + t9 + params->c;
  t47 = params->kappa * (0.1e1 - params->kappa / t42) - t14;
  r->f = t41 * t47 + t14 + 0.1e1;

  if(r->order < 1) return;

  r->dfdrs = 0.0e0;
  t49 = params->kappa * params->kappa;
  t50 = t10 * t10;
  t52 = t49 / t50;
  t53 = t6 * r->x;
  t54 = t52 * t53;
  t56 = t26 * t40;
  t57 = t56 * t47;
  t58 = t16 * t23;
  t59 = t58 * r->x;
  t62 = t39 * t39;
  t63 = 0.1e1 / t62;
  t64 = t27 * t63;
  t65 = t17 * t30;
  t69 = params->b * t32 * t16;
  t70 = t37 * r->x;
  t73 = -0.3e1 / 0.4e1 * t65 * r->x - 0.3e1 / 0.2e1 * t69 * t70;
  t74 = t47 * t73;
  t76 = t42 * t42;
  t78 = t49 / t76;
  t81 = 0.5e1 / 0.486e3 * t78 * t53 - 0.5e1 / 0.486e3 * t54;
  r->dfdx = 0.5e1 / 0.486e3 * t54 + 0.3e1 / 0.2e1 * t57 * t59 - t64 * t74 + t41 * t81;
  t84 = -0.2e1 * t58 + 0.2e1 * t65;
  t85 = t47 * t84;
  t89 = 0.1e1 / t35;
  t92 = t69 * t37;
  t95 = 0.1e1 / t35 / t29;
  t98 = -0.3e1 * t28 * t89 - 0.6e1 * t34 * t95 + 0.3e1 * t65 + 0.6e1 * t92;
  r->dfdt = -t64 * t47 * t98 + 0.3e1 * t56 * t85;
  r->dfdu = 0.0e0;

  if(r->order < 2) return;

  r->d2fdrs2 = 0.0e0;
  t107 = t18 / t3 / t2 * t7;
  t109 = 0.25e2 / 0.118098e6 * t49 / t50 / t10 * t107;
  t111 = 0.5e1 / 0.486e3 * t52 * t6;
  t112 = t25 * t40;
  t113 = t112 * t47;
  t114 = t17 * t89;
  t118 = t26 * t63;
  t119 = t118 * t47;
  t137 = t27 / t62 / t39;
  t138 = t73 * t73;
  t145 = t16 * t30;
  t149 = params->b * t32;
  r->d2fdx2 = -t109 + t111 + 0.3e1 / 0.2e1 * t113 * t114 * t7 - 0.3e1 * t119 * t58 * r->x * t73 + 0.3e1 * t56 * t81 * t59 - 0.3e1 / 0.8e1 * t56 * t47 * t7 * t23 + 0.3e1 / 0.2e1 * t56 * t47 * t16 * t23 + 0.2e1 * t137 * t47 * t138 - 0.2e1 * t64 * t81 * t73 - t64 * t47 * (0.3e1 / 0.8e1 * t145 * t7 - 0.3e1 / 0.4e1 * t65 + 0.15e2 / 0.8e1 * t149 * t37 * t7 - 0.3e1 / 0.2e1 * t92) + t41 * (-0.25e2 / 0.118098e6 * t49 / t76 / t42 * t107 + 0.5e1 / 0.486e3 * t78 * t6 + t109 - t111);
  t166 = t84 * t84;
  t180 = t98 * t98;
  t194 = t35 * t35;
  r->d2fdt2 = 0.6e1 * t112 * t47 * t166 - 0.6e1 * t118 * t85 * t98 + 0.3e1 * t56 * t47 * (-0.2e1 * t23 + 0.8e1 * t145 - 0.6e1 * t114) + 0.2e1 * t137 * t47 * t180 - t64 * t47 * (0.6e1 * t145 - 0.18e2 * t114 + 0.12e2 * t28 / t35 / t21 + 0.30e2 * t149 * t37 - 0.72e2 * t69 * t95 + 0.42e2 * t34 / t194);
  r->d2fdu2 = 0.0e0;
  r->d2fdrsx = 0.0e0;
  r->d2fdrst = 0.0e0;
  r->d2fdrsu = 0.0e0;
  t213 = t145 * r->x;
  r->d2fdxt = 0.3e1 * t113 * t58 * r->x * t84 - 0.3e1 / 0.2e1 * t119 * t58 * r->x * t98 + 0.3e1 / 0.2e1 * t56 * t47 * t23 * r->x - 0.3e1 * t57 * t213 - 0.3e1 * t118 * t74 * t84 + 0.2e1 * t137 * t74 * t98 - t64 * t47 * (-0.3e1 / 0.2e1 * t213 + 0.9e1 / 0.4e1 * t114 * r->x - 0.15e2 / 0.2e1 * t149 * t70 + 0.9e1 * t69 * t95 * r->x) + 0.3e1 * t56 * t81 * t84 - t64 * t81 * t98;
  r->d2fdxu = 0.0e0;
  r->d2fdtu = 0.0e0;

  if(r->order < 3) return;


}

#define maple2c_order 3
#define maple2c_func  xc_mgga_x_msb_enhance