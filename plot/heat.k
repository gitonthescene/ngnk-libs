// [[https://en.wikipedia.org/wiki/HSL_and_HSV]]
chroma:{[s;l]s*(1-{x|-x}1-2*l)}
c2:{[h;c](_h1;c*1-{x|-x}1-%[;A](2*A)!(h1:%[h;60])*A:1000)}
perm:{,/'(|x,,s+&#*x)@*/1+\\~=1+s:#x}/[;!0]
hsl2rgb:{[h;s;l]c:chroma[s;l];(h;x):c2[h;c];m:l-c%2;_255*m+(c;x;0.0)((@/1<:\+perm 3)0 2 4 5 3 1)@(!7)'h}

/ less fanfare but only chroma component
tbl:+(-1+,/||:\!3)6!![6]+/:4*!3
pct2rgb:{_255*1&0|tbl[s]+(f;1-f)@2!s:_s-f:1!s:6*1!x}
