."\\l ",`env[]`KINIT
imp.ort[`p;"parsing/bnf.k"]

hdr:`0:,[""],?[;1;]/1(,#/|"-",#*:)\
rls:,/,/:'/(*:';"|"\')@'+":"\'" "\

g41:"E:E+T|T T:T*F|F F:(E)|i"                 / grammar (4.1)
g42:"E:TR R:+TR| T:FY Y:*FY| F:(E)|i"         / grammar (4.2)
hdr@"|"/'p.aho431[rls g42]@\:4 0 1 2 3 5      / algorithm 4.31

de:"S:iEtS8|a 8:eS| E:b"                      / example 4.33
hdr@"|"/'p.aho431[rls de]@\:2 4 3 0 1 5

as:"S:aSa|aa"                                 / exercise 4.4.5
hdr@"|"/'p.aho431[rls as]
`0:""
(dd;;):e.rec["\0:E ",g41;""]
sh:{?[x[`T]y;z+1;"."]}

S:p.clsr[dd]/+,0 0
ss:(?,/1(,/.'p.gotos[dd]')\)/,S
lbls:sh[dd]/''+'ss

edges:,/(!#l){$[~`m=@y;:();](k;v):y;x,/:+(v;k)}'l:ss?p.gotos[dd]'ss
graph:{"  ",,[;";"]@" "/(," -> "/"node",/:$[(x;y)]),,("label = ",`k[$[z<0;?[*'dd[`T]]@-1-z;`c$z]])/"[]"}.'edges
nodes:" "/'(,'"  node",/:$!#l),','{,[;";"]@,["label = ";`k@x]/"[]"}'l:@'[''"\0"=l;l:"|"/','/|1(,'$!#:)\lbls;"^"]
`0:("digraph fsm {
  fontname=\"Helvetica,Arial,sans-serif\"
  node [fontname=\"Helvetica,Arial,sans-serif\"]
  edge [fontname=\"Helvetica,Arial,sans-serif\"]
  rankdir=LR;
  node [shape = record];")
`0:nodes
`0:graph
`0:,"}"

tbl:p.slrtbl dd
`0:,[""],?[;1;]/1(,#/|"-",#*:)\" |"/'$/|1(|/#',/)\(,[,'"$",1_?,/dd`T],{$[#x;;:""];,/("s r";$:)@'*x}''tbl)@\:8 2 4 6 7 0 1 3 5
`0:""
p.slr[dd]"(i+i)+i*i"
