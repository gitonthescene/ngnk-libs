R:2/+(0;11000000b;11100000b;11110000b)
bits:63(2*)\1
u8:{`c$(0x00c0e0f0[c],c#128)+(0,64+&c:1+128 2048 65536'x)\x} / utf8 encode
u8d:{$[~#x;:!0;~`C~@x;`err@"type"];@'/(/'0 64 64 64s;!''/-1 1*256!*\(bits(0 2 3 4s),'2+&'s:-1+-1_1_-':s;_[-2_s:@[+/1(!#:)\1+R'x;]\0;x:256!x]))} / utf8 decode

u160:{$[bits[16]>x;:,`c$256 256\x;];+`c$256 256\55296 56320+l.bits[10]\x-l.bits[16]} / utf16 encode
u16:{,/u160 x}     / utf16 encode (big endian)
u16l:{,/|'u160 x}  / utf16 encode (little endian)

u16d0:{,/{$[1=#x;x;l.bits[16]+l.bits[10]/l.bits[10]!x]}'256/''256!_[-2_@[+/1(!#:)\1+~^0xdfd8?*'h;]\0;h:x]} / utf16 decode
u16d:{$[~#x;:!0;~`C~@x;`err@"type"];u16d0 0N 2#x}     / utf16 decode (big endian)
u16dl:{$[~#x;:!0;~`C~@x;`err@"type"];u16d0@|'0N 2#x}  / utf16 decode (little endian)
