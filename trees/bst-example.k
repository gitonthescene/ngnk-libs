\l bst.k
\d tree
\l trees.k
\d .
para:`0:

drw:{(p;n):((<g)@;::)@'0^x[0 2]@\:g:gt.(0^x 0 1); tree.shw[$n;p]}
dr:drw@[;1 2 2]@

data:-15?50
t:(e;!0;!0;!0)
rs:t ins\data
r:*|rs

para"orig"
dr r
drw r[1 2],,!#r[1]
drw r 1 2 3

para"Insertion"
dr@/:1_rs;
para""

para"Indices"
drw r[1 2],,!#r[1]
para""

para"Height"
drw r[1 2 3]
para""

para"Delete middle index"
dr del[r;1]
