/ [[https://en.wikipedia.org/wiki/Resource_Interchange_File_Format]]
/ samples: [[https://www.mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/Samples.html]]

chnk:{(i;l;d):0 4 8_*x;(d;r):(0;+/1(2!)\l:256/|256!l)_d;(r;x[1],,(i;l#d))}
chnks:{*|(#*:)chnk/(x;())}
prs:{+*{{$[|/("RIFF";"LIST")~\:z[0];(,(y;z[0];4#z[1])),,/x[y+1;4_z[1]];,(y;z[0];z[1])]}[o;x]'chnks y}[0]x}

mkchnk:{,/(x;`c$|(4#256)\#y;y,(2!#y)#0x00)}
