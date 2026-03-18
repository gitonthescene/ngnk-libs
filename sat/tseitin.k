imp.ort[`p;"parsing/bnf.k"]
imp.ort[`tree;"trees/trees.k"]

ops:"()^v>~"
bool:"E:EvT|T T:T^F|T>F|F F:(E)|i|~F"
(dd;;):e.rec["\0:E ",bool;""]

lex:_/|1(&~=':+/1<\\~^ops?)\(^:)_
prs:{a:p.slr[x](^ops?x0)'[x0:*'t:lex y;"i"]
  (n;p):p.a2t[x]a
  rm:(|/"()"=\:n)
  (n;p):(-+/rm)_/:(n@<g;tree.redo[p]g:<<rm)
  (n;p):(n@<g 1;tree.redo/g:1 tree.dfo\{(1=x z)'[z;y z]}[#'=p;p]/p)
  rm:(n<0)&^p?!#p
  (n;p):(-+/rm)_/:(n@<g;tree.redo[p]g:<<rm)
  (@[n;w;:;(t;"t",/:$*|w:&'~:\^p?!#p)];p)}[dd]

T:!/+(("^";(-1 -2 3;1 -3;2 -3))
      (">";(-1 -2 -3;1 3:2 3))
      ("v";(1 2 -3;-1 3;-2 3))
      ("w";(1 2 3;-1 -3;-2 -3))
      ("~";(-1 -3;1 3))
      ("x";(-1 -2 -3;1 2 -3;1 -2 3;-1 2 3))
      ("W";(-1 -2 3;1 2 3;1 -2 -3;-1 2 -3)))

dimacs:{s:,/'+(!d;.d:^'[;?y]@=y)
  d:,[1],/{[x;y;w;z]
    (t;p):$[3=#z;$[~"~"~y z 1;`err"not";(z[2 0N 0];x "~")]
            4=#z;(z[1 3 0];x y z 2);`err"parse"]
    s:1 -1p<0
    s*1+@/(w@t;-1+s*p)}[T;*'x;(&^![T]?*'?x)??[x]?x]'s
  ,["p cnf "," "/$(|/,/d;#d)]," "/'$d:d,\:0}
