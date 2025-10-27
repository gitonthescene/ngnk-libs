/ [[https://en.wikipedia.org/wiki/SHA-1]]
hs:`B$/:|'(0x67452301;0xefcdab89;0x98badcfe;0x10325476;0xc3d2e1f0)

rr:{x_y,#[x;y]}
lr:{rr[32!-x;y]}
s:({r:(&/[x 1 2]|&[~x 1;x 3];`B$|0x5a827999);r}
   {r:((~=)/x 1 2 3;`B$|0x6ed9eba1);r}
   {r:(&/[x 1 2]|&/[x 1 3]|&/[x 2 3];`B$|0x8f1bbcdc);r}
   {((~=)/x 1 2 3;`B$|0xca62c1d6)})

bits:64(2*)\1
add:{32#`B$bits[32]!*+/`I$`B$`C$'x}

sha1:{m,:`c$&-8!512!-:64+8*#m:x,0x80; m,:|`C$`B$8*#x
  ,/|'`C${c:{x,,lr[1]@(~=)/x@y-3 8 14 16}/[y;16+!80-16]
    r:{(f;k):s[0 20 40 60'z][y]
        t:add(lr[5;y 0];f;y 4;k;x z)
        @[y;4 3 2 1 0;:;(y 3;y 2;lr[30;y 1];y 0;t)]}[c]/[x;!80]
        add'+(r;x)}/[hs;`B$''|''0N 4#/:0N 64#m]}

/
/ TESTS
tst:{t:`t[];r:sha1 x; \`t[]-t;r}
T:(("The quick brown fox jumps over the lazy dog";"2fd4e1c67a2d28fced849ee1bb76e7391b93eb12")
    ("The quick brown fox jumps over the lazy cog";"de9f2c7fd25e1b3afad3e85a0bd17d9b100db4b3")
    ("";"da39a3ee5e6b4b0d3255bfef95601890afd80709")
    ("abc";"a9993e364706816aba3e25717850c26c9cd0d89d")
    ("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";"84983e441c3bd26ebaae4aa1f95129e5e54670f1")
    ("abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu"
     "a49b2446a02c645bf419f995b67091253a04a259")
    (1000000#"a";"34aa973cd4c4daa4f61eeb2bdbad27316534016f"))
~/(`hex'tst';::)@'+T
