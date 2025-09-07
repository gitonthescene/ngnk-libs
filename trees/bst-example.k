."\\l ",`env[]`KINIT
imp.ort[`b;"trees/bst.k"]
imp.ort[`tree;"trees/trees.k"]
`prng@0
para:`0:

para"COMMENTARY:"
para""

para"Currently, bst.k contains an implementation of [[AVL trees][https://en.wikipedia.org/wiki/AVL_tree]].  The
intent was to be a basis to build other datatypes, like trees and dictionaries.  As such elements are key/value
pairs and the tree can only contain one element per key.  Insertion returns a triple of the modified tree and the
\"insertion index\".  If the element already existed in the tree the tree is unmodified and the index is where the
match was found.  If not the index is the index where the insertion occurred.  The final element of the triple
indicates if an insertion occured or not."

para""
para"SAMPLE RUN:"
para""
drw:{tree.shw/(x[y]@;::)@'b.dfo@y}
dr:drw[{$:y}]
di:drw[{$x[0]?y}]
dh:drw[{$x[4]1+x[0]?y}]

data:-15?25

rs:b.e {*b.ins[<;x;y]}\+1(!#:)\data
r:*|rs

para"orig"

di r
dh r

para""
para"Insertion"
dr'rs;
para""

para"Indices"
di r
para""

para"Height"
dh r
para""

para"Delete middle index: ",$r[0]i:-2!#r 0

dr b.del[r; i]
