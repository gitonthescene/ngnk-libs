\d sm
\l sparse.k
\d .
smm:sm.mm   / sparse matrix multiply
sp:sm.m2sm  / sparsify matrix (SCR format)

sh:-1_#'*:\

`prng@0
mk:{(x#0)@[;;:;1]'1?/:#/x}

/ random pair of sparse matrices
(ml;mr):mk' \ds:0N 2#(5+3?15)0 1 1 2

/ total number of elements in full matrix
*/+ds

sml:sp@ml
smr:sp@mr

/ sparse matrix multiply
(w;v):smm.(sp'(ml;mr))

/ convert results into a sparse matrix
sm.spf[v;w;1+*|/w]

/ full multiplication
:mm:+/'ml*\:mr

/ shape of result matrix
:d:(sh'(ml;mr))@'!2

/ regression test
mm~d#@[&*/d;d/'w;:;v]
