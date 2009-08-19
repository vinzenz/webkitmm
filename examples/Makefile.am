AUTOMAKE_OPTIONS=subdir-objects

local_webkitmm_lib = $(top_builddir)/webkit/webkitmm/libwebkitmm-1.0.la

AM_CPPFLAGS = -I$(top_builddir)/webkit -I$(top_srcdir)/webkit $(WEBKITMM_CFLAGS)

if BUILD_BROWSER
noinst_PROGRAMS = simple/simple browser/browser
else
noinst_PROGRAMS = simple/simple
endif
browser_browser_SOURCES = browser/browser.cc
simple_simple_SOURCES = simple/simple.cc
simple_simple_LDADD  = $(local_webkitmm_lib) $(WEBKITMM_LIBS)
browser_browser_LDADD  = $(local_webkitmm_lib) $(WEBKITMM_LIBS)
