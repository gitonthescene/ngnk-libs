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

/ unsigned addition with given base
addb:{(&\~:)_|add0[x]pad[y;z]}

/ unsigned addition
/add:{(&\~:)_|add0[128]pad[x;y]}
add:addb[128]

/ signed addition
adds:{r:|add0[128]pads[x;y]
  $[=/s:~64>*'(x;y)
    (((*s)=64>*r)#(0 127@*s)),r:(*s)_r
    _/|1(0 0~@[;!2]@)\(64>*r)_r]}

/ unsigned multiplication
mul:{{add/(x,0;y)}/@[&1+|/i;i:+/!#'x;add;,/*\:/x:(x;y)]}

/ unsigned subtraction using signed addition
sub:{(x;y):,'/|1(#\:/|0,,~64>*:')\(x;y);(&\~:)_adds[x;neg y]}

dm0:{2#(#*|:){(i;p;d):y
  $[(~#p)&(~c:-/#'h)&j:*<h:(x[i];*d)
     (i;p;(*d;!0),'(0,1)_*|d)
    (0>c)|(~c)&~j
     (i+1;x[i];d)
    (i;(sub[*d;p]),*|d;())]}[y]/(0;!0;(0,#*y)_z)}

divmod:{{$[*<+|1#:'\(*x;*|y);y;(*y;!0),'dm0[128;x;*|y]]}[x]/(!0;y)}

// Faster, but does most math in host K and so has limits.

\d fast
pad:{0^x@\:!|/#:'x:|'(!0),/:(x;y)}
str:,/|1(&~#:)\(&\~:)_
car:{str{(x\z+*y),1_y}[0,x]/[,0;y]}

add:car[128]@+/pad@
mul0:{@[&1+m;(m:|/i)-i:+/!#'x;+;,/*\:/x:(x;y)]}
mul:{car[128]mul0[x;y]}
\d .
