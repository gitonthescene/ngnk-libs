#include "unistd.h"
#include "k.h"
#undef shared
#include <Accelerate/Accelerate.h>

K ser2(K x,K y);
K mut(K x);
typedef long long L;

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
  KR("kblas.idamax", (void*)Fcb_idamax, 1);
  KR("kblas.dasum",  (void*)Fcb_dasum,  1);
  KR("kblas.daxpy",  (void*)Fcb_daxpy,  1);
  KR("kblas.dgemv",  (void*)Fcb_dgemv,  1);
}
