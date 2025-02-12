/ More info on BST's [[https://adtinfo.org]]

e:(,0N)!,!0

ch:{$[z~r:c@*y@x[1] c:x[0;z],z;0N;r]}   / (lf;rg):ch[(^'[;?p]@=p;n)]@/:(<:;>:)
btm:{*|(~^*:){x[y],y:*y}[x]/(y,0N)}     / nxt:btm[lf]rg@
gt:{[p;n]{z,,/o[x;y]'@/1(<x@)\y z}[n;(=0N,1_p),(,0N)!,!0;0]}

noreb:{y;x}
avlreb:{rot[x;*{(~^i)&</-1 2>\:*bal[x;i:*y]}[x](1_)/y]}
reb:noreb

/ x:(d;p;n;h) y:item z:roots -> insertion index
insi:{$[(l:y<x[2;*z])&~^c:ch[x 0 2;<:;*z];o[x;y;c,z]
        l|~1=#c:^[x[0;*z];c,*z];z
        o[x;y;c,z]]}

ins:{r:@[x;1+!3;,;(+/*i:insi[x;y;,0];y;0)]
     reb[@[r;0 1 3;:;(@[r 0;*i;(0=)_,;#x[1]];@[r 1;0;:;0N];@[r 3;i;|;1+!#i])];i]}

del0:{@[x;1 3;:;(@[x 1;y;:;-1]
                 x[3]{@[y;z;:;1+|/-1,y x z]}[x 0]/(^:)_(x[1]@)\x[1]y)]}
del1:{xx:@[x;!2;:;(@[x 0;x[1]y;,;*c]
                   @[x 1;y,*c:x[0;y];:;-1,x[1]y])]
       @[xx;3;:;x[3]{@[y;z;:;1+|/-1,y x[z]^z]}[xx 0]/(^:)_(x[1]@)\y]}
del2:{(lf;rg):ch[x 0 2]@/:(<:;>:)
      x:@[x;2;:;@[x 2;i;:;x[2]@|i:y,s:btm[lf]rg y]]
      x:@[x;0;:;@[@[x 0;x[1]y;,;y];x[1]s;^;s]]
      (del0;del1)[#x[0;s]][x;s]}

del:{x:@[x;0;:;@[x 0;x[1]y;^;y]]
     x:(del0;del1;del2)[#x[0;y]][x;y]
     x:@[x;1+!3;:;(-+/d)_/:((<g)@;::;::)@'x[1+!3]@\:g:<d:(~^x 1)&0>x 1]
     @[x;0;:;(!/(<g)(!x[0];.x[0]))_#x[1]]}

rot0:{xx:@[x;0 1;:
      (@[@[x 0;(#x 1)^x[1]y;^;y];(#x 1;#x 1;y 1)^'x[1]y;(^:)_,;(y 1;y 2;y 0)]_#x 1
       -1_@[x[1],0N;^[#x 1;y];:;(y 1;x[1]y 0;y 0)])]
       @[xx;3;:;xx[3]{@[y;z;:;1+|/-1,y x[z]^z]}[xx 0]/(^:)_(xx[1]@)\y 0]}

swp:{@[x;0 1;:;(@[@[x 0;x[1]y;^;y];(#x 1)^x[1]y;,;|y]_#x 1
                @[x 1;x[0;y]^y;:;|y])]{@[x;|y;:;x y]}\:y}

rot:{$[</-1 2>\:*b:bal[x;y];:x;]
  (lf;rg):ch[x 0 2]@/:(<:;>:);
  $[~h=/1 0=0<bal[x;c:@[(lf;rg);h:=/1 0=b>0]y]
      (c;x):(is[1];rot0[x;is:{y x}\c,(lf;rg)@1~:\~h]);]
  $[~y;(x;y):(swp[x;y,c];c);]
  rot0[x;{y x}\y,ch[x 0 2]@/:(<:;>:)@1~:\h]}

bal:{-/+(-1^x[3]@cd@!2;x[2]@y,*cd:x[0;y]^y)} / bal[bst;ix;] -> (heavy;side)

