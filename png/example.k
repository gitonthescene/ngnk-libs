\l png.k

/ [[https://github.com/mthom/scryer-prolog/tree/master/logo]]
png:1:fn:"scryer.png"
$[~png.ispng[png];`err"Not a png file: ", fn;]

(w;h):*png.ihdr@png
idat:png.decmp@png.idat@png
data:png.unfilt[8](h,0N)#idat

/ mark each pixel as either bg color or not
/ extend each row to have length a multiple of 8
bw:((0x5757d3d3dede~/:-2_'0N 8#)'data),\:0
/ collect this data as bytes
/ add a byte to the front to indicate no filtering
bwdata:,/(`c$0),/:(`c$2/+0N 8#)'bw

/ build up a b/w png
png0:png.PNGHDR
/ same dimensions, but now bit-depth 1, color-type 0
png0,:png.mkchnk["IHDR";`c$,/((4#256)\'w,h),1 0 0 0 0]
/ "compress" at level 0
png0,:png.mkchnk["IDAT";png.nocmp@bwdata]
png0,:png.mkchnk["IEND";!0]
"/tmp/bw.png" 1:png0

/ bottom image
/ [[https://www.w3.org/Graphics/PNG/Inline-img.html]]
png:1:fn:"test.png"
$[~png.ispng[png];`err"Not a png file: ",fn;]

(w;h):*png.ihdr@png
idat:png.decmp@png.idat@png

/ Pull out the interlaced images
c:png.iszs[w;h]

PIXELWIDTH:3
ii:(-1_+\0,(*|c)+PIXELWIDTH**/c)_idat

/ Unfilter each separately
rr:png.unfilt[PIXELWIDTH]'((*|c),\:0N)#'ii

/ interlace back into a single image with no filtering
dd:,/(`c$0),/:,/'(0N,w)#((0N,PIXELWIDTH)#,/,/'rr)@<<,/w#'h#png.A7
png0:png.PNGHDR
png0,:png.mkchnk["IHDR";`c$,/((4#256)\'w,h),8 2 0 0 0]
png0,:png.mkchnk["IDAT";png.cmp@dd]
png0,:png.mkchnk["IEND";!0]
"/tmp/testing.png" 1:png0
