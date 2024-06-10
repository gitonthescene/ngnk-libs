K=${HOME}/K/ngnk/k
RAYLIB=${HOME}/raylib/raylib/src
OPTINC=/opt/local/include
OPTLIB=/opt/local/lib

0:libsqll.dylib libmat.dylib libdraw.dylib libray.dylib

libsqll.dylib:sqlite/sqlite.c
	$(CC) -I$K -L$K -I${OPTINC} -L${OPTLIB} -dynamiclib -install_name $@ -g -fPIC $^ -o $@ -undefined dynamic_lookup -lsqlite3

libmat.dylib:mat/mat.c
	$(CC) -I$K -L$K -L${OPTLIB}/lapack -rpath ${OPTLIB}/gcc12 -dynamiclib -install_name $@ -g -fPIC $^ -o $@ -undefined dynamic_lookup -llapacke

libdraw.dylib:draw/draw.c
	$(CC) -I$K -I${OPTINC}/cairo -L$K -L${OPTLIB} -dynamiclib -install_name $@ -g -fPIC $^ -o $@ -undefined dynamic_lookup -lcairo

libray.dylib:ray/ray.c
	$(CC) -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -I$K -I${RAYLIB} -L$K -L${RAYLIB} -dynamiclib -install_name $@ -g -fPIC $^ -o $@ -undefined dynamic_lookup -lraylib

c:
	rm -rf libsqll* libmat* libdraw* libray*
