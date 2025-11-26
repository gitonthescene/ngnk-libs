."\\l ",`env[]`KINIT
imp.ort[`p;"parsing/bnf.k"]
para:`0:(,""),,:

para"Parse an EBNF grammar into plain BNF for easier processing.

Uses an Earley parser (https://github.com/gitonthescene/ngnk-libs/blob/master/parsing/earley.org)
which in general is not particularly performant but is relatively easy to implement and more than
up to the task.
"
para s," grammar ",s:#[15;"-"]
`1:html:1:"html.ebnf"
(rules;nn;n):p.grm html

para s," parsed ",s
`0:" "/'rr:{(x[0];"::="),1_x}'@'[''(0>n@rules)&^(,/p.pm[nn;n])?rules;$rules;nn@rules]

rls:?/|1(?,/)\@'[''(0>n@rules)&^(,/p.pm[nn;n])?rules;$rules;nn@rules]

eps:|/'~-1+#'[rls]@=*'(nr:?,/rls)?rls:rr_\:1
fst:{,/(^*'[x]?z;0^y z)#'z,-1}[nr?rls;eps]'!#nr
fst:{{@[y;z 0;?,/;(^:)_/:y@^[r@&1 :':&\e;#[~&/e:0^x@1+r:(1_z),-1;-1]]]}[x 0]/[y;x 1]}[(-1,.eps;nr?rls)]/fst

para s," first ",s
+(?*'rls;(^:)_/:/:nr@fst@?nr?*'rls)

para s," follow ",s

flw:@[#[nr]#,!0;0;:;,-1]
epf:|/'0>fst
flw:{{f:(t@w;f:(f@'&'1 :':'&\'1^x[1]@f:(1_)\1_t)@w:&~^x[0]?t:1_z,-1)
      y:@[y;f 0;?,/;^'[,/'x[2]^'[f 1;-1];-1]]
      @[y;w;?,/;#[#w:f[0]@&0>*'|'f 1;,y z 0]]}[x]/[z;y]}[(!eps;epf;fst);nr?rls]/flw
+(?*'rls;(^:)_/:/:nr@flw@?nr?*'rls)
