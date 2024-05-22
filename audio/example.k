\l wav.k

/ Think DSP [[https://greenteapress.com/wp/think-dsp/]]
/ See also [[http://arlyle.sdf.org/k/sound.k]]

/ sine wave: 25 samples for one cycle, 440 cycles for 11000 samples per second
FR:11025          / framerate
HZ:27.5           / frequency
AMP:1.0           / amplitude
DR:1.0            / duration
WIDTH:2           / sample width in bytes
rng:2/~!8*WIDTH   / quantization range

ts:(!_FR*DR)%FR

nt:note[12]       / twelve tone system
hz:16*HZ          / Base note

chrd:{+/1(+\12*<':)\+/(0 2 3 5 7 8 9;-1 0 1)@'("abcdefg";"b #")?'+(" "\x)@/:\:0 1}

ys:+/sin[;AMP;0;ts]'hz*nt[chrd "c eb g# bb"]
ys:nrm[1-1e-15]ys

data:,/+|`c$(WIDTH#256)\qnt[rng] apo[0.015]ys

wav:mkchnk["RIFF"]@,/("WAVE";mkfmt pcm[1;FR;WIDTH];mkchnk["data";data])

/ WARNING:  Be cautious with the volume while testing!!

"test.wav" 1:wav
