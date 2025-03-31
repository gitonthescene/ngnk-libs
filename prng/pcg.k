/ [[https://www.pcg-random.org]]

bits:2/~!1+

lcg:1_{bits[x]{[x;y;z;w]bits[x]!z+y*w}[x;y 0;y 1]\y 2}@

shftpcg16:{bits[8]!-[bb:bits'[6--[bits 14]!x]]!'x}
rot:{+/(bits[x-y];1)*(-:\bits[y])!\:z}

rotpcg16:{(-[bits 14]!x)rot[8;]'bits[8]!-[bits 6]!x}

/ randograms
/ [[https://www.pcg-random.org/paper.html]]
rando1:{x 0:("P2";"# testing";" "/$(2#d);$256)," "/'$(0N;d:bits -2!y)#@[256+&bits[y];z;:;256-_256*0.5+(!#z)%bits[y]]}

/ [[https://www.pcg-random.org/posts/visualizing-the-heart-of-some-prngs.html]]
rando2:{x 0:("P2";"# testing";" "/$(2#d);$256)," "/'$(0N;d:bits -2!y)#@[256+&bits[y];!d;:;_256*{1%x(2*)/1}'.d:#'=z]}
 
