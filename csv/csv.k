/ ngn/k
\d csv
ESC:  "\""    / escape
ROW:  "\n"    / row separator
FLD:  ","     / field separator

uq:{$[*q:x=ESC;-1_x@&~q&2!+\q;x]}          / unquote
sp:{[s;x](1&l)_'(l:0,&(2!+\x=ESC)<x=s)_x}  / split
csv:{uq''sp[FLD]'sp[ROW;x]}                / parse CSV
\d .
