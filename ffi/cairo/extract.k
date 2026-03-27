."\\l ",`env[]`KINIT
imp.ort[`xml;"xml/xml.k"]
imp.ort[`tree;"trees/trees.k"]
todict:{$[#x;!/(`$;::)@'+:x;`id`type`nm!3#,""]}

xml:1:"cairo.xml"
parsed:xml.parse xml

(nn;pp):|1($!#:)\tree.p parsed 0
(tags;text):.=!'parsed 1

tagtyp:@[;`nm]'parsed[1]tags
attrslkp:!/|1@[;`id]'\attrs:todict'@[;`attrs]'parsed[1]tags
idxlkp:![attrslkp]!!#tags
gettag:&tagtyp~\:

fs:gettag "Function"
as:gettag "Argument"
ps:gettag "PointerType"
fargs:tags?(^tags[as]?)_/:(=pp)tags fs
fnames:@[;`name]'attrs@fs

/ resolve pointers
plkp:pid!,'/(@[attrslkp[;`type];]';(^:)_/:,/'"p",/:/:)@'+({c:"c"=*|t:@[attrslkp[;`type];]x;$[^ps?idxlkp t;(x;y);(t;" c"c,y)]}/)/'(,'pid:@[attrs[;`id];]'ps),\:," "

fargtyp:@'[@[plkp;]/;;]/'+|1(~^ps?@[idxlkp;]'')\@[attrs[;`type];]''fargs
qualifiers:(|/"cp"=\:)#''fargtyp

rettyp:@[@[plkp;]/;;]/'+|1(~^ps?@[idxlkp;]')\@[attrs[;`returns];]'fs
retqualifiers:(|/"cp"=\:)#'rettyp

sig:,'/'+(@[attrslkp[;`name];]''bt:_'/'+(-#''qualifiers;fargtyp);" ",/''("const";"*")"cp"?qualifiers)
struct:{(,n;a):0 1_x;"STRUCT",", "/[(n;$[#a];" "/a)]/"()"}','[fnames],'{x,y/"()"}.''+'+("CAIRO",/:/:fargtyp;@[attrs[;`name];]''fargs)
types:" "/',/,\:/'+(,''"CAIRO",/:/:,/:/'+(;):?'(,/qualifiers)@btlkp;,'@[attrslkp[;`name];]'!btlkp;,'tagtyp@@[idxlkp;]'@[attrslkp[;`type];]'!btlkp:=,/bt)

schema:2_0:"types.schema"
schema:@[;0;*'" "\']@{(|&\|^:)_x}''+1_/:2_/:/:_/:/|1(0,&"|"=*:)\"| ",/:schema
sigmacros:{,/("#define S_";x;"(a) ";y)}/'+@[;0 1]@schema
chkmacros:{,/("#define C_";x;"(a) ";y)}/'+@[;0 2]@schema
appmacros:{,/("#define A_";x;"(a) ";y;",")}/'+@[;0 3]@schema
retmacros:{" "/("#define R_CAIRO_",x;y)}/'+(fnames;,'/(@[attrslkp[;`name];]'retbt:_/'+(-#'retqualifiers;rettyp);" ",/'("const";"*")"cp"?retqualifiers))
"sigmacros.h"0:sigmacros
"chkmacros.h"0:chkmacros
"retmacros.h"0:retmacros
"appmacros.h"0:appmacros
`0:struct
