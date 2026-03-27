K=$(HOME)/K/ngnk/growler/k # path to k source where you've built libk.dylib
OPT=/opt/local
DYLD_LIBRARY_PATH=$(K)

CFILES=cairo.c cairo_impl.c check.c
HFILES=typedefs.h cairoffi.h
OFILES=$(patsubst %.c,%.o,$(CFILES))
CFLAGS=-g -march=native -fPIC -Dshared -Dlibc -I$(K) -I$(OPT)/include
LDFLAGS=-undefined dynamic_lookup -L$(K) -L$(OPT)/lib
0:libcairoffi.dylib

libcairoffi.dylib:$(OFILES) $(HFILES) makefile
	$(CC) $(CFLAGS) $(LDFLAGS) -dynamiclib -install_name $@ $(OFILES) -o $@ -lcairo

c:
	rm -rf libcairo.dylib* *.o
