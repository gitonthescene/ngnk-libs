sm:{C:@[&256;x[0];:;1+!#x[0]]                    / create a state machine with character classes
    (C;((1_*+y)?(1_'1_y))@\:(".",x[1])?1_*y)}    / x and table y

lex:{y{x[y;z]}[x[1]]\x[0]@z}            / parse text z with state machine x and initial value y

spl:{(,x[0]),1_+(+y)@(*y)?x[1]}         / split character classes using a mapping

mrg0:{f:&'"."=r:@/1(&^" ."?*:')\1_z[0]@\:1^(*z[0])?x  / preparse sub-state machine for merging
      @[;;:;]'[r;f;y@f:f^\:x?z[1]]}

mrg:{cs:" .",x[0];((,cs),,/mrg0[cs;x[1]]'y),,x[1]}
