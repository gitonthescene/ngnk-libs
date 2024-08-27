// parent vector from depth vector
p:{r:@[;;|;]\[(!0)@&1+|/x;x;!#x];(!#x)^'r@'x-1}

// parent children lookup (excludes self-parenting)
cp:{^'[;?x]@=x}

/ join the values of x in z with y.
cxn:{r+y*r<{(y|z)&z<x}[*|x]\r*|/x=\:r:z}

/ classify the types of child nodes
/ 0 lone node, 1 leftmost node, 2 rightmost node, 3 middle node
cls:{1+(-x=!#x)+1+@[&#x;+(-1 1_\:)'.cp[x];+;1 2]}

/ spread out the nodes
spr:{y@(-x)_,/(!#y),\:x#-1}

shp:-1_#'*:\

// vertical tree rendering
/ This is basically a reimplementation of this algorithm [[https://ktye.github.io/kweb/compile.html]]
sh0:{,/'(" ";"┬";"─";"├";"└";"│")x}
t0:{t:(1+^x?!#x)*+s1:(!1+|/y)=\:y
 t+:(3+|/'|0>':|\|(!#x)=/:x)*+1_s1,,0
 sh0 cxn[1 4;5;t]}

// horizontal tree rendering
sh1:{,/'(" ";"┬";"│";"├";"┐";"┬";"─")x}
t1:{t:spr[x]@+/(0N;t)*~:\=':t:t@\:!|/#'t:|'(y@)\'(!#y)^y
  t0:cxn[3 4;6;0^cls[y]@t]
  (sh1 0^+t0;+t)}

sh2:{,/'(" ";"┬";"│";"┌";"┐";"┬";"─";"│";"┴";"┼")x}

/ center adjust horizontal position
ctr:{$[^(!x)?z; y
       1~c:#x@z; @[y;z;:;@[y:o[x]/[y;x@z];*x@z]]
       @[y;z;:;(-c)!+/@[y:o[x]/[y;x@z];x@z]]]}

/ center labels
ctl0:{<>((#c)#!2)@&c:,/+(((-':i)-(0,-1_x@i))+(-1_+/1(-|0,|1_)\0,-2!_-0.5+x@i);x@i:&1&x)}
ctl:{ m:(~&/^:)''x
  d:,/'(~&//'^:)#'x
  (d@'ctl0'm*#''x)@\:!#*x}

pad:{p:x#/:" ",0N;p,/:'y,\:'p}

/ mark where node splits to children
frk:{[i;t;r;y;p]shp[t]#@[0^r[cls[y]];;:;].1(7+0 1 0N 2@-2+3^r[cls[y]]@)\1+i@?y@p}

t2:{t:spr[x]@+/(0N;t)*~:\=':t:t@\:!|/#'t:|'(y@)\'(!#y)^y
  (h;d):&~^t
  p:(~^:)#,/t
  h:ctr[cp@y]/[h@<p;&y=!#y]
  i:(#*t)/(h;d@<p)
  r:@[,/0N+t*0;i;:;]
  (sh2@+cxn[3 4;6;frk[i;t;r;y;p]];+shp[t]#r[!#y])}

// depth first preordering of indices
dfo:{<,/{y,,/$[^(!x)?y;!0;o[x]'x[y]]}[cp[x]]'&x=!#x}

// Change all the index references in x "under" permutation <y
redo:{y@x@<y}

// left vector from parent.   assumes dfs preorder
lfp:{@[!#x;;:;].1{-1_(*x),x}'\.cp[x]}

// right vector from parent.  assumes dfs preorder
rfp:{@[!#x;;:;].1{1_x,*|x}'\.cp[x]}

// right vector from left.    assumes dfs preorder
rfl:{c-1+(|!c)^'(|x)?!c:#x}

// left vector from right.    assumes dfs preorder
lfr:{(!c)^'x?!c:#x}

// first left child.          assumes dfs preorder
/ *'cp[x]
flc:!/1(1+)\?:

// first right child.         assumes dfs preorder
/ (*|)'cp[x]
frc:{(?x)!(rfp[x]@)/1+?x}

/ simple interface to printing
shw:{(tr;lb):pad[pd]t2[pd:|/#'x]y
 `0:,/+(tr;ctl@x@lb)}
