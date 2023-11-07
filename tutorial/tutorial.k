\d tut
evl:{.[`k@.:;,x;"\n",]}
hdr0:{(x$($z)/"[]"),y}

hdr:hdr0[6].
ply:{(*|x)=~#*x}{inp:2(|(&\~^"\n\r\t "?)_)/1:1
                $[(~#inp)~"\\"=*inp;`0:evl[inp];];(inp;"\\"=*inp)}/
hdl:{n:z+*x;i:$[z;y;*|x]
     $[~"\\"~*y;
       z&"goto"~4#1_y;n:`I$*|" "\y;]
       (n;i;z+1)}
nxt:{(2>*|:){(s;i;c):x;`1:$[~c;hdr i
           "::"~r:evl[*i];"";(2#" "),r,"\n"]
           hdl[(s;i);*ply@0 0;c]}/(x;y;0)}
cmts:"/"=@'/1(*'&'~^:)\
btch0:{((x+1)$"\n")/'(&|/1(-1_0,)\~cmts@y)_y}
btch:btch0[6]
run:{{(*|x)<#*x}{r:tut.nxt[*|x]@@/x;(*x;$[1=(*r)-*|x;*r;(*|+*x)?*r])}/(x;0)}
\d .

/$[#x;{tut.nxt[0N]'+1(+\~tut.cmts@)\tut.btch@0:x}'x;];

$[#x;{tut.run@+1(+\~tut.cmts@)\tut.btch@0:x}'x;];
