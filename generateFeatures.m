clear variables;
clc;

load rawCustomSensorData_train;

% 0 indicates Training as Decision Tree, 1 indicates training as KNN
type = 0;

rawSensorDataTrain = table( total_acc_x_train, total_acc_y_train, total_acc_z_train, 'VariableNames', {'total_acc_x', 'total_acc_y', 'total_acc_z'} );

%T_mean = varfun(@Wmean, rawSensorDataTrain);
T_stdv = varfun(@Wstd,rawSensorDataTrain);
T_pca  = varfun(@Wpca1,rawSensorDataTrain);
T_fft = varfun(@Wfft, rawSensorDataTrain);

humanActivityData = [T_stdv, T_pca, T_fft];

humanActivityData.activity = trainActivity;