\d png
PNGHDR:0x89504e470d0a1a0a
ispng:{PNGHDR~8#x}
chunk:{(ln;nm):2 4#@[x;y+!8];ln:256/+/1(256*0>)\ln;(ln;nm)}
chnks:{+1_*+(~"IEND"~*|*:){(ln;nm):chunk[x;*|y];((ln;nm);ln+12+*|y)}[x]\(();8)}
data:{(ls;ns):chnks x;+(ns;+/(8+-1_+\8,12+ls;!'ls))}
/ decom leaves temp files that need cleaning up
decom:{n:*. "\\mktemp /tmp/idat-XXXX";n 1:x;. ,/("\\zlib_decompress ";n;" ";n;".dat");1:n,".dat"}
idat:{x@,/(*|)'("IDAT"~/:*:')#data@x}
ihdr:{(w;h;f):256!0 4 8_x@16+!13;(256/+(w;h);f)}

paeth:{(x;y;z)@*<{x|-x}((x+y)-z)-/:(x;y;z)}

unnone:{z}
/unsub:{x_{y,z+y@(#y)-x}[x]/[x#0;z]}
unsub:{,/+\(0N,x)#z}
unup:{y+z}
unavg:{z;`err@"nyi"}
unpaeth:{x_{[x;a;b;c;d];a,256!d+paeth.(a@(#a)-x;b;c)}[x]/[x#0;y;(-x)_(x#0),y;z]}

unfilt:{`c${(t;r):0 1_z;256!(*(unnone;unsub;unup;unavg;unpaeth)t)[x;y;r]}[x]\[(-1+#*y)#0;256!y]}

(CMF;FLG):120 1
nozip:{(`c$CMF,FLG,128,2/'0N 8#l,~l:(16#2)\#x),x}            / No compression [[https://datatracker.ietf.org/doc/html/rfc1950]]
ad32:{b:+/a:(1+\256!x);`c$2/'0N 8#,/(16#2)\'65521!/:(b;*|a)} / [[https://datatracker.ietf.org/doc/html/rfc1950#section-9]]

nocmp:{,/(nozip;ad32)@\:x}

P:,/+(8#2)\256!0xedb88320                                    / [[http://www.libpng.org/pub/png/spec/iso/index-object.html#D-CRCAppendix]]
crctbl:(8{$[*|x;~P=-1_0,x;-1_0,x]}/(32#2)\)'!256
crc:{`c$256\2/~{~crctbl[2/-8#~x=(32#2)\y]=-8_(8#0),x}/[32#1;256!x]}

mkchnk:{(`c$(4#256)\#y),,/1 png.crc\x,y}

\d .