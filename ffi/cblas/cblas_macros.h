#define SCA(a,b)              SCA##a(b)
#define SCAint(a) C typ##a;   L a;
#define SCAdoubleP(a)         arr a;
#define SCAdouble(a)          arr a;
#define SCAdouble_complexP(a) arr a;
#define SCAdouble_complex(a)  arr a;
#define SCAfloatP(a)          arr a;
#define SCAfloat(a)           arr a;
#define SCAfloat_complexP(a)  arr a;
#define SCAfloat_complex(a)   arr a;
#define VEC(t,n)              cb_stride n;
#define MAT(t,n)              cb_matrix n;

#define STRUCT(n,c,a...) typedef struct __attribute__((packed)) { hdr lst; a } n##_sig;

#include "struct.h"

#undef SCAint
#undef SCAdoubleP
#undef SCAdouble
#undef SCAdouble_complexP
#undef SCAdouble_complex
#undef SCAfloatP
#undef SCAfloat
#undef SCAfloat_complexP
#undef SCAfloat_complex
#undef VEC
#undef MAT
#undef STRUCT

#define SCAint(a)             (in->typ##a != 13) ||
#define SCAdoubleP(a)         (ART(in->a.hdr) != 15) ||
#define SCAdouble(a)          (ART(in->a.hdr) != 15) ||
#define SCAdouble_complexP(a) (ART(in->a.hdr) != 15) ||
#define SCAdouble_complex(a)  (ART(in->a.hdr) != 15) ||
#define SCAfloatP(a)          (ART(in->a.hdr) != 15) || // die??
#define SCAfloat(a)           (ART(in->a.hdr) != 15) || // die??
#define SCAfloat_complexP(a)  (ART(in->a.hdr) != 15) || // die??
#define SCAfloat_complex(a)   (ART(in->a.hdr) != 15) || // die??

#define VEC(a,b) VEC##a(b)
#define VECdoubleP(a)         (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typinc != 13) ||
#define VECdouble(a)          (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typinc != 13) ||
#define VECdouble_complexP(a) (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typinc != 13) ||
#define VECdouble_complex(a)  (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typinc != 13) ||
#define VECfloatP(a)          (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typinc != 13) || // die??
#define VECfloat(a)           (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typinc != 13) || // die??
#define VECfloat_complexP(a)  (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typinc != 13) || // die??
#define VECfloat_complex(a)   (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typinc != 13) || // die??

#define MAT(a,b) MAT##a(b)
#define MATdoubleP(a)         (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typlda != 13) ||
#define MATdouble(a)          (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typlda != 13) ||
#define MATdouble_complexP(a) (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typlda != 13) ||
#define MATdouble_complex(a)  (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typlda != 13) ||
#define MATfloatP(a)          (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typlda != 13) || // die??
#define MATfloat(a)           (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typlda != 13) || // die??
#define MATfloat_complexP(a)  (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typlda != 13) || // die??
#define MATfloat_complex(a)   (ART(in->a.arr.hdr) != 8) || (in->a.lst.len !=2) || (in->a.typlda != 13) || // die??

#define VER 1 // serialization version

#define STRUCT(n,c,a...) n##_sig* chk_##n##_sig(S x){ \
  if (x[0] != VER || x[1] != 1) return 0;             \
  n##_sig* in = (n##_sig*)(x+1);                      \
  if( in->lst.len != c || a 0) { return 0; }; return in; }

#include "struct.h"

#undef SCAint
#undef SCAdoubleP
#undef SCAdouble
#undef SCAdouble_complexP
#undef SCAdouble_complex
#undef SCAfloatP
#undef SCAfloat
#undef SCAfloat_complexP
#undef SCAfloat_complex
#undef VEC
#undef MAT
#undef STRUCT
#undef VEC
#undef VECdouble
#undef VECdouble_complex
#undef VECfloat
#undef VECfloat_complex
#undef MAT
#undef MATdoubleP
#undef MATdouble
#undef MATdouble_complexP
#undef MATdouble_complex
#undef MATfloatP
#undef MATfloat
#undef MATfloat_complexP
#undef MATfloat_complex

#define SCAint(b)               in->b,
#define SCAdoubleP(b)           (double*)in->b.arr,
#define SCAdouble(b)            *(double*)in->b.arr,
#define SCAdouble_complexP(b)   (double complex*)in->b.arr,
#define SCAdouble_complex(b)    *(double copmlex*)in->b.arr,
#define SCAfloatP(b)            (float*)in->b.arr,
#define SCAfloat(b)             *(float*)in->b.arr,
#define SCAfloat_complexP(b)    (float complex*)in->b.arr,
#define SCAfloat_complex(b)     *(float complex*)in->b.arr,

#define VEC(a,b) VEC##a(b)
#define VECdouble(b)           (double*)in->b.arr.arr,         in->b.inc,
#define VECdouble_complex(b)   (double complex*)in->b.arr.arr, in->b.inc,
#define VECfloat(b)            (float*)in->b.arr.arr,          in->b.inc,
#define VECfloat_complex(b)    (float complex*)in->b.arr.arr,  in->b.inc,

#define MAT(a,b) MAT##a(b)
#define MATdoubleP(b)           (double*)in->b.arr.arr,         &in->b.lda,
#define MATdouble(b)            (double*)in->b.arr.arr,          in->b.lda,
#define MATdouble_complexP(b)   (double complex*)in->b.arr.arr, &in->b.lda,
#define MATdouble_complex(b)    (double complex*)in->b.arr.arr,  in->b.lda,
#define MATfloatP(b)            (float*)in->b.arr.arr,          &in->b.lda,
#define MATfloat(b)             (float*)in->b.arr.arr,           in->b.lda,
#define MATfloat_complexP(b)    (float complex*)in->b.arr.arr,  &in->b.lda,
#define MATfloat_complex(b)     (float complex*)in->b.arr.arr,   in->b.lda,

#define STRUCT(n,c,a...) Fcb_##n(K x) {ref(x);  K xs = ser2(Ki(1),x); if( TK(xs)!=9 || NK(xs) != SZ(n##_sig) + 1 ) { unref(xs); unref(x); return 0; } \
	n##_sig* in = chk_##n##_sig((char*)xs); if (!in) { unref(xs); unref(x); return 0; } \
  cblas_##n(a);                        \
  K y=(K)in->y.arr.arr;  ref(y);       \
  unref(xs); unref(x);				   \
  return y; }

//#include "struct.h"

#undef SCAint
#undef SCAdoubleP
#undef SCAdouble
#undef SCAdouble_complexP
#undef SCAdouble_complex
#undef SCAfloatP
#undef SCAfloat
#undef SCAfloat_complexP
#undef SCAfloat_complex
#undef VEC
#undef MAT
#undef STRUCT
#undef VEC
#undef VECdoubleP
#undef VECdouble
#undef VECdouble_complexP
#undef VECdouble_complex
#undef VECfloatP
#undef VECfloat
#undef VECfloat_complexP
#undef VECfloat_complex
#undef MAT
#undef MATdoubleP
#undef MATdouble
#undef MATdouble_complexP
#undef MATdouble_complex
#undef MATfloatP
#undef MATfloat
#undef MATfloat_complexP
#undef MATfloat_complex
