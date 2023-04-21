`0:".#"grd:8 8#,/#'/+(16 0;4 0;3 1;1 0;4 0;2 1;2 0;6 1;2 0;6 1;2 0;4 1;4 0;4 1;3 0;1 1)

/ quadtree from grid
c:0N 4#1_qt[grd;zo[3]]
 
drw@c

/ extract the nodes at indices 1 and 2 and reattach
drw@ro.(am/[(,0;,1 0 2 0);;].(2 3;ex[c]'1 2))

/ ditto but attach to SE and NW nodes
drw@ro.(am/[(,0;,0 1 2 0);;].|'(3 1;ex[c]'1 2))
