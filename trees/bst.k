e:(,0;,0;,0;-1 -1;-1 0) / (keys;vals;parent;children;height)

ht:{1+|/x[4]1+x[3]![2]+2*y}
rot:{c:x[3](~z)+2*y;p:x[2]y;i:ci[x;y]                           / rot[tree;idx;dir]
     x:.[x;(2;y,c,(0<d)#d);:;c,(p;c)[~c],#[0<d:x[3;z+2*c];y]]
     x:.[x;(3;(^i)_(i;(~z)+2*y;z+2*c));:;(^i)_(c,x[3;z+2*c],y)]
     x{.[x;4,1+y;:;ht[x;y]]}/y,c}

reb:{x{x:.[x;4,1+y;:;ht[x;y]];$[~b:-/0 1=2 -1>\:-/x[4]1+c:x[3]![2]+2*y;:x;x];c:c @~b:b>0
     rot/[x;#[-#b;c,y];|b:?1 0=b,0<-/x[4]1+x[3]1 0+2*c]}/-1_(x[2]@)\y}

insi:{$[0N~n:z[0;0]z[2];(reb[r 0;(r:@[.[z;(0;3;z[3]+2*z[1]);:;#z[0;0]];0;,'[;(y[0];y[1];z[1];-1 -1;0)]])1];z[2];1)
       n~y 0;z[0 2],0
       [d:(z[0];z[2];z[0;3;lr+2*z[2]];lr:~x[y 0;n]);o[x;y;d]]]}

ins:{$[^*z;`err@"ed";];insi[x;z;(y;0;y[3]0;0)]}

dfo:{d:1_(x[2]=)#!#x[2]                                         / dead nodes
     g:,//(((0>)_,/x[3]@(!2)+/:2*)\0;d)                         / left before right
     (n;p):(-#d)_/:(x[0]@g;tree.redo[x[2]]@<g)
     (n@g;tree.redo[p;<g:<tree.dfo[p]])}                        / dfo

pred:{*(&/0<)(-2#,/1(x[3]@1+2**|:)\)/,x[3]2*y}                  / pred[t;idx]  / immediate predecessor
ci:{*(y=x[3]@)#![2]+2*x[2]y}                                    / ci[t;idx]    / where we exist in the child vector

del0:{reb[.[.[x;2,y;:;y];3,ci[x;y];:;-1]{.[x;4,1+y;:;ht[x;y]]}/(x[2]@)\p;p:x[2]y]}   / del0[t;idx]  / leaf
del1:{c:*(0<)#x[3]![2]+2*y;del[.[x;(0 1;y,c);:;x[0 1;c,y]];c]}                       / del1[t;idx]  / 1 child
del2:{c:pred[x;y];del[.[x;(0 1;y,c);:;x[0 1;c,y]];c]}                                / del2[t;idx]  / 2 child
del: {(del0;del1;del2)[+/0<x[3;![2]+2*y]][x;y]}
