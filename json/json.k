pr:{(g;p):0 2\<((2*#x)#!2)+{2}#x;f:&~p;(g@(|\p*!#p)@f)@<g@f};dp:{+/~~,/(x@)\,!#x}
lf:{@[x;,/g;:;,/{(*x),-1_x}'g:=@[x;0;-;1]]};
rt:{+/(!#r;-r+1-#r)*'~:\^r:(|x)?!#x}
ds0:{ds:&'"\\\"{}[],:"=\:x;ds[0]:{x@&~<\(1=-)':x}@ds[0];
  ds[1]@:&^ds[0]?-1+ds[1];
  ds}
ds1:{ds:ds0@x;
  $[1~2!#ds[1];`err@"mismatched quotes";];
  ds}
ds2:{ds:ds1@x;
  ds:(1_ds)@'&'1_r:2!{x'y}[ds[1]+(#ds[1])#1 0]\:ds;
  $[|/0,*r;`err@"stray escape";];ds[0]+:(#ds[0])#0 1;
  ds}
  
WS:"\t\n\r "

ns0:{ds:ds2@x;lvl:+\(,/(#:'r)#'0 0 -1 0 -1 0 0 1 0 1 0 0 0)@g:<,/r:ds[!7],1+ds[1_!7];
  nds:((,/r)@g)_x;
  (nds;lvl):(nds;lvl)@\:&0|/'^WS?nds;
  (ns;nds;lvl):(ns;nds;lvl)@\:&~|/"}],"=\:ns:*'nds;
  (ns;nds;lvl)}
  
ns11:{[ns;l;r]:$[(~&//^c?/:ls,,r@c)||/(=/ls:-1_ls)=~^c?*|ls:1_3 l\c:&":"=ns;`err@"malformed object";(c;ls)]}
ns12:{[nds;p;c]$[~(,"{")~?,/nds@p@c;`err@"malformed object";]}
ns13:{[c;p;l;r];(c;ls):c;
  cl:+/(c;l@*|ls)*'~:\=/ls;
  p:@[p;,/(l;r)@\:c;:;c,c];
  l:@[l;(,c),(l;r)@\:c;:;(,cl),2#,l@c];
  (p;l)}
ns1:{(ns;nds;lvl):ns0@x;
  r:rt@l:lf@p:pr@lvl;
  c:ns11[ns;l;r];
  $[0<#*c;[ns12[nds;p;*c];(p;l):ns13[c;p;l;r];];];
  (ns;nds;p;l)}
tree:{(ns;nds;p;l):ns1@x;
  $[(~(,":")~?w)&(#w:,/ns@^'/|(,w),,&'p=/:w)&#w:&"{"=ns;`err@"malformed object";];
  (nds;p;l)}
  
hx:16/+/1(-39*~:10>)\-48+_: / to hex
trm:{a:~^WS?x;(+/&\a)_(-+/&\|a)_x}
u8:{`c$(0x00c0e0f0[c],c#128)+(0,64+&c:1+128 2048 65536'x)\x} /utf8 encode
L:("true";"false";"null");E:`c$"\"\\/bfnrt"!(34 92 47 8 12 10 13 9)

de:{,/{i:&<\"\\"=s:" ",x;s:@[s;ii@j;:;w@j:&~^w:E@s@ii:1+i];,/1_'(0,i)_s}'{$["\\u"~2#x;(u8@hx@2_6#x),6_x;x]}'_[;x]0,@/1(&"u"=x@1+)\&<\"\\"=x}
pt:{$["\""=*x;de@-1_1_x;~&/^(`c$"-","0"+!10)?*x;.(_x);~^*L?x;`$x;x]};
pp:{$[~`C~@*x;`err@"non-string key";x]}
d:{n:y[z];c:c@&~z=c:$[~^(!x)?z;x[z];!0];
  $["["~t:*n;y[c];":"~t;pp@y[c];"{"~t;!/+y[c];pt@trm@n]}
prs:{(nds;p;l):tree@x;*{@[y;z;:;d[x;y]'z]}[=p]/[nds;dp@|!1+|/!dp:=dp@p]}

dmp:{$[~^`c`C?t:@x;`k@x;~~/1_:\t;(","/o'x)/"[]";`m~t;(","/":"/'+o''(!x;.x))/"{}";~^`i`f?t;$x;|/(`$L)~\:x;$x]}
