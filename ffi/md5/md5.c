#include<md5.h>
#include<k.h>

K md5(K x){K y=KC(0,MD5_DIGEST_LENGTH);MD5_CTX ctx;MD5Init(&ctx);
  MD5Update(&ctx,(const uint8_t *)x,NK(x));MD5Final((uint8_t*)y,&ctx);
		   unref(x);return KC((char*)y,NK(y));}
