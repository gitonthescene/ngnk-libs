/ [[https://en.wikipedia.org/wiki/Pixel-art_scaling_algorithms]]

sh:-1_#'*:\
scl:{d:sh i:x;I:,/i
  N:i?(i:(2+d)/1+!d)+/:(2+d)/D:+|,/-:\=2
  J:0^I@@\:[''(1+!4)*1_-1=':i:0^I@5#N;!#I;;;;].N
  m:4#,~2=+/-1_i
  k:@'[''~m;I*/:m;J]0 1 3 2
  (2*d)#(,//+k)@<<D/(D:|/d)!-2!!2*d}
