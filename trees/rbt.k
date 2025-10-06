/ Red-black trees loosely following Chris Okasaki's "Purely Functional Data Structures"

C:(0 1 2;2 0 1;1 0 2;2 1 0)
E:(4#,!0),0 / (parent;color;value;children;root)

bal:{s:t@C@2/c:2#S:1_<':y[2]@t:3@[y[0];]\x
  $[~0 0~y[1]@2#t;:y;]
  $[~=/c;[y:.[y;(3;-[0>t 3]_(,[!2],S)+2*t);:;-[0>t 3]_(s 0 2;y[3]@~[S 0]+2*t 0;y[3]@S[0]+2*t 0;t 0)]
          w:&'~^y[2]i:(s;y[3]@1 0+2*s 0 2);
          y:.[y;(0;i@'w);:;((t 0;t 3;t 0);s 0 2)@'w]]
         [c:y[3]@~[S 1]+2*t 1
          y:.[y;(3;-[0>t 3]_(~[S 1]+2*t 1;S[1]+2*t 2;S[2]+2*t 3));:;-[0>t 3]_(t 2;y[3]@~[S 1]+2*t 1;t 1)]
          w:&~^y[2]i:(t 2;c;t 1)
          y:.[y;(0;i@w);:;(t 1;t 2;t 3)@w]]]
  $[-1~y[0]s 1;y:@[y;4;:;s 1];]
  r:.[y;(1;s);:;1 0 1];bal[s 1;r]}


ins0:{$[^v:x[2][y 0];[c:#x 0;x:@[x;!4;,;(y 1;z 1;z 0;-1 -1)];
    $[c;bal[c]@.[x;3,y[2]+2*y 1;:;c];.[x;0 0;:;-1]]]
  v>z 0;o[x;(x[3]2*y[0];y 0;0);z]
  v<z 0;o[x;(x[3]1+2*y[0];y 0;1);z]
  `err"repeat"]} / [tree;(node;parent;side);(val;color)] -> tree

ins:{r:ins0[x;(2#x[4]),0;y,~#x 0];.[r;1,r 4;:;1]}

shw:{tree.shw/($x[y][g1]@<g 1;tree.redo/g:1 tree.dfo\0^tree.redo[y 0]@<g1:,//((0>)_,/y[3]![2]+/:2*)\y 4)}
