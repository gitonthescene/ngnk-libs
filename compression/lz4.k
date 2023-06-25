// decompression
LZ4HDR:0x184D2204
islz4:LZ4HDR~|4#

flgs:{(vs;b):0 2_(8#2)\x
  $[~0 1~vs;`err"unsupported version";]
  `bi`bc`cs`cc`"_"`did!b}
bdb:{`"_"`bmx`"_"!2/'0 1 4_(8#2)\x}

frm:{islz4@x
  (f;b):(flgs;bdb)@'x[4 5]
  off:8 4*`cs`did#f
  sz:256/256!|x@7+!off`cs
  did:x@7+off[`cs]+!off`did
  ((7++/off)_x;f;b;sz;did)}

blks:{(out;in):y
  sn:$[x`bi;"";out]
  $[0x00000000~s:|4#in;out
    0>*s;(out;""),'(4+0,256/(256!s)-128,3#0)_in
    [(b;r):(4+0,256/256!s)_in
     (4*x`bc)_r                      / block checksum.  Just drop for now.
     (out,*(#*|:)f/(sn;b);r)]]}

tk:{1++/&\255=7#x}

f0:{(r;s;l;m):0 0,16 16\**(t;b):0 1_x
  $[l=15;[(s;b):_/|1(0,tk@)\b;l:+/l,s];]
  $[m=15;m:+/m,#/r:|1 tk\(2+l)_b;]
  (l;4+m;256/|b[l+!2];*r;b)}

f:{(l;m;off;r;b):f0[*|x]
     m*:lst:~l=#b
     (n,m#(-off)#n:(*x),l#b;(l+r+2*lst)_b)}

dcm:{0 4_'(~0x00000000~4#*|:) blks[*flg]/("";**(data;flg;rest):0 1 2_frm x)}

/
// compression
:t:"this his repeats because repeating helps"
/:t:"haaaaaaaaa\0"
*{ \(r;s;lb):y
  r:$[(x-1)<@/i:1(*>:)\(*lb)*~|/'a:z=s[+/lb]
      r,,((#s)-*i;i:|/'lb@\:*|i);r]
  (r;s,z;1 0+(0;,&z=s),'(*lb;a)@\:&0<#'a:(*|lb)@'&'a)}[4]/[(();"";(,-1;,,0));t]
+(!#t;t)
\
