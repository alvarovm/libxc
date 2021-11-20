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

noinst_LTLIBRARIES = libmgga_vxc.la

libmgga_vxc_la_SOURCES = \
        mgga_x_2d_prp10.c mgga_x_tb09.c
