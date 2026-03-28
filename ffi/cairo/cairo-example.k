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
h:200
w:200

#buff:`c$&h*s:kairo.formatStrideForWidth[f;w]           / Needs to stay alive as long as surf
surf:kairo.imageSurfaceCreateForData[(buff;f;w;h;s)]
cairo.status kairo.surfaceStatus surf
cr:kairo.create surf
cairo.status kairo.status cr
kairo.setSourceRGB[(cr;1.0;1.0;1.0)]           / set color to white
kairo.rectangle[(cr;0.0;0.0;1.0*w;1.0*w)]
kairo.fill cr                                  / fill background
kairo.setSourceRGB[(cr;0.0;0.0;0.0)]           / default color black
kairo.setLineWidth[(cr;1.0)]                   / default line width

kairo.arc[(cr;40.0;40.0;20.0;0.0;pi2)]         / draw a circle
kairo.closePath cr
kairo.stroke cr

kairo.surfaceFlush surf

p6:(3=4!!#:)_buff                              / drop alpha channel

"/tmp/circle.ppm"1:,/[("P6";" "/$(h;w);$255),\:"\n"],p6

/ data:kairo.imageSurfaceGetData surf         / when there is no initial buffer
kairo.surfaceDestroy surf
kairo.destroy cr
