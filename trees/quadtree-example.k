\l quadtree.k
c:(1 0 2 0
 1 1 2 0
 2 1 1 0
 2 1 1 1
 1 1 1 2)
 
drw@c

/ extract the nodes at indices 1 and 2 and reattach
drw@ro.(am/[(,0;,1 0 2 0);;].(2 3;ex[c]'1 2))

/ ditto but attach to SE and NW nodes
drw@ro.(am/[(,0;,0 1 2 0);;].|'(3 1;ex[c]'1 2))
