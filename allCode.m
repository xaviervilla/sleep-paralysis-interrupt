% This function will be an encapsulation of all code required for computing
% a single label given a 6x16 matrix

clear variables;
clc;

%% Now we can load test data and check accuracy from data that was not used to train the classifier
load rawCustomSensorData_train;

% We need to convert the predictor strings to integers
result = trainActivity;

% Get label returns
label = zeros(size(trainActivity));

% Simulate live feed 
for i = 1:1:size(trainActivity)-4
    label(i:i+1) = loadAndTestModel(total_acc_x_train(i:i+1,1:32), total_acc_y_train(i:i+1,1:32), total_acc_z_train(i:i+1,1:32) );
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