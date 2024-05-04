/ [[https://www.mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html]]
\l riff.k

/ pi continued fraction A001203
pcf:.'", "\"3, 7, 15, 1, 292, 1, 1, 1, 2, 1, 3, 1, 14, 2, 1, 1, 2, 2, 2, 2, 1, 84, 2, 1, 1, 15, 3, 13, 1, 4, 2, 6, 6, 99, 1, 2, 2, 6, 3, 5, 1, 1, 6, 8, 1, 7, 1, 2, 3, 7, 1, 2, 1, 1, 12, 1, 1, 1, 3, 1, 1, 8, 1, 1, 2, 1, 6, 1, 1, 5, 2, 2, 3, 1, 2, 4, 4, 16, 1, 161, 45, 1, 22, 1, 2, 2, 1, 4, 1, 2, 24, 1, 2, 1, 3, 1, 2, 1"
pi:{y+1%x}/|pcf

fspec:`t`nc`ss`abs`ba`bs`es`vb`cm`sf!2 2 4 4 2 2 2 2 4 16
fmt:{((#r)#!fspec)!r:256/'256!|'-1_(<[#x;]_+\0,.fspec)_x}
prsfmt:{((#c)#!fspec)!256/'|'(c:0,((#x)>)#+\.fspec)_x}

pcm:{[c;r;l]`t`nc`ss`abs`ba`bs!(1;c;r;r*l*c;l*c;8*l)}
mkfmt:{mkchnk["fmt ";,/(256+&'fspec@!v){|`c$x\y}'v:(^:)_k!x@k:!fspec]}

/
  sw:,/440#,_128*`sin@(2*pi*!50)%50
  mkchnk["RIFF"]@,/("WAVE";mkfmt pcm[1;22000;1];mkchnk["data";`c$sw])
