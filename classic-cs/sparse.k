spf:{(,/'(x;.y[1]@d)),,+\0,@[&z;!d;:;]@#'x:x@d:=*y:+y}  / sparsify (CSR)
nnz:{(((,/x)@&,/;+&:)@\:~~x),,#x}                       / non-zero entries and row count
m2sm:{spf.(nnz@x)}                                      / matrix to sparse matrix

rws:{@[i;(-1_x[2])_i:!#x[0];:;!-1+#x[2]]}    / rows
ci:{p@\:{x^x^y}/!'p:='(x;y)}                 / common indices

cr:{(rws;@[;1])@\:x}                         / rows/columns
cx:+,/,/,/:\:'/                              / match elements
enc:{b:1+|/'x;(b;b/x)}                       / encode

mm:{(l;r):`row`col!/:cr'(x;y)
    j:*|e:enc@cx(l`row;r`col)@'w:ci[l`col;r`row]
    c:*/cx((x;y)@\:0)@'w
    (e[0]\'w;v@w:&~~:v:@[;;+;]/[&1+|/j;j;c])}
