
HOSTLEX=flex

#LDADD=-lchsetdet -lpf -lxslt -lxml2
AM_LDFLAGS=
AM_CFLAGS=
EXTRA_DIST=

if DEBUG
# use "valgrind --tool=memcheck --leak-check=yes" to check memory leak, MemWatch will drag the program.
#DEFS+=-DMEMWATCH=1
DEFS+=-DDEBUG=1 -D_DEBUG=1 -DDEBUG_MDIC=1
AM_CFLAGS +=-g -O0 -Wall

else
AM_CFLAGS +=-O3 -Wall
endif

EXT_FLAGS=
@MK@GITNUMTMP=$(shell cd "$(top_srcdir)"; A=$$(git show | head -n 1 | awk '{print $$2}'); echo $${A:0:7}; cd - > /dev/null )
#@MK@SVNNUMTMP=$(shell cd "$(top_srcdir)"; LC_ALL=C svn info | grep -i Revision | awk '{print $$2}'; cd - > /dev/null )
#@MK@ifeq ($(SVNNUMTMP),)
#EXT_FLAGS+= -DSVN_VERSION='"${GITNUMTMP}"'
#@MK@else
#EXT_FLAGS+= -DSVN_VERSION='"${SVNNUMTMP}"'
#@MK@endif
@MK@ifeq ($(GITNUMTMP),)
@MK@else
EXT_FLAGS+= -DSVN_VERSION='"${GITNUMTMP}"'
@MK@endif
DEFS+=$(EXT_FLAGS)


DEFS+= \
     -std=c++11 \
    `getconf LFS_CFLAGS` \
    `getconf LFS64_CFLAGS` \
    -D_GNU_SOURCE \
    -D_FILE_OFFSET_BITS=64 \
    -DHAVE_MMAP64=1 \
    $(NULL)

AM_CFLAGS += \
    -I /usr/include/libxml2/ \
    -I /usr/include/skcore/ \
    -I /usr/include/skfind/ \
    -I $(top_srcdir)/include/ \
    -I $(top_builddir)/include/ \
    $(NULL)


#if USE_PLUGIN_SK
#DEFS+= -DUSE_PLUGIN_SK=1
#endif

#DEFS+=-std=c99

DEFS+=-DUSE_ADAGFX=0 -DUSE_LCDGFX=0 -DUSE_LIQLCD=0 -DUSE_ST7920=0


libmenusystem_la_CFLAGS=
libmenusystem_la_LDFLAGS=

libmenusystem_la_CFLAGS += $(AM_CFLAGS) $(CFLAGS)
libmenusystem_la_LDFLAGS+= $(LDFLAGS)

libmenusystem_la_CXXFLAGS=$(libmenusystem_la_CFLAGS) $(CXXFLAGS)

# public headers
# it will be moved to include/Makefile.am
include_HEADERS = \
    $(top_srcdir)/src/MenuSystem.h \
    $(top_srcdir)/src/MenuComponentRenderer2.h \
    $(top_srcdir)/src/NumericDisplayMenuItem.h \
    $(top_srcdir)/src/TextEditMenuItem.h \
    $(top_srcdir)/src/ToggleMenuItem.h \
    $(NULL)

EXTRA_DIST += libmenusystem.pc.in

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libmenusystem.pc

#BUILT_SOURCES = $(top_builddir)/src/xmllex.c
#CLEANFILES = $(top_builddir)/src/xmllex.c
#nodist_libmenusystem_la_SOURCES = $(top_builddir)/src/xmllex.c
#$(top_builddir)/src/xmllex.c: $(top_srcdir)/src/xmllex.l $(top_srcdir)/src/xmldecl.h
#	$(HOSTLEX) -o $@ $(top_srcdir)/src/xmllex.l

#lib_LTLIBRARIES=libmenusystem.la
libmenusystem_la_SOURCES= \
    #MenuSystem.cpp \
    $(NULL)

