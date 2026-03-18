."\\l ",`env[]`KINIT
imp.ort[`sat;"sat/tseitin.k"]
para:`0:1("",#/|"-",#:)\

para"boolean formula"
`0: f:"~~a^b v a^~b > c^~b v b^~c"
para""

para"Generate dimacs output"
`0:sat.dimacs/(n;p):sat.prs f
para""

para"tree"
tree.shw/(n;p)
para""

para"basic breakdown"
" = "/'+(n@!d;.d:" "/'n@^'[;?p]@=p)
