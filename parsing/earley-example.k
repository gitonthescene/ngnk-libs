\l earley.k

para:`0:
T:(("S:aS|b";"aab")
   ("e:NNe|Ne|";"NNN"))

para"parse grammar \"",p[0], "\" with input \"",((p:T 1)1),"\""
para""

(d;t):rec. p
para"result table"
t
para""

para"result internal data"
d
para""

(rules;itms):dsp[d;t]
para"List of productions"
rules
para""

para"Table of items"
`0:,/'$/|1(2+|/#',/)\($!#itms),'((-1_d[`i]),"-"),'itms
para""

para"trees"
`0:`k'trees[d;t;itms]
para""
para"More explanation to come ..."
