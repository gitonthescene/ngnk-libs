
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
dsp:{`0:(" ",x)(1+!#x)*/:(,1+&#x),~~(y@)\!#y}

/ last child of a given node in a given parent vector
lc:{(c;r):(-1+#x;|x)
 *|-1_(c-r?)\y}

rrp:{[n;p]rm@:&("("=n)rm:(,/"^"="^"^n@g@)_&2>#'g:=p
  p:@[p;w;:;np:p@(-/1(~^rm?p@)\)/w:(&|/0,rm=\:p)^rm]
  (n;p):(-#rm)_/:srt[n;p;<@[&#p;rm;:;1]]
  $[2=+/~p;1_/:(n;0|p-1);(n;p)]}


copy:{[n;p;e;l]
      (sn;sp):(*/l)#/:("(";0),'(-*l-1)#/:e#/:(n;p)
      sp:@[(#p)+(0|sp-e-*l)+(*l)*(&#/|l);(*l)*!*|l;:;0N]
      (sn;sp)}

beta0:{[n;p;off]
      (off;e):off
      l:lc[p;off]
      e:1+lc[p;e]
      idx:(2;1+idx?l)_idx:off+!e-off
      p:@[p;((1+off)=p@)#*idx;:;off]
      p:@[p;(off=p@)#*idx;:;p[off]]
      idx[0]:(n[off+1]=n@)#*idx
      l:1 0+#'|idx
      ro:<,/@[&#p;*idx;,;(|l)#1]
      (n;p):(n;p),'copy[n;p;e;l]
      p:@[p;&^p;:;p@*idx]
      (n;p):srt[n;p;<ro]
      (-#l)_/:srt[n;p;<@[&#p;ro@l:(off+!2),,/idx;:;1]]}

rdx:{[n;p]{y;~^x}[w]#+(,*l),,w:*'(*|l)@'&'</l:1(&'p=/:p@p@)\rd:&"^"=n}

beta:{[n;p](n;p):("(",n;0,(~p=!#p)*1+p)
      $[~#rd:rdx[n;p];:rrp/(n;p);]
      rrp/beta0[n;p;*rd]}

alpha:{[n;p]((+(,n),,@/|1(`c$"`"+!1+|/)\?/|1?:\i*m)@'m:(~|/"(^"=\:n)*~^i:*'(~:)_'+i*n=/:(" ",n)@2+i*"^"=n@i:(p@)\!#p;p)}

dspf:{[n;p]{$["("=x@z;"(",(,/o[x;y]'y@z),")"
   ~^(!y)?z;(x@z),,/o[x;y]'y@z
   x@z]}[n;^'[;?p]@=p]0}

/
/ Left associate (not needed)
la:{[n;p]g:-1_'g@!d:(#p)+=("("=n@)#&(0<)#-2+#'g:^'[;?p]@=p0:p
  $[~#d;:(n;p);]
  (n;p):(n,(#e)#"(";@[p,e:,/d;;:;].(g,'.d;(.(,/|1*:\)'|'d),'(!d),'.-1_'d))
  ro:<(!#p0),&#'d
  srt[n;p;ro]}
\

para:{`0:x}
tbl:{`0:,/'$/|1(-:1+|/#',/)\$(!#x;x),y}
tblb:{`0:(x;" ^"@y)}
tblmb:{`0:(,x),(" -";" ^")@'y}
