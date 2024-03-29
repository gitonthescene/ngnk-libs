pk:{x@*<{x|-x}x-y}

pre:{+/y*0^z@(!#z)+/:|x}
pres:{g:+g@/:\:!g:(x[0;1];x[1])@\:=**x;({+/y*0^z@x-1}.*g;{+/x@'0^y@!#x}[pre.'1_g])}
fldrow:{(e,*y;(*|y),'(e:z-n;n:x[0]@z:z+x[1][*y]%x[3]))}
pr:{fldrow[x]/[(,0.0;(!0;!0)); z+x[2][y]%x[3]]}
ediff:{|*|{(,'*|pr[x;*y;z]),'y}[x]/[(,&#*y;0#,!0);y]}

setup:{l:(w:&0<y[1])-*+&^y[1];f:.[y[1];]'+w;pk[x],pres[(l;f)], y[0]}

specs:!/+(("floyd-steinberg"
  (16;(0  0N  7
       3  5   1)))
 ("sierra"
  (32;(0   0   0N  5   3
       2   4   5   4   2
       0   2   3   2   0)))
 ("sierraTwo"
  (16;(0   0   0N  4   3
       1   2   3   2   1)))
 ("sierraLite"
  (4;(0   0N  2
      1   1   0)))
 ("burkes"
  (32;(0   0   0N  8   4
       2   4   8   4   2)))
 ("stucki"
  (42;(0   0   0N  8   4
       2   4   8   4   2
       1   2   4   2   1)))
 ("jarvis"
  (48;(0   0   0N  7   5
       3   5   7   5   3
       1   3   5   3   1)))
  ("atkinson"
   (8;(0   0N  1   1
       1   1   1   0
       0   1   0   0))))

/

Inspired by
[[https://gist.github.com/0racle/f48586b6b2c05d13e3abbcb046e91dfb][0racle]]
this is an implementation of several error diffusion dithering
algorithms.

Each spec is a divisor along with a distribution of the errors
relative to the location of 0N.

Each row is then scanned, collecting both output and errors
(i.e. difference between the calculated input and the output).  Error
accumulated from a single previous row is calculated by pre.  The
function pres returns both a function which collects error for the
current row and one which aggregates the calculated accumulated error
for each previous row.

The behavior of pres changes depending on the spec and are configured
with setup.  The first argument to setup is the range of output values
the second is the spec which is parsed to produce pre and pres.
