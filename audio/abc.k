/  ABC music notation [[https://abcnotation.com/wiki/abc:standard:v2.1]]
/ [[https://michaeleskin.com/abctools/userguide.html]]

/t:"C,^a2/3(3__d>G'=Z4c''A128e//f/3"
is:{&(x="z")|~0 8'-"a"-x:_x}                                               / index of base note
ns:{-1_*/1(,[;0]1_<':)\0{(1&y)*y+10*x}\*/1(~0 10')\-"0"-x,"0"}             / calculated numbers
tk:{-/|(::;n@)@'(.w)*'/:1~:\~n@w:w@=x'w:@/1<:\(&1&n:ns z),(&|/y=\:z)}
ds:{w:is[x]; $[~#d:tk[w;"(/<>";x];:1.0+&#w;]
    r:+{$[1=c:+/&\"/"=x@-y;(1%+/(y[1];2)*1~:\0<y 1;1+0<y 1)
       (0=c)&0>*y;(1.0;0)
       c>1;(1%c(2*)/1;c)
       ("/"~x@-y 1)&/0<y[0 2];(%/y[0 2];3)
       0<*y;(*y;1)
       (1.0;0)]}[x]'d
     b:{$[^"<>"?*b:(&\(=':).|1*:\)#x@-y;0N;(1(2-)\1%(#b)(2*)/1)1~:\">"=*b]}[x]'r[1]_'.d
     {$[0N~z;x;@[x;y+!2;:;x[y]*z]]}/[@[1.0+&#w;!r;:;.r:r 0];!b;.b]}
os:{(=/1_:\x@w)+@[&#x;&|~c;:;|-':(+\c)@&~c:|-/"',"=\:x]@w:is[x]}           / register of base note
as:{(-/1(~^:)\"_=^"?*a;2*=/a:x@is[x]-/:1 2)}                               / accidentals

td:2 3 4 5 6 7 8 9!3 2 3 2 2 2 3 2
tpl:{d:{(0N;td[r 0];r 0)^'r:@[;!3]@*'1_'_/|1(0,&":"=x@-:)\1,y}[x]'tk[w:&"("=x;,":";x]
     $[~#w;:1.0+&#is[x];]
     a:+,/'.((,'=(w@!d)'i:is[x])_-1;(%/|:)''0 2_/:d)
     {[d;i;r;c]@[d;(c&#i)#i;*;r]}/[1.0+&#i;;;].a}
/ds t
key:0 2 3 5 7 8 10
scale:0 2 2 1 2 2 2
range:"cdefgab"
sig:{r:-/(y+key[b]+\scale;12/(::;key@)@'g:7 7\(!7)+b:range?x);r@<*|g}  / adjustments to notes by key signature

mel:{s:sig.(x);(n;m):1(~^:)\key@b:range?_y@is[y];a:*as[y]              / calculate melody from notes,
     n+m*(12*os[y])+0^{x,z^y+y*y*z}/[();*as[y];s@b]}                   /   accidentals and signature

/ Plenty of room for nonsensical input.
