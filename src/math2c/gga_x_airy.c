/* 
  This file was generated automatically with scripts/math2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Mathematica source: ./mathematica/functionals/gga_x_airy.m
  Type of functional: work_gga_x
*/

void XC(math2c_gga_x_airy_enhance)
  (const XC(func_type) *p, int order, 
   FLOAT x, FLOAT *f, FLOAT *dfdx, FLOAT *d2fdx2, FLOAT *d3fdx3)
{


  if(order < 0) return;

  *f = (a1*POW(x*X2S,a2))/POW(1 + a3*POW(x*X2S,a2),a4) + (1 - a5*POW(x*X2S,a6) + a7*POW(x*X2S,a8))/(1 + a9*POW(x*X2S,a10));

  if(order < 1) return;

  *dfdx = -((a1*a2*a3*a4*POW(x*X2S,2*a2)*POW(1 + a3*POW(x*X2S,a2),-1 - a4))/x) + (a1*a2*POW(x*X2S,a2))/(x*POW(1 + a3*POW(x*X2S,a2),a4)) + (a10*a9*POW(x*X2S,a10)*(-1 + a5*POW(x*X2S,a6) - a7*POW(x*X2S,a8)))/(x*POW(1 + a9*POW(x*X2S,a10),2)) + (-(a5*a6*POW(x*X2S,a6)) + a7*a8*POW(x*X2S,a8))/(x + a9*x*POW(x*X2S,a10));

  if(order < 2) return;

  *d2fdx2 = (-2*a1*POW(a2,2)*a3*a4*POW(x*X2S,2*a2)*POW(1 + a3*POW(x*X2S,a2),-1 - a4))/POW(x,2) + (a1*(-1 + a2)*a2*POW(x*X2S,a2))/(POW(x,2)*POW(1 + a3*POW(x*X2S,a2),a4)) + (2*a10*a9*POW(x*X2S,a10)*(a5*a6*POW(x*X2S,a6) - a7*a8*POW(x*X2S,a8)))/POW(x + a9*x*POW(x*X2S,a10),2) + (-(a5*(-1 + a6)*a6*POW(x*X2S,a6)) + a7*(-1 + a8)*a8*POW(x*X2S,a8))/(POW(x,2)*(1 + a9*POW(x*X2S,a10))) - (a10*a9*POW(x*X2S,a10)*(-1 + a5*POW(x*X2S,a6) - a7*POW(x*X2S,a8))*(1 + a9*POW(x*X2S,a10) + a10*(-1 + a9*POW(x*X2S,a10))))/(POW(x,2)*POW(1 + a9*POW(x*X2S,a10),3)) + (a1*a2*a3*a4*POW(x*X2S,2*a2)*POW(1 + a3*POW(x*X2S,a2),-2 - a4)*(1 + a3*POW(x*X2S,a2) + a2*(-1 + a3*a4*POW(x*X2S,a2))))/POW(x,2);

  if(order < 3) return;

  *d3fdx3 = (-3*a1*(-1 + a2)*POW(a2,2)*a3*a4*POW(x*X2S,2*a2)*POW(1 + a3*POW(x*X2S,a2),-1 - a4))/POW(x,3) + (a1*(-2 + a2)*(-1 + a2)*a2*POW(x*X2S,a2))/(POW(x,3)*POW(1 + a3*POW(x*X2S,a2),a4)) + (3*a10*a9*POW(x*X2S,a10)*(a5*(-1 + a6)*a6*POW(x*X2S,a6) - a7*(-1 + a8)*a8*POW(x*X2S,a8)))/(POW(x,3)*POW(1 + a9*POW(x*X2S,a10),2)) + (-(a5*a6*(2 - 3*a6 + POW(a6,2))*POW(x*X2S,a6)) + a7*a8*(2 - 3*a8 + POW(a8,2))*POW(x*X2S,a8))/(POW(x,3)*(1 + a9*POW(x*X2S,a10))) - (3*a10*a9*POW(x*X2S,a10)*(a5*a6*POW(x*X2S,a6) - a7*a8*POW(x*X2S,a8))*(1 + a9*POW(x*X2S,a10) + a10*(-1 + a9*POW(x*X2S,a10))))/POW(x + a9*x*POW(x*X2S,a10),3) + (a10*a9*POW(x*X2S,a10)*(-1 + a5*POW(x*X2S,a6) - a7*POW(x*X2S,a8))*(2*POW(1 + a9*POW(x*X2S,a10),2) + 3*a10*(-1 + POW(a9,2)*POW(x*X2S,2*a10)) + POW(a10,2)*(1 - 4*a9*POW(x*X2S,a10) + POW(a9,2)*POW(x*X2S,2*a10))))/(POW(x,3)*POW(1 + a9*POW(x*X2S,a10),4)) + (3*a1*POW(a2,2)*a3*a4*POW(x*X2S,2*a2)*POW(1 + a3*POW(x*X2S,a2),-2 - a4)*(1 + a3*POW(x*X2S,a2) + a2*(-1 + a3*a4*POW(x*X2S,a2))))/POW(x,3) - (a1*a2*a3*a4*POW(x*X2S,2*a2)*POW(1 + a3*POW(x*X2S,a2),-3 - a4)*(2*POW(1 + a3*POW(x*X2S,a2),2) + 3*a2*(1 + a3*POW(x*X2S,a2))*(-1 + a3*a4*POW(x*X2S,a2)) + POW(a2,2)*(1 - a3*(1 + 3*a4)*POW(x*X2S,a2) + POW(a3,2)*POW(a4,2)*POW(x*X2S,2*a2))))/POW(x,3);
}


#define math2c_order 3
#define math2c_func  XC(math2c_gga_x_airy_enhance)
