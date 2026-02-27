`"./libcblas.dylib"2:(`loadcblas;1);

`prng[ 1748229206560524786 -3661725398958796622 -2029063451938031988 1228439012929887510 ]

mkmtx:{y#-[x]+?(*/y)?2*x}
mkvec:{*mkmtx[x;1,y]}
mksq:{mkmtx[x;y,y]}
mktri:{mksq[x;y]*+|\=y}
mksym:{(-t*=z)+/1(x*+:)\t:mktri[y;z]}
shw:`0:"| ",/:,[;,""]@,[,"";]@" "/'$/|1(-|/#',/)\$:
sh:-1_#'*:\
flat:@[;0;,//]
band:{0^z@',/'+(!-x;!y+1)+/:\:!#z}
rnd:%[;F]@_(F:10000)*
Ovec0:{x/" + "/'+y#(::;,\:[;"*i"])@'$2#+(0N;y)#z}
Ovec:{Ovec0[x;y;z]/"[]"}
Omat:{(x/Ovec0[," ";y]'z)/"[]"}
Oprint:`0:"    ",
/Oprint:{}
Kprint:`0:": "/`k'
/Kprint:{}
/shw:{}

/ Level 1
N:6
X:(0.5*mkvec[10;N];1)
XZ:(0.5*mkvec[10;N*2];1)

Oprint "X = ",Ovec[," ";1;X 0],";"
Oprint "XZ = ",Ovec[," ";2;XZ 0],";"

i:(N;X); j:(N;XZ)
Kprint (`idamax; kblas.idamax[i])
Kprint (`izamax; kblas.izamax[j])
Kprint (`dasum;  kblas.dasum[i])
Kprint (`dzasum; kblas.dzasum[j])

Y:(0.5*mkvec[10;N];1)
YZ:(0.5*mkvec[10;N*2];1)
a:1.0; az:1.0 0

Oprint "Y = ",Ovec[," ";1;Y 0],";"
Oprint "YZ = ",Ovec[," ";2;YZ 0],";"
Oprint "a = ",Ovec[," ";1;a],"(1);"
Oprint "az = ",Ovec[," ";2;az],"(1);"
Oprint "a*X + Y"
Oprint "az*XZ + YZ"

i:(N;a;X;Y); j:(N;az;XZ;YZ)
Kprint (`daxpy;kblas.daxpy[i])
Kprint (`zaxpy;r:kblas.zaxpy[j])
shw 0N 2#r

p:0.5 0.5 0.0 0.0
Kprint (`drotg;r:kblas.drotg p)

i:(#l;(l:1.0 0.0 -1.0;1);(0.0 1.0 0.0;1);r 2; -r 3)
Kprint (`drot;kblas.drot[i])

N:5
X:(0.3*mkvec[20;N];1)

Oprint "X = ",Ovec[," ";1;X 0],";"

R:0 1*X
i:(N;X;R)
Kprint (`dcopy;r:kblas.dcopy[(N;X;R)])
/ r~X[0]

XZ:(0.3*mkvec[20;N*2];1)

Oprint "XZ = ",Ovec[," ";2;XZ 0],";"

R:0 1*XZ
j:(N;XZ;R)
Kprint (`zcopy;r:kblas.zcopy[j])
/ r~XZ[0]

Y:(0.3*mkvec[20;N];1)
YZ:(0.3*mkvec[20;N*2];1)

Oprint "Y = ",Ovec["; ";1;Y 0],";"
Oprint "YZ = ",Ovec["; ";2;YZ 0],";"
Oprint "X*Y"
Oprint "XZ*YZ"
Oprint "XZ*conj(YZ)"

i:(N;X;Y);j:(N;XZ;YZ)

Kprint (`ddot;kblas.ddot[i])
Kprint (`"zdotu_sub";kblas.zdotusub[j])
Kprint (`"zdotc_sub";kblas.zdotcsub[j])

Oprint "sqrt(X*X')"
Oprint "sqrt(XZ*XZ')"

i:(N;X);j:(N;XZ)
Kprint (`dnrm2;kblas.dnrm2[i])
Kprint (`dznrm2;kblas.dznrm2[j])

i:(N;X;Y);j:(N;XZ;YZ)
Kprint (`dswap;kblas.dswap[i])
Kprint (`zswap;kblas.zswap[j])

Kprint (`drotmg;kblas.drotmg[p])


/ Level 2
ROWMAJOR:  101
COLMAJOR:  102
NOXPOS:    111
XPOS:      112
CONJXPOS:  113
ATLASXPOS: 114
UPPER:     121
LOWER:     122
NONUNIT:   131
UNIT:      132
LEFT:      141
RIGHT:     142

sA:3 4
A:(1.0*mkmtx[10;sA];sA 1)
X:(1.0*mkvec[10;sA 1];1)
Y:(1.0*mkvec[10;sA 0];1)
a:1.0
b:2.0

Oprint "A = ",Omat["; ";1;A 0],";"
Oprint "X = ",Ovec["; ";1;X 0],";"
Oprint "Y = ",Ovec["; ";1;Y 0],";"
Oprint "a = ",Ovec[," ";1;a],"(1);"
Oprint "b = ",Ovec[," ";1;b],"(1);"
Oprint "a*A*X+b*Y"

i:(ROWMAJOR;NOXPOS;sA 0;sA 1;a;flat A;X;b;Y)
Kprint (`dgemv;kblas.dgemv[i])

Ai:(1.0*mkmtx[10;sA];sA 1)
Xi:(1.0*mkvec[10;sA 1];1)
Yi:(1.0*mkvec[10;sA 0];1)
AZ:(,''/*'(A;Ai);sA 1)
XZ:(,/,'/*'(X;Xi);1)
YZ:(,/,'/*'(Y;Yi);1)
az:1.0 0
bz:1.0 0

Oprint "AZ = ",Omat["; ";2;,/'AZ 0],";"
Oprint "XZ = ",Ovec["; ";2;XZ 0],";"
Oprint "YZ = ",Ovec["; ";2;YZ 0],";"
Oprint "az*AZ*XZ+bz*YZ"

j:(ROWMAJOR;NOXPOS;sA 0;sA 1;az;flat AZ;XZ;1.0*bz;YZ)
Kprint (`zgemv;r:kblas.zgemv[j])
shw 0N 2#r

sA:5 8
A:(1.0*mkmtx[10;sA];sA 1)
X:(1.0*mkvec[10;sA 1];1)
Y:(1.0*mkvec[10;sA 0];1)
K:2
L:1
B:(1.0*b0;*|sh b0:band[K;L]A 0)

Oprint "A = ",Omat["; ";1;A 0],";"
Oprint "X = ",Ovec["; ";1;X 0],";"
Oprint "Y = ",Ovec["; ";1;Y 0],";"
Oprint "K = ",Ovec[," ";1;K],"(1)",";"
Oprint "L = ",Ovec[," ";1;L],"(1)",";"
Oprint "B = ",Omat["; ";1;B 0],";"
Oprint "Ab = A*0;                       %%% generate banded matrix %%%"
Oprint "Ab(1,1:2) = B(1,3:4);"
Oprint "Ab(2,1:3) = B(2,2:4);"
Oprint "Ab(3,1:4) = B(3,1:4);"
Oprint "Ab(4,2:5) = B(4,1:4);"
Oprint "Ab(5,3:6) = B(5,1:4);"
Oprint "a*Ab*X+b*Y"

i:(ROWMAJOR;NOXPOS;sA 0;sA 1;K;L;a;flat B;X;b;Y)
Kprint (`dgbmv;kblas.dgbmv[i])

Oprint "a*Y*X'+A"

i:(ROWMAJOR;sA 0;sA 1;a;Y;X;flat A)
Kprint(`dger;r:kblas.dger[i])
shw sA#r

Ai:(1.0*mkmtx[10;sA];sA 1)
Xi:(1.0*mkvec[10;sA 1];1)
Yi:(1.0*mkvec[10;sA 0];1)
AZ:(,''/*'(A;Ai);sA 1)
XZ:(,/,'/*'(X;Xi);1)
YZ:(,/,'/*'(Y;Yi);1)

Oprint "AZ = ",Omat["; ";2;,/'AZ 0],";"
Oprint "XZ = ",Ovec["; ";2;XZ 0],";"
Oprint "YZ = ",Ovec["; ";2;YZ 0],";"

Oprint "RZ = az*YZ*XZ'+AZ"

j:(ROWMAJOR;sA 0;sA 1;az;YZ;XZ;flat AZ)
Kprint (`zgerc;r:kblas.zgerc[j])
shw'sA#/:+0N 2#r;

Oprint "RZ = az*YZ*XZ.'+AZ"

j:(ROWMAJOR;sA 0;sA 1;az;YZ;XZ;flat AZ)
Kprint (`zgeru;r:kblas.zgeru[j])
shw'sA#/:+0N 2#r;

N:7
Hr:(mksym[1;10;N];N)
Hi:(mksym[-1;10;N]*~=N;N)
X:(1.0*mkvec[10;N];1)
Xi:(1.0*mkvec[10;N];1)
Y:(1.0*mkvec[10;N];1)
Yi:(1.0*mkvec[10;N];1)
H:(1.0*,''/*'(Hr;Hi);N)
XZ:(1.0*,/,'/*'(X;Xi);1)
YZ:(1.0*,/,'/*'(Y;Yi);1)

Oprint "H = ",Omat["; ";2;,/'H 0],";"
Oprint "XZ = ",Ovec["; ";2;XZ 0],";"
Oprint "YZ = ",Ovec["; ";2;YZ 0],";"
Oprint "az*H*XZ+bz*YZ"

j:(ROWMAJOR;UPPER;N;az;flat H;XZ;bz;YZ)
Kprint (`zhemv;r:kblas.zhemv[j])
shw 0N 2#r

BH:(1.0*b0;*|-1_sh b0:band[0;K]H 0)

Oprint "BH = ",Omat["; ";2;,/'BH 0],";"
Oprint "Hb = H*0;                       %%% generate banded matrix %%%"
Oprint "Hb(1,1:3) = BH(1,1:3);"
Oprint "Hb(2,2:4) = BH(2,1:3);"
Oprint "Hb(3,3:5) = BH(3,1:3);"
Oprint "Hb(4,4:6) = BH(4,1:3);"
Oprint "Hb(5,5:7) = BH(5,1:3);"
Oprint "Hb(6,6:7) = BH(6,1:2);"
Oprint "Hb(7,7:7) = BH(7,1:1);"
Oprint "TZb = Hb;"
Oprint "Hb = Hb + Hb' - eye(7).*diag(Hb);"
Oprint "RZ = az*Hb*XZ+bz*YZ"

j:(ROWMAJOR;UPPER;N;K;az;flat BH;XZ;bz;YZ)
Kprint (`zhbmv;r:kblas.zhbmv[j])
shw 0N 2#r

Oprint "RZ = a*XZ*XZ'+H"

j:(ROWMAJOR;UPPER;N;a;XZ;flat H)
Kprint (`zher;r:kblas.zher[j])
shw'sA#/:+0N 2#r;

Oprint "r = YZ*(az*XZ)';"
Oprint "RZ = r + r' + H"

j:(ROWMAJOR;UPPER;N;az;XZ;YZ;flat H)
Kprint (`zher2;r:kblas.zher2[j])
shw'sA#/:+0N 2#r;

HP:,/(,/H 0)@w:&,/|\'=#H 0
j:(ROWMAJOR;UPPER;N;az;HP;XZ;bz;YZ)
Kprint (`zhpmv;r:kblas.zhpmv[j])
shw 0N 2#r

j:(ROWMAJOR;UPPER;N;a;XZ;HP)
Kprint (`zhpr;r:kblas.zhpr[j])
shw'(-2_+\0,|!N+1)_/:+0N 2#r;

j:(ROWMAJOR;UPPER;N;az;XZ;YZ;HP)
Kprint (`zhpr2;r:kblas.zhpr2[j])
shw'(-2_+\0,|!N+1)_/:+0N 2#r;

S:(1.0*mksym[1;10;N];N)
B:(1.0*b0;*|sh b0:band[K;0]S 0)
X:(1.0*mkvec[10;N];1)
Y:(1.0*mkvec[10;N];1)

Oprint "B = ",Omat["; ";1;,/'B 0],";"
Oprint "X = ",Ovec["; ";1;X 0],";"
Oprint "Y = ",Ovec["; ";1;Y 0],";"

Oprint "clear Sb;                       %%% generate banded matrix %%%"
Oprint "Sb(1,1)=B(1,3);"
Oprint "Sb(2,1:2)=B(2,2:3);"
Oprint "Sb(3,1:3)=B(3,1:3);"
Oprint "Sb(4,2:4)=B(4,1:3);"
Oprint "Sb(5,3:5)=B(5,1:3);"
Oprint "Sb(6,4:6)=B(6,1:3);"
Oprint "Sb(7,5:7)=B(7,1:3);"
Oprint "Tb = Sb;"
Oprint "Sb = Sb + Sb' - eye(7) .* diag(Sb);"
Oprint "a*Sb*X+b*Y"

i:(ROWMAJOR;LOWER;N;K;a;flat B;X;b;Y)
Kprint (`dsbmv;kblas.dsbmv[i])

S:(1.0*mksym[1;10;N];N)
SP:(,/S 0)@&,/|\=#S 0

Oprint "S = ",Omat["; ";1;S 0],";"
Oprint "a*S*X+b*Y"

i:(ROWMAJOR;LOWER;N;a;SP;X;b;Y)
Kprint (`dspmv;kblas.dspmv[i])

Oprint "a*X*X'+S"

i:(ROWMAJOR;LOWER;N;1.0;X;SP)
Kprint (`dspr;r:kblas.dspr[i])
shw (-1_+\0,!N+1)_r;

Oprint "r=a*X*Y';",";"
Oprint "r + r' + S"

i:(ROWMAJOR;LOWER;N;a;X;Y;SP)
Kprint (`dspr2;r:kblas.dspr2[i])
shw (-1_+\0,!N+1)_r;

Oprint "Tb",";"
Oprint "Tb*X"

i:(ROWMAJOR;LOWER;NOXPOS;NONUNIT;N;K;flat B;X)
Kprint (`dtbmv;kblas.dtbmv[i])

Oprint "TZb",";"
Oprint "TZb*XZ"

j:(ROWMAJOR;UPPER;NOXPOS;NONUNIT;N;K;flat BH;XZ)
Kprint (`ztbmv;kblas.ztbmv[j])

i:(ROWMAJOR;LOWER;NOXPOS;NONUNIT;N;K;flat B;X)
Kprint (`dtbsv;r:kblas.dtbsv[i])
shw 0N 2#rnd r;

j:(ROWMAJOR;UPPER;NOXPOS;NONUNIT;N;K;flat BH;XZ)
Kprint (`ztbsv;r:kblas.ztbsv[j])
shw 0N 2#rnd r;

Oprint "tril(S) * X"

i:(ROWMAJOR;LOWER;NOXPOS;NONUNIT;N;SP;X)
Kprint (`dtpmv;kblas.dtpmv[i])

TH:(H[0]*|\=#H 0;N)
TP:(,/TH 0)@&,/|\=#TH 0

Oprint "tril(H) * XZ"

j:(ROWMAJOR;LOWER;NOXPOS;NONUNIT;N;,//TP;XZ)
Kprint (`ztpmv;r:kblas.ztpmv[j])
shw 0N 2#r;

Oprint "tril(S) \\ X"

i:(ROWMAJOR;LOWER;NOXPOS;NONUNIT;N;SP;X)
Kprint (`dtpsv;r:kblas.dtpsv[i])
shw 0N 2#rnd r;

Oprint "tril(H) \\ XZ"

j:(ROWMAJOR;LOWER;NOXPOS;NONUNIT;N;,//TP;XZ)
Kprint (`ztpsv;r:kblas.ztpsv[j])
shw 0N 2#rnd r;

T:(S[0]*|\=#S 0;N)

Oprint "tril(S)*X"

i:(ROWMAJOR;LOWER;NOXPOS;NONUNIT;N;flat T;X)
Kprint (`dtrmv;kblas.dtrmv[i])

Oprint "tril(H)*XZ"

j:(ROWMAJOR;LOWER;NOXPOS;NONUNIT;N;flat TH;XZ)
Kprint (`ztrmv;r:kblas.ztrmv[j])
shw 0N 2#r;

Oprint "tril(S) \\ X"

i:(ROWMAJOR;LOWER;NOXPOS;NONUNIT;N;flat T;X)
Kprint (`dtrsv;rnd kblas.dtrsv[i])

Oprint "tril(H) \\ XZ"

j:(ROWMAJOR;LOWER;NOXPOS;NONUNIT;N;flat TH;XZ)
Kprint (`ztrsv;r:kblas.ztrsv[j])
shw 0N 2#rnd r;

sA:5 7
sB:7 3
A:(1.0*mkmtx[10;sA];sA 1)
B:(1.0*mkmtx[10;sB];sB 1)

sC:?[sA,sB;1 3;!0]
C:(sC#0.0+&*/sC;sC 1)

Oprint "A = ",Omat["; ";1;A 0],";"
Oprint "B = ",Omat["; ";1;B 0],";"
Oprint "C = ",Omat["; ";1;C 0],";"
Oprint "a*A*B+b*C"

i:(ROWMAJOR;NOXPOS;NOXPOS;sA 0;sB 1;sA 1;a;flat A;flat B;b;flat C)
Kprint (`dgemm;r:kblas.dgemm[i])
shw sC#r;

Ai:(1.0*mkmtx[10;sA];sA 1)
Bi:(1.0*mkmtx[10;sB];sB 1)
Ci:(sC#0.0+&*/sC;sC 1)
AZ:(,''/*'(A;Ai);sA 1)
BZ:(,''/*'(B;Bi);sB 1)
CZ:(,''/*'(C;Ci);sC 1)

Oprint "Ai = ",Omat["; ";1;Ai 0],";"
Oprint "Bi = ",Omat["; ";1;Bi 0],";"
Oprint "Ci = ",Omat["; ";1;Ci 0],";"
Oprint "AZ = A+i*Ai;"
Oprint "BZ = B+i*Bi;"
Oprint "CZ = C+i*Ci;"
Oprint "RZ = az*AZ*BZ+bz*CZ"

j:(ROWMAJOR;NOXPOS;NOXPOS;sA 0;sB 1;sA 1;az;flat AZ;flat BZ;bz;flat CZ)
Kprint (`zgemm;r:kblas.zgemm[j])
shw'sC#/:+0N 2#r;

Oprint "RZ = az*H*BZ"

j:(ROWMAJOR;LEFT;UPPER;sB 0;sB 1;az;flat H;flat BZ;bz;@[flat BZ;0;0.0*])
Kprint (`zhemm;r:kblas.zhemm[j])
shw'sB#/:+0N 2#r;

Oprint "RZ = az*AZ*H"

j:(ROWMAJOR;RIGHT;UPPER;sA 0;sA 1;az;flat H;flat AZ;bz;@[flat AZ;0;0.0*])
Kprint (`zhemm;r:kblas.zhemm[j])
shw'sA#/:+0N 2#r;

Oprint "RZ = a*AZ'*AZ+b*H"
j:(ROWMAJOR;UPPER;CONJXPOS;N;sA 0;a;flat AZ;b;flat H)
Kprint (`zherk;r:kblas.zherk[j])
shw'(0N;N)#/:+0N 2#r;

sC:sA
C:(1.0*mkmtx[10;sC];sC 1)
Ci:(1.0*mkmtx[10;sC];sC 1)
CZ:(,''/*'(C;Ci);sC 1)

Oprint "clear C;"
Oprint "C = ",Omat["; ";1;C 0],";"
Oprint "Ci = ",Omat["; ";1;Ci 0],";"
Oprint "CZ = C+i*Ci;"
Oprint "r = a*AZ'*CZ;"
Oprint "RZ = r + r' + bz*H"

i:(ROWMAJOR;UPPER;CONJXPOS;N;sC 1;az;flat AZ;flat CZ;bz;flat H)
Kprint (`zher2k;r:kblas.zher2k[i])
shw'(0N;N)#/:+0N 2#r;

Oprint "RZ = a*A*S"

i:(ROWMAJOR;RIGHT;UPPER;sA 0;sA 1;a;flat S;flat A;b;@[flat A;0;0.0*])
Kprint (`dsymm;r:kblas.dsymm[i])
shw sA#r;

Oprint "SZ = triu(H) + triu(H,1).';"
Oprint "RZ = az*AZ*SZ"

i:(ROWMAJOR;RIGHT;UPPER;sA 0;sA 1;a;flat S;flat A;b;@[flat A;0;0.0*])
Kprint (`dsymm;r:kblas.dsymm[i])
shw sA#r;

Oprint "R = a*A'*A + b*S"

i:(ROWMAJOR;UPPER;XPOS;sA 1;sA 0;a;flat A;b;flat S)
Kprint (`dsyrk;r:kblas.dsyrk[i])
shw (0N;N)#r;

Oprint "RZ = az*AZ.'*AZ+bz*SZ"

j:(ROWMAJOR;UPPER;XPOS;sA 1;sA 0;az;flat AZ;bz;flat H)
Kprint (`zsyrk;r:kblas.zsyrk[j])
shw'(0N;N)#/:+0N 2#r;

i:(ROWMAJOR;UPPER;XPOS;N;sA 0;a;flat A;flat C;b;flat S)
Kprint (`dsyr2k;r:kblas.dsyr2k[i])
shw (0N;N)#r;

Oprint "r = a*AZ.'*CZ;"
Oprint "RZ = r + r.' + bz*SZ"

j:(ROWMAJOR;UPPER;XPOS;N;sA 0;az;flat AZ;flat CZ;bz;flat H)
Kprint (`zsyr2k;r:kblas.zsyr2k[j])
shw'(0N;N)#/:+0N 2#r;

Oprint "R = a*A*tril(S)"

i:(ROWMAJOR;RIGHT;LOWER;NOXPOS;NONUNIT;sA 0;sA 1;a;flat S;flat A)
Kprint (`dtrmm;r:kblas.dtrmm[i])
shw sA#r;

Oprint "R = az*AZ*tril(H)"

j:(ROWMAJOR;RIGHT;LOWER;NOXPOS;NONUNIT;sA 0;sA 1;az;flat H;flat AZ)
Kprint (`ztrmm;r:kblas.ztrmm[j])
shw'sA#/:+0N 2#r;

Oprint "R = (a*tril(S) \\ A')'"

i:(ROWMAJOR;RIGHT;LOWER;XPOS;NONUNIT;sA 0;sA 1;a;flat S;flat A)
Kprint (`dtrsm;r:kblas.dtrsm[i])
shw sA#rnd r;

Oprint "RZ = (az*tril(SZ) \\ AZ')'"

j:(ROWMAJOR;RIGHT;LOWER;XPOS;NONUNIT;sA 0;sA 1;az;flat H;flat AZ)
Kprint (`ztrsm;r:kblas.ztrsm[j])
shw'sA#/:+0N 2#rnd r;
