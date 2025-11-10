/ Inspired by [[https://codeberg.org/effbiae/earley/src/branch/main]]
/ Well written tutorial here: [[https://loup-vaillant.fr/tutorials/earley-parsing/]]
imp.ort[`avl;"trees/bst.k"]

/ Earley item: (rule; dot position; origin; id)
empty:3#,!0
data0:{(r;,'/{@''['''(),/:/:~^d;0+(x;y);-:1+d:(?x)?(x;y)]}/r:+,/+'((*:;1_"|"\"|",)@'":"\)'" "\x)}
data1:{((*'x;1_/:x);x)}
data:{(r;R):$[`C~@x;data0[x];data1[x]]
     r:`p`t`T`i!(+\0,#'R;,/R;,'/r;(0+y),0N+1)
     @[r;`B;:;0,1+(#r`p;|/-':r`p;#r`i)]}

pred:{[d;s;c;t]w:&(-1_d[`t]d[`p])=/:?c;(s;++(*|w;0;s+&#*w);#[*w]#,())}
scan:{[d;s;c;t]w:&d[`i;s]=/:c;(s+1;@[3#t[s]@\:w;1;+;1];,'s,/:w)}
comp:{[d;s;c;t]$[~#c:&^c;:(s;empty;!0);]
      f:(f@;::)@'w:&(d[`t;d[`p;t[s;0;c]]])=t[;4]f:t[s;2;c]
      (s;{[x;y;z;w]y,'@[3#x[z;;w];1;+;1]}[t]/[empty].f;+(+f;s,/:c@w 0))}

ins:{{e:x[1 2];r:avl.ins[<;*x;y,z];(,r[0]),e,'r[1 2]}/[(x;!0;!0);y;0]}  / [tree0;ids]                -> (where ins;tree1)
add:{[d;a;t;n](a;k;w):ins[a;i:d[`B]/,/n[0 1]]                           / [dta;tree0;tbl0;(s;new;a)] -> (dta;tree1;tbl1)
     j:@[d[`t]j;&d[`p;1+n[1;0]]=j:1+n[1;1]+d[`p;n[1;0]];:;0N]
     t:.[t;n 0;,';:[;w]#/:n[1],(i;j;#[#i;,()])]
     a:.[a;(1;k@&w);:;#[t[s:n 0;0]]+!-+/w]
     t:.[t;(s;5;a[1;k]);?,;,'n 2]
     (+/w;(d;a;t))}
stp:{(d;a;y):y;add[d;a;y;z[d;x;y[x;4];y]]}

rec0:{{#**|x 2}{s:*|x:$[n:#**|x 2;x[0 1],(x[2],,6#,();1+x 3);:x]
      ,[*|{*x}{(0;y 1){c:y[0];r:stp[x;y[1];z];(c+r 0;r 1)}[x]/(pred;scan;comp)}[s]/(-1;3#x);s]}/(x,-1)}
rec1:{s:++(&=/1*:\x[`t]x`p;0;0)
      rec0@*|add[x;avl.e;,6#,();(0;s;#[*s]#,())]}

rec:{-1_rec1 data[x;y]}

cmp:{[d;t]w:&~t[lst:-2+#t;2];lst,/:w@&{&/(*[x[`t]]=x[`t]r;=/(1+z+r:x[`p]y;x[`p]y+1))}[d]/t[lst;0 1;w]}

shw:{?[?[x[`T]y 0;1;":"],"/";2+y 1;"."],$y 2}

c1:{$[~#z 1;:z;];(,h;r):0 1_z 1;c:y h 0;$[1<#c;(,,/*'x[y]'(,,z[0;0],*|h),/:,'[,'c],\:r),,();~#c 0;(,z[0;0],*|h;r);(,z[0;0],*|h;c,r)]}
c:{|'1_/:*{c1[o;x]/y}[x](,();,2#y)}

trs1:{$[~#z 1;:z;];(,h;r):0 1_z 1;n:(,,z[0;0],'h),/:,'(y[h 0],\:\:h 0),\:r;$[1<#n;(,,/*'x[y]'n),,();n 0]}

trs:{ bp:![0],/:/:,/{y[1]+x y 0}[l:+\-1_0,#'bp]''''bp:y[;5]
  st:{x[y]+z}[l]/*cmp[x;y]
  (,/[y[;3]];::)@'/:?\'*{(y;r:trs1[o;x]/y);r}[c bp](,(();());,2#st)}


