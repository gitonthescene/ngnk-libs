imp.ort[`tree;"trees/trees.k"] / [[https://github.com/gitonthescene/ngnk-libs/tree/master/trees]]
imp.ort[`e;"parsing/earley.k"]

ls:1_/:_/|1(&<\^:)\" ::=   | \n * + ( ) [ ]"
g:+":"\',/" "\'bnfg:1_(""
"s:r s:rs r:nw0wef w:1w w:"
"e:lw2we e:lf2we e:l f:w3f f:w3 l:twl l:t"
"g:6wew7 o:8wew9 t:g t:g4 t:g5 t:o t:i t:i4 t:i5 t:n t:n4 t:n5")

/ show the grammar grammar
/ k:"srwefltinog"!`syntax`rule`whitespace`expression`eol`list`term`literal`name`option`group
/ +(*:';::)@'{(x)'[y;z]}''[^''i;i:k@g;ls@g-"0"]

cxn:{r+y*r<{(y|z)&z<x}[*|x]\r*|/x=\:r:z}
tok:{e:<\"\\"=x;$[+/e>c:~=\~q:e<"\""=x;`err@"stray escape";]
     q|:c;c|:q|2*c<~^" \t\n"?x
     c|:m:3*~^1 3?cxn[1 2;3;+/1 2*q</:";\n"=\:x]
     c|:(<\d)+4*d:m<q<|/"()[]"=\:x
     c|:(<\d)+6*d:m<q<|/"+*"=\:x
     |+1_,':(&~=':c),#c}

ser:{$[|/"\n"=x;"3";|/~^" \t"?x;"1";~^w:ls?x;*$w;"\""=*x;"i";"n"]} / serialize tokens into a byte stream

sh:{e.shw[x]'+(x[`B],1+#x`i)\*/1(~0>)\y}

tr:{[x;y;z](n;p):e.tree[x;y]
    n:@[n;(4=*(x[`B],1+#x`i)\n@)_(!#p)^p;:;-1]
    n*:1+*/1(-1+\)\n<0
    nn:(n<0)'[sh[x] n;((,""),z)@+\n<0]
    i:x[`t]x[`p]((x[`B],1+#x`i)\n)0
    (nn;n;p;i)}

prn:{(-+/y)_/:(x[0]g;x[1]g;tree.redo[x[2];<g];x[3]@g:<y)} / prn[(nn;n;p;i);msk]
lft:{[x;y;z]p:@[x;y;:;y];@[x;z;:;(p@)/z]}                 / lft[p;frm;to;lvls]

pm:{w@&'(,'"+*")~/:\:x@w:&0>y}           / identify adverbs
ref0:{[nn;n;p;i]p:@[p;&-1_0,w:"s"=i;:;0] / collect all the rules
      p:lft[p;&"e"=i;&"l"=i]             / collect all the expressions
      p:lft[p;&~"e"=i;&"e"=i]            / unchain the expressions
      p:@[p;w;:;3(p@)/w:&"t"=i@p]        / lift the terms
      (nn;n;p;i)}

ref1:{[nn;n;p;i](nn;n;p;i):ref0[nn;n;p;i]
      w:@[&#n;&n<0;:;|/nn[&n<0]~\:/:(,"::="),,'"()[]|"] / delete structural terminals
      w|:|/"lts"=\:i                                    / delete structural non-terminals
      (nn;n;p;i):prn[(nn;n;p;i);@[w;0;:;0]]             / preserve the root (as structural)
      px:@[p;w;:;w:&~^"wf"?i]                           / delete whitespace nodes
      w:1&(px@)/px
      prn[(nn;n;p;i);w]}

ref:{[nn;n;p;i](nn;n;p;i):ref1[nn;n;p;i]
      p:@[p;-1+w;:;w:,/pm[nn;n]]   / lift adverbs
      (nn;n;p;i)}

chld:^'/(=:;?:)@\:
rls1:{i:(1<#:')#.*''y@d[0]@=x@y[;1]@*|d:+.z#=*'y  / consolidate identical +/* rules
      y{@'[''^y?r;*y;r:(~^(1_y)?*:')_x]}/i}

rls2:{[r;chld;a]
     r,:,/1_/:,\'+(a[0];chld@a[0];a[0])            / + rules
     r,,/(,*:;,/3#)@\:/:+(a[1];chld@a[1])}         / * rules

rls:{chld:chld[y 2]                                / rls[d;(nn;n;p)]
     a:pm/2#y
     i:x[`t]x[`p]((x[`B],1+#x`i)\y 1)0
     r:,/(,/:/(*:;chld@)@')'0 1_/:chld@w:&"r"=i    / top level rules
     r:rls2[r;chld;a]
     r,:,/w,/:'(chld@)'chld@w:&"g"=i               / groups
     r,:,/,\',/w,/:','(chld@)'chld@w:&"o"=i        / options
     r rls1[y 0]/a}

grm0:{tks:(";"=*:')_{x@y+!'z-y}[x;;].tok x
      i:ser'tks
      (tks;i):(+/&\"3"=i)_/:(tks;i)
      (dta;tbl):e.dfix/(dd;tt):e.rec[" "/bnfg;i]
      rs:e.cmp[dta;tbl]
      r:(0,1+#dta`i)/(tbl[;3;].rs[0];rs[0;0])
      (dta;tr[dta;tbl;tks])}

grm:{(dta;(nn;n;p;i)):grm0[x]
     (nn;n;p;i):ref[nn;n;p;i]
     (rls[dta;(nn;n;p)];nn;n)}

/
Next ABNF
[[https://web.archive.org/web/20120730085339/http://www.ietf.org/rfc/rfc2234.txt]]
