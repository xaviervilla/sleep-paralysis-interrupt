clear variables;
clc;

load rawSensorData_train;

rawSensorDataTrain = table( total_acc_x_train, total_acc_y_train, total_acc_z_train, 'VariableNames', {'total_acc_x', 'total_acc_y', 'total_acc_z'} );

%T_mean = varfun(@Wmean, rawSensorDataTrain);
T_stdv = varfun(@Wstd,rawSensorDataTrain);
T_pca  = varfun(@Wpca1,rawSensorDataTrain);

humanActivityData = [T_stdv, T_pca];

result = zeros(size(trainActivity));
for i = 1:size(trainActivity)
    if (trainActivity(i) == "Laying")
        result(i) = 0;
    elseif (trainActivity(i) == "Sitting")
        result(i) = 0;
    elseif (trainActivity(i) == "ClimbingStairs")
        result(i) = 1;
    elseif (trainActivity(i) == "Standing")
        result(i) = 0;
    elseif (trainActivity(i) == "Walking")
        result(i) = 1;
    else
    end
end
humanActivityData.activity = result;

trainedModel = REDUCED_trainClassifier(humanActivityData);



saveLearnerForCoder(trainedModel.ClassificationTree, 'myLearnerForCoder');