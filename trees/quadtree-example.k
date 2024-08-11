\l quadtree.k
grd:(0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0
     0 0 0 0 1 1 1 0
     0 0 0 0 1 1 0 0
     1 1 1 1 1 1 0 0
     1 1 1 1 1 1 0 0
     1 1 1 1 0 0 0 0
     1 1 1 1 0 0 0 1)

/ quadtree from grid
:c:ct[1+grd]

-1+drw[8;c]

/ extract the nodes at indices 1 and 2 and reattach
-1+drw[8]@ro.(am/[(,0;,1 0 2 0);;].(2 3;ex[c]'1 2))

/ ditto but attach to SE and NW nodes
-1+drw[8]@ro.(am/[(,0;,0 1 2 0);;].|'(3 1;ex[c]'1 2))
