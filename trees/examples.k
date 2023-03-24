\l trees.k

TT:"ABEFG56N8PV"
P0:P:0 0 1 2 20 4 4 6 7 20 9 10 10 10 9 14 15 20 17 18 20
R:dfo[P]
T:(TT 3 2 1 10 4 10 2 0 7 4 2 10 9 10 2 0 7 2 0 7 3)@<R

// reorder the indices based on depth first pre-ordering
P:redo[P;R]
D:#'(P@)\'!#P
(tr;l):t1[2]@P
tn:T@l
`0:1_(tr,+tn)@<<,/(#tr)#,!2
`0:(sh0 t0[P;D]),'"  ",/:T
