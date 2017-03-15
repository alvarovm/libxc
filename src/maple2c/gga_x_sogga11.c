/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/gga_x_sogga11.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_sogga11_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
  double t2, t3, t4, t5, t7, t8, t11, t13;
  double t14, t16, t17, t19, t20, t22, t26, t27;
  double t28, t30, t31, t33, t34, t36, t37, t39;
  double t42, t43, t44, t45, t48, t52, t56, t60;
  double t64, t66, t69, t73, t77, t81, t86, t90;
  double t91, t92, t93, t94, t95, t96, t99, t100;
  double t101, t104, t105, t106, t109, t110, t111, t120;
  double t134, t135, t138, t139, t142, t145, t146, t149;
  double t152, t153, t156, t159, t162, t163, t166, t169;
  double t170, t173, t176, t177, t180, t183, t184, t190;
  double t192, t194, t195, t199, t203, t204, t208, t209;
  double t213, t217, t223, t226, t259, t319;

  gga_x_sogga11_params *params;
 
  assert(p->params != NULL);
  params = (gga_x_sogga11_params * )(p->params);

  t2 = params->a[1];
  t3 = 0.1e1 / params->kappa;
  t4 = params->mu * t3;
  t5 = r->x * r->x;
  t7 = 0.16455307846020557507e-1 * t4 * t5;
  t8 = 0.10e1 + t7;
  t11 = 0.10e1 - 0.10e1 / t8;
  t13 = params->a[2];
  t14 = t11 * t11;
  t16 = params->a[3];
  t17 = t14 * t11;
  t19 = params->a[4];
  t20 = t14 * t14;
  t22 = params->a[5];
  t26 = params->b[1];
  t27 = exp(-t7);
  t28 = 0.10e1 - t27;
  t30 = params->b[2];
  t31 = t28 * t28;
  t33 = params->b[3];
  t34 = t31 * t28;
  t36 = params->b[4];
  t37 = t31 * t31;
  t39 = params->b[5];
  r->f = t22 * t20 * t11 + t39 * t37 * t28 + t2 * t11 + t13 * t14 + t16 * t17 + t19 * t20 + t26 * t28 + t30 * t31 + t33 * t34 + t36 * t37 + params->a[0] + params->b[0];

  if(r->order < 1) return;

  t42 = t8 * t8;
  t43 = 0.1e1 / t42;
  t44 = t2 * t43;
  t45 = t4 * r->x;
  t48 = t13 * t11;
  t52 = t16 * t14;
  t56 = t19 * t17;
  t60 = t22 * t20;
  t64 = t26 * params->mu;
  t66 = t3 * r->x * t27;
  t69 = t30 * t28;
  t73 = t33 * t31;
  t77 = t36 * t34;
  t81 = t39 * t37;
  r->dfdx = 0.32910615692041115014e-1 * t44 * t45 + 0.65821231384082230028e-1 * t48 * t43 * t45 + 0.98731847076123345042e-1 * t52 * t43 * t45 + 0.13164246276816446006e0 * t56 * t43 * t45 + 0.16455307846020557507e0 * t60 * t43 * t45 + 0.32910615692041115014e-1 * t64 * t66 + 0.65821231384082230028e-1 * t69 * params->mu * t66 + 0.98731847076123345042e-1 * t73 * params->mu * t66 + 0.13164246276816446006e0 * t77 * params->mu * t66 + 0.16455307846020557507e0 * t81 * params->mu * t66;

  if(r->order < 2) return;

  t86 = t43 * params->mu * t3;
  t90 = 0.1e1 / t42 / t8;
  t91 = t2 * t90;
  t92 = params->mu * params->mu;
  t93 = params->kappa * params->kappa;
  t94 = 0.1e1 / t93;
  t95 = t92 * t94;
  t96 = t95 * t5;
  t99 = t42 * t42;
  t100 = 0.1e1 / t99;
  t101 = t13 * t100;
  t104 = t26 * t92;
  t105 = t94 * t5;
  t106 = t105 * t27;
  t109 = t30 * t92;
  t110 = t27 * t27;
  t111 = t105 * t110;
  t120 = t4 * t27;
  t134 = 0.65821231384082230028e-1 * t48 * t86 - 0.21662172504584457594e-2 * t91 * t96 + 0.21662172504584457594e-2 * t101 * t96 - 0.10831086252292228797e-2 * t104 * t106 + 0.21662172504584457594e-2 * t109 * t111 + 0.98731847076123345042e-1 * t52 * t86 + 0.13164246276816446006e0 * t56 * t86 + 0.16455307846020557507e0 * t60 * t86 + 0.65821231384082230028e-1 * t69 * t120 + 0.98731847076123345042e-1 * t73 * t120 + 0.13164246276816446006e0 * t77 * t120 + 0.16455307846020557507e0 * t81 * t120 + 0.32910615692041115014e-1 * t44 * t4 + 0.32910615692041115014e-1 * t64 * t3 * t27;
  t135 = t48 * t90;
  t138 = t16 * t11;
  t139 = t138 * t100;
  t142 = t52 * t90;
  t145 = t19 * t14;
  t146 = t145 * t100;
  t149 = t56 * t90;
  t152 = t22 * t17;
  t153 = t152 * t100;
  t156 = t60 * t90;
  t159 = t69 * t92;
  t162 = t33 * t28;
  t163 = t162 * t92;
  t166 = t73 * t92;
  t169 = t36 * t31;
  t170 = t169 * t92;
  t173 = t77 * t92;
  t176 = t39 * t34;
  t177 = t176 * t92;
  t180 = t81 * t92;
  t183 = -0.43324345009168915189e-2 * t135 * t96 + 0.64986517513753372783e-2 * t139 * t96 - 0.64986517513753372783e-2 * t142 * t96 + 0.12997303502750674557e-1 * t146 * t96 - 0.86648690018337830380e-2 * t149 * t96 + 0.21662172504584457595e-1 * t153 * t96 - 0.10831086252292228797e-1 * t156 * t96 - 0.21662172504584457594e-2 * t159 * t106 + 0.64986517513753372783e-2 * t163 * t111 - 0.32493258756876686391e-2 * t166 * t106 + 0.12997303502750674557e-1 * t170 * t111 - 0.43324345009168915190e-2 * t173 * t106 + 0.21662172504584457595e-1 * t177 * t111 - 0.54155431261461143986e-2 * t180 * t106;
  r->d2fdx2 = t134 + t183;

  if(r->order < 3) return;

  t184 = t95 * r->x;
  t190 = t92 * params->mu;
  t192 = 0.1e1 / t93 / params->kappa;
  t194 = t5 * r->x;
  t195 = t190 * t192 * t194;
  t199 = 0.1e1 / t99 / t8;
  t203 = t94 * r->x;
  t204 = t203 * t27;
  t208 = t192 * t194;
  t209 = t208 * t27;
  t213 = t208 * t110;
  t217 = 0.1e1 / t99 / t42;
  t223 = t208 * t110 * t27;
  t226 = t203 * t110;
  t259 = -0.12997303502750674557e-1 * t135 * t184 + 0.42774926061184729954e-3 * t48 * t100 * t195 + 0.19495955254126011835e-1 * t139 * t184 - 0.19495955254126011835e-1 * t142 * t184 - 0.12832477818355418986e-2 * t138 * t199 * t195 + 0.64162389091777094931e-3 * t52 * t100 * t195 + 0.38991910508252023671e-1 * t146 * t184 - 0.25994607005501349114e-1 * t149 * t184 + 0.85549852122369459911e-3 * t19 * t11 * t217 * t195 - 0.25664955636710837974e-2 * t145 * t199 * t195 + 0.85549852122369459911e-3 * t56 * t100 * t195;
  t319 = 0.10693731515296182488e-3 * t73 * t190 * t209 + 0.38991910508252023671e-1 * t170 * t226 - 0.12997303502750674557e-1 * t173 * t204 + 0.85549852122369459911e-3 * t36 * t28 * t190 * t223 - 0.12832477818355418987e-2 * t169 * t190 * t213 + 0.14258308687061576652e-3 * t77 * t190 * t209 + 0.64986517513753372785e-1 * t177 * t226 - 0.16246629378438343196e-1 * t180 * t204 + 0.21387463030592364978e-2 * t39 * t31 * t190 * t223 - 0.21387463030592364978e-2 * t176 * t190 * t213 + 0.17822885858826970814e-3 * t81 * t190 * t209;
  r->d3fdx3 = 0.64986517513753372782e-2 * t101 * t184 - 0.64986517513753372782e-2 * t91 * t184 + 0.21387463030592364977e-3 * t2 * t100 * t195 - 0.42774926061184729954e-3 * t13 * t199 * t195 - 0.32493258756876686391e-2 * t104 * t204 + 0.35645771717653941628e-4 * t26 * t190 * t209 - 0.21387463030592364977e-3 * t30 * t190 * t213 + 0.21387463030592364977e-3 * t16 * t217 * t195 + 0.21387463030592364977e-3 * t33 * t190 * t223 + 0.64986517513753372782e-2 * t109 * t226 + t259 + 0.64986517513753372785e-1 * t153 * t184 - 0.32493258756876686391e-1 * t156 * t184 + 0.21387463030592364978e-2 * t22 * t14 * t217 * t195 - 0.42774926061184729957e-2 * t152 * t199 * t195 + 0.10693731515296182488e-2 * t60 * t100 * t195 - 0.64986517513753372782e-2 * t159 * t204 + 0.71291543435307883256e-4 * t69 * t190 * t209 + 0.19495955254126011835e-1 * t163 * t226 - 0.97479776270630059173e-2 * t166 * t204 - 0.64162389091777094931e-3 * t162 * t190 * t213 + t319;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_sogga11_enhance)