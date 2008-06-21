## Copyright (c) 2001
## The libgdamm development team.

SUBDIRS			= private

sublib_name		= libgdamm
sublib_libname = libgdamm-3.0
sublib_libversion = $(LIBGDAMM_SO_VERSION)
sublib_namespace	= Gda
sublib_cflags		= $(LIBGDAMM_CFLAGS)
sublib_topdir = libgda


files_extra_h	= init.h wrap_init.h config.h value.h
files_extra_cc = init.cc config.cc value.cc

include $(top_srcdir)/build_shared/Makefile_build_gensrc.am_fragment

lib_LTLIBRARIES			= libgdamm-3.0.la
libgdamm_3_0_la_SOURCES	= $(files_all_cc)
libgdamm_3_0_la_LDFLAGS	= $(common_ldflags)
libgdamm_3_0_la_LIBADD	= $(LIBGDAMM_LIBS)

