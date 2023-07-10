\l bigint.k

/ -- (not (n base 2)) ~ ((127 - n) base 2) for all base 127 digits n --
`0:"-- use subtraction to not bits --"
~/(~2\!128;2\127-!128)

/ -- bigints use lists of digits --
/ Signed 7-bit numbers use the most significant bit for the signed bit
/ negation uses twos complement
`0:"-- twos complement --"
+2\*'(,59; \neg[,59])

/ -- since we're base 128, numbers which use the 7th bit need a leading zero --
/ to provide a signed bit.
`0:"-- extra digit for signed bit --"
,/'+'2\'(0 69; \neg 0 69)

/ -- double negation is the identity --
`0:"-- negation is own inverse --"
neg neg[,69]
neg neg[0 69]

/ -- for unsigned base 128 bigints, extra digit is not needed --
`0:"-- unsigned addition --"
add[,69;72]

/ -- signed addtion follows the convention above --
`0:"-- signed addition --"
adds[,69;,72]

/ -- Handling the signed bit is tricky --
/ test cases
#T:,/,/:\:/2#,,',/1 neg'\T0:,/1(+|1(0 127@64>)\)\12 63 121
/ convert to integers
c:{(-1 1s)*128/((neg;::)@s:64>*x)x}
/ test that digit-wise addition matches addition
/ covers (all?) the odd sign bit cases
`0:"-- addtion test --"
~/(+/'c''T;c'adds.'T)

/ divisor times all positive digits base 128
`0:"-- Render base 10 --"
ms:128\'10*1_!128

($n)~ \,/$|*|(#*:){(!0;*|x),' \divmod[ms;*x]}/( \128\n:72932651;!0)
