close all
clear variables
clc  

% A common use of Fourier transforms is to find the frequency components 
% of a signal buried in a noisy time domain signal. Consider data sampled 
% at 1000 Hz. Form a signal containing 50 Hz and 120 Hz and corrupt it 
% with some zero-mean random noise:

% Sensor Data:
%accel = csvread('alfonso.csv');

% [strongestFreqX, strengthX] = Wfreq(accel(139:202, 1).');
% [strongestFreqY, strengthY] = Wfreq(accel(139:202, 2).');
% [strongestFreqZ, strengthZ] = Wfreq(accel(139:202, 3).');

rawSensorDataTrain = table( accel(:,1), accel(:,2), accel(:,3), 'VariableNames', {'total_acc_x', 'total_acc_y', 'total_acc_z'} );

%T_mean = varfun(@Wmean, rawSensorDataTrain);
T_stdv = varfun(@Wstd,rawSensorDataTrain);
T_pca  = varfun(@Wpca1,rawSensorDataTrain);
T_freq = varfun(@Wfreq,rawSensorDataTrain);

% get most prominent freq of signals for x y and z and their strengths

humanActivityData = [T_stdv, T_pca, T_freq];

humanActivityData.activity = trainActivity;