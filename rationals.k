gcd:*(*|:)(|!\)/
add:{(+/*/(x;|y);*/*'|'(x;y))}
sub:{add[x;-1 1*y]}
mul:{*/(x;y)}
div:{mul[x;|y]}
red:{(-gcd x)!x}
