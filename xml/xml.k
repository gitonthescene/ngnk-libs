\d xml
MX:0N-1
ev:#'/|1(2*-2!#:)'\
fm:{(v@g)@&~0<':0&\+\(,/(#'x)#'1 -1)@g:<v:,/x}
fr:{m:2!fd:{y'x}.'x@/:i:+&~=#x
    $[&/,//^k:m?\:0;:0N;]
    j:*&=/1&/\MX^x[i[;0]]@'k
    MX^1 0+x[i[j;1]]@0 1+(fd@j)@k@j}
cl3:{r:fr@(,-1,fm@x[!2]),2_x;$[0N~r;x;x@'(&~</r>\:)'x]}
cl2:{{r:fr@x;$[0N~r;x;x@'(&~</r>\:)'x]}/x}
WS:" \t"
tr:{&/(~`cmt=;(|/^" \n\t"?" ",)')@'+x}
/tag parse
tp:{l:@/1(&0<#:')\1_'(0,@/1(&2!{x'y}[-1+*-/x[2 0]]@)\&|/WS=\:s)_s:-1_x[1]
    (tp;nm;loc;len;attrs):(`tag;l[0];x[0];#x[1];{(x;-1_2_y)}@/'(0,/:(1_l)?\:"=")_'1_l)
    +(`tp`nm`loc`len`attrs;(tp;nm;loc;len;attrs))}
pt:{c:0,((#c)#0 1)+c:@/1<:\,//x[3 4]-x[0]
    (tp;loc;len;cnt):(`txt;x[0]
                      #x[1]
                      tr#+(`txt`cmt`cdata@(0,,/((#*)'x[3 4])#'1 2,\:0)@<c
                      c_x[1],((*|c)~#x[1])#" "))
    +(`tp`loc`len`cnt;(tp;loc;len;cnt))}
ps:{!/+((pt;tp)@>/"<!"=2#x[1])x}
cc:{cl:2+cl@'&'"-]"='x@cl:y[1;4 3]-2
    op:op@/:&'("--";"[CDATA["){x~(#x)#y}/:\:x@(op:y[0;0])+\:2+!7
    cl2@ev@fm'+(op;cl)}
cl0:{[cms;cds;is]@/1(&2!(+/1(#/|(,0 1),#:)\@/1<:\cms,cds)')\is}
cl:{[ds;qs;cms;cds;sp];(ds;qs):0 2_cl3/,/cl0[cms;cds]@''(ds;qs)
    (ds@'&'^(,/'sp)?'ds;,/qs;cl0[cms;cds]''sp)}
lvl0:{(+\(,/(#'x)#'2 -1 0 -2)@g)-(,/(#'x)#'2 0 0 0)@g:<,/x}
nds0:{[xml;sep;dd],/'(nds;(.'dl)@'&'(!'dl:(@/1(=c')\)'(sep))=)@\:/:!#nds:+(c;(c:@/1<:\dd)_xml)}
p1:{ds:&'"<>"=\:x
    qs:&'"'\""=\:x;
    sp:-1 1+'sp@'/:&''~^ds?'(sp:&'"!?/]-"=\:x)+\:/:-1 1
    (ds;qs;sp)}
p2:{(ds;qs;sp):p1[x];:(ds;qs;sp),cc[x;sp]}
parse:{(ds;qs;sp;cms;cds):p2[x]
       (ds;qs;sp):cl[ds;qs;cms;cds;sp]
       (lvl0[ds,sp[;2]];ps'nds0[x;(qs;cms;cds);,//0 1+/:(ds;sp[;2])])}
\d .
