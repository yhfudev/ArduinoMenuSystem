
AM_LDFLAGS=
AM_CFLAGS=
EXTRA_DIST=

DEFS += \
    `getconf LFS_CFLAGS` \
    `getconf LFS64_CFLAGS` \
    -D_GNU_SOURCE \
    -D_FILE_OFFSET_BITS=64 \
    -DHAVE_MMAP64=1 \
    -DUSE_EDIO24_SERVER=1 \
    $(NULL)

AM_CFLAGS += \
    -I$(top_srcdir)/src/ \
    -I$(top_srcdir)/include/ \
    -I$(top_builddir)/ \
    -I$(top_builddir)/src/ \
    -I$(top_builddir)/include/ \
    $(NULL)

AM_LDFLAGS += \
    -L$(top_builddir)/src/ \
    `getconf LFS_LDFLAGS` \
    `getconf LFS64_LDFLAGS` \
    $(NULL)

if DEBUG
# use "valgrind --tool=memcheck --leak-check=yes" to check memory leak, MemWatch will drag the program.
#DEFS+=-DMEMWATCH
DEFS+= -DDEBUG=1
AM_CFLAGS+=-g -Wall

else
AM_CFLAGS+=-O3 -Wall
endif

################################################################################

# add "VALGRIND = valgrind --gen-suppressions=all" in your makefile to get the content of .supp
# default valgrind supp file: /usr/lib/valgrind/default.supp
@VALGRIND_CHECK_RULES@
VALGRIND_SUPPRESSIONS_FILES = tests-valgrind-test.supp
EXTRA_DIST += tests-valgrind-test.supp

EXT_FLAGS=
@MK@GITNUMTMP=$(shell cd "$(top_srcdir)"; A=$$( (git show || echo 0 0) | head -n 1 | awk '{print $$2}'); echo $${A:0:7}; cd - > /dev/null )
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

#DEFS+= -DCOMPILE4LINUX=1 `sdl2-config --cflags`



# force the autoconf use g++ to link the c program with c++ lib
dummy.cpp:
	touch $@
clean-local-dummy:
	-rm -rf dummy.cpp

ciutexecpp.cpp:
	-echo "#define CIUT_ENABLED 1" >> $@
	-echo "#define CIUT_PLACE_MAIN 1" >> $@
	-echo "#ifndef DEBUG" >> $@
	-echo "#define DEBUG 1" >> $@
	-echo "#endif" >> $@
	-echo "#include <ciut.h>" >> $@
	-echo "#include \"../src/MenuSystem.h\"" >> $@
	-echo "int main(int argc, const char * argv[]) { return ciut_main(argc, argv); }" >> $@
clean-local-check:
	-rm -rf ciutexecpp.cpp

clean-local: clean-local-check clean-local-dummy


#noinst_PROGRAMS=ciutexecpp
TESTS=ciutexecpp
check_PROGRAMS=ciutexecpp

#ciutexecpp_LDADD = -luv
ciutexecpp_CFLAGS = -DCIUT_ENABLED=1 $(AM_CFLAGS)
ciutexecpp_LDFLAGS =$(AM_LDFLAGS) -lz

ciutexecpp_SOURCES= \
    ciutexecpp.cpp \
    $(NULL)


