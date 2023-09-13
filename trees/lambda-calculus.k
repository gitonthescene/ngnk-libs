/ parse vector of nodes into a parent vector
prs:{*|{(s;p):x;p,:**|s
     $["("=y;s,:,(-1+#p;1)
       "^"=y;s,:,(-1+#p;1+*|*|s)
       ")"=y;[s:(-*|*|s)_s;p:-1_p; p,:**|s]
      ]
      (s;p)}/[(,0 0;!0);x]}

/ re-sort both the values and parent indices according to a permutation
srt:{(x@z;(<z)@y@z)}

/ parse and prune unnecessary nodes
prn:{(-#&i)_/:srt.(x;prs[x];<i:|/" .)"=\:s)}

/ pleasant display of tree
dsp:{`0:(" ",x)(1+!#x)*/:(,1+&#x),~~(y@)\!#y}

/ last child of a given node in a given parent vector
lc:{(c;r):(-1+#x;|x)
 *|-1_(c-r?)\y}

beta:{[n;p]l:lc[p;1]
      (li;ri):(3,l+1)_!#p
      si:(n[2]=n@)#li
      p:@[p;(~l<)#&1=p;:;0]
      (sn;sp):(*/ll:#'(1,ri;si))#/:("(";0),'(1+l)_/:(n;p)
      sp:@[0|sp-l;(*ll)*!*|ll;:;p@si]
      off:&#/|ll
      (n;p):srt.((n;p),'(sn;(1&(*ll)!!#off)*(#p)+sp+(*ll)*off)),,ro:<<,/@[&#p;si;,;(|ll)#1]
      (-#ll)_/:srt[n;p;<@[&#p;(<ro)@ll:1 2,si,ri;:;1]]}
