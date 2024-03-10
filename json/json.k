T:1_4\0xe74717
ws:~^"\t\n\r "?

/ make sure that all the brackets match
chkb:{$[(,2)~?(2!!#:)#-':,/x@@[y;]#'=z;;`err@"mismatched brackets"]}

/ make sure that keys to dictionaries are strings
chkds:{$[(,"\"")~?x@y@-1+&":"=x@y;;`err@"keys are strings"]}

/ pairs have objects as parents
/ children of objects are pairs
chko:{$[((,"{")~?x@y@z@":"=x@y)&(,":")~?x@y@(~:)_&~^(&"{"=x@y)?z;;`err@"malformed object"]}

pr:{(g;p):0 2\<((2*#x)#!2)+{2}#x;f:&~p;(g@(|\p*!#p)@f)@<g@f};dp:{+/~~,/(x@)\,!#x}

prn:{p:pr@z@y;@[p;;:;].+.{$[~#c:&":"=x[y]@z;(();())
                            ~1~#?3!c;`err@"malformed object"
                            z@(c+\:1 2;c)]}[x;y]'=p}

trmt:{(-/1(ws@x@-1+)\)/y}
tree:{ x:trmt[x;#x]#x
       m:{$[~^x?3;`err@"stray escape";x>0]}@0{T[x;y]}\2^"\\\""?x
       s:(+/1(ws@x@)\)/&|':m<|/w:"{[]},:"=\:x
       d:(-|/2#w)++\+/1 1 -1 -1*w:4#w>\:m
       chkb[x;|/w;d]
       chkds[x;s]
       end:trmt[x]'!/|+1_,':s,#x
       s:@[s;|w;:;s@w:-1 0+\:&":"=x@s]
       s@:&~|/",]}"=\:x@s
       chko[x;s;p:prn[x;s;d]]
       (p;s#end) }

hx:16/+/1(-39*~:10>)\-48+_: / to hex
trm:{a:~^ws@x;(+/&\a)_(-+/&\|a)_x}
u8:{`c$(0x00c0e0f0[c],c#128)+(0,64+&c:1+128 2048 65536'x)\x} /utf8 encode
L:("true";"false";"null");E:`c$"\"\\/bfnrt"!(34 92 47 8 12 10 13 9)
de:{,/{i:&<\"\\"=s:" ",x;s:@[s;ii@j;:;w@j:&~^w:E@s@ii:1+i];,/1_'(0,i)_s}'{$["\\u"~2#x;(u8@hx@2_6#x),6_x;x]}'_[;x]0,@/1(&"u"=x@1+)\&<\"\\"=x}

tkn:{x@+/(!--)\(!y;.y)@\:z}
leaf:{$["\""~*t:tkn[x;y;z];de@1_-1_t;~&/^(`c$"-","0"+!10)?*t;._t;~^L?t;`$t;t]}

prs:{t:tree[x];{$[~^":["?t:x[!y[1]]@z; o[x;y]'((y[0][z])^z)^0N
                 "{"~t; !/+o[x;y]'((y[0][z])^z)^0N
                 leaf[x;y[1];z]]}[x;(=t[0];t[1]);0]}


dmp:{$[~^`c`C?t:@x;`k@x;~~/1_:\t;(","/o'x)/"[]";`m~t;(","/":"/'+o''(!x;.x))/"{}";~^`i`f?t;$x;|/(`$L)~\:x;$x]}
