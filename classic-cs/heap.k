\d heap
/ shift down
sd:{$[(y<z)&0<c:*>x@i:(z>)#y,-1 0+2*y+1;o[@[x;y,i[c];:;x@i[c],y];i[c];z];x]}

/ shift up
su:{$[y&>/v:x@y,s:-2!y-1;o[@[x;s,y;:;v];s];x]}

/heapify
hp:{sd/[x;|:!c:1+-2!-2+#x;#x]}

/ heap insert
hi:{su[x,y;#x]}

/ max extract
hx:{(*x;sd[(*|x),1_x;0;#x])}

/ heap sort
hs:{h:hp@x;*(-1+#x)({(sd[@[x;0,y;:;x@y,0];0;y];y-1)}.)/(h;-1+#x)}
\d .
