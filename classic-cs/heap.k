/ binary heap
\d hpbn
/ shift down
sd:{$[(y<z)&0<c:*>x@i:(z>)#y,-1 0+2*y+1;o[@[x;y,i[c];:;x@i[c],y];i[c];z];x]}

/ shift up
su:{$[y&>/v:x@y,s:-2!y-1;o[@[x;s,y;:;v];s];x]}

/heapify
hp:{sd/[x;|:!c:1+-2!-2+#x;#x]}

/ heap insert
hi:{su[x,y;#x]}

/ max extract
hx:{(*x;sd[(*|x),-1_1_x;0;#x])}

/ heap sort
hs:{h:hp@x;*(-1+#x)({(sd[@[x;0,y;:;x@y,0];0;y];y-1)}.)/(h;-1+#x)}

/ binomial heap
\d hpbl

hi:{mg@hi0[x;y]}
hi0:{(r;p;d;n):x;(r,#p;p,#p;d,0;n,y)}
mg:{(r;p;d):-1_x
    *{$[2>#l:*|x;x
      ~=/x[0;2;2#l];x
     (cm[*x;2#l];1_l)]}/(x;@/1(<d@)\r)}
cm:{(r;p;d;n):x;y:@/1(<n@)\y
    r:r_r?y@0;p[y@0]:y@1;d[y@1]+:1
    (r;p;d;n)}
hx:{(r;p;d;n):x;m:*>n@r
    p:@[p;r@m;:;0N]
    p:@[p;c;:;c:&p=r@m]
    (n@r@m;mg@(c,r_m;p;d;n))}
\d .
