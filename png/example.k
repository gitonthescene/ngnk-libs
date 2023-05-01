\l png.k
png:1:"scryer.png"
(w;h):*png.ihdr@png
idat:png.decom@png.idat@png
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
png0,:png.mkchnk["IHDR";`c$,/((4#256)\'375 375),1 0 0 0 0]
/ "compress" at level 0
png0,:png.mkchnk["IDAT";png.nocmp@bwdata]
png0,:png.mkchnk["IEND";!0]
"/tmp/bw.png" 1:png0
