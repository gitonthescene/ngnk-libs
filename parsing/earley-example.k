."\\l ",`env[]`KINIT            / [[https://github.com/gitonthescene/ngnk-libs/tree/master/projectmanagement]]
imp.ort[`tree;"trees/trees.k"]  / [[https://github.com/gitonthescene/ngnk-libs/tree/master/trees]]
imp.ort[`e;"parsing/earley.k"]

para:`0:
T:(("S:aS|b";"aab")
   ("S:SSS|SS|b";"bb")
   ("S:ST|a B: T:aB|a";"aa")
   ("e:NNe|Ne|";"NNN")
   ("E:ER|2|3|4 R:+E|*E";"2+3*4")
   ("e:s|p s:p|s+p p:f|p*f f:(s) f:N"; "N+(N+N)*N"))

p:T 1
para"parse grammar \"",p[0], "\" with input \"",(p 1),"\""
para""

(d;t):e.dfix/e.rec. p
para"result table"
t
para""

para"result internal data"
d
para""

para"List of productions"
?[;1;"."]'d`T
para""

para"Table of items"
itms:e.shw[d]''+'-1_/:-1_t
`0:,/'$/|1(2+|/#',/)\($!#itms),'((-1_d[`i]),"-"),'itms
para""

para"trees"
`0:`k'ts:?e.trees[d;t;itms]
para""

para"Apter trees"
`0:`k'at:e.apt'ts
tree.shw/'at;
para""

para"More explanation to come ..."
