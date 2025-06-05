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
:rs:(-1+#d`i),/:&~fn[2]
r:(0,1+#d`i)/(t[;3;].rs[0];rs[0;0])

bps:bp[d;t;r]
nn:{y,/o[x]'x y}[bps]r

sh:shw[d]'+(d[`B],1+#d`i)\*/1(~0>)\

(n;p):(nn@<g;tree.redo[p]g:tree.dfo p:@[0N+&#nn;nn?(r;.bps);:;nn?(r;!bps)])
n:@[n;(4=*(d[`B],1+#d`i)\n@)_(!#p)^p;:;-1]
n*:1+*/1(-1+\)\n<0
nn:(n<0)'[sh n;((,""),tks)@+\n<0]
i:((d[`B],1+#d`i)\n)0

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
tm:&"t"=d[`t]d[`p]i
p:@[p;tm;:;p@p@tm]

/ unchain the expressions
e:&"e"=d[`t]d[`p]i
p:@[p;e;:;p@{("e"=d[`t]d[`p]i@p)'[y;p:x@y]}[p]/e]

/ lift terms
tm:&"t"=d[`t]d[`p]i@p
p:@[p;tm;:;2(p@)/tm]

/ delete structural nodes
w:@[&#n;&n<0;:;|/tks~\:/:(,"::="),,'"()[]|"]
w|:|/"lt"=\:d[`t]d[`p]i
(nn;n;p;i):(-+/w)_/:(nn@g;n@g;tree.redo[p;<g];i@g:<w)

/ clear whitespace
px:@[p;w;:;w:&~^"wf"?d[`t]d[`p]i]
w:1&(px@)/px
(nn;n;p;i):(-+/w)_/:(nn@g;n@g;tree.redo[p;<g];i@g:<w)

/ lift adverbs
pm:-&'(,'"+*")~/:\:(,""),tks
p:@[p;-1+w;:;w:,/pm:n?pm]

chld:^'[;?p]@=p

tree.shwv[nn;p]

/ top level rules:
rules:,/(,/:/(*:;chld@)@')'0 1_/:chld@w:&"r"=d[`t]d[`p]i

/ + rules
rules,:,/1_/:,\'+(pm[0];chld@pm[0];pm[0])

/ * rules
rules,:,/,\'+(pm[1];chld@pm[1])

/ groups
rules,:,/w,/:'(chld@)'chld@w:&"g"=d[`t]d[`p]i

/ options
rules,:,/,\',/w,/:','(chld@)'chld@w:&"o"=d[`t]d[`p]i

`0:{" "/(x[0];"::="),1_x}'@'[''(0>n@rules)&^(,/pm)?rules;$rules;nn@rules]
