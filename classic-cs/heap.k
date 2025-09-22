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

E:4#,!0
add:{$[~#*x;:y;~#*y;:x]
    x,'y+(l;l:#x 1;0;0)}
hi0:{add[x;+,&[3],y]}

/ heap insert
hi:{cm hi0[x;y]}
lk:{y@:~~:\</x[3;y];.[@[.[x;1,y 1;:;y 0];0;^;y 1];2,y 0;+;1]}

/ merge heap
cm:{r:x[0]@<+x[2 3]@\:x[0];*{$[2>#x 1;x;=/x[0;2]r:2#x 1;(lk[x 0; r];x[1]_1);(x 0;1_x 1)]}/(x;r)}

/ min extract
hx:{w:&x[1]= i:x[0]@*<x[3]x[0];(x[3]i;cm @[.[x;(1;w,i);:;w,0N];0;^[;i]@,;w])}

/ helper
shw:{t:(-+/w)_/:((<g)@;::)@'t@\:g:<w:^:*t:x[1 3]
     tree.shw/($:0N,t[1]@<g 1;0,(~p=!#p)*1+p:tree.redo/g:1 tree.dfo\t 0)}

/ leftist heap
\d hplf
E:,0
/ merge
mrg:{$[E~x;y;E~y;x
     ~>/(x;y)@\:1;mk[x 1;x 2;o[x 3;y]]
     mk[y 1;y 2;o[x;y 3]]]}
/ rank join
mk:{(`h;y;z);$[~</r:(y;z)@\:0;(1+r 1;x;y;z)
     (1+r 0;x;z;y)]}

/ remove min
del:{$[E~x;E;mrg/-2#x]}

/ heap from list
l2h:{*{mrg/'0N 2#x,#[2!#x;,E]}/{(1;x;E;E)}'x}

\d .
