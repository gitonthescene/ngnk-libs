\l parse.k

para:`0:
para"Make a state machine that parses quoted strings handline escapes"
para"----------------------------------------------------------------"
para"First identify the relevant characters and give the classes names."

:G:("\"\\";"QS") / quotes and slashes
para"Define a table indicating relevant transitions."
para"The first row and column are labels and the rest are transitions."
para"By convention the first class is . representing \"everything else\"."
:Q:(" .QS"
    "..Q."
    "QQ.E"
    "EQQQ")

para"\nParse table to generate the class classification table and transition matrix."
:(C;TT):sm[G;Q]

para"\nSome text:"
`0:txt:"This is \"text\" with \"quotes\" and an escaped escape \"here\\\\\" but not here: \\\\"

para"\nParse text using config and start state."
s:1_*+Q
c:1_*Q
P:prs[(C;TT);s?"."]

s@P@txt

para""
para"With the convention that the first class is \"everything else\", you can combine state tables mechanically."

:G:("\"/\\\n ";"QSENW";"..Q...W") / quotes, slashes, newlines and spaces

para"Comments start at slash and end at newlines, but must be preceded by whitespace."
:C:(" .SNW"
    "....W"
    "W.C.W"
    "CCC.C")

para"To aggregate, need the order of the classes in the aggregate table"
para"and which states to transition to from the generic class ."
para"Each sub-state machine declares its internal states and classes"

:T:mrg[-2#G;((Q;"QE";"QS");(C;"WC";"SNW"))]

s:1_*+T
c:".",G[1]
para"\nMake a comment:"
`0:txt:"This is \"text\" with \"quotes\" and an / escaped escape \"here\\\\\" but not here: \\\\"

P:prs[sm[2#G;T];s?"."]
para"\nParse"
`0:pp:s@P@txt
`0:txt
para""
`0:,/":",/:+(pp;txt)

para"\nChallenge: Change state machine to include the closing quote."
