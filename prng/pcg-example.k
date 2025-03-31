/ Experiments with PCG's [[https://www.pcg-random.org]]
\l pcg.k

rs:lcg[16;43317 39 5]        / 16-bit LCG
hi:-[bits 8]!rs              / high bits

prs:bits[8]/+0N 2#

/ Generate PBM's (greyscale) of various plots [[https://en.wikipedia.org/wiki/Netpbm#File_formats]]
rando1["lcg.pbm";16;prs hi]             / high bits
rando1["pcg.pbm";16;prs shftpcg16[rs]]  / 8-bit output function

rando1["lcg8.pbm";16;prs bits[8]!-[bits 8]!rs]             / bits 8-15
rando1["lcg7.pbm";16;prs bits[8]!-[bits 7]!rs]             / bits 7-14
rando1["lcg6.pbm";16;prs bits[8]!-[bits 6]!rs]             / bits 6-13
rando1["lcg5.pbm";16;prs bits[8]!-[bits 5]!rs]             / bits 5-12
rando1["lcg4.pbm";16;prs bits[8]!-[bits 4]!rs]             / bits 4-11
rando1["lcg3.pbm";16;prs bits[8]!-[bits 3]!rs]             / bits 3-10
rando1["lcg2.pbm";16;prs bits[8]!-[bits 2]!rs]             / bits 2-9
rando1["lcg1.pbm";16;prs bits[8]!-[bits 1]!rs]             / bits 1-8
