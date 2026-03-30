K=$(HOME)/K/ngnk/growler/k # path to k source where you've built libk.dylib
OPT=/opt/local

OS=mac
ifeq ($(OS), mac)
  EXT=dylib
  LLP=DY
  LDFLAGS=-undefined dynamic_lookup -dynamiclib -install_name $@
else
  EXT=so
  LLP=
  LDFLAGS=
endif

$(LLP)LD_LIBRARY_PATH=$(K)

CFILES=cairo.c cairo_impl.c check.c
HFILES=typedefs.h cairoffi.h
OFILES=$(patsubst %.c,%.o,$(CFILES))
CFLAGS=-g -march=native -fPIC -Dshared -Dlibc -I$(K) -I$(OPT)/include
0:libcairoffi.$(EXT)

libcairoffi.dylib:$(OFILES) $(HFILES) makefile
	$(CC) $(CFLAGS) $(LDFLAGS) -L$(K) -L$(OPT)/lib $(OFILES) -o $@ -lcairo

c:
	rm -rf libcairo.(EXT)* *.o
