/ radix grade based on [[https://codeberg.org/ngn/k/src/branch/master/o.c#L28][ascZ]]

rg:{*|(#*:){a:x 1
            c:+\@[&1+10;1+g:x[0;0]@a;+;1]
            (1_x 0;*|{(@[x 0;y;+;1];@[x 1;x[0]y;:;z])}/[(c;&#a);g;a])}/(|10\x;!#x)}

/ counting sort grade [[https://en.wikipedia.org/wiki/Counting_sort]]
cg:*{{(@[x 0;c y;:;z]
       c:@[x 1;y;-;1])}/[(&#x;+\@[&10;x;+;1]);|x;|!#x]}

