\l lambda-calculus.k

para"lambda expression:"
para s:"(^x.x y x y)z z (^y.z z)"
para""

para"parsed into a tree"
:p:prs[s]
para""

para"displayed in a friendly way"
dsp[s;p]
para""

para"pruned of excess nodes"
:(n;p):alpha/prn[s]
dsp[n;p]
para""

para" .. as a table"
tbl[n;,p]
para""

para"table showing where parens are"
tbl[n;(p;"("=n)]
para""

para"different table showing where parens are"
tblb[n;"("=n]
para""

para"table showing where z's are in last lambda"
tblmb[n;(m;("z"=n)*m:p=*|&"^"=n)]
para""

para"beta reduced"
:(n;p):beta/prn[s]
dsp[n;p]
para""

para"beta reduced (using currying)"
dsp/beta/prn s
para""

para"alpha conversion"
:(n;p):prn \"((^x.xxx)(^x.xxx))"
alpha[n;p]
para""

para"add back in closing parentheses"
dspf[n;p]
para""

para"actually two trees"
para"  node at index 8 is its own parent and thus a root"
tbl[s;,prs \s:"(^x.xxx)(^x.xxx)"]

para""

para"remove redundant parentheses"
dspf/(n;p):prn "(((^x.(x(x)x))(^x.(xxx))"
dspf/rrp/(n;p)
para""

para"some expressions"
para"zero: ",z:"(^f.^x.x)"
para"successor: ",sc:"(^n.^f.^x.f(nfx))"
para"one!: ",one:sc,z
para""

para"alpha convert, do one reduction"
para"  note that beta reduction automatically adds a root node"
dspf/alpha/prn "(",one,")"
dspf/beta/alpha/prn one
para"  canonaclize names"
dspf/alpha/beta/alpha/prn one

para""

para"converge..."
dspf/alpha/(beta/alpha/)/prn one
para""

para"more ints"
:i:{"(",y,x,")"}\(,z),5#,sc
para""

para"reduce three showing steps"
para"  three applications of a ..."
dspf/'rr:alpha/'(beta/alpha/)\alpha/prn i[3]
para""

\d t
\l trees.k
\d .

para"pictures!"
para"  we don't canoncialize here (not needed) for clarity"
rr:beta/\alpha/prn i[3]
shw:{(tr;lb):t.pad[pd]t.t2[pd:|/#'x]y; `0:,/+(tr;t.ctl@x@lb)}
shw/'rr;
para""

para"numerical variables"
loadNumerical[]
:(n;p):prn \"(((^x.(x(x)x))(^x.(xxx))"
dspf/(n;p)

para"translate to characters"
ALPHA@dspf/(n;p)
para""

para"alpha reduction still works"
ALPHA@dspf/alpha/(n;p)
para""

para"beta reduction too"
ALPHA@dspf/beta/alpha/(n;p)
para""

para"Can now do more complicated reductions..."
para""
rt:{x/,'"()"}
T:rt["^x.^y.x"]
F:rt["^x.^y.y"]
A:rt["^p.^q.p q p"]
O:rt["^p.^q.p p q"]
SX:rt["^n.^f.^x. f(nfx)"]
ADD:rt["^m.^n.^f.^x.m f (nfx)"]
MUL:rt["^m.^n.^f.m(nf)"]
ZP:rt["^n.n",rt["^z.",F],T]
TIMES:!0
clrt:{TIMES::!0}
ev:{(r;n):prn rt[x]
  dspf/alpha/{beta/alpha[x;y]}//(r;n)}
    /dspf/alpha/{c:`t@0;rr:beta/alpha[x;y];TIMES,:-c-`t@0;rr}//(r;n)}

TF:(dspf/alpha/prn@)'(T;F)

para"OR"
+1("TF"TF?/:ev'.:')\("O,",","/,')'"TF"@+!2 2
para""

para"AND"
+1("TF"TF?/:ev'.:')\("A,",","/,')'"TF"@+!2 2
para""

para"numbers"
N0:{rt y,x}\(,F),15#,SX
N:ev'N0
ALPHA@N@!5
para""

para"addition 10~7+3"
~/(N[10];ev ADD,N0[7],N0[3])
para""

para"multiplication"
N[6]~ev MUL,N0[2],N0[3]
+t,,~'/(,N@(*/)t),,ev'MUL,/:,/'+N0@t:!5 3
para""

para"is zero"
+1("TF"TF?/:ev'ZP,/:N0@)\0 1 3 7
para""

para"predecessor"
PR:rt["^n.n",rt["^g.^k.",ZP,rt["g",N0[1]],"k",rt[SX,"(gk)"]],rt["^v.",N0[0]],N0[0]]

N[2]~ev e: PR,N0[3]
para""

para"predecessor 2"
PR:rt["^x.^y.^f.fxy"]
FST:rt["^p.p",T]
SND:rt["^p.p",F]
SFT:rt["^p.",PR,rt[SX,rt[FST,"p"]],rt[FST,"p"]]
base:rt[PR,N0[0],N0[0]]
PRE:rt["^n.",SND,rt["n",SFT,base]]

~/(N[13];ev PRE,N0[14])
para""

Y:rt["^f.(^x.f(xx))(^x.f(xx))"]
TH:,/2#,rt["^x.^y.y(xxy)"]
X:rt["^f.(^x.xx)(^x.f(xx))"]
TRI:rt[TH,rt["^a.^n.",ZP,"n",N0[0],rt[ADD,"n",rt["a",rt[PRE,"n"]]]]]
FAC:rt[TH,rt["^a.^n.",ZP,"n",N0[1],rt[MUL,"n",rt["a",rt[PRE,"n"]]]]]

rr:ev \TRI,ALPHA@N[5]
~/(N[15];rr)

rr:ev \FAC,ALPHA@N[3]
~/(N[6];rr)
