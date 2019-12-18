close all
clear variables
clc  

% A common use of Fourier transforms is to find the frequency components 
% of a signal buried in a noisy time domain signal. Consider data sampled 
% at 1000 Hz. Form a signal containing 50 Hz and 120 Hz and corrupt it 
% with some zero-mean random noise:

% Sensor Data:
accel = csvread('alfonso.csv');
% Number of samples:
numSamples = 64;
% Number of seconds:
numSeconds = 2;

%%%%%%%%%%%%%%% No need to modify anything below this line %%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
sampleFreq = numSamples/numSeconds;

t = (0:numSamples-1)/sampleFreq;
x = accel(139:202, 1).';
x=x-mean(x);
y = x;

figure
plot(t,y)
title('Panic Breathing Signal with Noise')
xlabel('time (seconds)')
hold off

% It is difficult to identify the frequency components by looking at the 
% original signal. Converting to the frequency domain, the discrete 
% Fourier transform of the noisy signal y is found by taking the 512-point 
% fast Fourier transform (FFT):
Y = fft(y,64);

% The power spectrum, a measurement of the power at various frequencies:
Pyy = Y.* conj(Y) / 64;

% Graph the first 257 points (the other 255 points are redundant) on a 
% meaningful frequency axis:
figure
f = 32*(1:sampleFreq*numSeconds)/(sampleFreq*2);
[pk,loc] = max(Pyy);
%test = f(locs)
plot(f(1:32),Pyy(1:32))
hold on
plot(f(loc),pk,'or')
title('Frequency component of Panic Breathing')
xlabel('frequency (Hz)')

