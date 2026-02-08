K=$(HOME)/K/ngnk/growler/k # path to k source where you've built libk.dylib
DYLD_LIBRARY_PATH=$(K)

libcblas.dylib:cblas.c cblas_impl.c cblas_impl.h makefile
	$(CC) -L$(K) -I$(K) -dynamiclib -install_name $@ $< -o $@ -g -march=native -framework Accelerate -DACCELERATE_NEW_LAPACK -Dlibc -fPIC -Dshared -undefined dynamic_lookup

c:
	rm -rf libcblas.dylib*
