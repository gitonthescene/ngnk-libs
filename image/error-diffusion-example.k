\l error-diffusion.k

/ grey scale pbm with range 0 255
/ This image is taken from [[https://georgeclinton.com/family/sylvester-stewart/]] and
/ converted to a pnm using [[https://imagemagick.org]]

img:.'3_0:"Sylvester-Stewart.pnm"

"img.pnm"0:{s:-1_#'*:\x;("P1";" "/$s)," "/'$~255=ediff[setup[0 255;specs[y]]]@x}[img;"burkes"]

`0:"done"
