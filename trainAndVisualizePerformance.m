    
% Step 1: Load raw sensor data to train classifier
load rawSensorData_train;

rawSensorDataTrain = table(...
    total_acc_x_train, total_acc_y_train, total_acc_z_train, body_gyro_x_train, body_gyro_y_train, body_gyro_z_train);

T_mean = varfun(@Wmean, rawSensorDataTrain);
T_stdv = varfun(@Wstd,rawSensorDataTrain);
T_pca  = varfun(@Wpca1,rawSensorDataTrain);

humanActivityData = [T_mean, T_stdv, T_pca];
humanActivityData.activity = trainActivity;

trainedClassifier = trainMyClassifier(humanActivityData);
humanActivityData.activity = trainActivity;

%% Now we can load test data and check accuracy from data that was not used to train the classifier

load rawSensorData_test;

rawSensorDataTest = table(...
    total_acc_x_test, total_acc_y_test, total_acc_z_test, ...
    body_gyro_x_test, body_gyro_y_test, body_gyro_z_test);

% Step 2: Extract features from raw sensor data
T_mean = varfun(@Wmean, rawSensorDataTest);
T_stdv = varfun(@Wstd,rawSensorDataTest);
T_pca  = varfun(@Wpca1,rawSensorDataTest);

humanActivityData = [T_mean, T_stdv, T_pca];
humanActivityData.activity = testActivity;

% Step 3: Use trained model to predict activity on new sensor data
% Make sure that you've exported 'trainedClassifier' from
% ClassificationLearner
a=trainedClassifier.ClassificationTree
saveLearnerForCoder(a,'LearnerForExport');
plotActivityResults(a,rawSensorDataTest,humanActivityData,0.5)