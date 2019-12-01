clear variables;
clc;

% Step 1: Load raw sensor data to train classifier
load rawSensorData_train;

rawSensorDataTrain = table( total_acc_x_train, total_acc_y_train, total_acc_z_train, body_gyro_x_train, body_gyro_y_train, body_gyro_z_train, 'VariableNames', {'total_acc_x', 'total_acc_y', 'total_acc_z', 'body_gyro_x', 'body_gyro_y', 'body_gyro_z'} );

% Step 2: Extract features from raw sensor data
T_mean = varfun(@Wmean, rawSensorDataTrain);
T_stdv = varfun(@Wstd,rawSensorDataTrain);
T_pca  = varfun(@Wpca1,rawSensorDataTrain);

humanActivityData = [T_mean, T_stdv, T_pca];

% We need to convert the predictor strings to integers
result = zeros(size(trainActivity));
for i = 1:size(trainActivity)
    if (trainActivity(i) == "Laying")
        result(i) = 1;
    elseif (trainActivity(i) == "Sitting")
        result(i) = 1;
    elseif (trainActivity(i) == "ClimbingStairs")
        result(i) = 2;
    elseif (trainActivity(i) == "Standing")
        result(i) = 1;
    elseif (trainActivity(i) == "Walking")
        result(i) = 2;
    else
    end
end
humanActivityData.activity = result;

% Create a trained model using our function from classificationLearner
trainedModel = trainClassifier(humanActivityData);

% Export the trained model to myLearnerForCoder.mat
saveLearnerForCoder(trainedModel.ClassificationTree, 'myLearnerForCoder');