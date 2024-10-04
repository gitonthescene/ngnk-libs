/ http://shootout.alioth.debian.org/debian/benchmark.php?test=meteor&lang=all#about
/ http://www-128.ibm.com/developerworks/java/library/j-javaopt/
/ [[http://nsl.com/k/meteork4.k]]

/ P = pieces
P:(,`)!,(``)
P[`b]:`e`e`e`se
P[`y]:`se`sw`w`sw
P[`p]:`w`sw`se`se
P[`w]:`sw`w`se`se
P[`g]:`w`se`se`sw
P[`t]:`se`sw`ne`e`se
P[`k]:`ne`ne`nw`sw
P[`m]:`nw`sw`sw`se
P[`r]:`e`e`ne`e
P[`c]:`e`e`ne`se
P _: `
/ Q = rotations , rotations of flips
D:`nw`w`sw`se`e`ne!`w`sw`se`e`ne`nw
E:`nw`w`sw`se`e`ne!`ne`e`se`sw`w`nw
Q:(!P)!Q,'E@/:Q:5 D\'. P

/ R = reversals
F:`nw`w`sw`se`e`ne!`se`e`ne`nw`w`sw
R:@[Q;!Q;F@]

/ N = neighbors
N:(`e`se    !1 5
   `w`e`sw`se    !0 2 5 6
   `w`e`sw`se    !1 3 6 7
   `w`e`sw`se    !2 4 7 8
   `w`sw`se    !3 8 9
   `nw`ne`e`sw`se  !0 1 6 10 11
   `nw`ne`w`e`sw`se  !1 2 5 7 11 12
   `nw`ne`w`e`sw`se  !2 3 6 8 12 13
   `nw`ne`w`e`sw`se  !3 4 7 9 13 14
   `nw`w`sw    !4 8 14
   `ne`e`se    !5 11 15
   `nw`ne`w`e`sw`se  !5 6 10 12 15 16
   `nw`ne`w`e`sw`se  !6 7 11 13 16 17
   `nw`ne`w`e`sw`se  !7 8 12 14 17 18
   `nw`ne`w`sw`se  !8 9 13 18 19
   `nw`ne`e`sw`se  !10 11 16 20 21
   `nw`ne`w`e`sw`se  !11 12 15 17 21 22
   `nw`ne`w`e`sw`se  !12 13 16 18 22 23
   `nw`ne`w`e`sw`se  !13 14 17 19 23 24
   `nw`w`sw    !14 18 24
   `ne`e`se    !15 21 25
   `nw`ne`w`e`sw`se  !15 16 20 22 25 26
   `nw`ne`w`e`sw`se  !16 17 21 23 26 27
   `nw`ne`w`e`sw`se  !17 18 22 24 27 28
   `nw`ne`w`sw`se  !18 19 23 28 29
   `nw`ne`e`sw`se  !20 21 26 30 31
   `nw`ne`w`e`sw`se  !21 22 25 27 31 32
   `nw`ne`w`e`sw`se  !22 23 26 28 32 33
   `nw`ne`w`e`sw`se  !23 24 27 29 33 34
   `nw`w`sw    !24 28 34
   `ne`e`se    !25 31 35
   `nw`ne`w`e`sw`se  !25 26 30 32 35 36
   `nw`ne`w`e`sw`se  !26 27 31 33 36 37
   `nw`ne`w`e`sw`se  !27 28 32 34 37 38
   `nw`ne`w`sw`se  !28 29 33 38 39
   `nw`ne`e`sw`se  !30 31 36 40 41
   `nw`ne`w`e`sw`se  !31 32 35 37 41 42
   `nw`ne`w`e`sw`se  !32 33 36 38 42 43
   `nw`ne`w`e`sw`se  !33 34 37 39 43 44
   `nw`w`sw    !34 38 44
   `ne`e`se    !35 41 45
   `nw`ne`w`e`sw`se  !35 36 40 42 45 46
   `nw`ne`w`e`sw`se  !36 37 41 43 46 47
   `nw`ne`w`e`sw`se  !37 38 42 44 47 48
   `nw`ne`w`sw`se  !38 39 43 48 49
   `nw`ne`e    !40 41 46
   `nw`ne`w`e    !41 42 45 47
   `nw`ne`w`e    !42 43 46 48
   `nw`ne`w`e    !43 44 47 49
   `nw`w    !44 48)

/ island detection
isl:{[v]r:~*{(~*x)&~^*|x}{(e;v;i):x
    c:1;v[i]:1
    (i;v;c):(#*:){(i;v;c):x
      v[i]:1
      i:?,/.:'N(),i
      c+:#i@:&~v i
      (i;v;c)}/(i;v;c)
  (5!c;v;v?0)}/(0;v;v?0)
  r}

/ positions on board b of piece c, transformation t, cell i
pos:{[b;c;t;i]b,(b {N[x;y]}\i_Q[c;t]),b {N[x;y]}\|i#R[c;t]}

/ print solution
/ print:{`0:(,""),(10#1 0)!'-1 10#,/2$'_ssr[x;" ";"."];}

/ K = pieces x transformations x cells (nb: piece t has an extra cell)
K:+(,/,/:\:)/(!Q;!12;!6)
K:K[;&(5>K 2)|`t=*K]

/ I = all positions of all permutations of all pieces at all positions
/ C = corresponding colors (pieces)
I:{(pos[x]'). K}'!50            / all positions
w:(&~|/'^:)'I                   / where valid positions
I:I@'w                          / keep those positions
C:,/'$K[0;w]                    / keep those colors
w:I{&~y>&/'x}'!50               / where i <= cell in position
I:I@'w                          / keep those positions
C:C@'w                          / keep those colors
w:&0<#:'w                       / where non-empty
I@:w                            / keep those positions
C@:w                            / keep those colors

/ S = solution counter, T = termination, U = recursion counter
S:0
T:2098
U:0

/ solve
solve:{[b]
 U+:1                           / count recursions
 $[^p:("",b)?" ";:,b;]          / if no empties, return solution
 c:C p;i:I p                    / colors, positions
 w:&^b?c                        / where unused colors
 $[~#w;:();]                    / if no unused colors available, exit
 w@:&~(&~b=" ")(|/~^?)/:i[w]    / where no overlap
 t:@[b;;:;]'[i w;c w]           / place colors at positions
 t:(isl'~" "=)#t                / eliminate islands
 ,/solve't}                     / solve next layer

/ run -> T solutions
T=#B:solve 50#""
B
/

nb:  because solve is tail-recursive, we can rewrite it as a convergence:
== NOTE: CODE BELOW NOT PORTED ==

solve:{[b]
 if[(#b)=p:b?" ";:,b]           / if no empties, return solution
 if[p=#C;:()]                   / if no colors for this position, exit
 c:C p;i:I p                    / colors, positions
 w:&~c in?b                     / where unused colors
 w@:&~i[w](|/in)\:&~b=" "       / where no overlap
 t:@[b;;:;]'[i w;c w]           / place colors at positions
 t@:&isl'~t=" "                 / eliminate islands
 t}                             / return set

B:(,/solve')/,50#""             / solve all




