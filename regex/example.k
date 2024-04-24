\d re
\l re.k
\d .
para:`0:

para"regex: ", rex:"[\\+-]?[0-9]+(\\.[0-9]+)?([Ee][\\+-]?[0-9]+)?"
rx:re.match[re.cmp@rex]
{para"match: ",x;`0:$rx x}'("1";"-3.1415e0";"-.1415e0";"-3.1415e";"dog");

cases:("abc";"xxxabbc";"abbbcyyy";"xxxabbbbcyyy")
testcases:{para"search ",z;`0:$x z;para"match ",z;`0:$y z}

test:{para"---";para"regex: ", x;testcases[re.match[re.scmp@x];re.match[re.cmp@x]]'y;}

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
