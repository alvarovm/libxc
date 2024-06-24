(*
 Copyright (C) 2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: lda_exc *)
(* prefix:
  lda_c_utt14_params *params;

  assert(p->params != NULL);
  params = (lda_c_utt14_params * )(p->params);
*)

(* Equation (44) in Mejia-Rodriguez and Lande *)
utt14_beta := rho_e -> params_a_q * rho_e^(1/3):

(* Equation (45) in Mejia-Rodriguez and Lande *)
utt14_E := (rho_e, rho_p) -> -rho_e*rho_p * (utt14_F0(utt14_beta(rho_e)) + utt14_F1(utt14_beta(rho_e)) + utt14_F2(utt14_beta(rho_e))):

(* Equation (46) in Mejia-Rodriguez and Lande *)
utt14_F0 := beta -> -3*Pi / beta^3:
(* Equation (46) in Mejia-Rodriguez and Lande *)
utt14_F1 := beta -> (32*beta^3 + (8*sqrt(2) - 32*sqrt(Pi))*params_a_Z*beta^2 + 24 * params_a_Z^2 * beta + (sqrt(2*Pi) - 8*sqrt(Pi))*params_a_Z^3) / ( 64 * beta^5 ) * utt14_Phi(beta):
(* Equation (46) in Mejia-Rodriguez and Lande *)
utt14_F2 := beta -> (384*beta^6 - 192*sqrt(2*Pi)*params_a_Z*beta^5 + 384 * params_a_Z^2 * beta^4 - 196*sqrt(2*Pi)*params_a_Z^3 * beta^3 + 112*params_a_Z^4*beta^2 - 15*sqrt(2*Pi)*params_a_Z^5*beta + 8*params_a_Z^6) / (1536*beta^8) * utt14_Phi(beta)^2:
(* Equation (47) in Mejia-Rodriguez and Lande *)
utt14_Phi := beta -> (16*(48*sqrt(2*Pi) - 192*sqrt(Pi))*beta^6 + 4608*beta^5 + 16*(18*sqrt(2*Pi)-144*sqrt(Pi))*beta^4 + 1792*beta^3 + 16*sqrt(2)*beta^3*sqrt(utt14_f(beta)))/(35*sqrt(2*Pi) - 384*beta + 420*sqrt(2*Pi)*beta^2 - 2048*beta^3 + 1152*sqrt(2*Pi)*beta^4 - 3072*beta^5 + 768*sqrt(2*Pi)*beta^6):
(* Equation (48) in Mejia-Rodriguez and Lande *)
utt14_f := beta -> 18432*Pi*beta^6 + 18432*beta^5*sqrt(Pi)*(sqrt(2)-5) + 1728*beta^4*(2*sqrt(2)*Pi + 15 * Pi + 24) + 192*beta^3*sqrt(Pi)*(71*sqrt(2)-456) + 72*beta^2*(34*sqrt(2*Pi) + 131*Pi + 448) + 2592*beta*sqrt(Pi)*(sqrt(2)-8) + 7*(15*Pi*(4*sqrt(2)-1)+896):

(* Energy density; require significant proton and electron density *)
f_utt14 := (rs, zeta) ->
        my_piecewise3(screen_dens(rs,zeta) and screen_dens(rs,-zeta), 0,
        utt14_E(n_spin(rs, z_thr(zeta)), n_spin(rs, z_thr(-zeta))) / n_total(rs)):

f := (rs, zeta) -> f_utt14(rs, zeta):
