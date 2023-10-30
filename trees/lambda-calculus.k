imp:{(.0#`)`$(x,(1&#x)#"."),/:y}

(P;L;C;D;N):(=)@/:(Pc;Lc;Cc;Dc;Nc):Cs:"(^). "
LP:|/"^("=\:

/ parse vector of nodes into a parent vector
prs:{(!#x)^'*|{(s;p):x;p,:**|s
     $["("=y;s,:,(-1+#p;1)
       "^"=y;s,:,(-1+#p;1+*|*|s)
       ")"=y;[s:(-*|*|s)_s;p:-1_p; p,:**|s]
      ]
     (s;p)}/[(,0N 0;!0);x]}

/ re-sort both the values and parent indices according to a permutation
srt:{(x@z;(<z)@y@z)}

/ parse and prune unnecessary nodes
prn:{(-#&i)_/:srt.(x;prs[x];<i:|/" .)"=\:x)}

/ pleasant display of tree
dsp:{`0:(" ",x)(1+!#x)*/:(,1+&#x),~~((y@)\!#y)-\:|\*/1(y=)\!#y}

/ last child of a given node in a given parent vector
lc:{(c;r):(-1+#x;|x)
 *|-1_(c-r?)\y}


rrp:{[n;p]rm@:&(P n)rm:(,/L@Lc^n@g@)_&2>#'g:=p
     p:@[p;w;:;p@(-/1(~^rm?p@)\)/w:(&|/0,rm=\:p)^rm]
     rm,:rm2:(P n@)#2+(L n@)#&2=#'g:=p
     p:@[p;w;:;p@p@w:(&|/0,rm2=\:p)]
     (n;p):(-#rm)_/:srt[n;p;<@[&#p;rm;:;1]]
     $[2=+/~p;1_/:(n;0|p-1);(n;p)]}


copy:{[n;p;e;l]
      (sn;sp):(*/l)#/:(Pc;0),'(-*l-1)#/:e#/:(n;p)
      sp:@[(#p)+(0|sp-e-*l)+(*l)*(&#/|l);(*l)*!*|l;:;0N]
      (sn;sp)}

beta0:{[n;p;off]
      (l;e):0 1+lc[p]'off
      idx:(2;1+idx?l)_idx:off+!e-off:*off
      p:@[p;(off=p@)#*idx;:;p[off]]
      idx[0]:(n[off+1]=n@)#*idx
      l:1 0+#'|idx
      ro:<,/@[&#p;*idx;,;(|l)#1]
      (n;p):(n;p),'copy[n;p;e;l]
      p:@[p;&^p;:;p@*idx]
      (n;p):srt[n;p;<ro]
      (-#l)_/:srt[n;p;<@[&#p;ro@l:(off+!2),,/idx;:;1]]}

rdx:{[n;p]{y;~^x}[w]#+(l;w:*'s@'&'l<s:(&'p=/:p@p@)l:&L n)}

beta:{[n;p](n;p):(Pc,n;0,(~p=!#p)*1+p)
      $[~#rd:rdx[n;p];:rrp/(n;p);]
      rrp/beta0[n;p;*rd]}

alpha:{[n;p]((+(,n),,@/|1(`c$"`"+!1+|/)\?/|1?:\i*m)@'m:(~LP n)*~^i:*'(~:)_'+i*n=/:(Nc,n)@(2+i)*L n@i:(p@)\!#p;p)}

dspf:{[n;p]{$[P x@z;Pc,(,/o[x;y]'y@z),Cc
   L x@z;Lc,c[0],Dc,1_c:,/o[x;y]'y@z
   x@z]}[n;^'[;?p]@=p]0}

/
/ Left associate (not needed)
la:{[n;p]g:-1_'g@!d:(#p)+=(P n@)#&(0<)#-2+#'g:^'[;?p]@=p0:p
    $[~#d;:(n;p);]
    (n;p):(n,(#e)#Pc;@[p,e:,/d;;:;].(g,'.d;(.(,/|1*:\)'|'d),'(!d),'.-1_'d))
    ro:<(!#p0),&#'d
    srt[n;p;ro]}
\

/ Leave as numbers

\d numerical
imp:(.0#`)`imp

(Pc;Lc;Cc;Dc;Nc;Cs;prn):imp[""]@$`Pc`Lc`Cc`Dc`Nc`Cs`prn
alpha:{[n;p]((+(,n),,@/|1(4+!1+|/)\?/|1?:\i*m)@'m:(~ LP n)*~^i:*'(~:)_'+i*n=/:(Nc,n)@(2+i)*L n@i:(p@)\!#p;p)}

ALPHA:Cs,`c$"a"+!26
TONUM:{[n;p](ALPHA?n;p)}
prn0:prn
prn:TONUM/prn0@

(P;L;C;D;N):(=)@/:(Pc;Lc;Cc;Dc;Nc):Cs?(Pc;Lc;Cc;Dc;Nc)
Nc:0N
LP:|/(Pc;Lc)=\:
\d .

loadNumerical:{ (Pc0;Lc0;Cc0;Dc0;Nc0;Cs0):imp["numerical";$`Pc`Lc`Cc`Dc`Nc`Cs]
 (ALPHA0;alpha0;prn0;P0;L0):imp["numerical";$`ALPHA`alpha`prn`P`L]
 Pc::Pc0
 Lc::Lc0
 Cc::Cc0
 Dc::Dc0
 Nc::Nc0
 Cs::Cs0
 ALPHA::ALPHA0
 alpha::alpha0
 prn::prn0
 P::P0
 L::L0 }

para:{`0:x}
tbl:{`0:,/'$/|1(-:1+|/#',/)\$(!#x;x),y}
tblb:{`0:(x;" ^"@y)}
tblmb:{`0:(,x),(" -";" ^")@'y}
