\l wav.k

/ Think DSP [[https://greenteapress.com/wp/think-dsp/]]
/ See also [[http://arlyle.sdf.org/k/sound.k]]

/ sine wave: 25 samples for one cycle, 440 cycles for 11000 samples per second
FR:11025          / framerate
HZ:27.5           / frequency
AMP:1.0           / amplitude
DR:1.0            / duration
WIDTH:1           / sample width in bytes
rng:2/~!8*WIDTH   / quantization range

ts:(!_FR*DR)%FR

nt:note[12]                       / twelve tone system
hz:8*HZ

ys:sin[hz:_nt[0]*hz;AMP;0;ts]
ys+:sin[hz:_nt[3]*hz;AMP;0;ts]
ys+:sin[hz:_nt[7]*hz;AMP;0;ts]
ys:nrm[1-1e-15]ys

data:,/+|`c$(WIDTH#256)\qnt[rng] apo[0.015]ys

wav:mkchnk["RIFF"]@,/("WAVE";mkfmt pcm[1;FR;WIDTH];mkchnk["data";data])

/ WARNING:  Be cautious with the volume while testing!!

"test.wav" 1:wav
