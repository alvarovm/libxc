/* 
  This file was generated automatically with scripts/math2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Mathematica source: ./mathematica/functionals/gga_x_b86.m
  Type of functional: work_gga_x
*/

void XC(math2c_gga_x_b86_enhance)
  (const XC(func_type) *p, int order, 
   FLOAT x, FLOAT *f, FLOAT *dfdx, FLOAT *d2fdx2, FLOAT *d3fdx3)
{
  gga_x_b86_params *params;
 
  assert(p->params != NULL);
  params = (gga_x_b86_params * )(p->params);


  if(order < 0) return;

  *f = 1. + (params->beta*POW(x,2))/POW(1 + params->gamma*POW(x,2),params->omega);

  if(order < 1) return;

  *dfdx = -2*params->beta*x*POW(1 + params->gamma*POW(x,2),-1 - params->omega)*(-1 + params->gamma*(-1 + params->omega)*POW(x,2));

  if(order < 2) return;

  *d2fdx2 = 2*params->beta*POW(1 + params->gamma*POW(x,2),-2 - params->omega)*(1 + params->gamma*(2 - 5*params->omega)*POW(x,2) + POW(params->gamma,2)*(1 - 3*params->omega + 2*POW(params->omega,2))*POW(x,4));

  if(order < 3) return;

  *d3fdx3 = -4*params->beta*params->gamma*params->omega*x*POW(1 + params->gamma*POW(x,2),-3 - params->omega)*(6 + 3*params->gamma*(1 - 3*params->omega)*POW(x,2) + POW(params->gamma,2)*(1 - 3*params->omega + 2*POW(params->omega,2))*POW(x,4));
}


#define math2c_order 3
#define math2c_func  XC(math2c_gga_x_b86_enhance)
