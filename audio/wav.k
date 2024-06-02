/ [[https://www.mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html]]
\l riff.k

/ pi continued fraction A001203
pcf:.'", "\"3, 7, 15, 1, 292, 1, 1, 1, 2, 1, 3, 1, 14, 2, 1, 1, 2, 2, 2, 2, 1, 84, 2, 1, 1, 15, 3, 13, 1, 4, 2, 6, 6, 99, 1, 2, 2, 6, 3, 5, 1, 1, 6, 8, 1, 7, 1, 2, 3, 7, 1, 2, 1, 1, 12, 1, 1, 1, 3, 1, 1, 8, 1, 1, 2, 1, 6, 1, 1, 5, 2, 2, 3, 1, 2, 4, 4, 16, 1, 161, 45, 1, 22, 1, 2, 2, 1, 4, 1, 2, 24, 1, 2, 1, 3, 1, 2, 1"
pi:{y+1%x}/|pcf
pi2:2*pi

fspec:`t`nc`ss`abs`ba`bs`es`vb`cm`sf!2 2 4 4 2 2 2 2 4 16
fmt:{((#r)#!fspec)!r:256/'256!|'-1_(<[#x;]_+\0,.fspec)_x}
prsfmt:{((#c)#!fspec)!256/'256!|'(c:0,((#x)>)#+\.fspec)_x}

pcm:{[c;r;l]`t`nc`ss`abs`ba`bs!(1;c;r;r*l*c;l*c;8*l)}
mkfmt:{mkchnk["fmt ";,/(256+&'fspec@!v){|`c$x\y}'v:(^:)_k!x@k:!fspec]}

alaw:{s:1 -1@0>y;s*$[1>r:s*y*x;r;1+`ln r]%1+`ln x}o
alawinv:{s:1 -1@0>y;a:1+`ln x;s*$[1>r:s*y*a;r;`exp@-1+r]%x}

apo:{@[y;+i;*;%[;s]@*i:1((#y)-1+)\!s:_x*#y]}

sin:{[f;a;s;t]a*`sin s+pi2*f*t}  / [HZ;AMP;off;ts]
cos:{[f;a;s;t]a*`cos s+pi2*f*t}  / [HZ;AMP;off;ts]

qnt:{_x*y+~x>128}                / [rng;ys] quantization
ph:{(!_x*y)%x}                   / [FR;dur] phases
nrm:{x*y%|/{x|-x}(|/;&/)@\:y}
ser:{,/+|`c$(x#256)\y}           / [WIDTH;qnt data] serialize


/ [[https://en.wikipedia.org/wiki/Equal_temperament]]
note:{`exp y*(`ln 2)%x}

/
  sw:,/440#,_128*`sin@(2*pi*!50)%50
  mkchnk["RIFF"]@,/("WAVE";mkfmt pcm[1;22000;1];mkchnk["data";`c$sw])
