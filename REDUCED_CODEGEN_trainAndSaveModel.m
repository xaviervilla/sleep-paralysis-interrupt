clear variables;
clc;

load rawCustomSensorData_train;

rawSensorDataTrain = table( total_acc_x_train, total_acc_y_train, total_acc_z_train, 'VariableNames', {'total_acc_x', 'total_acc_y', 'total_acc_z'} );

%T_mean = varfun(@Wmean, rawSensorDataTrain);
T_stdv = varfun(@Wstd,rawSensorDataTrain);
T_pca  = varfun(@Wpca1,rawSensorDataTrain);

humanActivityData = [T_stdv, T_pca];

humanActivityData.activity = trainActivity;

trainedModel = REDUCED_trainClassifier(humanActivityData);

saveLearnerForCoder(trainedModel.ClassificationTree, 'myLearnerForCoder')