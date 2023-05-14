// parent vector from depth vector
p:{r:{@[;;|;]}\[(!0)@&1+|/x;x;!#x];(!#x)^'r@'x-1}

// parent children lookup (excludes self-parenting)
cp:{^'[;?x]@=x}

/ join the values of x in z with y.
cxn:{r+y*r<{(y|z)&z<x}[*|x]\r*|/x=\:r:z}

/ classify the types of child nodes
/ 0 lone node, 1 leftmost node, 2 rightmost node, 3 middle node
cls:{1+(-x=!#x)+1+@[&#x;+(-1 1_\:)'.cp[x];+;1 2]}

/ spread out the nodes
spr:{y@(-x)_,/(!#y),\:x#-1}

/ center adjust horizontal position
ctr:{$[^(!x)?z;y;1~c:#x@z;o[x]/[y;x@z];@[y;z;:;(-c)!+/@[y:o[x]/[y;x@z];x@z]]]}

shp:-1_#'*:\

// vertical tree rendering
sh0:{,/'(" ";"┬";"─";"├";"└";"│")x}
t0:{t:(1+^x?!#x)*+s1:(!1+|/y)=\:y
 t+:(3+|/'|0>':|\|(!#x)=/:x)*+1_s1,,0
 t+5*t<({(x|y)&4>y}\t*|/1 4=\:t)}

// horizontal tree rendering
sh1:{,/'(" ";"┬";"│";"├";"┐";"┬";"─")x}
t1:{t:spr[x]@+/(0N;t)*~:\=':t:t@\:!|/#'t:|'(y@)\'(!#y)^y
  t0:cxn[3 4;6;0^cls[y]@t]
  (sh1 0^+t0;+t)}

sh2:{,/'(" ";"┬";"│";"┌";"┐";"┬";"─";"│";"┴";"┼")x}

/ mark where node splits to children
frk:{[i;t;r;y;p]shp[t]#@[0^r[cls[y]];;:;].1(7+0 1 0N 2@-2+3^r[cls[y]]@)\1+i@?y@p}
t2:{t:spr[x]@+/(0N;t)*~:\=':t:t@\:!|/#'t:|'(y@)\'(!#y)^y
  (h;d):&~^t
  p:(~^:)#,/t
  h:ctr[cp@y]/[h@<p;0 4]
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
