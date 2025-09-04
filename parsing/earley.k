/ Inspired by [[https://codeberg.org/effbiae/earley/src/branch/main]]
/ Well written tutorial here: [[https://loup-vaillant.fr/tutorials/earley-parsing/]]
imp.ort[`avl;"trees/bst.k"]

/ Earley item: (rule; dot position; origin; id)
empty:3#,!0
id:{x[`B]/y}
dot:{@[x[`t]@n;&x[`p;1+y[0]]=n:1+y[1]+x[`p;y[0]];:;0N]}

aug:{,/1((id[x];dot[x])@\:)\y}
data0:{(r;,'/{@''['''(),/:/:~^d;0+(x;y);-:1+d:(?x)?(x;y)]}/r:+,/+'((*:;1_"|"\"|",)@'":"\)'" "\x)}
data1:{((*'x;1_/:x);x)}
data:{(r;R):$[`C~@x;data0[x];data1[x]]
     r:`p`t`T`i`bp!(+\0,#'R;,/R;,'/r;(0+y),0N+1;avl.e)
     @[r;`B;:;1+(#r`p;|/-':r`p;#r`i)]}

pred:{[d;s;c;t]w:&(-1_d[`t]d[`p])=/:?c;(s;++(*|w;0;s+&#*w);!0)}
scan:{[d;s;c;t]w:&d[`i;s]=/:c;(s+1;@[3#t[s]@\:w;1;+;1];,'s,/:w)}
comp:{[d;s;c;t]$[~#c:&^c;:(s;empty;!0);]
      f:(f@;::)@'w:&(d[`t;d[`p;t[s;0;c]]])=t[;4]f:t[s;2;c]
      (s;{[x;y;z;w]y,'@[3#x[z;;w];1;+;1]}[t]/[empty].f;+(+f;s,/:c@w 0))}

upd:{[w;x;y;z](x;i;u):avl.ins[<;x;(w/|y;,())];.[x;1,i;?,;,w/|+z]}
stp:{(d;y):y;add[d;y;@[z[d;x;y[x;4];y];1;aug[d]]]}
add:{(s;t;a):z;n:t@\:&((!#i)=i?i)&w:^(y[s;3])?i:t[3]
     $[~#*|nxt:(+(s;i); a);;[w:0,1+#x`i;x:.[x;`bp;upd[w]/[;nxt 0;nxt 1]]]]
     (#[*n];(x;@[y;s;,';n]))}

rec0:{(#**|@[;1]@){s:*|x:$[n:#**|x 1;(x[0];x[1],,empty,(!0;"");1+x 2);:x]
       ,[*|{*x}{(0;y 1){c:y[0];r:stp[x;y[1];z];(c+r 0;r 1)}[x]/(pred;scan;comp)}[s]/(-1;2#x);s]}/(x;,aug[x;y];-1)}
rec1:{s:++(&=/1*:\x[`t]x`p;0;0);rec0[x;s]}
rec:{-1_rec1 data[x;y]}

cmbos:{!/:/({y,x[y]?z}[x].'!y;1_'(,0N){,/x,/:\:,'y}/y)}

shw:{?[?[x[`t]@+/(!--)\x[`p]0 1+y 0;1;":"],"/";2+y 1;"."],$y 2}
dfix:{[d;t]f:{((^t)+0>t)'[`c$t;x@-1-t:y]}; d:@[d;`t`i;:;f[?*'d`T]'d`t`i]
      (@[d;`bp;:;!/1_/:2#d`bp]; {@[z;-1+#z;x[y]]}[f;?*'d`T]'t)}

tree0:{$[^*z;:0N;]
      ls:.[y[0];]'-1_c:1_|(*x@)\z
      (y[1]. z;(c~'0N)'[c:o[x;y]'*'1_'x@1_c;ls])}

/ direct Apter tree calculation (no stack)
tree:{[d;t]st:*cmp[d;t];r:(0,1+#d`i)/(t[;3;].st;st[0]);bp:bp[d;t;r]
      nds:|*|{$[~#y[0];y;^y[0;0];(1_y 0;y 1);(x[y[0;0]],1_y[0];y[0;0],y[1])]}[bp]/(,r;!0)
      prt:-1_@[&1+#nds;(#nds)^.nds?nds#bp;:;!#nds]
      emp:nds?&~#'bp / empty nodes
      (-+/w)_/:(nds@g;tree.redo[prt;<g:<w:@[&#nds;emp;:;1]])}

cmp:{[d;t]w:&~t[lst:-2+#t;2];lst,/:w@&{&/(*[x[`t]]=x[`t]r;=/(1+z+r:x[`p]y;x[`p]y+1))}[d]/t[lst;0 1;w]}
trees:{dc:+|(0,1+#x`i)\;?,/(cmbos[y[;3]](dc@!d)!dc''.d:x[`bp]_0N)tree0[;(y[;4];z);]/:\:cmp[x;y]}
apt:{(dp;nd):+{$[~`A~@y;,(x;y);(,(x;*y)),,/o[x+1]'y 1]}[0;x];(nd;tree.p@dp)}

chs:*: / disambiguate
bp:{bp:(0,1+#x`i)/'(+{(x[;3;].|y;y[1])}[y]'+(0,1+#x`i)\)'bp:chs'x[`bp]_0N
    sibs:{|1_-1_{(x y 0)}[x]\(y;y)}[bp]
    !/+*|{(q;s):y;$[~#q;:y;2>#*q;:(1_q;s);]b:x@q[0;1];(b,1_q;(,(q[0;1];*'|'b)),s)}[sibs]/(,(z;z);())}

/
/ back pointers:
/ gives all possible choices of back pointers

cmbos[r[1;;3]]r[0;`bp]_0N 0N

/ display
tree[bp;start]
