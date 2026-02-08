K=$(HOME)/K/ngnk/growler/k

libcblas.dylib:cblas.c cblas_impl.c cblas_impl.h makefile
	$(CC) -L$(K) -I$(K) -dynamiclib -install_name $@ $< -o $@ -g -march=native -framework Accelerate -DACCELERATE_NEW_LAPACK -Dlibc -fPIC -Dshared -undefined dynamic_lookup

$(K)/libk.dylib:$(K)/*.c ../../*.h
	$(MAKE) -C$(K) libk.dylib

c:
	rm -rf libcblas.dylib*
