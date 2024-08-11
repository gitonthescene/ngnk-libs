/ Z-order curve
zo:{,/r+/:2*r:4/2\!x}

/ Parent vector from color vector
pc:0,&!/1(4+&#:)\&~0,/

/ Calculate the parent vector from a grid
pt0:{(x[0],,@[1+&4;i;:;0];(1_x 1),d@i:&|/'1&#'(&/'~:)_/:d:1_/:'@/1(=*:')\x[1;0])}
pt:{pc@*(#*|:)pt0/(();,+4\&~=':(,/x)@<zo@#x)}

/ calculate the coordinates of each cell from a parent vector
ix:{4!-1+(~:)_/:+|(x@)\(!#x)}

sz:-2+#(-2!)\

/ Given a grid, fill in a color vector
ct:{0N 4#1_@[(,/x)@(<zo@#x)@4/+0^@[;!sz@#x]@/:ix[p];?p:pt x;:;0]}

/ Draw a grid given a scale and a color vector
drw:{(2#x)#(&!/((0,/y)@i;d:(4*)/[;1]'l-#'ii)@\:<0^@[;!l:sz x]@/:ii:ix[p]@i:(!#p)^p:pc y)@zo@x}

/ Facing cell
f0:{(~x[0]=(|':&\=':).|1*:\x 0;x 1)}
f0:{$[*|r:(&\=':).|1*:\x 0;x;(~x[0]=|':r;x 1)]}
fv:{|2/f0@2 2\|x}   / facing vertically
fh:{|2/|f0@|2 2\|x} / facing horizontally

/ fill in null colors with the color of nearest ancestor
fl:{y@{+/*/((::;x)@\:;~1~:\^y@)@\:z}[x;y]/!#y}

mg:{P:?/1(-1_/:)\C:?@/1(<:+|1(#:')\)\,/I:ix'pc'x
 fl[P]'(0,/'x)@'I?\:C}

/ quad tree for a given cell and necessary parent cells
cl:{0N 4#(0 -1,1)@[1+&4*#x;|x+4*!#x;:;2*~!#x]}

/ Trivially facing; x=0 : vertically, x=1 horizontally
tf:{|@[|y;0;@[(2 3 0 1;1 0 3 2)x;]]}

ex0:{a:x[1;z]
  $[#n:,/x[0]?(n0:&'~a)+\:'1+4*z
    o[x;y,'(1+,/(4*(!#a)+#*|y)+'n0;a);n]
    y,'(!0;a)]}

/ extract subtree from x at index y
ex:{ex0[(0,1+&~,/x;x);(0N;!0);,y]}

/ amend z to x at index y
/ Here z and x are (p;c) parent color pairs
am:{x,'(y^+/1(1*(#*|x)*4*~^:)\*z;*|z)}

/ reorder color vector based on parent vector
ro:{y@<x}
