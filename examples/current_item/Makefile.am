
AM_LDFLAGS=
AM_CFLAGS=
EXTRA_DIST=


DEFS += \
    `getconf LFS_CFLAGS` \
    `getconf LFS64_CFLAGS` \
    -D_GNU_SOURCE \
    -D_FILE_OFFSET_BITS=64 \
    -DHAVE_MMAP64=1 \
    $(NULL)

AM_CFLAGS += \
    -I$(top_srcdir)/src/ \
    -I$(top_srcdir)/include/ \
    -I$(top_builddir)/ \
    -I$(top_builddir)/src/ \
    -I$(top_builddir)/include/ \
    -I../common/ \
    $(NULL)

AM_LDFLAGS += \
    -L$(top_builddir)/src/ \
    `getconf LFS_LDFLAGS` \
    `getconf LFS64_LDFLAGS` \
    $(NULL)

AM_LDFLAGS += -L$(top_builddir)/src/ -lmenusystem

if DEBUG
# use "valgrind --tool=memcheck --leak-check=yes" to check memory leak, MemWatch will drag the program.
#DEFS+=-DMEMWATCH
DEFS+= -DDEBUG=1
AM_CFLAGS +=-g -O0 -Wall
AM_LDFLAGS += -lbfd

else
AM_CFLAGS+=-O3 -Wall
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

#AM_CFLAGS+=$(EXT_FLAGS)



noinst_PROGRAMS=currentitem
#TESTS=ciutexe
#check_PROGRAMS=ciutexe
bin_PROGRAMS=


#SDL_CFLAGS := $(shell sdl2-config --cflags)
#SDL_LDFLAGS := $(shell sdl2-config --libs)

currentitem_LDADD = $(top_builddir)/src/libmenusystem.la $(libmenusystem_LIBADD)
currentitem_CFLAGS = $(AM_CFLAGS) $(SDL_CFLAGS) $(libmenusystem_la_CFLAGS)
currentitem_CXXFLAGS = $(currentitem_CFLAGS)
currentitem_LDFLAGS = $(AM_LDFLAGS) $(SDL_LDFLAGS)

currentitem_SOURCES= \
    current_item.cpp \
    ../native/main.cpp \
    $(NULL)

EXTRA_DIST += \
    $(NULL)


.pde.cpp:
	cp $< $@
.ino.cpp:
	echo cp $< $@
	cp $< $@
dummy.cpp:
	touch $@


