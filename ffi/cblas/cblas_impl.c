#include "cblas_impl.h"
/* K Fcb_isamax(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(isamax_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  isamax_sig* in = chk_isamax_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  int r=cblas_isamax(in->N, (float*)in->X.arr.arr, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return Ki(r); */
/*  } */

K Fcb_idamax(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(idamax_sig) + 1 ) { unref(xs); unref(x); return 0; }
 idamax_sig* in = chk_idamax_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 int r=cblas_idamax(in->N, (double*)in->X.arr.arr, in->X.inc);
 unref(xs); unref(x);
 return Ki(r);
 }

/* K Fcb_icamax(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(icamax_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  icamax_sig* in = chk_icamax_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  int r=cblas_icamax(in->N, (float complex*)in->X.arr.arr, in->X.inc); */
/*  return Ki(r) */
/*  } */

K Fcb_izamax(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(izamax_sig) + 1 ) { unref(xs); unref(x); return 0; }
 izamax_sig* in = chk_izamax_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 int r=cblas_izamax(in->N, (double complex*)in->X.arr.arr, in->X.inc);
 unref(xs); unref(x);
 return Ki(r);
 }

/* K Fcb_sasum(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sasum_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sasum_sig* in = chk_sasum_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  float r=cblas_sasum(in->N, (float*)in->X.arr.arr, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return Kf(r); */
/*  } */

K Fcb_dasum(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dasum_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dasum_sig* in = chk_dasum_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r=cblas_dasum(in->N, (double*)in->X.arr.arr, in->X.inc);
 unref(xs); unref(x);
 return Kf(r);
 }

/* K Fcb_scasum(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(scasum_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  scasum_sig* in = chk_scasum_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  float complex=cblas_scasum(in->N, (float complex*)in->X.arr.arr, in->X.inc); */
/*  unref(xs); unref(x); return 0; */
/*  } */

K Fcb_dzasum(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dzasum_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dzasum_sig* in = chk_dzasum_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r=cblas_dzasum(in->N, (double complex*)in->X.arr.arr, in->X.inc);
 unref(xs); unref(x); return 0;
 }

/* K Fcb_saxpy(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(saxpy_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  saxpy_sig* in = chk_saxpy_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_saxpy(in->N, *(float*)in->ALPHA.arr, (float*)in->X.arr.arr, in->X.inc, (float*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_daxpy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(daxpy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 daxpy_sig* in = chk_daxpy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_daxpy(in->N, *(double*)in->ALPHA.arr, (double*)in->X.arr.arr, in->X.inc, (double*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_caxpy(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(caxpy_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  caxpy_sig* in = chk_caxpy_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_caxpy(in->N, (float complex*)in->ALPHA.arr, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zaxpy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zaxpy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zaxpy_sig* in = chk_zaxpy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_zaxpy(in->N, (double complex*)in->ALPHA.arr, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_scopy(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(scopy_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  scopy_sig* in = chk_scopy_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_scopy(in->N, (float*)in->X.arr.arr, in->X.inc, (float*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dcopy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dcopy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dcopy_sig* in = chk_dcopy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_dcopy(in->N, (double*)in->X.arr.arr, in->X.inc, (double*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ccopy(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ccopy_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ccopy_sig* in = chk_ccopy_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_ccopy(in->N, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zcopy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zcopy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zcopy_sig* in = chk_zcopy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_zcopy(in->N, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_sdot(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sdot_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sdot_sig* in = chk_sdot_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  float r=cblas_sdot(in->N, (float*)in->X.arr.arr, in->X.inc, (float*)in->Y.arr.arr, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return Kf(r); */
/*  } */

K Fcb_ddot(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(ddot_sig) + 1 ) { unref(xs); unref(x); return 0; }
 ddot_sig* in = chk_ddot_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r=cblas_ddot(in->N, (double*)in->X.arr.arr, in->X.inc, (double*)in->Y.arr.arr, in->Y.inc);
 unref(xs); unref(x);
 return Kf(r);
 }

/* K Fcb_cdotu_sub(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cdotu_sub_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cdotu_sub_sig* in = chk_cdotu_sub_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->DOTU.arr; y=mut(ref(y)); */
/*  cblas_cdotu_sub(in->N, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->Y.arr.arr, in->Y.inc, (float complex*)y); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zdotu_sub(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zdotu_sub_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zdotu_sub_sig* in = chk_zdotu_sub_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->DOTU.arr; y=mut(ref(y));
 cblas_zdotu_sub(in->N, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->Y.arr.arr, in->Y.inc, (double complex*)y);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_cdotc_sub(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cdotc_sub_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cdotc_sub_sig* in = chk_cdotc_sub_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->DOTC.arr; y=mut(ref(y)); */
/*  cblas_cdotc_sub(in->N, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->Y.arr.arr, in->Y.inc, (float complex*)y); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zdotc_sub(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zdotc_sub_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zdotc_sub_sig* in = chk_zdotc_sub_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->DOTC.arr; y=mut(ref(y));
 cblas_zdotc_sub(in->N, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->Y.arr.arr, in->Y.inc, (double complex*)y);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_sdsdot(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sdsdot_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sdsdot_sig* in = chk_sdsdot_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  float r=cblas_sdsdot(in->N, *(float*)in->ALPHA.arr, (float*)in->X.arr.arr, in->X.inc, (float*)in->Y.arr.arr, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return Kf(r); */
/*  } */

/* K Fcb_dsdot(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(dsdot_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  dsdot_sig* in = chk_dsdot_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  double r=cblas_dsdot(in->N, (float*)in->X.arr.arr, in->X.inc, (float*)in->Y.arr.arr, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return Kf(r); */
/*  } */

/* K Fcb_snrm2(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(snrm2_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  snrm2_sig* in = chk_snrm2_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  float r=cblas_snrm2(in->N, (float*)in->X.arr.arr, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return Kf(r); */
/*  } */

K Fcb_dnrm2(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dnrm2_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dnrm2_sig* in = chk_dnrm2_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r=cblas_dnrm2(in->N, (double*)in->X.arr.arr, in->X.inc);
 unref(xs); unref(x);
 return Kf(r);
 }

/* K Fcb_scnrm2(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(scnrm2_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  scnrm2_sig* in = chk_scnrm2_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  float r=cblas_scnrm2(in->N, (float complex*)in->X.arr.arr, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return Kf(r); */
/*  } */

K Fcb_dznrm2(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dznrm2_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dznrm2_sig* in = chk_dznrm2_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r=cblas_dznrm2(in->N, (double complex*)in->X.arr.arr, in->X.inc);
 unref(xs); unref(x);
 return Kf(r);
 }

/* K Fcb_srot(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(srot_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  srot_sig* in = chk_srot_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_srot(in->N, (float*)in->X.arr.arr, in->X.inc, (float*)y, in->Y.inc, *(float*)in->C.arr, *(float*)in->S.arr); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_drot(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(drot_sig) + 1 ) { unref(xs); unref(x); return 0; }
 drot_sig* in = chk_drot_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_drot(in->N, (double*)in->X.arr.arr, in->X.inc, (double*)y, in->Y.inc, *(double*)in->C.arr, *(double*)in->S.arr);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_csrot(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(csrot_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  csrot_sig* in = chk_csrot_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_csrot(in->N, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)y, in->Y.inc, *(float*)in->C.arr, *(float*)in->S.arr); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zdrot(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zdrot_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zdrot_sig* in = chk_zdrot_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_zdrot(in->N, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)y, in->Y.inc, *(double*)in->C.arr, *(double*)in->S.arr);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_srotg(K x) {x=mut(x); */
/*  if( TK(x)!=8 || NK(x) != 4 ) { unref(x); return 0; } */
/*  float* a=(float*)x; */
/*  cblas_drotg(a+0,a+1,a+2,a+3); */
/*  return x; */
/*  } */

K Fcb_drotg(K x) {x=mut(x);
 if( TK(x)!=8 || NK(x) != 4 ) { unref(x); return 0; }
 F* a=(F*)x;
 cblas_drotg(a+0,a+1,a+2,a+3);
 return x;
 }

/* K Fcb_crotg(K x) {x=mut(x); */
/*  if( TK(x)!=8 || NK(x) != 8 ) { unref(x); return 0; } */
/*  float* a=(float*)x; */
/*  cblas_drotg(a+0,a+2,a+4,a+6); */
/*  return x; */
/*  } */

K Fcb_zrotg(K x) {x=mut(x);
 if( TK(x)!=8 || NK(x) != 8 ) { unref(x); return 0; }
 double* a=(double*)x;
 cblas_drotg(a+0,a+2,a+4,a+6);
 return x;
 }

/* K Fcb_srotm(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(srotm_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  srotm_sig* in = chk_srotm_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  cblas_srotm(in->N, (float*)in->X.arr.arr, in->X.inc, (float*)in->Y.arr.arr, in->Y.inc, (float*)in->P.arr); */
/*  unref(xs); */
/*  return x; */
/*  } */

K Fcb_drotm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(drotm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 drotm_sig* in = chk_drotm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cblas_drotm(in->N, (double*)in->X.arr.arr, in->X.inc, (double*)in->Y.arr.arr, in->Y.inc, (double*)in->P.arr);
 unref(xs);
 return x;
 }

/* K Fcb_srotmg(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(srotmg_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  srotmg_sig* in = chk_srotmg_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  cblas_srotmg((float*)in->D1.arr, (float*)in->D2.arr, (float*)in->B1.arr, *(float*)in->B2.arr, (float*)in->P.arr); */
/*  unref(xs); */
/*  return x; */
/*  } */

K Fcb_drotmg(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(drotmg_sig) + 1 ) { unref(xs); unref(x); return 0; }
 drotmg_sig* in = chk_drotmg_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cblas_drotmg((double*)in->D1.arr, (double*)in->D2.arr, (double*)in->B1.arr, *(double*)in->B2.arr, (double*)in->P.arr);
 unref(xs);
 return x;
 }

/* K Fcb_sscal(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sscal_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sscal_sig* in = chk_sscal_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  cblas_sscal(in->N, *(float*)in->ALPHA.arr, (float*)in->X.arr.arr, in->X.inc); */
/*  unref(xs); */
/*  return x; */
/*  } */

K Fcb_dscal(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dscal_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dscal_sig* in = chk_dscal_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cblas_dscal(in->N, *(double*)in->ALPHA.arr, (double*)in->X.arr.arr, in->X.inc);
 unref(xs);
 return x;
 }

/* K Fcb_cscal(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cscal_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cscal_sig* in = chk_cscal_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  cblas_cscal(in->N, (float complex*)in->ALPHA.arr, (float complex*)in->X.arr.arr, in->X.inc); */
/*  unref(xs); */
/*  return x; */
/*  } */

K Fcb_zscal(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zscal_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zscal_sig* in = chk_zscal_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cblas_zscal(in->N, (double complex*)in->ALPHA.arr, (double complex*)in->X.arr.arr, in->X.inc);
 unref(xs);
 return x;
 }

/* K Fcb_csscal(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(csscal_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  csscal_sig* in = chk_csscal_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  cblas_csscal(in->N, *(float*)in->ALPHA.arr, (float complex*)in->X.arr.arr, in->X.inc); */
/*  unref(xs); */
/*  return x; */
/*  } */

K Fcb_zdscal(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zdscal_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zdscal_sig* in = chk_zdscal_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cblas_zdscal(in->N, *(double*)in->ALPHA.arr, (double complex*)in->X.arr.arr, in->X.inc);
 unref(xs);
 return x;
 }

/* K Fcb_sswap(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sswap_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sswap_sig* in = chk_sswap_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  cblas_sswap(in->N, (float*)in->X.arr.arr, in->X.inc, (float*)in->Y.arr.arr, in->Y.inc); */
/*  unref(xs); */
/*  return x; */
/*  } */

K Fcb_dswap(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dswap_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dswap_sig* in = chk_dswap_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cblas_dswap(in->N, (double*)in->X.arr.arr, in->X.inc, (double*)in->Y.arr.arr, in->Y.inc);
 unref(xs);
 return x;
 }

/* K Fcb_cswap(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cswap_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cswap_sig* in = chk_cswap_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  cblas_cswap(in->N, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->Y.arr.arr, in->Y.inc); */
/*  unref(xs); */
/*  return x; */
/*  } */

K Fcb_zswap(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zswap_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zswap_sig* in = chk_zswap_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cblas_zswap(in->N, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->Y.arr.arr, in->Y.inc);
 unref(xs);
 return x;
 }

/* K Fcb_sgemv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sgemv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sgemv_sig* in = chk_sgemv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_sgemv(in->ORDER, in->TRANSA, in->M, in->N, *(float*)in->ALPHA.arr, (float*)in->A.arr.arr, in->A.lda, (float*)in->X.arr.arr, in->X.inc, *(float*)in->BETA.arr, (float*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dgemv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dgemv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dgemv_sig* in = chk_dgemv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_dgemv(in->ORDER, in->TRANSA, in->M, in->N, *(double*)in->ALPHA.arr, (double*)in->A.arr.arr, in->A.lda, (double*)in->X.arr.arr, in->X.inc, *(double*)in->BETA.arr, (double*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_cgemv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cgemv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cgemv_sig* in = chk_cgemv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_cgemv(in->ORDER, in->TRANSA, in->M, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->BETA.arr, (float complex*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zgemv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zgemv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zgemv_sig* in = chk_zgemv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_zgemv(in->ORDER, in->TRANSA, in->M, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->BETA.arr, (double complex*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_sgbmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sgbmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sgbmv_sig* in = chk_sgbmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_sgbmv(in->ORDER, in->TRANSA, in->M, in->N, in->KL, in->KU, *(float*)in->ALPHA.arr, (float*)in->A.arr.arr, in->A.lda, (float*)in->X.arr.arr, in->X.inc, *(float*)in->BETA.arr, (float*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dgbmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dgbmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dgbmv_sig* in = chk_dgbmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_dgbmv(in->ORDER, in->TRANSA, in->M, in->N, in->KL, in->KU, *(double*)in->ALPHA.arr, (double*)in->A.arr.arr, in->A.lda, (double*)in->X.arr.arr, in->X.inc, *(double*)in->BETA.arr, (double*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_cgbmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cgbmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cgbmv_sig* in = chk_cgbmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_cgbmv(in->ORDER, in->TRANSA, in->M, in->N, in->KL, in->KU, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->BETA.arr, (float complex*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zgbmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zgbmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zgbmv_sig* in = chk_zgbmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_zgbmv(in->ORDER, in->TRANSA, in->M, in->N, in->KL, in->KU, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->BETA.arr, (double complex*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_sger(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sger_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sger_sig* in = chk_sger_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->A.arr.arr; y=mut(ref(y)); */
/*  cblas_sger(in->ORDER, in->M, in->N, *(float*)in->ALPHA.arr, (float*)in->X.arr.arr, in->X.inc, (float*)in->Y.arr.arr, in->Y.inc, (float*)y, in->A.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dger(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dger_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dger_sig* in = chk_dger_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->A.arr.arr; y=mut(ref(y));
 cblas_dger(in->ORDER, in->M, in->N, *(double*)in->ALPHA.arr, (double*)in->X.arr.arr, in->X.inc, (double*)in->Y.arr.arr, in->Y.inc, (double*)y, in->A.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_cgerc(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cgerc_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cgerc_sig* in = chk_cgerc_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->A.arr.arr; y=mut(ref(y)); */
/*  cblas_cgerc(in->ORDER, in->M, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->Y.arr.arr, in->Y.inc, (float complex*)in->y, in->A.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zgerc(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zgerc_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zgerc_sig* in = chk_zgerc_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->A.arr.arr; y=mut(ref(y));
 cblas_zgerc(in->ORDER, in->M, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->Y.arr.arr, in->Y.inc, (double complex*)y, in->A.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_cgeru(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cgeru_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cgeru_sig* in = chk_cgeru_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->A.arr.arr; y=mut(ref(y)); */
/*  cblas_cgeru(in->ORDER, in->M, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->Y.arr.arr, in->Y.inc, (float complex*)y, in->A.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zgeru(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zgeru_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zgeru_sig* in = chk_zgeru_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->A.arr.arr; y=mut(ref(y));
 cblas_zgeru(in->ORDER, in->M, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->Y.arr.arr, in->Y.inc, (double complex*)y, in->A.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_chbmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(chbmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  chbmv_sig* in = chk_chbmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_chbmv(in->ORDER, in->UPLO, in->N, in->K, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->BETA.arr, (float complex*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zhbmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zhbmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zhbmv_sig* in = chk_zhbmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_zhbmv(in->ORDER, in->UPLO, in->N, in->K, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->BETA.arr, (double complex*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_chemv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(chemv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  chemv_sig* in = chk_chemv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_chemv(in->ORDER, in->UPLO, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->BETA.arr, (float complex*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zhemv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zhemv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zhemv_sig* in = chk_zhemv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_zhemv(in->ORDER, in->UPLO, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->BETA.arr, (double complex*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_cher(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cher_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cher_sig* in = chk_cher_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->A.arr.arr; y=mut(ref(y)); */
/*  cblas_cher(in->ORDER, in->UPLO, in->N, *(float*)in->ALPHA.arr, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)y, in->A.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zher(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zher_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zher_sig* in = chk_zher_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->A.arr.arr; y=mut(ref(y));
 cblas_zher(in->ORDER, in->UPLO, in->N, *(double*)in->ALPHA.arr, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)y, in->A.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_cher2(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cher2_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cher2_sig* in = chk_cher2_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_cher2(in->ORDER, in->UPLO, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)y, in->Y.inc, (float complex*)in->A.arr.arr, in->A.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zher2(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zher2_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zher2_sig* in = chk_zher2_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->A.arr.arr; y=mut(ref(y));
 cblas_zher2(in->ORDER, in->UPLO, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->Y.arr.arr, in->Y.inc, (double complex*)y, in->A.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_chpmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(chpmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  chpmv_sig* in = chk_chpmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_chpmv(in->ORDER, in->UPLO, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->AP.arr, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->BETA.arr, (float complex*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zhpmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zhpmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zhpmv_sig* in = chk_zhpmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_zhpmv(in->ORDER, in->UPLO, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->AP.arr, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->BETA.arr, (double complex*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_chpr(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(chpr_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  chpr_sig* in = chk_chpr_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->A.arr; y=mut(ref(y)); */
/*  cblas_chpr(in->ORDER, in->UPLO, in->N, *(float*)in->ALPHA.arr, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)y); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zhpr(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zhpr_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zhpr_sig* in = chk_zhpr_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->A.arr; y=mut(ref(y));
 cblas_zhpr(in->ORDER, in->UPLO, in->N, *(double*)in->ALPHA.arr, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)y);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_chpr2(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(chpr2_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  chpr2_sig* in = chk_chpr2_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->AP.arr.arr; y=mut(ref(y)); */
/*  cblas_chpr2(in->ORDER, in->UPLO, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->X.arr.arr, in->X.inc, (float complex*)in->Y.arr.arr, in->Y.inc, (float complex*)y); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zhpr2(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zhpr2_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zhpr2_sig* in = chk_zhpr2_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->AP.arr; y=mut(ref(y));
 cblas_zhpr2(in->ORDER, in->UPLO, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->X.arr.arr, in->X.inc, (double complex*)in->Y.arr.arr, in->Y.inc, (double complex*)y);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ssbmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ssbmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ssbmv_sig* in = chk_ssbmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_ssbmv(in->ORDER, in->UPLO, in->N, in->K, *(float*)in->ALPHA.arr, (float*)in->A.arr.arr, in->A.lda, (float*)in->X.arr.arr, in->X.inc, *(float*)in->BETA.arr, (float*)in->y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dsbmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dsbmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dsbmv_sig* in = chk_dsbmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_dsbmv(in->ORDER, in->UPLO, in->N, in->K, *(double*)in->ALPHA.arr, (double*)in->A.arr.arr, in->A.lda, (double*)in->X.arr.arr, in->X.inc, *(double*)in->BETA.arr, (double*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_sspmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sspmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sspmv_sig* in = chk_sspmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_sspmv(in->ORDER, in->UPLO, in->N, *(float*)in->ALPHA.arr, (float*)in->AP.arr, (float*)in->X.arr.arr, in->X.inc, *(float*)in->BETA.arr, (float*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dspmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dspmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dspmv_sig* in = chk_dspmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_dspmv(in->ORDER, in->UPLO, in->N, *(double*)in->ALPHA.arr, (double*)in->AP.arr, (double*)in->X.arr.arr, in->X.inc, *(double*)in->BETA.arr, (double*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_sspr(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sspr_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sspr_sig* in = chk_sspr_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->AP.arr; y=mut(ref(y)); */
/*  cblas_sspr(in->ORDER, in->UPLO, in->N, *(float*)in->ALPHA.arr, (float*)in->X.arr.arr, in->X.inc, (float*)y); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dspr(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dspr_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dspr_sig* in = chk_dspr_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->AP.arr; y=mut(ref(y));
 cblas_dspr(in->ORDER, in->UPLO, in->N, *(double*)in->ALPHA.arr, (double*)in->X.arr.arr, in->X.inc, (double*)y);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_sspr2(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sspr2_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sspr2_sig* in = chk_sspr2_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->A.arr; y=mut(ref(y)); */
/*  cblas_sspr2(in->ORDER, in->UPLO, in->N, *(float*)in->ALPHA.arr, (float*)in->X.arr.arr, in->X.inc, (float*)in->Y.arr.arr, in->Y.inc, (float*)y); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dspr2(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dspr2_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dspr2_sig* in = chk_dspr2_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->A.arr; y=mut(ref(y));
 cblas_dspr2(in->ORDER, in->UPLO, in->N, *(double*)in->ALPHA.arr, (double*)in->X.arr.arr, in->X.inc, (double*)in->Y.arr.arr, in->Y.inc, (double*)y);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ssymv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ssymv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ssymv_sig* in = chk_ssymv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->Y.arr.arr; y=mut(ref(y)); */
/*  cblas_ssymv(in->ORDER, in->UPLO, in->N, *(float*)in->ALPHA.arr, (float*)in->A.arr.arr, in->A.lda, (float*)in->X.arr.arr, in->X.inc, *(float*)in->BETA.arr, (float*)y, in->Y.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dsymv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dsymv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dsymv_sig* in = chk_dsymv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->Y.arr.arr; y=mut(ref(y));
 cblas_dsymv(in->ORDER, in->UPLO, in->N, *(double*)in->ALPHA.arr, (double*)in->A.arr.arr, in->A.lda, (double*)in->X.arr.arr, in->X.inc, *(double*)in->BETA.arr, (double*)y, in->Y.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ssyr(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ssyr_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ssyr_sig* in = chk_ssyr_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->A.arr.arr; y=mut(ref(y)); */
/*  cblas_ssyr(in->ORDER, in->UPLO, in->N, *(float*)in->ALPHA.arr, (float*)in->X.arr.arr, in->X.inc, (float*)y, in->A.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dsyr(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dsyr_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dsyr_sig* in = chk_dsyr_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->A.arr.arr; y=mut(ref(y));
 cblas_dsyr(in->ORDER, in->UPLO, in->N, *(double*)in->ALPHA.arr, (double*)in->X.arr.arr, in->X.inc, (double*)y, in->A.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ssyr2(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ssyr2_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ssyr2_sig* in = chk_ssyr2_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->A.arr.arr; y=mut(ref(y)); */
/*  cblas_ssyr2(in->ORDER, in->UPLO, in->N, *(float*)in->ALPHA.arr, (float*)in->X.arr.arr, in->X.inc, (float*)in->Y.arr.arr, in->Y.inc, (float*)y, in->A.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dsyr2(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dsyr2_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dsyr2_sig* in = chk_dsyr2_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->A.arr.arr; y=mut(ref(y));
 cblas_dsyr2(in->ORDER, in->UPLO, in->N, *(double*)in->ALPHA.arr, (double*)in->X.arr.arr, in->X.inc, (double*)in->Y.arr.arr, in->Y.inc, (double*)y, in->A.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_stbmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(stbmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  stbmv_sig* in = chk_stbmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_stbmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, in->K, (float*)in->A.arr.arr, in->A.lda, (float*)in->y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dtbmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dtbmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dtbmv_sig* in = chk_dtbmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_dtbmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, in->K, (double*)in->A.arr.arr, in->A.lda, (double*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ctbmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ctbmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ctbmv_sig* in = chk_ctbmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_ctbmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, in->K, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_ztbmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(ztbmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 ztbmv_sig* in = chk_ztbmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_ztbmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, in->K, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_stbsv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(stbsv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  stbsv_sig* in = chk_stbsv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_stbsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, in->K, (float*)in->A.arr.arr, in->A.lda, (float*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dtbsv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dtbsv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dtbsv_sig* in = chk_dtbsv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_dtbsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, in->K, (double*)in->A.arr.arr, in->A.lda, (double*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ctbsv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ctbsv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ctbsv_sig* in = chk_ctbsv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_ctbsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, in->K, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_ztbsv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(ztbsv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 ztbsv_sig* in = chk_ztbsv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_ztbsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, in->K, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_stpmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(stpmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  stpmv_sig* in = chk_stpmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_stpmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (float*)in->AP.arr, (float*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dtpmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dtpmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dtpmv_sig* in = chk_dtpmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_dtpmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (double*)in->AP.arr, (double*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ctpmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ctpmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ctpmv_sig* in = chk_ctpmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_ctpmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (float complex*)in->AP.arr, (float complex*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_ztpmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(ztpmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 ztpmv_sig* in = chk_ztpmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_ztpmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (double complex*)in->AP.arr, (double complex*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_stpsv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(stpsv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  stpsv_sig* in = chk_stpsv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_stpsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (float*)in->AP.arr, (float*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dtpsv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dtpsv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dtpsv_sig* in = chk_dtpsv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_dtpsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (double*)in->AP.arr, (double*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ctpsv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ctpsv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ctpsv_sig* in = chk_ctpsv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_ctpsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (float complex*)in->AP.arr, (float complex*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_ztpsv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(ztpsv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 ztpsv_sig* in = chk_ztpsv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_ztpsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (double complex*)in->AP.arr, (double complex*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_strmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(strmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  strmv_sig* in = chk_strmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_strmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (float*)in->A.arr.arr, in->A.lda, (float*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dtrmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dtrmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dtrmv_sig* in = chk_dtrmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_dtrmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (double*)in->A.arr.arr, in->A.lda, (double*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ctrmv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ctrmv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ctrmv_sig* in = chk_ctrmv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_ctrmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_ztrmv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(ztrmv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 ztrmv_sig* in = chk_ztrmv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_ztrmv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_strsv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(strsv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  strsv_sig* in = chk_strsv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_strsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (float*)in->A.arr.arr, in->A.lda, (float*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dtrsv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dtrsv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dtrsv_sig* in = chk_dtrsv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_dtrsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (double*)in->A.arr.arr, in->A.lda, (double*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ctrsv(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ctrsv_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ctrsv_sig* in = chk_ctrsv_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->X.arr.arr; y=mut(ref(y)); */
/*  cblas_ctrsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)y, in->X.inc); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_ztrsv(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(ztrsv_sig) + 1 ) { unref(xs); unref(x); return 0; }
 ztrsv_sig* in = chk_ztrsv_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->X.arr.arr; y=mut(ref(y));
 cblas_ztrsv(in->ORDER, in->UPLO, in->TRANSA, in->DIAG, in->N, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)y, in->X.inc);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_sgemm(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(sgemm_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  sgemm_sig* in = chk_sgemm_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_sgemm(in->ORDER, in->TRANSA, in->TRANSB, in->M, in->N, in->K, *(float*)in->ALPHA.arr, (float*)in->A.arr.arr, in->A.lda, (float*)in->B.arr.arr, in->B.lda, *(float*)in->BETA.arr, (float*)y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dgemm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dgemm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dgemm_sig* in = chk_dgemm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_dgemm(in->ORDER, in->TRANSA, in->TRANSB, in->M, in->N, in->K, *(double*)in->ALPHA.arr, (double*)in->A.arr.arr, in->A.lda, (double*)in->B.arr.arr, in->B.lda, *(double*)in->BETA.arr, (double*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_cgemm(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cgemm_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cgemm_sig* in = chk_cgemm_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_cgemm(in->ORDER, in->TRANSA, in->TRANSB, in->M, in->N, in->K, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)in->B.arr.arr, in->B.lda, (float complex*)in->BETA.arr, (float complex*)y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zgemm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zgemm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zgemm_sig* in = chk_zgemm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_zgemm(in->ORDER, in->TRANSA, in->TRANSB, in->M, in->N, in->K, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)in->B.arr.arr, in->B.lda, (double complex*)in->BETA.arr, (double complex*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_chemm(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(chemm_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  chemm_sig* in = chk_chemm_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_chemm(in->ORDER, in->SIDE, in->UPLO, in->M, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)in->B.arr.arr, in->B.lda, (float complex*)in->BETA.arr, (float complex*)in->y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zhemm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zhemm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zhemm_sig* in = chk_zhemm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_zhemm(in->ORDER, in->SIDE, in->UPLO, in->M, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)in->B.arr.arr, in->B.lda, (double complex*)in->BETA.arr, (double complex*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_cherk(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cherk_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cherk_sig* in = chk_cherk_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_cherk(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, *(float*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, *(float*)in->BETA.arr, (float complex*)y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zherk(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zherk_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zherk_sig* in = chk_zherk_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_zherk(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, *(double*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, *(double*)in->BETA.arr, (double complex*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_cher2k(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(cher2k_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  cher2k_sig* in = chk_cher2k_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_cher2k(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)in->B.arr.arr, in->B.lda, *(float*)in->BETA.arr, (float complex*)y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zher2k(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zher2k_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zher2k_sig* in = chk_zher2k_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_zher2k(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)in->B.arr.arr, in->B.lda, *(double*)in->BETA.arr, (double complex*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ssymm(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ssymm_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ssymm_sig* in = chk_ssymm_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_ssymm(in->ORDER, in->SIDE, in->UPLO, in->M, in->N, *(float*)in->ALPHA.arr, (float*)in->A.arr.arr, in->A.lda, (float*)in->B.arr.arr, in->B.lda, *(float*)in->BETA.arr, (float*)y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dsymm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dsymm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dsymm_sig* in = chk_dsymm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_dsymm(in->ORDER, in->SIDE, in->UPLO, in->M, in->N, *(double*)in->ALPHA.arr, (double*)in->A.arr.arr, in->A.lda, (double*)in->B.arr.arr, in->B.lda, *(double*)in->BETA.arr, (double*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_csymm(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(csymm_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  csymm_sig* in = chk_csymm_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_csymm(in->ORDER, in->SIDE, in->UPLO, in->M, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)in->B.arr.arr, in->B.lda, (float complex*)in->BETA.arr, (float complex*)y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zsymm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zsymm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zsymm_sig* in = chk_zsymm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_zsymm(in->ORDER, in->SIDE, in->UPLO, in->M, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)in->B.arr.arr, in->B.lda, (double complex*)in->BETA.arr, (double complex*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ssyrk(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ssyrk_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ssyrk_sig* in = chk_ssyrk_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_ssyrk(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, *(float*)in->ALPHA.arr, (float*)in->A.arr.arr, in->A.lda, *(float*)in->BETA.arr, (float*)y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dsyrk(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dsyrk_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dsyrk_sig* in = chk_dsyrk_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_dsyrk(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, *(double*)in->ALPHA.arr, (double*)in->A.arr.arr, in->A.lda, *(double*)in->BETA.arr, (double*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_csyrk(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(csyrk_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  csyrk_sig* in = chk_csyrk_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_csyrk(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)in->BETA.arr, (float complex*)y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zsyrk(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zsyrk_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zsyrk_sig* in = chk_zsyrk_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_zsyrk(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)in->BETA.arr, (double complex*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ssyr2k(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ssyr2k_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ssyr2k_sig* in = chk_ssyr2k_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_ssyr2k(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, *(float*)in->ALPHA.arr, (float*)in->A.arr.arr, in->A.lda, (float*)in->B.arr.arr, in->B.lda, *(float*)in->BETA.arr, (float*)y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dsyr2k(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dsyr2k_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dsyr2k_sig* in = chk_dsyr2k_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_dsyr2k(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, *(double*)in->ALPHA.arr, (double*)in->A.arr.arr, in->A.lda, (double*)in->B.arr.arr, in->B.lda, *(double*)in->BETA.arr, (double*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_csyr2k(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(csyr2k_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  csyr2k_sig* in = chk_csyr2k_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->C.arr.arr; y=mut(ref(y)); */
/*  cblas_csyr2k(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)in->B.arr.arr, in->B.lda, (float complex*)in->BETA.arr, (float complex*)y, in->C.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_zsyr2k(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(zsyr2k_sig) + 1 ) { unref(xs); unref(x); return 0; }
 zsyr2k_sig* in = chk_zsyr2k_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->C.arr.arr; y=mut(ref(y));
 cblas_zsyr2k(in->ORDER, in->UPLO, in->TRANS, in->N, in->K, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)in->B.arr.arr, in->B.lda, (double complex*)in->BETA.arr, (double complex*)y, in->C.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_strmm(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(strmm_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  strmm_sig* in = chk_strmm_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->B.arr.arr; y=mut(ref(y)); */
/*  cblas_strmm(in->ORDER, in->SIDE, in->UPLO, in->TRANSA, in->DIAG, in->M, in->N, *(float*)in->ALPHA.arr, (float*)in->A.arr.arr, in->A.lda, (float*)y, in->B.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dtrmm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dtrmm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dtrmm_sig* in = chk_dtrmm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->B.arr.arr; y=mut(ref(y));
 cblas_dtrmm(in->ORDER, in->SIDE, in->UPLO, in->TRANSA, in->DIAG, in->M, in->N, *(double*)in->ALPHA.arr, (double*)in->A.arr.arr, in->A.lda, (double*)y, in->B.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ctrmm(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ctrmm_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ctrmm_sig* in = chk_ctrmm_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->B.arr.arr; y=mut(ref(y)); */
/*  cblas_ctrmm(in->ORDER, in->SIDE, in->UPLO, in->TRANSA, in->DIAG, in->M, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)y, in->B.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_ztrmm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(ztrmm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 ztrmm_sig* in = chk_ztrmm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->B.arr.arr; y=mut(ref(y));
 cblas_ztrmm(in->ORDER, in->SIDE, in->UPLO, in->TRANSA, in->DIAG, in->M, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)y, in->B.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_strsm(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(strsm_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  strsm_sig* in = chk_strsm_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->B.arr.arr; y=mut(ref(y)); */
/*  cblas_strsm(in->ORDER, in->SIDE, in->UPLO, in->TRANSA, in->DIAG, in->M, in->N, *(float*)in->ALPHA.arr, (float*)in->A.arr.arr, in->A.lda, (float*)y, in->B.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_dtrsm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(dtrsm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 dtrsm_sig* in = chk_dtrsm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->B.arr.arr; y=mut(ref(y));
 cblas_dtrsm(in->ORDER, in->SIDE, in->UPLO, in->TRANSA, in->DIAG, in->M, in->N, *(double*)in->ALPHA.arr, (double*)in->A.arr.arr, in->A.lda, (double*)y, in->B.lda);
 unref(xs); unref(x);
 return y;
 }

/* K Fcb_ctrsm(K x) {ref(x); */
/*  K xs = ser2(Ki(1),x); */
/*  if( TK(xs)!=9 || NK(xs) != SZ(ctrsm_sig) + 1 ) { unref(xs); unref(x); return 0; } */
/*  ctrsm_sig* in = chk_ctrsm_sig((char*)xs); */
/*  if (!in) { unref(xs); unref(x); return 0; } */
/*  K y=(K)in->B.arr.arr; y=mut(ref(y)); */
/*  cblas_ctrsm(in->ORDER, in->SIDE, in->UPLO, in->TRANSA, in->DIAG, in->M, in->N, (float complex*)in->ALPHA.arr, (float complex*)in->A.arr.arr, in->A.lda, (float complex*)y, in->B.lda); */
/*  unref(xs); unref(x); */
/*  return y; */
/*  } */

K Fcb_ztrsm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(ztrsm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 ztrsm_sig* in = chk_ztrsm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K y=(K)in->B.arr.arr; y=mut(ref(y));
 cblas_ztrsm(in->ORDER, in->SIDE, in->UPLO, in->TRANSA, in->DIAG, in->M, in->N, (double complex*)in->ALPHA.arr, (double complex*)in->A.arr.arr, in->A.lda, (double complex*)y, in->B.lda);
 unref(xs); unref(x);
 return y;
 }
