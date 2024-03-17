\d re
\l re.k
\d .
\d tree
\l trees.k
\d .

/(e;t):re.prs \rex:"(([ab]|cd\\+)+\\)e*)fgh"
(e;t):re.prs \rex:"[\\+-]?[0123456789]*(.[0123456789]*)?([Ee][\\+-]?[0123456789]*)?"

tree.shw[`k'e;t]
rx:re.match[re.cmp rex]
rx"1"
rx"-3.1415e0"
rx"dog"

/
num: re.rep[re.re[,"0123456789"]]
sign: re.maybe[re.re[,"+-"]]
fp: re.fix mm:re.seq[(sign;num;re.maybe[re.seq[(re.re[,"."];num)]];re.maybe[re.seq[(re.re[,"Ee"];sign;num)]])]

calc:1((@/1<:\?:)','/fp@)\
r:,calc fp[0;re.non] / T[init;]
r:{x,,/(calc'(~#:')_^[;*+x]@?*|:)'x}/r

*(s;t):+r
T:0^s?t
A:&|/'~^(,re.final[fp])?s

~^A?0{T[x;y]}/"1"
~^A?0{T[x;y]}/"-3.1415e0"
~^A?0{T[x;y]}/"dog"
