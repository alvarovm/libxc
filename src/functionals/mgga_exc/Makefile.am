## Process this file with automake to produce Makefile.in

## Copyright (C) 2021 Igor S. Gerasimov
##
## This Source Code Form is subject to the terms of the Mozilla Public
## License, v. 2.0. If a copy of the MPL was not distributed with this
## file, You can obtain one at http://mozilla.org/MPL/2.0/.
##

AM_CFLAGS = -I$(top_srcdir)/src -I$(top_builddir)/src -I$(top_srcdir)/src/functionals

if HAVE_CUDA
#this is a hack for nvcc, this should be improved.
CC+="-dc"
endif

noinst_LTLIBRARIES = libmgga_exc.la

libmgga_exc_la_SOURCES = \
        hyb_mgga_xc_b88b95.c mgga_c_tpssloc.c mgga_x_mbeefvdw.c    \
        hyb_mgga_xc_br3p86.c mgga_c_vsxc.c mgga_x_mbr.c    \
        hyb_mgga_xc_kcis.c mgga_k_csk.c mgga_x_mbrxc_bg.c    \
        hyb_mgga_xc_tpssh.c mgga_k_csk_loc.c mgga_x_mbrxh_bg.c    \
        hyb_mgga_xc_wb97mv.c mgga_k_gea2.c mgga_x_mcml.c    \
        hyb_mgga_x_dldf.c mgga_k_gea4.c mgga_x_mggac.c    \
        hyb_mgga_x_js18.c mgga_k_lk.c mgga_x_mn12.c    \
        hyb_mgga_x_m05.c mgga_k_pc07.c mgga_x_msb.c    \
        hyb_mgga_x_mvsh.c mgga_k_pgslb.c mgga_x_ms.c    \
        hyb_mgga_x_pjs18.c mgga_k_rda.c mgga_x_mvsb.c    \
        mgga_c_b88.c mgga_x_2d_js17.c mgga_x_mvs.c    \
        mgga_c_b94.c mgga_x_2d_prhg07.c mgga_x_pbe_gx.c    \
        mgga_c_bc95.c mgga_x_br89.c mgga_x_pkzb.c    \
        mgga_c_ccalda.c mgga_x_br89_explicit.c mgga_x_r2scan.c    \
        mgga_c_cc.c mgga_xc_b97mv.c mgga_x_r2scanl.c    \
        mgga_c_cs.c mgga_xc_b98.c mgga_x_r4scan.c    \
        mgga_c_kcis.c mgga_xc_cc06.c mgga_x_regtm.c    \
        mgga_c_kcisk.c mgga_xc_hle17.c mgga_x_regtpss.c    \
        mgga_c_ltapw.c mgga_xc_lp90.c mgga_x_revtm.c    \
        mgga_c_m05.c mgga_xc_otpss_d.c mgga_x_rlda.c    \
        mgga_c_m06l.c mgga_xc_zlp.c mgga_x_rppscan.c    \
        mgga_c_m08.c mgga_x_edmgga.c mgga_x_rscan.c    \
        mgga_c_pkzb.c mgga_x_ft98.c mgga_x_rtpss.c    \
        mgga_c_r2scan.c mgga_x_gdme.c mgga_x_sa_tpss.c    \
        mgga_c_r2scanl.c mgga_x_gvt4.c mgga_x_scan.c    \
        mgga_c_revscan.c mgga_x_gx.c mgga_x_scanl.c    \
        mgga_c_revtpss.c mgga_x_jk.c mgga_x_task.c    \
        mgga_c_rmggac.c mgga_x_lta.c mgga_x_tau_hcth.c    \
        mgga_c_rppscan.c mgga_x_m06l.c mgga_x_th.c    \
        mgga_c_rregtm.c mgga_x_m08.c mgga_x_tm.c    \
        mgga_c_rscan.c mgga_x_m11.c mgga_x_tpss.c    \
        mgga_c_scan.c mgga_x_m11_l.c mgga_x_vcml.c    \
        mgga_c_scanl.c mgga_x_mbeef.c mgga_x_vt84.c    \
        mgga_c_tpss.c
