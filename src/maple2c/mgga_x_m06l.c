/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/mgga_x_m06l.mpl
  Type of functional: work_mgga_x
*/

static void 
XC(mgga_x_m06l_enhance)(const XC(func_type) *pt, XC(mgga_work_x_t) *r)
{
  double t1, t3, t6, t8, t9, t10, t11, t12;
  double t15, t16, t17, t18, t19, t22, t23, t24;
  double t25, t26, t29, t30, t31, t32, t33, t36;
  double t37, t38, t39, t40, t43, t44, t45, t47;
  double t50, t51, t52, t54, t57, t58, t59, t60;
  double t61, t64, t65, t66, t68, t71, t72, t73;
  double t75, t78, t80, t82, t85, t87, t90, t93;
  double t94, t95, t97, t99, t100, t101, t103, t104;
  double t106, t107, t109, t110, t112, t114, t116, t117;
  double t118, t121, t124, t127, t133, t136, t138, t139;
  double t140, t147, t152, t157, t162, t167, t170, t173;
  double t178, t183, t188, t193, t197, t200, t201, t210;
  double t220, t228, t238, t243, t279, t323, t327, t332;

  mgga_x_m06l_params *params;

  assert(pt->params != NULL);
  params = (mgga_x_m06l_params * )(pt->params);

  t1 = r->x * r->x;
  t3 = 0.8040e0 + 0.36121864536509472266e-2 * t1;
  t6 = 0.180400e1 - 0.64641600e0 / t3;
  t8 = params->a[1];
  t9 = 0.45577998723455971374e1 - r->t;
  t10 = t8 * t9;
  t11 = 0.45577998723455971374e1 + r->t;
  t12 = 0.1e1 / t11;
  t15 = params->a[2];
  t16 = t9 * t9;
  t17 = t15 * t16;
  t18 = t11 * t11;
  t19 = 0.1e1 / t18;
  t22 = params->a[3];
  t23 = t16 * t9;
  t24 = t22 * t23;
  t25 = t18 * t11;
  t26 = 0.1e1 / t25;
  t29 = params->a[4];
  t30 = t16 * t16;
  t31 = t29 * t30;
  t32 = t18 * t18;
  t33 = 0.1e1 / t32;
  t36 = params->a[5];
  t37 = t30 * t9;
  t38 = t36 * t37;
  t39 = t32 * t11;
  t40 = 0.1e1 / t39;
  t43 = params->a[6];
  t44 = t30 * t16;
  t45 = t43 * t44;
  t47 = 0.1e1 / t32 / t18;
  t50 = params->a[7];
  t51 = t30 * t23;
  t52 = t50 * t51;
  t54 = 0.1e1 / t32 / t25;
  t57 = params->a[8];
  t58 = t30 * t30;
  t59 = t57 * t58;
  t60 = t32 * t32;
  t61 = 0.1e1 / t60;
  t64 = params->a[9];
  t65 = t58 * t9;
  t66 = t64 * t65;
  t68 = 0.1e1 / t60 / t11;
  t71 = params->a[10];
  t72 = t58 * t16;
  t73 = t71 * t72;
  t75 = 0.1e1 / t60 / t18;
  t78 = params->a[11];
  t80 = t78 * t58 * t23;
  t82 = 0.1e1 / t60 / t25;
  t85 = params->a[0] + 0.10e1 * t10 * t12 + 0.100e1 * t17 * t19 + 0.1000e1 * t24 * t26 + 0.10000e1 * t31 * t33 + 0.100000e1 * t38 * t40 + 0.1000000e1 * t45 * t47 + 0.10000000e1 * t52 * t54 + 0.100000000e1 * t59 * t61 + 0.1000000000e1 * t66 * t68 + 0.10000000000e1 * t73 * t75 + 0.100000000000e1 * t80 * t82;
  t87 = params->d[0];
  t90 = 0.98297880522072792058e0 + 0.186726e-2 * t1 + 0.3734520e-2 * r->t;
  t93 = params->d[1];
  t94 = t93 * t1;
  t95 = params->d[2];
  t97 = 0.20e1 * r->t - 0.91155997446911942748e1;
  t99 = t95 * t97 + t94;
  t100 = t90 * t90;
  t101 = 0.1e1 / t100;
  t103 = params->d[3];
  t104 = t1 * t1;
  t106 = params->d[4];
  t107 = t106 * t1;
  t109 = params->d[5];
  t110 = t97 * t97;
  t112 = t103 * t104 + t107 * t97 + t109 * t110;
  t114 = 0.1e1 / t100 / t90;
  r->f = t6 * t85 + t87 / t90 + t99 * t101 + t112 * t114;

  if(r->order < 1) return;

  r->dfdrs = 0;
  t116 = t3 * t3;
  t117 = 0.1e1 / t116;
  t118 = t117 * r->x;
  t121 = t87 * t101;
  t124 = t93 * r->x;
  t127 = t99 * t114;
  t133 = t106 * r->x;
  t136 = 0.4e1 * t103 * t1 * r->x + 0.2e1 * t133 * t97;
  t138 = t100 * t100;
  t139 = 0.1e1 / t138;
  t140 = t112 * t139;
  r->dfdx = 0.46699502372464614049e-2 * t118 * t85 - 0.373452e-2 * t121 * r->x + 0.2e1 * t124 * t101 - 0.746904e-2 * t127 * r->x + t136 * t114 - 0.1120356e-1 * t140 * r->x;
  t147 = t15 * t9;
  t152 = t22 * t16;
  t157 = t29 * t23;
  t162 = t36 * t30;
  t167 = t43 * t37;
  t170 = -0.10e1 * t8 * t12 - 0.10e1 * t10 * t19 - 0.200e1 * t147 * t19 - 0.200e1 * t17 * t26 - 0.3000e1 * t152 * t26 - 0.3000e1 * t24 * t33 - 0.40000e1 * t157 * t33 - 0.40000e1 * t31 * t40 - 0.500000e1 * t162 * t40 - 0.500000e1 * t38 * t47 - 0.6000000e1 * t167 * t47;
  t173 = t50 * t44;
  t178 = t57 * t51;
  t183 = t64 * t58;
  t188 = t71 * t65;
  t193 = t78 * t72;
  t197 = 0.1e1 / t60 / t32;
  t200 = -0.6000000e1 * t45 * t54 - 0.70000000e1 * t173 * t54 - 0.70000000e1 * t52 * t61 - 0.800000000e1 * t178 * t61 - 0.800000000e1 * t59 * t68 - 0.9000000000e1 * t183 * t68 - 0.9000000000e1 * t66 * t75 - 0.100000000000e2 * t188 * t75 - 0.100000000000e2 * t73 * t82 - 0.1100000000000e2 * t193 * t82 - 0.1100000000000e2 * t80 * t197;
  t201 = t170 + t200;
  t210 = 0.20e1 * t107 + 0.40e1 * t109 * t97;
  r->dfdt = t6 * t201 - 0.3734520e-2 * t121 + 0.20e1 * t95 * t101 - 0.7469040e-2 * t127 + t210 * t114 - 0.11203560e-1 * t140;
  r->dfdu = 0;

  if(r->order < 2) return;

  r->d2fdrs2 = 0;
  t220 = t87 * t114;
  t228 = t99 * t139;
  t238 = t136 * t139;
  t243 = t112 / t138 / t90;
  r->d2fdx2 = -0.67474923944822780255e-4 / t116 / t3 * t1 * t85 + 0.46699502372464614049e-2 * t117 * t85 + 0.278932792608e-4 * t220 * t1 - 0.373452e-2 * t121 + 0.2e1 * t93 * t101 - 0.2987616e-1 * t94 * t114 + 0.836798377824e-4 * t228 * t1 - 0.746904e-2 * t127 + (0.12e2 * t103 * t1 + 0.2e1 * t106 * t97) * t114 - 0.2240712e-1 * t238 * r->x + 0.1673596755648e-3 * t243 * t1 - 0.1120356e-1 * t140;
  t279 = 0.20e1 * t8 * t19 + 0.200e1 * t15 * t19 + 0.20e1 * t10 * t26 + 0.800e1 * t147 * t26 + 0.600e1 * t17 * t33 + 0.18000e2 * t152 * t33 + 0.12000e2 * t24 * t40 + 0.320000e2 * t157 * t40 + 0.200000e2 * t31 * t47 + 0.5000000e2 * t162 * t47 + 0.3000000e2 * t38 * t54 + 0.72000000e2 * t167 * t54 + 0.42000000e2 * t45 * t61 + 0.980000000e2 * t173 * t61 + 0.560000000e2 * t52 * t68 + 0.12800000000e3 * t178 * t68;
  t323 = 0.7200000000e2 * t59 * t75 + 0.162000000000e3 * t183 * t75 + 0.90000000000e2 * t66 * t82 + 0.2000000000000e3 * t188 * t82 + 0.1100000000000e3 * t73 * t197 + 0.24200000000000e3 * t193 * t197 + 0.13200000000000e3 * t80 / t60 / t39 + 0.6000e1 * t22 * t9 * t26 + 0.120000e2 * t29 * t16 * t33 + 0.2000000e2 * t36 * t23 * t40 + 0.30000000e2 * t43 * t30 * t47 + 0.420000000e2 * t50 * t37 * t54 + 0.5600000000e2 * t57 * t44 * t61 + 0.72000000000e2 * t64 * t51 * t68 + 0.900000000000e2 * t71 * t58 * t75 + 0.11000000000000e3 * t78 * t65 * t82;
  t327 = t95 * t114;
  t332 = t210 * t139;
  r->d2fdt2 = t6 * (t279 + t323) + 0.27893279260800e-4 * t220 - 0.298761600e-1 * t327 + 0.83679837782400e-4 * t228 + 0.800e1 * t109 * t114 - 0.22407120e-1 * t332 + 0.167359675564800e-3 * t243;
  r->d2fdu2 = 0;
  r->d2fdrsx = 0;
  r->d2fdrst = 0;
  r->d2fdrsu = 0;
  r->d2fdxt = 0.46699502372464614049e-2 * t118 * t201 + 0.2789327926080e-4 * t220 * r->x - 0.14938080e-1 * t124 * t114 - 0.14938080e-1 * t327 * r->x + 0.8367983778240e-4 * t228 * r->x + 0.40e1 * t133 * t114 - 0.11203560e-1 * t238 - 0.1120356e-1 * t332 * r->x + 0.16735967556480e-3 * t243 * r->x;
  r->d2fdxu = 0;
  r->d2fdtu = 0;

  if(r->order < 3) return;


}

#define maple2c_order 3
#define maple2c_func  XC(mgga_x_m06l_enhance)