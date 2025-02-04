K= # path to k source where you've built libk.dylib
MDINC=/opt/local/include/libmd
MDLIB=/opt/local/lib

0:libmd5.dylib
	DYLD_LIBRARY_PATH=$(K):$(MDLIB) k test.k

libmd5.dylib:md5.c
	$(CC) -I$(K) -I$(MDINC) -L$(K) -L$(MDLIB) -install_name $@ -dynamiclib -fPIC $^ -o $@ -lk -lmd
