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
