(*
 Copyright (C) 2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: lda_exc *)
(* prefix:
  lda_c_nsf07_params *params;

  assert(p->params != NULL);
  params = (lda_c_nsf07_params * )(p->params);
*)

(* Equation (7) *)
nsf07_beta := rho_e -> params_a_q * rho_e^(1/3):

(* Equation (11) *)
nsf07_E := (rho_e, rho_p) -> rho_e*rho_p * (Pi*params_a_Z^2*((24+(-9+2*sqrt(2))*Pi)*params_a_Z + 4*(-4+Pi)*sqrt(Pi)*nsf07_beta(rho_e))) / (2*Pi*nsf07_beta(rho_e)^4 * exp(4*params_a_Z*(params_a_Z-sqrt(Pi)*nsf07_beta(rho_e))/(Pi*nsf07_beta(rho_e)^2))):

(* Energy density; require significant proton and electron density *)
f_nsf07 := (rs, zeta) ->
        my_piecewise3(screen_dens(rs,zeta) and screen_dens(rs,-zeta), 0,
        nsf07_E(n_spin(rs, z_thr(zeta)), n_spin(rs, z_thr(-zeta))) / n_total(rs)):

f := (rs, zeta) -> f_nsf07(rs, zeta):
