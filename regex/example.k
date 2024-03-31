\d re
\l re.k
\d .
para:`0:

para"regex: ", rex:"[\\+-]?[0123456789]+(.[0123456789]+)?([Ee][\\+-]?[0123456789]+)?"
/rx:re.match[re.cmp rex]
rx:re.match[rex]
{para"match: ",x;`0:$rx x}'("1";"-3.1415e0";"-.1415e0";"-3.1415e";"dog");

cases:("abc";"xxxabc";"abcyyy";"xxxabcyyy")
testcases:{para"search ",z;`0:$x z;para"match ",z;`0:$y z}

test:{para"---";para"regex: ", x;testcases[re.search[x];re.match[x]]'y;}

test["ab+c";cases]
test["^ab+c";cases]
test["ab+c$";cases]
test["^ab+c$";cases]

/
/  [[https://github.com/gitonthescene/ngnk-libs/tree/master/trees]]
\d tree
\l trees.k
\d .
(e;t):re.prs rex
tree.shw[`k'e;t]

/ Original
num: re.rep[re.re[,"0123456789"]]
sign: re.maybe[re.re[,"+-"]]
fp: re.fix mm:re.seq[(sign;num;re.maybe[re.seq[(re.re[,"."];num)]];re.maybe[re.seq[(re.re[,"Ee"];sign;num)]])]

/ DFA conversion
calc:1((@/1<:\?:)','/fp@)\
r:,calc fp[0;re.non] / T[init;]
r:{x,,/(calc'(~#:')_^[;*+x]@?*|:)'x}/r

*(s;t):+r
T:0^s?t
A:&|/'~^(,re.final[fp])?s

~^A?0{T[x;y]}/"1"
~^A?0{T[x;y]}/"-3.1415e0"
~^A?0{T[x;y]}/"dog"
