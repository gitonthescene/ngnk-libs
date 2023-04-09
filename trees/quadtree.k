
/ z-order
ds:(0 0;0 1;1 0;1 1)

/ parent vector from color vector
prt:{0,p@(!#p)@&(#p:&~x)#4}

/ paths to root from parent vector
pth:{(x@)\'!#x}

/ render
drw:{ d:pth[prt[c:0,,/x]]
 s:*/'(-/1|/\#'d)#\:2             / size of each "pixel" doubles each level "up"
 r:ds@4!-1+p:-1_/:d@w:&~~c        / find quadrant of each non-zero pixel
 r:(dm:2#*s)/'+/'(s@p)*r          / find upper left corner of each pixel
 r:r+{(x*!y)+/:!y}[*s]'s@w        / find all points within "pixel"
 `0:(,"")," .#-"dm#@[&*/dm;r;:;2&c@w]}  / draw all white pixels

ex0:{a:x[1;z]
  $[#n:,/x[0]?(n0:&'~a)+\:'1+4*z
    o[x;y,'(1+,/(4*(!#a)+#*|y)+'n0;a);n]
    y,'(!0;a)]}

/ extract subtree from x at index y
ex:{ex0[(0,1+&~,/x;x);(0N;!0);,y]}

/ ammend z to x at index y
/ Here z and x are (p;c) parent color pairs
am:{(p;rn):x; p,:y^+/1(1*(#rn)*4*~^:)\*z
 (p;rn,*|z)}

/ reorder color vector based on parent vector
ro:{y@<x}
