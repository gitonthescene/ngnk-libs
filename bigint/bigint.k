red:{f:0 127@x;,/|1(#/|f,x=64>*:)\(&\f=)_y}

leb80:{`c$|+/1(128*&1,-1+#:)\x}

/ unsigned leb8
leb8:{leb80[128\x]}
unleb8:|+/1(128*0>)\0+

/ signed leb8
leb8s:{s:x<0;leb80 red[s]((::;neg)s)[128\(1 -1s)*x]}

/ unsigned padding
pad:{0^@\:/1(!|/#:')\|:'(!0),/:(x;y)}

/ signed padding
pads:{(127 0@64>*p[~i])^(|'p)@\:!s@i:*>s:#'p:(!0),/:(x;y)}

neg:{$[64>*x;add[1;127-x];127-add[-1;x]]}

add0:{,/(::;|x\)@'{(r;c):y;(c;d):(0;x)\+/c,z;(r,d;c)}[x]/[(!0;0);+y]}
addb:{(&\~:)_|add0[x]pad[y;z]}

/ unsigned addition
add:{(&\~:)_|add0[128]pad[x;y]}

/ signed addition
adds:{(|/~64>*'(x;y))_|add0[128]pads[x;y]}

/ unsigned multiplication
mul:{{add/(x,0;y)}/@[&1+|/i;i:+/!#'x;add;,/*\:/x:(x;y)]}
