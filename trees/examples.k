\l trees.k

TT:"ABEFG56N8PV"
P0:P:0 0 1 2 20 4 4 6 7 20 9 10 10 10 9 14 15 20 17 18 20
R:dfo[P]
T:(TT 3 2 1 10 4 10 2 0 7 4 2 10 9 10 2 0 7 2 0 7 3)@<R

// reorder the indices based on depth first pre-ordering
P:redo[P;R]
D:#'(P@)\'!#P
`0:"\n -- vertical tree --\n"
`0:t0[P;D],'"  ",/:T

(tr;l):t1[2]@P
`0:"\n -- horizontal left adjusted --\n"
`0:1_,/+(tr;T@l)

(tr;l):t2[2]@P
`0:"\n -- horizontal center adjusted --\n"
`0:1_,/+(tr;T@l)

// Generate a random depth vector with x nodes (min 2)
rd:{0,(0|x-2){x+@/1(*1?#:)\1-&(1|-_-0.25*d),1+&d:1|x}\1}

sh:{(tr;l):((t1;t2)[x-1])[2]@y
  `0:(,""),1_,/+(tr;(,/`c$97+!#y)@l)}

`0:"\n -- random trees horiz left adj --"
sh[1]'p'rd'10#10+!5;
`0:"\n -- random trees horiz ctr adj --"
sh[2]'p'rd'10#10+!5;

// Generate random length labels
/ pad the picture to make room
/ center the labels
sh:{ls:`c$97+(1+(#y)?5)?\:26
  (tr;l):pad[p]((t1;t2)[x-1])[p:1+|/#'ls]@y
  `0:(,""),/+(tr;ctl@ls@l)}

`0:"\n -- random trees horiz left adj random width labels --"
sh[1]'p'rd'10#10+!5;
`0:"\n -- random trees horiz ctr adj random width labels --"
sh[2]'p'rd'10#10+!5;

`0:"\n\n -- random code --\n"
`0:C:"@//1(*1?#:)\1-&(1|-_- 0.5*d),1+&d:1|=':{x}"

/ Nested lists are in effect trees
/ The lists themselves are the inner nodes

`0:"\n -- render nested list as tree --\n"
`0:`k@sexpr:(+;3;(-;2;8))
shw/(`k';::)@'|{+{$[`A~@z;o[#y]/[y,,(x;z);z];y,,(x;z)]}[0;();x]} sexpr

/ render parse tree considered as an sexpr
k:{$[`c~_@x;x;~`v~@x;`k@x;26=.x;"GAP";`k@x]}

`0:"\n -- render parse tree --\n"
(P;L):sexpr2apt `p@C
shw[k'L;P]
