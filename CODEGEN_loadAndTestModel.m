clear variables;
clc;

%% Now we can load test data and check accuracy from data that was not used to train the classifier
load rawSensorData_test;

rawSensorDataTest = table( total_acc_x_test, total_acc_y_test, total_acc_z_test, body_gyro_x_test, body_gyro_y_test, body_gyro_z_test, 'VariableNames', {'total_acc_x', 'total_acc_y', 'total_acc_z', 'body_gyro_x', 'body_gyro_y', 'body_gyro_z'} );

% Step 2: Extract features from raw sensor data
T_mean = varfun(@Wmean, rawSensorDataTest);
T_stdv = varfun(@Wstd,rawSensorDataTest);
T_pca  = varfun(@Wpca1,rawSensorDataTest);

humanActivityData = [T_mean, T_stdv, T_pca];

% We need to convert the predictor strings to integers
result = zeros(size(testActivity));
for i = 1:size(testActivity)
    if (testActivity(i) == "Laying")
        result(i) = 1;
    elseif (testActivity(i) == "Sitting")
        result(i) = 2;
    elseif (testActivity(i) == "ClimbingStairs")
        result(i) = 3;
    elseif (testActivity(i) == "Standing")
        result(i) = 4;
    elseif (testActivity(i) == "Walking")
        result(i) = 5;
    else
    end
end
humanActivityData.activity = result;

% Load the classifier from file
SVM = loadLearnerForCoder('myLearnerForCoder');

% Get matrix dimensions
p = size(humanActivityData,2) - 1;
x = coder.typeof(0,[inf,p],[1 0]);

% Generate Mex files
%fprintf("Generating Mex files...\n");
%codegen CODEGEN_standalonePredictor -args x
%fprintf("Done with Mex files...\n");

% Simple math to compute accuracy of classifier
accuracy = 0;
for i = 1:size(result,1)
    % Create a label of predictions
    label = CODEGEN_standalonePredictor(table2array(humanActivityData(i,1:18)));
    if(label == result(i))
        accuracy = accuracy+1;
    end
end
accuracy = (accuracy/size(result,1))*100;