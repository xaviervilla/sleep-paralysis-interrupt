% Import csv from arduino serial and convert into a format that the ML can
% process
clear variables;

% Only change these
width = 32;
xyz0 = csvread('xyz0.csv');
xyz1 = csvread('xyz1.csv');

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