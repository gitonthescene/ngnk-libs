/ Inspired by [[https://codeberg.org/effbiae/earley/src/branch/main]]
/ Well written tutorial here: [[https://loup-vaillant.fr/tutorials/earley-parsing/]]

/ Earley item: (rule; dot position; origin; id)
empty:3#,!0
id:{(1+#'x`p`i`i)/y}
dot:{@[x[`t]@n;&x[`p;1+y[0]]=n:1+y[1]+x[`p;y[0]];:;" "]}
dot0:{@[x[`t]@n;&x[`p;1+y[0]]=n:1+y[1]+x[`p;y[0]];:;0N]}
dot:dot0
aug:{,/1((id[x];dot[x])@\:)\y}
data:{R:,/',/+'((*:;1_"|"\"|",)@'":"\)'" "\x
     `p`t`i`bp!(+\0,#'R;,/R;y,"\0";(,0N 0N)!,())}
data0:{R:,'/{@''['''(),/:/:~^d;0+(x;y);-:1+d:(?x)?(x;y)]}/r:+,/+'((*:;1_"|"\"|",)@'":"\)'" "\x
     `p`t`T`i`bp!(+\0,#'R;,/R;,'/r;(0+y),0N+1;(,0N 0N)!,())}
data:data0

pred:{[d;s;c;t]w:&(-1_d[`t]d[`p])=/:?c;(s;++(*|w;0;s+&#*w);!0)}
scan:{[d;s;c;t]w:&d[`i;s]=/:c;(s+1;@[3#t[s]@\:w;1;+;1];,'s,/:w)}
comp:{[d;s;c;t]$[~#c:&^c;:(s;empty;!0);]
      f:(f@;::)@'w:&(d[`t;d[`p;t[s;0;c]]])=t[;4]f:t[s;2;c]
      (s;{[x;y;z;w]y,'@[3#x[z;;w];1;+;1]}[t]/[empty].f;+(+f;s,/:c@w 0))}

stp:{add[y 0;y 1]@[r:z[y 0;x;y[1;x;4];y 1];1;aug[y 0]]}
add:{n:(z[1])@\:&((!#i)=i?i)&w:^(y[z 0;3])?i:z[1;3]
     $[~#*|nxt:(+(z[0];i); z[2]);;x[`bp]:{@[x;y;?,;,z]}/[x`bp].nxt]
     (x;@[y;z 0;,';n])}

rec0:{{(d;st;s):$[n:#**|x 1;(x[0];x[1],,empty,(!0;"");1+x 2);:x]
       ({y stp[x]/(pred;scan;comp)}[s]/(d;st)),s}/(x;,aug[x;y];-1)}
rec1:{s:++(&=/1*:\x[`t]x`p;0;0);rec0[x;s]}
rec:{-1_rec1 data[x;y]}

cmbos:{!/:/({y,x[y]?z}[x].'!y;1_'(,0N){,/x,/:\:,'y}/y)}

dsp:{[d;t]rules:{?[x[`t]y+!z;1;":"]}[d].'+-1 1_'1(-':)\d[`p]
     itms:{x[z;1]{?[y;2+x;"."]}'y@x[z;0]}[t;rules]'!-1+#t
     (rules;itms,''"/",/:/:$-1_t[;2])}

dfix:{[d;t]f:{((^t)+0>t)'[`c$t;x@-1-t:y]};(@[d;`t`i;:;f[*'d`T]'d`t`i];{@[z;-1+#z;x[y]]}[f;*'d`T]'t)}

tree:{$[^*z;:0N;]
      ls:.[y[0];]'-1_c:1_|(*x@)\z
      (y[1]. z;(c~'0N)'[c:o[x;y]'*'1_'x@1_c;ls])}

trees:{?,/(cmbos[y[;3]]x[`bp]_0N 0N)tree[;(y[;4];z);]/:\:lst,/:&~y[lst:-2+#y;2]}

apt:{(dp;nd):+{$[~`A~@y;,(x;y);(,(x;*y)),,/o[x+1]'y 1]}[0;x];(nd;tree.p@dp)}

/
/ back pointers:
/ gives all possible choices of back pointers

cmbos[r[1;;3]]r[0;`bp]_0N 0N

/ display

dsp[d;t]
tree[bp;start]
