/  ABC music notation [[https://abcnotation.com/wiki/abc:standard:v2.1]]

/t:"C,^a2/3(3__d>G'=Z4c''A128e//f/3"
is:{&(x="z")|~0 8'-"a"-x:_x}                                               / index of base note
ns:{-1_*/1(,[;0]1_<':)\0{(1&y)*y+10*x}\*/1(~0 10')\-"0"-x,"0"}             / calculated numbers
ds:{w:is[x]; d:-/1(d*~:)\n@ww@d:=w'ww:@/1<:\(&1&n:ns[x]),&c:|/"(/<>"=\:x   / base durations
    r:{$[1=c:+/&\"/"=x@y@-z;1%2^z@1
       (0=c)&0>*z;1.0
       c>1;1%c(2*)/1
       ("/"~x@y@-z 1)&/0<z[0 2];%/z[0 2]
       *z]}[x;ww]'d
     b:{$[^"<>"?*b:(&\(=':).|1*:\)#x@y@-z;0N;(1(1+)\1%(#b)(2*)/1)1~:\">"=*b]}[x;ww]'d
     {$[0N~z;x;@[x;y+!2;:;x[y]* \z]]}/[r:@[1.0+&#w;!r;:;.r];!b;.b]}
os:{(=/1_:\x@w)+@[&#x;&|~c;:;|-':(+\c)@&~c:|-/"',"=\:x]@w:is[x]}           / register of base note
as:{+("^=_"?*a;2*=/a:x@is[x]-/:1 2)}                                       / accidentals

/ds t

mel:{+/(1;12*os[x])*1(~^:)\0 2 3 5 7 8 10"abcdefg"?_x@is[x]}

/ Broken rhythm still a bit hack.  Only works with base duration.  Should probably pop consumed symbols.
/ Plenty of room for nonsensical input.