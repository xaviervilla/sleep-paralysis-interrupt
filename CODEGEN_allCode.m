% This function will be an encapsulation of all code required for computing
% a single label given a 6x16 matrix

clear variables;
clc;

%% Now we can load test data and check accuracy from data that was not used to train the classifier
load rawSensorData_test;

% We need to convert the predictor strings to integers
result = zeros(size(testActivity));
for i = 1:size(testActivity)
    if (testActivity(i) == "Laying")
        result(i) = 0;
    elseif (testActivity(i) == "Sitting")
        result(i) = 0;
    elseif (testActivity(i) == "ClimbingStairs")
        result(i) = 1;
    elseif (testActivity(i) == "Standing")
        result(i) = 0;
    elseif (testActivity(i) == "Walking")
        result(i) = 1;
    else
    end
end

% Get label returns
label = zeros(size(testActivity));

% Simulate live feed 
for i = 1:2:2*floor(size(testActivity)/2)-2
    label(i:i+1) = REDUCED_CODEGEN_REALTIME_loadAndTestModel(total_acc_x_test(i:i+1,1:16:128), total_acc_y_test(i:i+1,1:16:128), total_acc_z_test(i:i+1,1:16:128) );
end

accuracy = 0.0;
for j = 1:size(result,1)
    if label(j)==result(j)
        accuracy=accuracy+1;
    else
        fprintf("Actual:%u\tGuessed:%u\n", result(j), label(j));
    end
end
fprintf("Accuracy: %f\nRight: %u\nWrong: %u\n", accuracy/size(result,1)*100, accuracy, size(result,1)-accuracy);