// [[https://www.digiater.nl/openvms/decus/vax90b1/krypton-nasa/all-about-sixels.text]]

ESC:`c$27
RNG:128
md:{(-1+&>':n;&<':n;ns:.x(~n:~"0:"'x)'" ")}                            / metadata
cm:{y[2]@{(";"=x@y[1;]@)(1+)\z}[x;y]'(&/"#;"=x@y[0 1]@\:)#i:&"#"=x@*y} / color map
prs:{x:?[;;]/[x;+0 1+d[0 1;]@\:i;d[2;i]#'x[d[1;i:|&"!"=x@*d:md x]]]    / run length encoding
 i:(~&/"#;"=x@d[0 1]@\:)#&"#"=x@*d:md x
 m:(0,d[2;i])@+\@[&#x;d[0;i];:;1]                                      / color mask
 mp:cm[x;d]
 x:(RNG;2;64)/(m;~0 64's;63&{x|-x}s:x-63)
 ({(*(2;64)\)#x}'1_/:f;mp;128!*'f:_/|1(0,&~^27 18?128!)\0,x)}          / (color sixel;color map;feed)

/
  ---------------
  sixel to bitmap
  ---------------
\
rr:{(c;d;s):(RNG;2;64)\x;+c*(2+&6)\'s}                                 / render row
ren:{,/||'{$[~#y;:x;];r:rr[y];$[z=27;(,+/r,\:'&'0|-:1-:\-/#'*'r:(*x;r)),1_x;(,r),x]}/[();x;y]}
m2rbg:{!/(*'x;_0.5+255*%[;100]2_/:x)}
