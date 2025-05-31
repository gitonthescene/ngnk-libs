."\\l ",`env[]`KINIT /[[https://github.com/gitonthescene/ngnk-libs/tree/master/projectmanagement]]
imp.ort[`tree;"trees/trees.k"] / [[https://github.com/gitonthescene/ngnk-libs/tree/master/trees]]

\l earley.k
ls:1_/:_/|1(&<\^:)\" ::=   | \n * + ( ) [ ]"
g:+":"\',/" "\'bnfg:("s:r s:rs r:nw0wef w:1w w:"
                   "e:lw2we e:lf2we e:l f:w3f f:w3 l:twl l:t"
                   "g:6wew7 o:8wew9 t:g t:g4 t:g5 t:o t:i t:i4 t:i5 t:n t:n4 t:n5")
k:"SsrwefFltin"!`start`syntax`rule`whitespace`expression`eol`eols`list`term`literal`name
+(*:';::)@'{(x)'[y;z]}''[^''i;i:k@g;ls@g-"0"]

cxn:{r+y*r<{(y|z)&z<x}[*|x]\r*|/x=\:r:z}
tok:{e:<\"\\"=x;$[+/e>c:~=\~q:e<"\""=x;`err@"stray escape";]
     q|:c;c|:q|2*c<~^" \t\n"?x
     c|:3*~^1 3?cxn[1 2;3;+/1 2*q</:";\n"=\:x]
     c|:(<\d)+4*d:|/q</:"()[]"=\:x
     c|:(<\d)+6*d:|/q</:"+*"=\:x
     |+1_,':(&~=':c),#c}

abc:1:"abc_subset_bnf.txt" / [[https://web.mit.edu/6.005/www/fa08/projects/abcPlayer/assignment_files/abc_subset_bnf.txt]]

ts:(";"=*:')_{x@y+!'z-y}[abc;;].tok abc
i:{$[|/"\n"=x;"3";|/~^" \t"?x;"1";~^w:ls?x;*$w;"\""=*x;"i";"n"]}'ts
lnl:+/&\"3"=i / number of leading newlines

/\t (d;t):dfix/(dd;tt):rec[" "/bnfg;#/|1(1+*&"3"=)\lnl_i]
\t (d;t):dfix/(dd;tt):rec[" "/bnfg;lnl_i]

(rules;itms):dsp[d;t]
#t
fn:t[-1+#d`i]
bp:1_({x,t[x;3]?y}/'!d[`bp])!.d`bp
(-1+#d`i),/:&~fn[2]

\t trs:trees[d;t;itms]
\t as:apt'trs
a:as[0]
/lvs:("w"=_*'a[0]@)_(!#a[1])^a[1]
lvs:(1<#:'a[0]@)_(!#a[1])^a[1]
a[0]:@[a[0];lvs;:;lnl_ts]

/ chuck whitespace
p:@[a[1];w;:;w:&|/("wf",\:":")~/:\:2#/:a[0]]
wh:1&(p@)/p
g:<wh
(nn;pp):(-+/wh)_/:(a[0]@g;tree.redo[a[1];<g])

/ collect all rules into a single list
ss:"s:"~/:2#/:nn
pp:@[pp;&-1_0,ss;:;0]
g:<@[ss;0;:;0]
(nn;pp):(--1+/ss)_/:(nn@g;tree.redo[pp;<g])

/ collect expressions into lists
es:&"e:"~/:2#/:nn
px:@[pp;es;:;es]
pp:@[pp;w;:;(px@)/w:&"l:"~/:2#/:nn]

/ lift terms to the containing expressions
ts:&"t:"~/:2#/:nn
pp:@[pp;ts;:;pp@pp@ts]

/ delete structural nodes
wh:(|/nn~\:/:,'"()[]|")|"l:"~/:2#/:nn
g:<wh
(nn;pp):(-+/wh)_/:(nn@g;tree.redo[pp;<g])

/ unchain the expressions
es:&"e:"~/:2#/:nn
pp:@[pp;es;:;pp@{("e:"~/:2#/:nn@p)'[x;p:pp@x]}/es]

tree.shwv[nn;pp]
