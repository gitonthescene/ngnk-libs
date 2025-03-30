/ Experiments with PCG's [[https://www.pcg-random.org]]
\l pcg.k

rs:lcg[16;43317 39 5]        / 16-bit LCG
hi:-[bits 8]!rs              / high bits

prs:bits[8]/+0N 2#

rando1["lcg.pbm";16;prs hi]             / high bits
rando1["pcg.pbm";16;prs shftpcg16[rs]]  / 8-bit output function

rando1["lcg8.pbm";16;prs bits[8]!-[bits 8]!rs]             / high bits
rando1["lcg7.pbm";16;prs bits[8]!-[bits 7]!rs]             / high bits
rando1["lcg6.pbm";16;prs bits[8]!-[bits 6]!rs]             / high bits
rando1["lcg5.pbm";16;prs bits[8]!-[bits 5]!rs]             / high bits
rando1["lcg4.pbm";16;prs bits[8]!-[bits 4]!rs]             / high bits
rando1["lcg3.pbm";16;prs bits[8]!-[bits 3]!rs]             / high bits
rando1["lcg2.pbm";16;prs bits[8]!-[bits 2]!rs]             / high bits
rando1["lcg1.pbm";16;prs bits[8]!-[bits 1]!rs]             / high bits
