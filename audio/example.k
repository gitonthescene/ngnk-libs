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

nt:note[12]       / twelve tone system
hz:8*HZ          / Base note

chrd:{+/1(+\12*<':)\+/(+\0 2 1 2 2 1 2;-1 0 1)@'("abcdefg";"b #")?'+(" "\x)@/:\:0 1}

dur:{*/(1%1 2 4 8 16;1.5 1)@'("whqes";". ")?'+(" "\x)@/:\:0 1}

ys:+/sin[;AMP;0;ph[FR;DR]]'hz*nt[chrd "c eb g# bb"]
ys:AMP*nrm[1-1e-15]ys

data:,/+|`c$(WIDTH#256)\qnt[rng] apo[0.015]ys

"test1.wav" 1:mkchnk["RIFF"]@,/("WAVE";mkfmt pcm[1;FR;WIDTH];mkchnk["data";data])

hz*:2
ys:,/{apo[0.05;sin[hz*nt x;AMP;0]y],&_0.15*#y}.'+(10 10 10 5 7 3 15;ph[FR]'0.85*dur"e q q e q h q")
ys:AMP*nrm[1-1e-15]ys

data:,/+|`c$(WIDTH#256)\qnt[rng] apo[0.015]ys

"test2.wav" 1:mkchnk["RIFF"]@,/("WAVE";mkfmt pcm[1;FR;WIDTH];mkchnk["data";data])

/ WARNING:  Be cautious with the volume while testing!!
