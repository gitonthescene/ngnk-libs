#include "unistd.h"
#include "k.h"
#undef shared
#include <Accelerate/Accelerate.h>

K ser2(K x,K y);
K mut(K x);
typedef long long L;typedef unsigned int U;

typedef struct __attribute__((packed)) { char type; uint32_t len; } hdr;
typedef struct __attribute__((packed)) { hdr hdr; void* arr; } arr;
typedef struct __attribute__((packed)) { hdr lst; arr arr; C typinc; L inc; } cb_stride;
typedef struct __attribute__((packed)) { hdr lst; arr arr; C typlda; L lda; } cb_matrix;

#define SZ(a) sizeof(a)

#define REF (1<<7)
#define ART(a) ((unsigned char)(a).type&~REF)

#include "cblas_impl.c"

__attribute__((constructor)) void loadcblas(K);
void loadcblas(K k) {
  kinit();
  // Level 1
  KR("kblas.idamax",    (void*)Fcb_idamax,    1);
  KR("kblas.izamax",    (void*)Fcb_izamax,    1);
  KR("kblas.dasum",     (void*)Fcb_dasum,     1);
  KR("kblas.dzasum",    (void*)Fcb_dzasum,    1);
  KR("kblas.daxpy",     (void*)Fcb_daxpy,     1);
  KR("kblas.zaxpy",     (void*)Fcb_zaxpy,     1);
  KR("kblas.dcopy",     (void*)Fcb_dcopy,     1);
  KR("kblas.zcopy",     (void*)Fcb_zcopy,     1);
  KR("kblas.ddot",      (void*)Fcb_ddot,      1);
  KR("kblas.zdotusub",  (void*)Fcb_zdotu_sub, 1);
  KR("kblas.zdotcsub",  (void*)Fcb_zdotc_sub, 1);
  KR("kblas.dnrm2",     (void*)Fcb_dnrm2,     1);
  KR("kblas.dznrm2",    (void*)Fcb_dznrm2,    1);
  KR("kblas.dscal",     (void*)Fcb_dscal,     1);
  KR("kblas.zscal",     (void*)Fcb_zscal,     1);
  KR("kblas.dswap",     (void*)Fcb_dswap,     1);
  KR("kblas.zswap",     (void*)Fcb_zswap,     1);
  KR("kblas.drot",      (void*)Fcb_drot,      1);
  KR("kblas.zdrot",     (void*)Fcb_zdrot,     1);
  KR("kblas.drotg",     (void*)Fcb_drotg,     1);
  KR("kblas.zrotg",     (void*)Fcb_zrotg,     1);
  KR("kblas.drotm",     (void*)Fcb_drotm,     1);
  KR("kblas.drotmg",    (void*)Fcb_drotmg,    1);
  // Level 2
  KR("kblas.dgemv",     (void*)Fcb_dgemv,     1);
  KR("kblas.zgemv",     (void*)Fcb_zgemv,     1);
}
