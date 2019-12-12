% Import csv from arduino serial and convert into a format that the ML can
% process
clear variables;

% Only change these
width = 32;
xyz0 = csvread('xyz0.csv');
xyz1 = csvread('xyz1.csv');

% This is just to be able to process the data with a signal processor
x0 = xyz0(:, 1);
y0 = xyz0(:, 2);
z0 = xyz0(:, 3);
x1 = xyz1(128:528, 1);
y1 = xyz1(128:528, 2);
z1 = xyz1(128:528, 3);

FX0 = fft (x0);
FX1 = fft (x1);
FY0 = fft (y0);
FY1 = fft (y1);
FZ0 = fft (z0);
FZ1 = fft (z1);

testx0 = mean(FX0);
testx1 = mean(FX1);
testy0 = mean(FY0);
testy1 = mean(FY1);
testz0 = mean(FZ0);
testz1 = mean(FZ1);
bar([testx0, testx1, testy0, testy1, testz0, testz1])

% plot(FX0);
% hold on
% plot(FX1);
% hold on
% plot(FY0);
% hold on
% plot(FY1);
% hold on
% plot(FZ0);
% hold on
% plot(FZ1);
% hold on
% figure
% PSD0 = (1/length(FY0)) * FY0 .* conj(FY0);
% plot(PSD0)
% hold on
% PSD1 = (1/length(FY1)) * FY1 .* conj(FY1);
% plot(PSD1)

%% Handle xyz0 first
height = size(xyz0,1);
height = (height-mod(height,width)) /width;

total_acc_x_train = zeros(height, width);
total_acc_y_train = zeros(height, width);
total_acc_z_train = zeros(height, width);
trainActivity = zeros(height, 1);

for i = 1:height
    for j=1:width
        total_acc_x_train(i,j) = xyz0((i-1)*width + j, 1);
        total_acc_y_train(i,j) = xyz0((i-1)*width + j, 2);
        total_acc_z_train(i,j) = xyz0((i-1)*width + j, 3);
    end
end

%% Handle xyz1
height = size(xyz1,1);
height = (height-mod(height,width)) /width;

total_acc_x_train1 = zeros(height, width);
total_acc_y_train1 = zeros(height, width);
total_acc_z_train1 = zeros(height, width);
trainActivity1 = ones(height,1);

for i = 1:height
    for j=1:width
        total_acc_x_train1(i,j) = xyz1((i-1)*width + j, 1);
        total_acc_y_train1(i,j) = xyz1((i-1)*width + j, 2);
        total_acc_z_train1(i,j) = xyz1((i-1)*width + j, 3);
    end
end

total_acc_x_train = [total_acc_x_train; total_acc_x_train1];
total_acc_y_train = [total_acc_y_train; total_acc_y_train1];
total_acc_z_train = [total_acc_z_train; total_acc_z_train1];
trainActivity = [trainActivity; trainActivity1];

clear height;
clear i;
clear j;
clear total_acc_x_train1;
clear total_acc_y_train1;
clear total_acc_z_train1;
clear trainActivity1;
clear xyz1;
clear width;
clear xyz0;