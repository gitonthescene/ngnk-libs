// parent vector from depth vector
p:{r:{@[x;y;:;z|x@y]}\[(!0)@&1+|/x;x;!#x];(!#x)^'r@'x-1}

// parent children lookup (excludes self-parenting)
cp:{^'[;?x]@=x}

// vertical tree rendering
sh0:{,/'(" ";"┬";"─";"├";"└";"│")x}
t0:{t:(1+^x?!#x)*+s1:(!1+|/y)=\:y
 t+:(3+|/'|0>':|\|(!#x)=/:x)*+1_s1,,0
 t+5*t<({(x|y)&4>y}\t*|/1 4=\:t)}

// horizontal tree rendering
sh1:{,/'(" ";"┬";"│";"├";"┐";"┬";"─")x}
spr:{y@(-x)_,/(!#y),\:x#-1}
t1:{t:t@\:!|/#'t:|'(y@)\'(!#y)^y
  t:spr[x]@+/(0N;t)*~:\=':t
  c:1+(-y=!#y)+1+@[&#y;+(-1 1_\:)'.cp[y];+;1 2]
  t0:t0+6*t0<{(x|y)&y<4}\t0*|/3 4=\:t0:0^c@t
  (sh1 0^+t0;t)}

// depth first preordering of indices
dfo:{<{,/{,/y,$[^(!x)?y;();o[x]'x@y]}[cp[x]]'&x=!#x}x}

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
