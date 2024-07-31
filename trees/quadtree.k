/ Z-order curve
zo:{,/r+/:2*r:4/2\!x}

/ Parent vector from color vector
pc:0,@/1(&#/|4,#:)\&~0,,/

/ Calculate the parent vector from a grid
pt0:{(x[0],,@[1+&4;i;:;0];(1_x 1),d@i:&|/'1&#'(&/'~:)_/:d:1_/:'@/1(=*:')\x[1;0])}
pt:{pc@*(#*|:)pt0/(();,+4\&~=':(,/x)@<zo@#x)}

/ calculate the coordinates of each cell from a parent vector
ix:{4!-1+(~:)_/:+|(x@)\(!#x)}

sz:-2+#(-2!)\

/ Given a grid, fill in a color vector
ct:{0N 4#1_@[1+(,/x)@(<zo@#x)@4/+0^@[;!sz@#x]@/:ix[p];?p:pt x;:;0]}

/ Draw a grid given a parent vector and a color vector (arguments overspecified)
drw:{(2#x)#(&!/(-1+(0,/y)@i;d:(4*)/[;1]'l-#'ii)@\:<0^@[;!l:sz x]@/:ii:ix[p]@i:(!#p)^p:pc y)@zo@x}

ex0:{a:x[1;z]
  $[#n:,/x[0]?(n0:&'~a)+\:'1+4*z
    o[x;y,'(1+,/(4*(!#a)+#*|y)+'n0;a);n]
    y,'(!0;a)]}

/ extract subtree from x at index y
ex:{ex0[(0,1+&~,/x;x);(0N;!0);,y]}

/ amend z to x at index y
/ Here z and x are (p;c) parent color pairs
am:{x,'(y^+/1(1*(#*|x)*4*~^:)\*z;*|z)}
