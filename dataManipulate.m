% Import csv from arduino serial and convert into a format that the ML can
% process
clear variables;

% Only change these
width = 64;

% Get a list of files from nonSP and SP data folders
nonSPfiles = dir('/home/xvilla/Documents/2019fall/195/my classifier/myRecordings/0/*.txt');
SPfiles = dir('/home/xvilla/Documents/2019fall/195/my classifier/myRecordings/1/*.txt');

% Load all of the nonSP csv data to one variable
xyz0 = csvread(['/home/xvilla/Documents/2019fall/195/my classifier/myRecordings/0/' nonSPfiles(1).name]);
for i = 2:size(nonSPfiles, 1)
    xyz0 = [xyz0; csvread(['/home/xvilla/Documents/2019fall/195/my classifier/myRecordings/0/' nonSPfiles(i).name])];
end

% Load all of the nonSP csv data to one variable
xyz1 = csvread(['/home/xvilla/Documents/2019fall/195/my classifier/myRecordings/1/' SPfiles(1).name]);
for i = 2:size(SPfiles, 1)
    xyz1 = [xyz1; csvread(['/home/xvilla/Documents/2019fall/195/my classifier/myRecordings/1/' SPfiles(i).name])];
end

% Handle xyz0 first
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

% Handle xyz1
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

total_acc_x_train = [total_acc_x_train; total_acc_x_train1] ./1.6;
total_acc_y_train = [total_acc_y_train; total_acc_y_train1] ./1.6;
total_acc_z_train = [total_acc_z_train; total_acc_z_train1] ./1.6;
trainActivity = [trainActivity; trainActivity1];

clear nonSPfiles;
clear SPfiles;
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

save('/home/xvilla/Documents/2019fall/195/my classifier/spTrainingData.mat');