red:,/|1{$[(~64 127'*x)|(~#x);0;!0]}\(&\~:)_

leb80:{`c$|+/1(128*&1,-1+#:)\x}

/ unsigned leb8
leb8:{leb80[128\x]}
unleb8:|+/1(128*0>)\0+

/ signed leb8
leb8s:{leb80 red[128\x]}

/ unsigned padding
pad:{0^@\:/1(!|/#:')\|:'(!0),/:(x;y)}

/ signed padding
pads:{(127 0@64>*p[~i])^(|'p)@\:!s@i:*>s:#'p:(!0),/:(x;y)}
neg:{red$[64>*x;add[1;127-x];127-add[-1;x]]}

add0:{,/(::;|x\)@'{(r;c):y;(c;d):(0;x)\+/c,z;(r,d;c)}[x]/[(!0;0);+y]}

/ unsigned addition
addb:{(&\~:)_|add0[x]pad[y;z]}
add:{(&\~:)_|add0[128]pad[x;y]}

/ signed addition
adds:{red@_/|1(1=*:)\|add0[128]pads[x;y]}

/ unsigned multiplication
mul:{{add/(x,0;y)}/.(add/{$[1=#x;++(0,x);x]}@+128\)'(,/*/:/d0)@=+/!#'d0:|'pad[x;y]}
