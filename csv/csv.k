/ ngn/k
ESC:  "\""    / escape
ROW:  "\n"    / row separator
FLD:  ","     / field separator

uq:{$[*q:x=ESC;-1_x@&~q&2!+\q;x]}          / unquote
sp:{[s;x](1&l)_'(l:0,&(2!+\x=ESC)<x=s)_x}  / split
csvorig:{uq''sp[FLD]'sp[ROW;x]}            / parse CSV

/ faster, but perhaps less elegant
csvnew:{m:=\~q:"\""=x:"\n",x
     d:m&/:",\n"=\:x
     f:1_/:(-/1((+\q)@)\&|/`b$d)_ :[;q:<\q]_x
     _[+/1(!#:)\(+\d 0)@&d 1;f]}

csv:csvnew
