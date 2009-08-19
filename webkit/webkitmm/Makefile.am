# This file is part of webkitmm

lib_LTLIBRARIES = libwebkitmm-1.0.la

include $(srcdir)/../src/filelist.am
include $(srcdir)/filelist.am
include $(top_srcdir)/build/compile-binding.am

libwebkitmm_1_0_la_SOURCES	= $(binding_sources)
libwebkitmm_1_0_la_LDFLAGS	= -no-undefined -version-info $(WEBKITMM_SO_VERSION)
libwebkitmm_1_0_la_LIBADD	= $(WEBKITMM_LIBS)

AM_CPPFLAGS = $(binding_includes), $(binding_cppflags)
AM_CXXFLAGS = $(WEBKITMM_CFLAGS)
