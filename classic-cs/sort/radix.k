/ radix grade based on [[https://codeberg.org/ngn/k/src/branch/master/o.c#L28][ascZ]]
rg:{*|(#*:){a:y 1
            c:+\@[&1+x;1+g:y[0;0]@a;+;1]
            (1_y 0;*|{(@[x 0;y;+;1];@[x 1;x[0]y;:;z])}/[(c;&#a);g;a])}[x]/(|x\y;!#y)}

/ counting sort grade [[https://en.wikipedia.org/wiki/Counting_sort]]
cg:{*{{(@[x 0;c y;:;z]
       c:@[x 1;y;-;1])}/[(&#y;+\@[&x;y;+;1]);|y;|!#y]}[x]y}
