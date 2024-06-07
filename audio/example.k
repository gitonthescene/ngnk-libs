\l wav.k

/ Think DSP           [[https://greenteapress.com/wp/think-dsp/]]
/ Mathematics of DFT  [[https://ccrma.stanford.edu/~jos/mdft/]]
/ See also            [[http://arlyle.sdf.org/k/sound.k]]

para:`0:
/ sine wave: 25 samples for one cycle, 440 cycles for 11000 samples per second
FR:11025          / framerate
HZ:27.5           / frequency
AMP:0.5           / amplitude
DR:1.0            / duration
WIDTH:2           / sample width in bytes
rng:2/~!8*WIDTH   / quantization range

nt:note[12]      / twelve tone system
hz:8*HZ          / Base note

mel:{s:+/12 -12*(,'"+-")~/:\:t:(~#:)_" "\x;,/(((~^n)*+\s)+n:0 2 3 5 7 8 10"abcdefgr"?t)@&~s}
chrd:{+/1(+\12*<':)\+/(+\0 2 1 2 2 1 2;-1 0 1)@'("abcdefg";"b #")?'+(" "\x)@/:\:0 1}
dur:{*/(1%4(2*)\1;1.5 1)@'("whqes";". ")?'+((~#:')_" "\x)@/:\:0 1}

mkpcm:{z 1:mkchnk["RIFF"]@,/("WAVE";mkfmt pcm.(x);mkchnk["data";y])}
ser:{,/+|`c$(x#256)\y}

ys:+/sin[;AMP;0;ph[FR;DR]]'hz*nt[chrd "c eb a"]

para"Play a chord: ",wav:"test1.wav"
mkpcm[(1;FR;WIDTH);ser[WIDTH]qnt[rng]apo[0.015]AMP*nrm[1-1e-15]ys;wav]
para""

hz*:2
tune:("g g g d e c  r r + c"
      "e q q e q e. s q   e.")

tone:{$[^y;&#z;apo[0.05;sin[hz*nt y;AMP;0]z]],&_(1-x)*(1%x)*#z}

ys:,/tone[0.65].'+(mel@;ph[FR]'0.65*dur@)@'tune

para"Play a tune: ",wav:"test2.wav"
mkpcm[(1;FR;WIDTH);ser[WIDTH]qnt[rng]apo[0.015]AMP*nrm[1-1e-15]ys;wav]
para""

ys:sin[hz*nt[2];0.5*AMP;0;ph[FR;DR]]
/ys+:cos[2*hz*nt[4];1.5*AMP;0;ph[FR;DR]]

para"Play a note: ",wav:"test3.wav"
mkpcm[(1;FR;WIDTH);ser[WIDTH]qnt[rng]apo[0.015]AMP*nrm[1-1e-15]ys;wav]
para""

/ WARNING:  Be cautious with the volume while testing!!

para"Parse a wav file: -> (depth; tag; data)"
para"RIFF format is a tree structure.  Depth is the depth vector for that tree."
2#(dp;tg;dt):p:prs@1:wav
para""

para"Map tags to data"
mp:!/1_p
para"fmt:"
mp"fmt "
para"parse fmt:"
prsfmt mp"fmt "
para"data length"
#mp"data"


\d abc
\l abc.k
\d .

t:"G/GGD/EC3/4z//zc3/4"
key:("c";0)
ys:,/tone[s].'+(abc.mel[key]@;ph[FR]'(s:0.65)*0.25*abc.ds@)@\:t

para"Play a tune: ",wav:"test4.wav"
mkpcm[(1;FR;WIDTH);ser[WIDTH]qnt[rng]apo[0.015]AMP*nrm[1-1e-15]ys;wav]
para""
