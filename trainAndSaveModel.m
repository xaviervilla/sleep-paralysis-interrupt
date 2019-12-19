clc;
clear variables;
close all

load rawCustomSensorData_train64;
rawSensorDataTrain = table( total_acc_x_train, total_acc_y_train, total_acc_z_train, 'VariableNames', {'total_acc_x', 'total_acc_y', 'total_acc_z'} );

T_mean = varfun(@Wmean, rawSensorDataTrain);
T_stdv = varfun(@Wstd,rawSensorDataTrain);
T_pca  = varfun(@Wpca1,rawSensorDataTrain);
M_freq = zeros(size(total_acc_x_train,1),3);

% 0 indicates Training as Decision Tree, 1 indicates training as KNN
type = 0;
for i = 1:size(total_acc_x_train,1)
    M_freq(i,1) = Wfreq(total_acc_x_train(i,:));
    M_freq(i,2) = Wfreq(total_acc_y_train(i,:));
    M_freq(i,3) = Wfreq(total_acc_z_train(i,:));
end

% get most prominent freq of signals for x y and z and their strengths
T_freq = table( M_freq(:,1), M_freq(:,2), M_freq(:,3), 'VariableNames', {'Wfreq_total_acc_x', 'Wfreq_total_acc_y', 'Wfreq_total_acc_z'}); 


humanActivityData = [T_mean, T_stdv, T_pca, T_freq];

humanActivityData.activity = trainActivity;

if type == 0
    trainedModel = trainClassifier(humanActivityData);
    saveLearnerForCoder(trainedModel.ClassificationKNN, 'myLearnerForCoder')
elseif type == 1
    trainedModel = trainClassifier(humanActivityData);
    saveLearnerForCoder(trainedModel.ClassificationTree, 'myLearnerForCoder')
end