\l wav.k

/ Think DSP [[https://greenteapress.com/wp/think-dsp/]]

/ sine wave: 25 samples for one cycle, 440 cycles for 11000 samples per second
FR:11025          / framerate
HZ:880            / frequency
AMP:0.5           / amplitude
DR:0.5            / duration
WIDTH:2           / sample width in bytes
rng:2/~!8*WIDTH   / quantization range

ts:(!_FR*DR)%FR

sin:{y*`sin 2*pi*x*z}  / [HZ;AMP;ts]
qnt:{_x*y}     / [rng;ys]

ys:qnt[rng]sin[HZ;AMP;ts]

data:,/+|`c$(WIDTH#256)\ys

wav:mkchnk["RIFF"]@,/("WAVE";mkfmt pcm[1;FR;WIDTH];mkchnk["data";data])

/ WARNING:  Be cautious with the volume while testing!!

"test.wav" 1:wav
