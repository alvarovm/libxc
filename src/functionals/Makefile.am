## Process this file with automake to produce Makefile.in

## Copyright (C) 2021 Igor S. Gerasimov
##
## This Source Code Form is subject to the terms of the Mozilla Public
## License, v. 2.0. If a copy of the MPL was not distributed with this
## file, You can obtain one at http://mozilla.org/MPL/2.0/.
##

SUBDIRS = lda_exc lda_vxc gga_exc gga_vxc mgga_exc mgga_vxc

AM_CFLAGS = -I$(top_srcdir)/src -I$(top_builddir)/src

if HAVE_CUDA
#this is a hack for nvcc, this should be improved.
CC+="-dc"
endif

noinst_LTLIBRARIES = libfunctionals.la
libfunctionals_la_LIBADD = \
  lda_exc/liblda_exc.la \
  lda_vxc/liblda_vxc.la \
  gga_exc/libgga_exc.la \
  gga_vxc/libgga_vxc.la \
  mgga_exc/libmgga_exc.la \
  mgga_vxc/libmgga_vxc.la

libfunctionals_la_SOURCES = functionals.c lda.c gga.c mgga.c hybrids.c
