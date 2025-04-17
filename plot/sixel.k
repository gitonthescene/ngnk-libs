// [[https://www.digiater.nl/openvms/decus/vax90b1/krypton-nasa/all-about-sixels.text]]
// [[https://vt100.net/docs/vt3xx-gp/chapter14.html]]

ESC:`c$27
RNG:512

ex:{s:x@{x+1+!'y-x+2}.'e@0 1+/:&"P"=x@e:1+/:&ESC=x;(1+s?\:"q")_'s}        / extract streams

md:{(-1+&>':n;&<':n;ns:.x(~n:~"0:"'x)'" ")}                               / metadata
tb:{y[2]@{(";"=x@y[1;]@)(1+)\z}[x;y]'(&/,[z;";"]=x@y[0 1]@\:)#i:&z=x@*y}  / data tables
rl:{?[;;]/[x;+0 1+y[0 1;]@\:i;y[2;i]#'x[y[1;i:|&"!"=x@*y]]]}              / run length encoding
prs:{d:md x;t:tb[x;d]'"#\"";x:rl[x;d]                                     / " emacs :|
 i:(~&/"#;"=x@d[0 1]@\:)#&"#"=x@*d:md x
 m:(0,d[2;i])@+\@[&#x;d[0;i];:;1]                                         / color mask
 x:(RNG;2;64)/(m;~0 64's;63&{x|-x}s:x-63)
 ({(*(2;64)\)#x}'1_/:f;128!*'f:_/|1(0,&~^27 18?128!)\0,x;t[0];*t[1])}     / (color sixel;feed;color map;dims)

/
  ---------------
  sixel to bitmap
  ---------------
\
rr:{(c;s):(RNG;128)\x;+c*(2+&6)\'s}                                       / render row
ren:{,/||'{$[~#y;:x;];r:rr[y];$[z=27;(,+/r,\:'&'0|-:1-:\-/#'*'r:(*x;r)),1_x;(,r),x]}/[();x;y]}
m2rbg:{!/(*'x;_0.5+255*%[;100]2_/:x)}


/
Example:

g:1:"my.sixel"     / load file
s:ex g             / find sixel pics in file (possibly more than one)
(s;f;c;d):prs@*s   / parse the first pic
img:ren[s;f]       / render the image using the sixels and line feed info
(w;h):-2#d         / grab the height and width (if given)
img:w#/:h#img      / crop using the given dimensions (if given)
mp:m2rbg[m]        / generate RBG from color map info
img:mp@img         / apply color map to the image.  Now you basically have a bitmap.
                   

