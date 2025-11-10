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

p:T 4
para"parse grammar \"",p[0], "\" with input \"",(p 1),"\""
para""

(d;a;t):e.rec. p

para"result table"
t
para""

r:+1_d[`B]\1_a 0
para"result internal data"
d
para""

para"List of productions"
?[;1;"."]'d`T
para""

para"Table of items"
itms:-1_e.shw[d]''+'3#/:t
`0:,/'$/|1(2+|/#',/)\,'/|1($!#:)\,'/|1(`c$@'/|1((:[;"-"];::)0<)\d[`i]@!#:)\itms
para""

para"Apter trees"
ts:e.trs[d;t];
tree.shw/'{(@[e.shw[x]'+1_x[`B]\y[0];![#p]^p:y[1];:;`c$-1_x`i];y 1)}[d]'ts;
para""

para"More explanation to come ..."
