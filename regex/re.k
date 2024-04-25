/ Inspired by [[http://nsl.com/papers/re.htm]] by Raul Miller
/ Expanded to J at [[https://code.jsoftware.com/wiki/Essays/RegularExpressions/NondeterministicFiniteAutomata]]

pr:{r:@[;;|;]\[(!0)@&1+|/x;x;!#x];(!#x)^'r@'x-1}

exp:{@[@/r;&=':*|r:1(&1+x<"("=)\y/,'"()";:;"|"]}
msk:{-1_0,<\"\\"=x}
dp:{d:(-x<"|"=y)+2*(-*t)++\-/t:x</:"()"=\:y
    $[1<|/dd:(-*t)++\-/t:x</:"[]"=\:y;`err@"bad character class"
      |/0,~^"()"?y@&x<dd;`err@"bad character class"
      |/dd<0;`err@"bad character class";]
    d+dd}

cls:{$[3>#x;x
       |/0>r:-/i:x@-1 0++1_,':&~|':<\"-"=x," ";`err@"bad class"
       ,/`c$i[1]+!'1+r]}

prs:{ t:dp[m:msk e] e:exp[0,msk[x],0;x]
      (e;t;m):(e;t;m)@\:&~|/m</:"])"=\:e
      (e;t;m):(e;t;m)@\:&~<\"\\"~/:e
      t:pr t
      e:@[e;?(t,&|/"*+?.|^$"=\:e)^&m;`i$]
      t:@[t;;:;].,'/{|y@1(-1+)\&|/x[y]~\:/:"?*+"+0}[e]'=t
      (e;t)}

cmp0:{[e;t] d:(~e[t]~\:"["+0)&|/e~\:/:"^$"+0
      (e;t):(-+/d)_/:(::;(<g)@)@'(e;t)@\:g:<d
      s:{$[`c~_@n:x@z;step@n
      n="?"+0;maybe@o[x;y]@*y[z]
      n="*"+0;rep@o[x;y]@*y[z]
      n="+"+0;rep1@o[x;y]@*y[z]
      n~"("+0;or@o[x;y]'y[z]
      n~"|"+0;seq@o[x;y]'y[z]
      n~"["+0;$["^"=*c:x@y[z];nstep@,cls@1_c;step@,cls@c]
      n~"."+0;nstep@,!0
      x@z]}[e;(=0N,1_t),(,0N)!,!0]@0
      fix s}

cmp:{cmp0.(prs x)}

anc:{[n;t]s:&n~\:"|"+0;e:s^'*'|'&'s=\:t
     +(((s;s);(e;s)))@\:'&'~|/'n[(s+1;e)]~\:/:'("(^";"$$")+0}

scmp:{(n;t):prs x
      (n;t):(::;(<g)@)@'(n;t)@\:g:{y,,/o[x]'x y}[(=0N,1_t),(,0N)!,!0]0
      a:anc[n;t]
      g:@[m;0 1+/:,/(::;(#m)-2+)@'(1|:\(m:&1+@[&#t;a[0];+;2]))?'a[0];:;0N 2#(#t)+!2*#,/a[0]]
      n,:(2*#,/a[0])#0+"*."
      t,:,/+(,/a[1];(#t)+2*!#,/a[0])
      cmp0.(::;(<g)@)@'(n;t)@\:g}

non:256
nul:(non+1)#,!0
final: {(#x)-1}

branch:{,@[nul;non;:;,/x]}
step:{branch[,1],(, @[nul;,/x;:;2]),,nul}
nstep:{branch[,1],(, @[nul;(!non)^,/x;:;2]),,nul}

maybe:{branch[1,#x],1+x}
seq:{.[,/(+\0,-1+#'x)+(-1_'x),,,nul;0,non;,;(~#x)#1]}
rep1:{x[,final x;non],:,0,#x; x,,nul}
rep:maybe@rep1@
or:{branch[m],(,/+/(*|n;x)*1~:\(m+c-1)=x+:m:-1_n:+\1,c:#'x),,nul}
re:seq@step'

comb: {?y,,//x@y}
tc: {comb[x;]'/x}
fix: {comb[tc x[;non];]''x}

next: {?,/x[0][y;x[1]z]}
match:{n:next[(x;"",y)]
       final[x]=|/*(&/#:'){(a;b):y;(x[a;*b];1_b)}[n]/(x[0;non];!#y)}

nfa2dfa:{c:1((@/1<:\?:)','/x@)\;r:{y,,/(x'(~#:')_^[;*+y]@?*|:)'y}[c]/,c x[0;re.non]
         (&|/'~^(,re.final[x])?*r;0^?/r:+r)}

nfacmp:nfa2dfa@cmp@
nfascmp:nfa2dfa@scmp@
nfamatch:{~^x[0]?0{x[y;z]}[x[1]]/y}
