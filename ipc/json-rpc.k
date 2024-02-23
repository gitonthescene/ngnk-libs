ec:!/+((`ParseError          ;-32700)
       (`InvalidRequest      ;-32600)
       (`MethodNotFound      ;-32601)
       (`InvalidParams       ;-32602)
       (`InternalError       ;-32603)
       (`ServerNotInitialized;-32002)
       (`UnknownErrorCode    ;-32001))

J:("jsonrpc";"2.0")
not:{(J;("method";x)),$[#y;,("params";y);()]}
req:{not[x;z],,("id";_y)}
rpl:{(J;("id";_x);("result";y))}
err:{(J;("id";_x);("error";!/+(,("code";y)),z))}

pe:{err[`null;ec`ParseError;,("message";"json parse error")]}
msg:{x}

ie:{err[(x["id"];`null)[y];ec`InvalidRequest;,("message";"invalid request")]}

/ accomodate for parser by forcing symbols and flooring ints
vld:{$[~*c:~^($!x)?("jsonrpc";"id";"method");0
       (~c[2])|~`C~@x`"jsonrpc";0
       c[1]&^`i`C`s?t:@ _x`"id";0
       c[1]&(`s~t)&~`null~x`"id";0;1]}

err0:{`err@"WHOOPS",`k@x}

LKUP:(,"dummy")!{}

nme:{z;err[(x`"id";`null)@*^($!x)?,"id";ec`MethodNotFound;,("message";"method \"",(x`"method"),"\" not found")]}

lkup:{$[mth:.[.:;`$x`"method";{::}];mth;~^(!LKUP)?x`"method";LKUP@x`"method";nme[x]]}
hdl:{$[~vld[x];:ie[x;*^($!x)?,"id"];];res:(lkup[x])[x`"params"];$[^*($!x)?,"id";();rpl[x`"id";res]]}

/ Maybe wrap in try and return `InternalError on errors that bubble up?
recv:{$[(::)~r:.[`j?;,x;{::}];pe[x];~/1_:\@r;msg@hdl@r;msg@hdl'r]}
