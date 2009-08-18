DISTCHECK_CONFIGURE_FLAGS = --enable-warnings=fatal
ACLOCAL_AMFLAGS = -I scripts ${ACLOCAL_FLAGS}

if MAINTAINER_MODE
    src_subdirs = tools webkit/src
else
    src_subdirs =
endif
SUBDIRS = $(src_subdirs) webkit/webkitmm examples
DIST_SUBDIRS = tools webkit/src webkit/webkitmm docs scripts

webkitmm_includedir		= $(includedir)/webkitmm-1.0
webkitmm_include_HEADERS	= webkit/webkitmm.h

webkitmm_configdir		= $(libdir)/webkitmm-1.0/include
webkitmm_config_DATA	= webkit/webkitmmconfig.h

pkgconfigdir		= $(libdir)/pkgconfig
pkgconfig_DATA		= webkit/webkitmm-1.0.pc

dist_noinst_DATA =  \
              COPYING.examples
dist_noinst_SCRIPTS = autogen.sh
