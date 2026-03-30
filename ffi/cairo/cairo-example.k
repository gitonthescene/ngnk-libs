`"./libcairoffi.dylib"2:(`loadcairo;1);

\d cairo.format
INVALID   : -1
ARGB32    : 0
RGB24     : 1
A8        : 2
A1        : 3
RGB16565  : 4
RGB30     : 5
RGB96F    : 6
RGBA128F  : 7
\d cairo
status:("SUCCESS"
        "NO_MEMORY"
        "INVALID_RESTORE"
        "INVALID_POP_GROUP"
        "NO_CURRENT_POINT"
        "INVALID_MATRIX"
        "INVALID_STATUS"
        "NULL_POINTER"
        "INVALID_STRING"
        "INVALID_PATH_DATA"
        "READ_ERROR"
        "WRITE_ERROR"
        "SURFACE_FINISHED"
        "SURFACE_TYPE_MISMATCH"
        "PATTERN_TYPE_MISMATCH"
        "INVALID_CONTENT"
        "INVALID_FORMAT"
        "INVALID_VISUAL"
        "FILE_NOT_FOUND"
        "INVALID_DASH"
        "INVALID_DSC_COMMENT"
        "INVALID_INDEX"
        "CLIP_NOT_REPRESENTABLE"
        "TEMP_FILE_ERROR"
        "INVALID_STRIDE"
        "FONT_TYPE_MISMATCH"
        "USER_FONT_IMMUTABLE"
        "USER_FONT_ERROR"
        "NEGATIVE_COUNT"
        "INVALID_CLUSTERS"
        "INVALID_SLANT"
        "INVALID_WEIGHT"
        "INVALID_SIZE"
        "USER_FONT_NOT_IMPLEMENTED"
        "DEVICE_TYPE_MISMATCH"
        "DEVICE_ERROR"
        "INVALID_MESH_CONSTRUCTION"
        "DEVICE_FINISHED"
        "JBIG2_GLOBAL_MISSING"
        "PNG_ERROR"
        "FREETYPE_ERROR"
        "WIN32_GDI_ERROR"
        "TAG_ERROR"
        "DWRITE_ERROR"
        "LAST_STATUS")
\d .

pi2:6.283185307179586

!`kairo
kairo.version[]
kairo.versionString[]
f:cairo.format.RGB24
h:300
w:200

#buff:`c$&h*s:kairo.formatStrideForWidth[f;w]           / Needs to stay alive as long as surf
surf:kairo.imageSurfaceCreateForData (buff;f;w;h;s)
cairo.status kairo.surfaceStatus surf
cr:kairo.create surf
cairo.status kairo.status cr

f:{y;kairo.fill x}[cr]
s:{y;kairo.stroke x}[cr]
cp:{y;kairo.closePath x}[cr]
rgb:{kairo.setSourceRGB ,[x],y}[cr]
rec:{kairo.rectangle ,[x],y}[cr]
arc:{kairo.arc ,[x],y}[cr]
lt:{kairo.lineTo ,[x],y}[cr]
mt:{kairo.moveTo ,[x],y}[cr]
poly:{(,s;r):0 1_x;mt s;lt'r;}

rgb (1.0;1.0;1.0)                              / set color to white
rec (0.0;0.0;1.0*w;1.0*h)
f[]                                            / fill background
rgb (0.0;0.0;0.0)                              / default color black
kairo.setLineWidth (cr;1.0)                    / default line width

rgb (1.0;1.0;0.0)
arc (100.0;100.0;40.0;0.0;pi2)                 / draw a circle

cp[];s[]
rgb (0.0;0.0;0.0)
arc (100.0;100.0;20.0;0.0;0.75*pi2)            / draw a circle
lt 100.0 100
cp[];f[]
poly (0.0 190.0
     10.0 100.0
     20.0 180.0
     30.0 110.0
     40.0 200.0)

cp[];s[]

(tx;ty;tw;th;;):kairo.textExtents (cr;t:"a b c\0")
cairo.status kairo.status cr
mt 100.0 160
rgb (0.0;1.0;0.0)
kairo.rotate[(cr;pi2*-0.125)]
kairo.showText (cr;t)
cairo.status kairo.status cr

kairo.surfaceFlush surf

p6:(3=4!!#:)_buff                              / drop alpha channel

"/tmp/circle.ppm"1:,/[("P6";" "/$(w;h);$255),\:"\n"],p6

/ data:kairo.imageSurfaceGetData surf          / when there is no initial buffer
kairo.surfaceDestroy surf
kairo.destroy cr
