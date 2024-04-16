\l wav.k

/ sine wave: 50 samples for one cycle, 440 cycles for 22000 samples per second
SC:50
HZ:440
sw:,/HZ#,_128*`sin@(2*pi*!SC)%SC
wav:mkchnk["RIFF"]@,/("WAVE";mkfmt pcm[1;SC*HZ;1];mkchnk["data";`c$sw])

/ WARNING:  Be cautious with the volume while testing!!

"test.wav" 1:wav

