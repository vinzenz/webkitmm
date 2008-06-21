## Copyright (c) 2001
## The webkitmm development team.

SUBDIRS			= private

sublib_name		= webkitmm
sublib_libname = webkitmm-1.0
sublib_libversion = $(WEBKITMM_SO_VERSION)
sublib_namespace	= WebKit
sublib_cflags		= $(WEBKITMM_CFLAGS)
sublib_topdir = webkit


files_extra_h	= init.h wrap_init.h config.h value.h
files_extra_cc = init.cc config.cc value.cc

include $(top_srcdir)/build_shared/Makefile_build_gensrc.am_fragment

lib_LTLIBRARIES			= libwebkitmm-1.0.la
libwebkitmm_1_0_la_SOURCES	= $(files_all_cc)
libwebkitmm_1_0_la_LDFLAGS	= $(common_ldflags)
libwebkitmm_1_0_la_LIBADD	= $(WEBKITMM_LIBS)

