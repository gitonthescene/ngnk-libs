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
