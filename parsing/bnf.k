."\\l ",`env[]`KINIT /[[https://github.com/gitonthescene/ngnk-libs/tree/master/projectmanagement]]
imp.ort[`tree;"trees/trees.k"] / [[https://github.com/gitonthescene/ngnk-libs/tree/master/trees]]

\l earley.k
ls:1_/:_/|1(&<\^:)\" ::=   | \n * + ( ) [ ]"
g:+":"\',/" "\'bnfg:("s:r s:rs r:nw0wef w:1w w:"
                   "e:lw2we e:lf2we e:l f:w3f f:w3 l:twl l:t"
                   "g:6wew7 o:8wew9 t:g t:g4 t:g5 t:o t:i t:i4 t:i5 t:n t:n4 t:n5")
k:"SsrwefFltinog"!`start`syntax`rule`whitespace`expression`eol`eols`list`term`literal`name`option`group
+(*:';::)@'{(x)'[y;z]}''[^''i;i:k@g;ls@g-"0"]

cxn:{r+y*r<{(y|z)&z<x}[*|x]\r*|/x=\:r:z}
tok:{e:<\"\\"=x;$[+/e>c:~=\~q:e<"\""=x;`err@"stray escape";]
     q|:c;c|:q|2*c<~^" \t\n"?x
     c|:3*~^1 3?cxn[1 2;3;+/1 2*q</:";\n"=\:x]
     c|:(<\d)+4*d:|/q</:"()[]"=\:x
     c|:(<\d)+6*d:|/q</:"+*"=\:x
     |+1_,':(&~=':c),#c}

abc:1:"abc_subset_bnf.txt" / [[https://web.mit.edu/6.005/www/fa08/projects/abcPlayer/assignment_files/abc_subset_bnf.txt]]

tks:(";"=*:')_{x@y+!'z-y}[abc;;].tok abc
i:{$[|/"\n"=x;"3";|/~^" \t"?x;"1";~^w:ls?x;*$w;"\""=*x;"i";"n"]}'tks
lnl:+/&\"3"=i / number of leading newlines
(tks;i):lnl_/:(tks;i)

/\t (d;t):dfix/(dd;tt):rec[" "/bnfg;#/|1(1+*&"3"=)\i]
\t (d;t):dfix/(dd;tt):rec[" "/bnfg;i]

(rules;itms):dsp[d;t]
fn:t[-1+#d`i]
bp:1_({x,t[x;3]?y}/'!d[`bp])!.d`bp
:rs:(-1+#d`i),/:&~fn[2]

/ New construction of a the tree given that the grammar is unambiguous
chs:*: / disambiguate

bp:(0,1+#d`i)/'(+{(x[;3;].|y;y[1])}[t]'+(0,1+#d`i)\)'bp:chs'd[`bp]_0N
r:(0,1+#d`i)/(t[;3;].rs[0];rs[0;0])
sibs:{|1_-1_{(x y 0)}[x]\(y;y)}[bp]

bp1:+*|{(q;s):y;$[~#q;:y;2>#*q;:(1_q;s);]b:sibs@q[0;1];(b,1_q;(,(q[0;1];*'|'b)),s)}[bp]/(,(r;r);())

nn:{y,/o[x]'x y}[bp2:!/bp1]r

sh:shw[d]'+(d[`B],1+#d`i)\*/1(~0>)\
(n;p):(nn@<g;tree.redo[p]g:tree.dfo p:@[0N+&#nn;nn?(r;.bp2);:;nn?(r;!bp2)])
n:@[n;(4=*(d[`B],1+#d`i)\n@)_(!#p)^p;:;-1]
nn:(n<0)'[sh n;((,""),tks)@+\n<0]
i:((d[`B],1+#d`i)\n)0

/ delete structural nodes
w:@[&#n;&n<0;:;|/tks~\:/:,'"()[]|"]
(nn;n;p;i):(-+/w)_/:(nn@g;n@g;tree.redo[p;<g];i@g:<w)

/ clear whitespace
px:@[p;w;:;w:&~^"wf"?d[`t]d[`p]i]
w:1&(px@)/px
(nn;n;p;i):(-+/w)_/:(nn@g;n@g;tree.redo[p;<g];i@g:<w)

/ collect all rules into a single list
s:"s"=d[`t]d[`p]i
p:@[p;&-1_0,s;:;0]
g:<@[s;0;:;0]
(nn;n;p;i):(--1+/s)_/:(nn@g;n@g;tree.redo[p;<g];i@g)

/ collect expressions into lists
e:&"e"=d[`t]d[`p]i
px:@[p;e;:;e]
p:@[p;w;:;(px@)/w:&"l"=d[`t]d[`p]i]

/ lift terms to the containing expressions
t:&"t"=d[`t]d[`p]i
p:@[p;t;:;p@p@t]

/ delete structural nodes
w:"l"=d[`t]d[`p]i
(nn;n;p;i):(-+/w)_/:(nn@g;n@g;tree.redo[p;<g];i@g:<w)

/ unchain the expressions
e:&"e"=d[`t]d[`p]i
p:@[p;e;:;p@{("e"=d[`t]d[`p]i@p)'[y;p:x@y]}[p]/e]

tree.shwv[nn;p]
