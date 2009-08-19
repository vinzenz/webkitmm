DISTCHECK_CONFIGURE_FLAGS = --enable-warnings=fatal
ACLOCAL_AMFLAGS = -I build ${ACLOCAL_FLAGS}

if MAINTAINER_MODE
    src_subdirs = tools webkit/src
else
    src_subdirs =
endif

if ENABLE_DOCUMENTATION
    docs_subdirs = docs
else
    docs_subdirs =
endif
SUBDIRS = $(src_subdirs) webkit/webkitmm examples $(docs_subdirs)

webkitmm_includedir = $(includedir)/@WEBKITMM_MODULE_NAME@
webkitmm_include_HEADERS = webkit/webkitmm.h

webkitmm_configdir = $(libdir)/@WEBKITMM_MODULE_NAME@/include
webkitmm_config_DATA = webkit/webkitmmconfig.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = webkit/webkitmm-1.0.pc

dist_noinst_DATA =  \
              COPYING.examples
dist_noinst_SCRIPTS = autogen.sh

include $(top_srcdir)/build/dist-changelog.am
