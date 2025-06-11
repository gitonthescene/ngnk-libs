\l lex.k
txt:1:"kmachine.txt"
(N;S;T):+0 1 2_/:"\n"\'"\n\n\n"\txt
M:(`$2*:/'":"\''N)!+(T;*'S)
T2:(mrg[("NSE";"..n...");M`B0`B1`B2];"")
N:(spl[(" .ZDnd";" .DDDd");*M`N0];"")
H:(spl[(" .ZxDH";" .ZxDD");*M`H0];"")
I:(spl[(" .AHxnZDd";" .AAAADDd");*M`I0];"")
S:(spl[(" .AHxnQEZD";" .AAAAQEDD");*M`S0];"")
ds:"0"+!10
as:"aA"+\:!26
G:("\"\\/\n `",(ds;as;"abcdef"),"0xN.";"QESNbsDAHZxnd";"..Q..nbsdIIhII.")
:T:mrg[-2#G]M[`T0`T1],(T2;H;N;I;S),M[`E`W`Z`M]
