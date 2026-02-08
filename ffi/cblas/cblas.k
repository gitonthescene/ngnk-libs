."\\l ",`env[]`KINIT
imp.ort[`xml;"xml/xml.k"]
imp.ort[`tree;"trees/trees.k"]
todict:!/(`$;::)@'+:

cblas:1:"cblas_new.xml"
parsed:xml.parse cblas

(nn;pp):|1($!#:)\tree.p parsed 0
(tags;text):.=!'parsed 1
gettag:&parsed[1;tags;`nm]~\:

fs:gettag "Function"
args:(^tags?)_/:(=pp)tags fs
fargs:,/'+(tags fs;args)

cb:&"cblas"~/:5#/:fnames:@[;`name]'todict'@[;`attrs]parsed[1]@*'fargs
cb:(|/'"Ellipsis/"~/:/:@[;`nm]',/'parsed[1]@fargs@)_cb

argattrs:(todict'@[;`attrs]@)'parsed[1]@-1_/:1_/:fargs@cb
argtyp:@[;`type]'argattrs

ftyp:gettag "FundamentalType"
ftypnm:todict -1_(@[;`id`name]@todict@[;`attrs]@)'parsed[1] tags ftyp

tdtyp:gettag "Typedef"
tdtypnm:(ftypnm@`$)'todict@-2#/:(^(!ftypnm)?`$*'|:')_tdmap:(@[;`name`id`type]@todict@[;`attrs]@)'parsed[1] tags tdtyp
tdtypnm,:todict@@[;1 0]'("complex"~/:-7#/:*+:)#tdmap

ptrtyp:!/`$@[;`id`type]@todict'@[;`attrs]parsed[1]tags@gettag "PointerType"
argtyp:{(^p)'[`$($p:ptrtyp x),\:"p";x]}'`$argtyp

qualifiers:(|/"cp"=\:)#''$argtyp
enum:!/(`$;::)@'@[;`id`name]@todict'@[;`attrs]parsed[1]@tags@gettag "Enumeration"
sig:,''/(((enum,ftypnm,tdtypnm)@`$(|/"cp"=\:)_''$argtyp),\:\:" ";" "/''("";"const";"*")@0^(" cp"?)qualifiers)

types:!/1((enum,ftypnm,tdtypnm)@)\`$?,/argbase:(|/"cp"=\:)_/:/:$argtyp /`$(|/"cp"=\:)_/:$?,/argtyp
typemap:!/+((`"_160";"int")
    (`"_427";"float")
    (`"_428";"double")
    (`"_158";"float complex")
    (`"_159";"double complex")
    (`"_427";"float")
    (`"_427";"float")
    (`"_428";"double")
    (`"_428";"double")
    (`"_158";"float complex"))
 
cuts:({-1_(x@)\0}(+/1(!#:)\1+1_~^("LDA";"INC")?3#/:)@)'@[;`name]'argattrs
ptrs:("";"P")@|/''"p"=(*|)''(~#:')_/:_'[cuts;qualifiers]
basetyp:,/''[("_"/" "\)''(![!enum;#[#.enum;,"int"]],typemap)@`$*''(~#:')_/:_'[cuts;argbase];ptrs]
names:*''(~#:')_/:_'[cuts;@[;`name]'argattrs]
tdargs:{,/(x;",";y)}''[basetyp;names]

`0:structs:{"STRUCT",(","/x)/"()"}'+(6_/:@[;`name]'todict'@[;`attrs]parsed[1]@*'fargs cb;$#'a;" "/'a:{x,y/"()"}''[{("SCA";"VEC";"MAT")0^("";"INC";"LDA")?3#x}''*''|''(~#:')_/:_'[cuts;@[;`name]'argattrs];tdargs])
/*''(~#:')_/:_'[cuts;@[;`name]'argattrs]
