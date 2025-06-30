."\\l ",`env[]`KINIT
imp.ort[`b;"trees/bst.k"]
imp.ort[`tree;"trees/trees.k"]
`prng@0
para:`0:

drw:{tree.shw/(x[y]@;::)@'b.dfo@y}
dr:drw[{$:y}]

:data:-15?25
rs:b.e b.ins[<]\+1(!#:)\data
r:*|rs

para"orig"

drw[{$x[0]?y}]r
drw[{$x[4]x[0]?y}]r

para"Insertion"
dr'rs;
para""

para"Indices"
drw[{$x[0]?y}]r
para""

para"Height"
drw[{$x[4]x[0]?y}]r
para""

para"Delete middle index: ",$r[0]i:-2!#r 0

dr b.del[r; i]
