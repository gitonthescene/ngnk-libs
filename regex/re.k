/ Inspired by [[http://nsl.com/papers/re.htm]] by Raul Miller
/ Expanded to J at [[https://code.jsoftware.com/wiki/Essays/RegularExpressions/NondeterministicFiniteAutomata]]

pr:{r:@[;;|;]\[(!0)@&1+|/x;x;!#x];(!#x)^'r@'x-1}

exp:{@[@/r;&=':*|r:1(&1+"("=)\x/,'"()";:;"|"]}
msk:{-1_0,<\"\\"=x}
dp:{d:(-x<"|"=y)+2*(-*t)++\-/t:x</:"()"=\:y
    $[1<|/dd:(-*t)++\-/t:x</:"[]"=\:y;`err@"bad character class"
      |/0,~^"()"?y@&x<dd;`err@"bad character class";]
    d+dd}

prs:{ t:dp[m:msk e] e:exp x
      (e;t;m):(e;t;m)@\:&~|/m</:"])"=\:e
      (e;t;m):(e;t;m)@\:&~"\\"~/:e
      t:pr t
      e:@[e;?(t,&|/"*+?"=\:e)^&m;`i$]
      t:@[t;;:;].,'/{|y@1(-1+)\&|/x[y]~\:/:"?*+"+0}[e]'=t
      (e;t)}

cmp:{(e;t):prs x
     s:{$[`c~_@n:x@z;step@n
          n="?"+0;maybe@o[x;y]@*y[z]
          n="*"+0;rep@o[x;y]@*y[z]
          n="+"+0;rep1@o[x;y]@*y[z]
          n~"("+0;or@o[x;y]'y[z]
          n~"|"+0;seq@o[x;y]'y[z]
          n~"["+0;step@,x@y[z];x@z]}[e;=0N,1_t]@0
     fix s}

non:256
nul:(non+1)#,!0
final: {(#x)-1}

branch:{,@[nul;non;:;,/x]}
step:{branch[,1],(, @[nul;n;:;2+&#n:,/x]),,nul}

maybe: {branch[1,#x],1+x}
seq:{,/(+\0,-1+#'x)+(-1_'x),,,nul}
rep1: {x[,final x;non],: ,0, #x;  x,,nul}
rep:maybe@rep@
or:{branch[m],(,/+/(*|n;x)*~:\(m+c-1)=x+:m:-1_n:+\1,c:#'x),,nul}
re:seq@step'

comb: {?y,,//x@y}
tc: {comb[x;]'/x}
fix: {comb[tc x[;non];]''x}

next: {?,/x[y;z]}
match: {final[x]=|/x[0;non]next[x]/y}
