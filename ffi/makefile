K=${HOME}/K/ngnk/k
RAYLIB=${HOME}/raylib/raylib/src
LAPACKINC=/opt/local/include/lapack
LAPACKLIB=/opt/local/lib/lapack
GCCLIB=/opt/local/lib/gcc14
OPTINC=/opt/local/include
OPTLIB=/opt/local/lib

KSRC=../k


0:libsqll.dylib libmat.dylib libdraw.dylib libray.dylib
	DYLD_LIBRARY_PATH=.:$(KSRC):$(GCCLIB) $(KSRC)/k mat/mat.k
	DYLD_LIBRARY_PATH=.:$(KSRC) $(KSRC)/k draw/draw.k
	DYLD_LIBRARY_PATH=.:$(KSRC) $(KSRC)/k draw/align.k
	DYLD_LIBRARY_PATH=.:$(KSRC) $(KSRC)/k draw/clip.k
	DYLD_LIBRARY_PATH=.:$(KSRC) $(KSRC)/k sqlite/sqlite.k

libsqll.dylib:sqlite/sqlite.c
	$(CC) -I$K -L$K -I${OPTINC} -L${OPTLIB} -dynamiclib -install_name $@ -g -fPIC $< -o $@ -undefined dynamic_lookup -lsqlite3

libmat.dylib:mat/mat.c
	$(CC) -I$K -L$K -L${OPTLIB}/lapack -rpath ${OPTLIB}/gcc12 -dynamiclib -install_name $@ -g -fPIC $< -o $@ -undefined dynamic_lookup -llapacke

libdraw.dylib:draw/draw.c
	$(CC) -I$K -I${OPTINC}/cairo -L$K -L${OPTLIB} -dynamiclib -install_name $@ -g -fPIC $< -o $@ -undefined dynamic_lookup -lcairo

libray.dylib:ray/ray.c
	$(CC) -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -I$K -I${RAYLIB} -L$K -L${RAYLIB} -dynamiclib -install_name $@ -g -fPIC $< -o $@ -undefined dynamic_lookup -lraylib

libsqll.dylib libmat.dylib libdraw.dylib libray.dylib: patch

.PHONY: c

patch:
	patch < ../ext.diff
	touch patch

c:
	rm -rf libsqll* libmat* libdraw* libray*
