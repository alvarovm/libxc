/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/mgga_x_sa_tpss.mpl
  Type of functional: work_mgga_x
*/

static void 
xc_mgga_x_sa_tpss_enhance(const xc_func_type *pt, xc_mgga_work_x_t *r)
{
  double t1, t2, t3, t5, t6, t7, t8, t9;
  double t10, t11, t12, t14, t15, t16, t17, t18;
  double t19, t20, t21, t22, t25, t26, t27, t28;
  double t30, t31, t32, t36, t37, t40, t41, t44;
  double t45, t46, t49, t50, t52, t53, t56, t58;
  double t59, t62, t63, t68, t69, t70, t76, t78;
  double t80, t81, t82, t84, t85, t89, t93, t94;
  double t95, t100, t101, t102, t103, t104, t108, t115;
  double t116, t117, t118, t119, t120, t124, t125, t129;
  double t130, t133, t134, t135, t138, t142, t145, t152;
  double t153, t156, t160, t163, t165, t170, t171, t175;
  double t178, t181, t183, t184, t185, t189, t200, t203;
  double t204, t207, t211, t215, t217, t221, t223, t225;
  double t229, t233, t237, t239, t240, t241, t244, t246;
  double t251, t254, t256, t258, t260, t263, t271, t275;
  double t278, t280, t284, t288, t289, t290, t294, t295;
  double t296, t300, t305, t307, t309, t310, t311, t312;
  double t313, t322, t329, t335, t339, t349, t350, t354;
  double t359, t360, t365, t366, t372, t380, t382, t383;
  double t394, t397, t401, t404, t405, t409, t416, t421;
  double t426, t427, t435, t438, t443, t449, t451, t455;
  double t464, t469, t487, t495, t507, t511, t516, t519;
  double t525, t533, t544, t547, t551, t560, t565, t570;
  double t575, t591, t597, t613, t617, t643, t651, t665;
  double t669, t674, t706, t730, t743;


  t1 = sqrt(0.5e1);
  t2 = 0.31415926535897932385e1 * t1;
  t3 = r->x * r->x;
  t5 = r->t - t3 / 0.8e1;
  t6 = M_CBRT6;
  t7 = t5 * t6;
  t8 = 0.31415926535897932385e1 * 0.31415926535897932385e1;
  t9 = POW_1_3(t8);
  t10 = t9 * t9;
  t11 = 0.1e1 / t10;
  t12 = t7 * t11;
  t14 = 0.5e1 * t12 + 0.9e1;
  t15 = sqrt(t14);
  t16 = 0.5e1 / 0.9e1 * t12;
  t17 = t16 + 0.348e0;
  t18 = log(t17);
  t19 = 0.2413e1 + t18;
  t20 = sqrt(t19);
  t21 = 0.1e1 / t20;
  t22 = t15 * t21;
  t25 = t3 * t3;
  t26 = r->t * r->t;
  t27 = 0.1e1 / t26;
  t28 = t25 * t27;
  t30 = 0.1e1 + t28 / 0.64e2;
  t31 = t30 * t30;
  t32 = 0.1e1 / t31;
  t36 = (0.10e2 / 0.81e2 + 0.24858750000000000000e-1 * t28 * t32) * t6;
  t37 = t11 * t3;
  t40 = t16 - 0.1e1;
  t41 = t11 * t40;
  t44 = 0.1e1 + 0.22222222222222222222e0 * t7 * t41;
  t45 = sqrt(t44);
  t46 = 0.1e1 / t45;
  t49 = t6 * t11;
  t50 = t49 * t3;
  t52 = 0.9e1 / 0.20e2 * t40 * t46 + t50 / 0.36e2;
  t53 = t52 * t52;
  t56 = t6 * t6;
  t58 = 0.1e1 / t9 / t8;
  t59 = t56 * t58;
  t62 = 0.50e2 * t59 * t25 + 0.162e3 * t28;
  t63 = sqrt(t62);
  t68 = 0.1e1 / t15;
  t69 = 0.1e1 / 0.31415926535897932385e1 * t1 * t68;
  t70 = t20 * t56;
  t76 = t25 * t3;
  t78 = t36 * t37 / 0.24e2 + 0.146e3 / 0.2025e4 * t53 - 0.73e2 / 0.97200e5 * t52 * t63 + 0.25e2 / 0.209952e6 * t69 * t70 * t58 * t25 + 0.17218861679299947194e-2 * t28 + 0.15033019185692233886e-5 * t76;
  t80 = 0.1e1 + 0.51656585037899841583e-1 * t50;
  t81 = t80 * t80;
  t82 = 0.1e1 / t81;
  t84 = 0.2e1 / 0.45e2 * t2 * t22 + t78 * t82;
  t85 = 0.1e1 / t84;
  t89 = 0.1e1 - 0.2e1 / 0.45e2 * t2 * t22 * t85;
  r->f = 0.1e1 + 0.2e1 / 0.45e2 * t2 * t22 * t89;

  if(r->order < 1) return;

  r->dfdrs = 0.0e0;
  t93 = t68 * t21;
  t94 = t2 * t93;
  t95 = t89 * r->x;
  t100 = 0.1e1 / t20 / t19;
  t101 = t15 * t100;
  t102 = t2 * t101;
  t103 = 0.1e1 / t17;
  t104 = t49 * t103;
  t108 = t85 * r->x;
  t115 = t2 * t15;
  t116 = t84 * t84;
  t117 = 0.1e1 / t116;
  t118 = t21 * t117;
  t119 = t2 * t68;
  t120 = t21 * r->x;
  t124 = r->x * t6;
  t125 = t11 * t103;
  t129 = t3 * r->x;
  t130 = t129 * t27;
  t133 = t25 * t129;
  t134 = t26 * t26;
  t135 = 0.1e1 / t134;
  t138 = 0.1e1 / t31 / t30;
  t142 = (0.99435000000000000000e-1 * t130 * t32 - 0.31073437500000000000e-2 * t133 * t135 * t138) * t6;
  t145 = t11 * r->x;
  t152 = 0.1e1 / t45 / t44;
  t153 = t40 * t152;
  t156 = t5 * t56;
  t160 = -0.55555555555555555555e-1 * t124 * t41 - 0.30864197530864197531e-1 * t156 * t58 * r->x;
  t163 = t124 * t11;
  t165 = -t124 * t11 * t46 / 0.16e2 - 0.9e1 / 0.40e2 * t153 * t160 + t163 / 0.18e2;
  t170 = 0.1e1 / t63;
  t171 = t52 * t170;
  t175 = 0.200e3 * t59 * t129 + 0.648e3 * t130;
  t178 = t8 * t8;
  t181 = 0.1e1 / t178 / 0.31415926535897932385e1 * t1;
  t183 = 0.1e1 / t15 / t14;
  t184 = t183 * t20;
  t185 = t25 * r->x;
  t189 = t181 * t68;
  t200 = t142 * t37 / 0.24e2 + t36 * t145 / 0.12e2 + 0.292e3 / 0.2025e4 * t52 * t165 - 0.73e2 / 0.97200e5 * t165 * t63 - 0.73e2 / 0.194400e6 * t171 * t175 + 0.125e3 / 0.279936e6 * t181 * t184 * t185 - 0.125e3 / 0.2519424e7 * t189 * t21 * t185 * t103 + 0.25e2 / 0.52488e5 * t69 * t70 * t58 * t129 + 0.68875446717199788776e-2 * t130 + 0.90198115114153403316e-5 * t185;
  t203 = 0.1e1 / t81 / t80;
  t204 = t78 * t203;
  t207 = -t119 * t120 * t49 / 0.36e2 + t102 * t124 * t125 / 0.324e3 + t200 * t82 - 0.20662634015159936634e0 * t204 * t163;
  t211 = t94 * t108 * t49 / 0.36e2 - t102 * t108 * t104 / 0.324e3 + 0.2e1 / 0.45e2 * t115 * t118 * t207;
  r->dfdx = -t94 * t95 * t49 / 0.36e2 + t102 * t95 * t104 / 0.324e3 + 0.2e1 / 0.45e2 * t2 * t22 * t211;
  t215 = t21 * t89;
  t217 = t119 * t215 * t49;
  t221 = t102 * t89 * t6 * t125;
  t223 = t21 * t85;
  t225 = t119 * t223 * t49;
  t229 = t102 * t85 * t6 * t125;
  t233 = t119 * t21 * t6 * t11;
  t237 = t115 * t100 * t6 * t125;
  t239 = t26 * r->t;
  t240 = 0.1e1 / t239;
  t241 = t25 * t240;
  t244 = t25 * t25;
  t246 = 0.1e1 / t134 / r->t;
  t251 = (-0.49717500000000000000e-1 * t241 * t32 + 0.15536718750000000000e-2 * t244 * t246 * t138) * t6;
  t254 = t49 * t46;
  t256 = t49 * t40;
  t258 = t156 * t58;
  t260 = 0.22222222222222222222e0 * t256 + 0.12345679012345679012e0 * t258;
  t263 = t254 / 0.4e1 - 0.9e1 / 0.40e2 * t153 * t260;
  t271 = t181 * t184 * t25;
  t275 = t189 * t21 * t25 * t103;
  t278 = t251 * t37 / 0.24e2 + 0.292e3 / 0.2025e4 * t52 * t263 - 0.73e2 / 0.97200e5 * t263 * t63 + 0.73e2 / 0.600e3 * t171 * t241 - 0.125e3 / 0.69984e5 * t271 + 0.125e3 / 0.629856e6 * t275 - 0.34437723358599894388e-2 * t241;
  t280 = t233 / 0.9e1 - t237 / 0.81e2 + t278 * t82;
  t284 = -t225 / 0.9e1 + t229 / 0.81e2 + 0.2e1 / 0.45e2 * t115 * t118 * t280;
  r->dfdt = t217 / 0.9e1 - t221 / 0.81e2 + 0.2e1 / 0.45e2 * t2 * t22 * t284;
  r->dfdu = 0.0e0;

  if(r->order < 2) return;

  r->d2fdrs2 = 0.0e0;
  t288 = t183 * t21;
  t289 = t2 * t288;
  t290 = t89 * t3;
  t294 = t68 * t100;
  t295 = t2 * t294;
  t296 = t59 * t103;
  t300 = t211 * r->x;
  t305 = t19 * t19;
  t307 = 0.1e1 / t20 / t305;
  t309 = t2 * t15 * t307;
  t310 = t17 * t17;
  t311 = 0.1e1 / t310;
  t312 = t59 * t311;
  t313 = t290 * t312;
  t322 = t85 * t3;
  t329 = t117 * r->x;
  t335 = t322 * t312;
  t339 = t2 * t101 * t117;
  t349 = t21 / t116 / t84;
  t350 = t207 * t207;
  t354 = t2 * t183;
  t359 = t3 * t56;
  t360 = t58 * t103;
  t365 = t58 * t311;
  t366 = t359 * t365;
  t372 = t3 * t27;
  t380 = 0.1e1 / t134 / t26;
  t382 = t31 * t31;
  t383 = 0.1e1 / t382;
  t394 = t165 * t165;
  t397 = t11 * t152;
  t401 = t44 * t44;
  t404 = t40 / t45 / t401;
  t405 = t160 * t160;
  t409 = t59 * t3;
  t416 = -t254 / 0.16e2 + t124 * t397 * t160 / 0.16e2 + 0.27e2 / 0.80e2 * t404 * t405 - 0.9e1 / 0.40e2 * t153 * (-0.55555555555555555555e-1 * t256 + 0.15432098765432098765e-1 * t409 - 0.30864197530864197531e-1 * t258) + t49 / 0.18e2;
  t421 = t165 * t170;
  t426 = t52 / t63 / t62;
  t427 = t175 * t175;
  t435 = t14 * t14;
  t438 = t181 / t15 / t435;
  t443 = t181 * t288;
  t449 = t181 * t294;
  t451 = t76 * t311 * t49;
  t455 = t181 * t93;
  t464 = (0.29830500000000000000e0 * t372 * t32 - 0.34180781250000000000e-1 * t76 * t135 * t138 + 0.58262695312500000000e-3 * t244 * t3 * t380 * t383) * t6 * t37 / 0.24e2 + t142 * t145 / 0.6e1 + t36 * t11 / 0.12e2 + 0.292e3 / 0.2025e4 * t394 + 0.292e3 / 0.2025e4 * t52 * t416 - 0.73e2 / 0.97200e5 * t416 * t63 - 0.73e2 / 0.97200e5 * t421 * t175 + 0.73e2 / 0.388800e6 * t426 * t427 - 0.73e2 / 0.194400e6 * t171 * (0.1944e4 * t372 + 0.600e3 * t409) + 0.625e3 / 0.746496e6 * t438 * t20 * t76 * t49 - 0.625e3 / 0.10077696e8 * t443 * t76 * t6 * t125 + 0.125e3 / 0.31104e5 * t271 - 0.625e3 / 0.181398528e9 * t449 * t451 - 0.125e3 / 0.279936e6 * t275 - 0.625e3 / 0.90699264e8 * t455 * t451 + 0.25e2 / 0.17496e5 * t69 * t70 * t58 * t3 + 0.20662634015159936633e-1 * t372 + 0.45099057557076701658e-4 * t25;
  t469 = t81 * t81;
  r->d2fdx2 = -0.5e1 / 0.288e3 * t289 * t290 * t59 - 0.5e1 / 0.1296e4 * t295 * t290 * t296 - t94 * t300 * t49 / 0.18e2 - t217 / 0.36e2 + 0.5e1 / 0.7776e4 * t309 * t313 + t102 * t300 * t104 / 0.162e3 + t221 / 0.324e3 + 0.5e1 / 0.11664e5 * t102 * t313 + 0.2e1 / 0.45e2 * t2 * t22 * (0.5e1 / 0.288e3 * t289 * t322 * t59 + 0.5e1 / 0.1296e4 * t295 * t322 * t296 - t94 * t329 * t49 * t207 / 0.18e2 + t225 / 0.36e2 - 0.5e1 / 0.7776e4 * t309 * t335 + t339 * t124 * t125 * t207 / 0.162e3 - t229 / 0.324e3 - 0.5e1 / 0.11664e5 * t102 * t335 - 0.4e1 / 0.45e2 * t115 * t349 * t350 + 0.2e1 / 0.45e2 * t115 * t118 * (-0.5e1 / 0.288e3 * t354 * t21 * t3 * t59 - 0.5e1 / 0.1296e4 * t295 * t359 * t360 - t233 / 0.36e2 + 0.5e1 / 0.7776e4 * t309 * t366 + t237 / 0.324e3 + 0.5e1 / 0.11664e5 * t102 * t366 + t464 * t82 - 0.41325268030319873268e0 * t200 * t203 * t163 + 0.64041666666666666674e-1 * t78 / t469 * t409 - 0.20662634015159936634e0 * t204 * t49));
  t487 = t89 * t56;
  t495 = t487 * t365;
  t507 = t85 * t56;
  t511 = t117 * t6;
  t516 = t507 * t365;
  t519 = t125 * t280;
  t525 = t280 * t280;
  t533 = t100 * t56;
  t544 = t25 * t135;
  t547 = t244 * t380;
  t551 = t134 * t134;
  t560 = t263 * t263;
  t565 = t260 * t260;
  t570 = -t49 * t152 * t260 / 0.4e1 + 0.27e2 / 0.80e2 * t404 * t565 - 0.55555555555555555554e-1 * t153 * t59;
  t575 = t263 * t170;
  t591 = t25 * t311 * t49;
  t597 = (0.14915250000000000000e0 * t544 * t32 - 0.10875703125000000000e-1 * t547 * t138 + 0.14565673828125000000e-3 * t244 * t25 / t551 * t383) * t6 * t37 / 0.24e2 + 0.292e3 / 0.2025e4 * t560 + 0.292e3 / 0.2025e4 * t52 * t570 - 0.73e2 / 0.97200e5 * t570 * t63 + 0.73e2 / 0.300e3 * t575 * t241 + 0.1971e4 / 0.100e3 * t426 * t547 - 0.73e2 / 0.200e3 * t171 * t544 + 0.625e3 / 0.46656e5 * t438 * t20 * t25 * t49 - 0.625e3 / 0.629856e6 * t443 * t25 * t6 * t125 - 0.625e3 / 0.11337408e8 * t449 * t591 - 0.625e3 / 0.5668704e7 * t455 * t591 + 0.10331317007579968316e-1 * t544;
  r->d2fdt2 = -0.5e1 / 0.18e2 * t354 * t215 * t59 - 0.5e1 / 0.81e2 * t295 * t487 * t360 + 0.2e1 / 0.9e1 * t119 * t21 * t284 * t49 + 0.5e1 / 0.486e3 * t309 * t495 - 0.2e1 / 0.81e2 * t102 * t284 * t6 * t125 + 0.5e1 / 0.729e3 * t102 * t495 + 0.2e1 / 0.45e2 * t2 * t22 * (0.5e1 / 0.18e2 * t354 * t223 * t59 + 0.5e1 / 0.81e2 * t295 * t507 * t360 + 0.2e1 / 0.9e1 * t94 * t511 * t11 * t280 - 0.5e1 / 0.486e3 * t309 * t516 - 0.2e1 / 0.81e2 * t102 * t511 * t519 - 0.5e1 / 0.729e3 * t102 * t516 - 0.4e1 / 0.45e2 * t115 * t349 * t525 + 0.2e1 / 0.45e2 * t115 * t118 * (-0.5e1 / 0.18e2 * t354 * t21 * t56 * t58 - 0.5e1 / 0.81e2 * t119 * t533 * t360 + 0.5e1 / 0.486e3 * t115 * t307 * t56 * t365 + 0.5e1 / 0.729e3 * t115 * t533 * t365 + t597 * t82));
  r->d2fdu2 = 0.0e0;
  r->d2fdrsx = 0.0e0;
  r->d2fdrst = 0.0e0;
  r->d2fdrsu = 0.0e0;
  t613 = t284 * r->x;
  t617 = t95 * t312;
  t643 = t108 * t312;
  t651 = t117 * t207;
  t665 = r->x * t56;
  t669 = t665 * t365;
  t674 = t129 * t240;
  t706 = t124 * t397 * t260 / 0.32e2 - t49 * t152 * t160 / 0.8e1 + 0.27e2 / 0.80e2 * t404 * t160 * t260 + 0.13888888888888888889e-1 * t153 * t665 * t58;
  t730 = t185 * t311 * t49;
  t743 = (-0.19887000000000000000e0 * t674 * t32 + 0.18644062500000000000e-1 * t133 * t246 * t138 - 0.29131347656250000000e-3 * t244 * t129 / t134 / t239 * t383) * t6 * t37 / 0.24e2 + t251 * t145 / 0.12e2 + 0.292e3 / 0.2025e4 * t263 * t165 + 0.292e3 / 0.2025e4 * t52 * t706 - 0.73e2 / 0.97200e5 * t706 * t63 + 0.73e2 / 0.600e3 * t421 * t241 - 0.73e2 / 0.194400e6 * t575 * t175 - 0.73e2 / 0.1200e4 * t426 * t175 * t25 * t240 + 0.73e2 / 0.150e3 * t171 * t674 - 0.625e3 / 0.186624e6 * t438 * t20 * t185 * t49 + 0.625e3 / 0.2519424e7 * t443 * t185 * t6 * t125 + 0.625e3 / 0.45349632e8 * t449 * t730 + 0.625e3 / 0.22674816e8 * t455 * t730 - 0.125e3 / 0.17496e5 * t181 * t184 * t129 + 0.125e3 / 0.157464e6 * t189 * t21 * t129 * t103 - 0.13775089343439957755e-1 * t674;
  r->d2fdxt = 0.5e1 / 0.72e2 * t289 * t95 * t59 + 0.5e1 / 0.324e3 * t295 * t95 * t296 - t94 * t613 * t49 / 0.36e2 - 0.5e1 / 0.1944e4 * t309 * t617 + t102 * t613 * t104 / 0.324e3 - 0.5e1 / 0.2916e4 * t102 * t617 + t119 * t21 * t211 * t49 / 0.9e1 - t102 * t211 * t6 * t125 / 0.81e2 + 0.2e1 / 0.45e2 * t2 * t22 * (-0.5e1 / 0.72e2 * t289 * t108 * t59 - 0.5e1 / 0.324e3 * t295 * t108 * t296 - t94 * t329 * t49 * t280 / 0.36e2 + 0.5e1 / 0.1944e4 * t309 * t643 + t339 * t124 * t519 / 0.324e3 + 0.5e1 / 0.2916e4 * t102 * t643 + t94 * t651 * t49 / 0.9e1 - t102 * t651 * t104 / 0.81e2 - 0.4e1 / 0.45e2 * t115 * t349 * t207 * t280 + 0.2e1 / 0.45e2 * t115 * t118 * (0.5e1 / 0.72e2 * t354 * t120 * t59 + 0.5e1 / 0.324e3 * t295 * t665 * t360 - 0.5e1 / 0.1944e4 * t309 * t669 - 0.5e1 / 0.2916e4 * t102 * t669 + t743 * t82 - 0.20662634015159936634e0 * t278 * t203 * t163));
  r->d2fdxu = 0.0e0;
  r->d2fdtu = 0.0e0;

  if(r->order < 3) return;


}

#define maple2c_order 3
#define maple2c_func  xc_mgga_x_sa_tpss_enhance