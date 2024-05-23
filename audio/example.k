\l wav.k

/ Think DSP [[https://greenteapress.com/wp/think-dsp/]]
/ See also [[http://arlyle.sdf.org/k/sound.k]]

/ sine wave: 25 samples for one cycle, 440 cycles for 11000 samples per second
FR:11025          / framerate
HZ:27.5           / frequency
AMP:0.5           / amplitude
DR:1.0            / duration
WIDTH:2           / sample width in bytes
rng:2/~!8*WIDTH   / quantization range

ts:(!_FR*DR)%FR
ph:{(!_x*y)%x}

nt:note[12]      / twelve tone system
hz:8*HZ          / Base note

chrd:{+/1(+\12*<':)\+/(+\0 2 1 2 2 1 2;-1 0 1)@'("abcdefg";"b #")?'+(" "\x)@/:\:0 1}
dur:{*/(1%4(2*)\1;1.5 1)@'("whqes";". ")?'+(" "\x)@/:\:0 1}

mkpcm:{z 1:mkchnk["RIFF"]@,/("WAVE";mkfmt pcm.(x);mkchnk["data";y])}
ser:{,/+|`c$(x#256)\y}

ys:+/sin[;AMP;0;ph[FR;DR]]'hz*nt[chrd "c eb g"]

mkpcm[(1;FR;WIDTH);ser[WIDTH]qnt[rng]apo[0.015]AMP*nrm[1-1e-15]ys;"test1.wav"]

hz*:2
ys:,/{apo[0.05;sin[hz*nt x;AMP;0]y],&_0.15*#y}.'+(10 10 10 5 7 3 15;ph[FR]'0.85*dur"e q q e q h e.")

mkpcm[(1;FR;WIDTH);ser[WIDTH]qnt[rng]apo[0.015]AMP*nrm[1-1e-15]ys;"test2.wav"]

ys:sin[hz*nt[2];0.5*AMP;0;ph[FR;DR]]
/ys+:cos[2*hz*nt[4];1.5*AMP;0;ph[FR;DR]]

mkpcm[(1;FR;WIDTH);ser[WIDTH]qnt[rng]apo[0.015]AMP*nrm[1-1e-15]ys;"test3.wav"]

/ WARNING:  Be cautious with the volume while testing!!
