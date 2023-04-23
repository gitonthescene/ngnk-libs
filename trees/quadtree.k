/ z-order
ds:(0 0;0 1;1 0;1 1)

/ parent vector from color vector
prt:{0,p@(!#p)@&(#p:&~x)#4}

/ paths to root from parent vector
pth:{(x@)\'!#x}

/ Z-order curve
zo:{,/r+/:2*r:4/2\!x}

/ render
drw:{ d:#'ps:pth[prt[c:0,,/x]]  / depth, paths to root
 dm:2#*s:*/'(-/1|/\d)#\:2       / size of each pixel, dimensions of graph
 pts:{[c;s;ps;i]|(c@i;+/'*/(s*s:s@p;4!-1+p:-1_'ps@i))}[c;s;ps;&1&c]  / upper left pixels in final graph
 `0:(,""),".#"dm#(2 0 1@{y+(~y)*x}\@[&*/dm;;:;].pts)@zo@-1+|/d       / fill out the rest of the box
}

/ quad tree from (2^N)x(2^N) grid. qt[grd;zo@N]
qt0:{(p;s):z;|((ps@&~w),\:-2!s;@[w;&w;:;1+x@ps@&w:(f-1)=-/y@1 -1_'0 1+\:ps:p+(f:s*s)*!5])}
qt:{0,*(#*|:){(r;q):z;0 1_'z,'qt0[x;y]@**|z}[grd;+\=':0,grd:(,/x)@<zo[y]]/(();,0,-2!y)}

ex0:{a:x[1;z]
  $[#n:,/x[0]?(n0:&'~a)+\:'1+4*z
    o[x;y,'(1+,/(4*(!#a)+#*|y)+'n0;a);n]
    y,'(!0;a)]}

/ extract subtree from x at index y
ex:{ex0[(0,1+&~,/x;x);(0N;!0);,y]}

/ ammend z to x at index y
/ Here z and x are (p;c) parent color pairs
am:{x,'(y^+/1(1*(#*|x)*4*~^:)\*z;*|z)}

/ reorder color vector based on parent vector
ro:{y@<x}
