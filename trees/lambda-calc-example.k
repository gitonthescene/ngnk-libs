\l lambda-calculus.k
para:{`0:""}

`0:"lambda expression:"
`0:,s:"(^x.x y x y)z z (^y.z z)"
para[]

`0:"parsed into a tree"
:p:prs[s]
para[]

`0:"displayed in a friendly way"
dsp[s;p]
para[]

`0:"pruned of excess nodes"
:(n;p):prn[s]
dsp[n;p]
para[]

`0:"beta reduced"
:(n;p):beta.(prn[s])
dsp[n;p]
para[]
