/ [[/Users/douglasmennella/K/ngnk/growler/k/b.c::10]]
ops:`bu`bv`bs`bg`bd`ba`bp`bm`bM`bx`bX`by`bY`bG`bS`bl`bL`bz`bj`bo`bP`bV`bn`bc
di:&[5],1 1 2 2 2 2 2 2 1 1 1 1 1 1 0 0 2 2 0
ds:0 -1 -1 1 1 1 1 -1 -1 -1 -1 -1 -1 1 -1 1 0 -1 0 1 -1 0 0 1
ks:&[5],-1 -1 0 0 0 0 0 0 0 0 -1 1 0 0 0 0 0 0 0
vs:(":","+","-","*","%","!","&","|","<",">","=","~",",","^","#","_","$","?","@",".","0","1","2","3","4","5","6")

warg:ops!di

ovs:0 32 64 80 96 112,113+!#[ops]-6

deets:{r:(c;i;p):,/(,:;1(ops@)\)@'1(ovs')\256!1_x 1
       r,,_[(#[p]>)#(+/0^1(@[1+0^warg p;]@)\)\0;!#c]}

pgm:{(c;i;p;op):deets x
     r:$/|1(4+|/#:')\,[$256!x[1]0],((1+#$#c)$$1+*'op),'{" "/($x[2;y 0];$[-[x[0;y 0];@[ovs;x[1;y 0]]]]/"[]"),$x[0]1_y}[(c;i;p)]'op
     r:@[r;1+w;,;`k'_[4;x]@-/(c ii;ovs i ii)@\:w:&ops[i ii:*'op]=`bc]
     r:@[r;1+w;,;`k'x[3]@-/(c ii;ovs i ii)@\:w:&|/ops[i ii]=/:`bg`bd`bs]
     r:@[r;1+w;,;vs@-/(c ii;ovs i ii)@\:w:&|/ops[i ii]=/:`bu`bv]
     r:@[r;1+w;,;" "/'+(`k'(4_x)@;vs)@'c@1 2+\:ii@w:&ops[i ii:*'op]=`bV]
     `0:r}

/ max stack
mxs00:{i:1+j:z 0
       r:(i+di[y[1]j]+(y[0][j]=ovs@ops?`bj)*y[0]i
         z[1]+ds[y[1]j]+ks[y[1]j]*y[0]i
         |/1_z)
       $[y[0][j]=ovs@ops?`bz
         @[r;2;|;*|x[y](r[0]+y[0]r[0]-1;r[1])]
         r]}

mxs0:{(x[0]@*:)mxs00[o;x]/y,-1}
mxs:{(c;i;p;op):deets x; @[;0;+;1]mxs0[(c;i);0 0]}

dmp:{`0:" "/'0N 16#0N 2#`hex x 1}

/ skip over a jump (either bz or bj)
skp:{+/1(2+256!x@1+)\y}
stp:{+/1(1+di@ovs'256!x@)\y}

(bg;bd;bj):ovs@ops?`bg`bd`bj

/ collects all the last usages in the body of a cond clause
lu0:{{(~(~x[1+y[0]0])<bj=x[y[0]0])&~[y[0]1]|y[0;0]<-1+y[0]1}[*x]{
      i:ovs'c:256!x[0;y[0]0]
      (n;a):$[bj~c;lu1[x](2+y[0]0;y[0]1);(stp[x 0;y[0]0];!0)]
      $[`bz~ops i;(n,y[0;1]|skp[x 0]@-2+skp[x 0]y[0]0;-1+&#y 1;!0)
        (n,y[0]1;@[y 1;-[#y 1;1]^*(~0 16')#-:(bg;bd)-c;:;y[0]0];y[2],a)]}[x]/(y;-1+&1+#x 1;!0)}

/ collects all the last usages in a cond
lu1:{r:{~[x[0]1]|</*x}{r:lu0[x]y 0
        s:$[~{~[x 1]|</x}r 0;r 0;bj~256!x[0]r[0]0;(2+r[0]0;skp[x 0] r[0]0);(stp[x 0]y[0]0;y[0]1)]
        n:(0>)_ :[;~((y[0;0];s[1]|y[1]))'x[1]]#-1_r 1
        (s;y[1];?y[2],n,r 2)}[x]/(y[0],0;y 1;!0)
     (r[0;1];r[2])}

lux:{lu:x[3]#(*|)'d[0]@=*|d:(::;x[3]@)@'1(-[bg]+l@)\&~(bg+0 16)'l:256!x 1
    lu|:x[3]#(*|)'d[0]@=*|d:(::;x[3]@)@'1(-[bd]+l@)\&~(bd+0 16)'l:256!x 1
    lu:.lu / this just calculates what we have on hand in the source code
    lu}

lu:{lu:lux x
    *|(#[x 1]>*:){
    i:ovs'c:256!x[0;y 0]
    $[(256!x[0;1+y 0])<c~bj;(d[0];y[1],*|d:lu1[x](2+y 0;0))
      (stp[x 0;y 0]+(c~bj)*256!x[0;1+y 0];y 1)]}[(x 1;lu)]/(1;!0)}
