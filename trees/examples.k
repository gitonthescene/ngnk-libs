\l trees.k

TT:"ABEFG56N8PV"
P0:P:0 0 1 2 20 4 4 6 7 20 9 10 10 10 9 14 15 20 17 18 20
R:dfo[P]
T:(TT 3 2 1 10 4 10 2 0 7 4 2 10 9 10 2 0 7 2 0 7 3)@<R

// reorder the indices based on depth first pre-ordering
P:redo[P;R]
D:#'(P@)\'!#P
`0:t0[P;D],'"  ",/:T

(tr;l):t1[2]@P
`0:1_,/+(tr;T@l)

(tr;l):t2[2]@P
`0:1_,/+(tr;T@l)

// Generate a random depth vector with x nodes (min 2)
rd:{0,(0|x-2){x+@/1(*1?#:)\1-&(1|-_-0.25*d),1+&d:1|x}\1}

sh:{(tr;l):((t1;t2)[x-1])[2]@y
  `0:(,""),1_,/+(tr;(,/`c$97+!#y)@l)}

sh[1]'p'rd'10#10+!5;
sh[2]'p'rd'10#10+!5;

// Generate random length labels
/ pad the picture to make room
/ center the labels
sh:{ls:`c$97+(1+(#y)?10)?\:26
  (tr;l):pad[p]((t1;t2)[x-1])[p:1+|/#'ls]@y
  `0:(,""),/+(tr;ctl@ls@l)}

sh[1]'p'rd'10#10+!5;
sh[2]'p'rd'10#10+!5;
