clear variables;
clc;

%% Now we can load test data and check accuracy from data that was not used to train the classifier
load rawSensorData_test;

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

% Load the classifier from file
SVM = loadLearnerForCoder('myLearnerForCoder');

% Kepp track of correct count
accuracy = 0;

% Simulate live feed 
for i = 1:64:size(result,1)-63
    % Calculate mean of all 128 samples for each channel
    T_mean_acc_x = Wmean(total_acc_x_test(i:i+63,:));
    T_mean_acc_y = Wmean(total_acc_y_test(i:i+63,:));
    T_mean_acc_z = Wmean(total_acc_z_test(i:i+63,:));
    T_mean_gyro_x = Wmean(body_gyro_x_test(i:i+63,:));
    T_mean_gyro_y = Wmean(body_gyro_y_test(i:i+63,:));
    T_mean_gyro_z = Wmean(body_gyro_z_test(i:i+63,:));

    % Calculate std of all 128 samples for each channel
    T_std_acc_x = Wstd(total_acc_x_test(i:i+63,:));
    T_std_acc_y = Wstd(total_acc_y_test(i:i+63,:));
    T_std_acc_z = Wstd(total_acc_z_test(i:i+63,:));
    T_std_gyro_x = Wstd(body_gyro_x_test(i:i+63,:));
    T_std_gyro_y = Wstd(body_gyro_y_test(i:i+63,:));
    T_std_gyro_z = Wstd(body_gyro_z_test(i:i+63,:));

    % Calculate pca of all 128 samples for each channel
    T_Wpca1_acc_x = Wpca1(total_acc_x_test(i:i+63,:));
    T_Wpca1_acc_y = Wpca1(total_acc_y_test(i:i+63,:));
    T_Wpca1_acc_z = Wpca1(total_acc_z_test(i:i+63,:));
    T_Wpca1_gyro_x = Wpca1(body_gyro_x_test(i:i+63,:));
    T_Wpca1_gyro_y = Wpca1(body_gyro_y_test(i:i+63,:));
    T_Wpca1_gyro_z = Wpca1(body_gyro_z_test(i:i+63,:));

    % Create a matrix of all the features
    humanActivityData = [T_mean_acc_x, T_mean_acc_y, T_mean_acc_z, T_mean_gyro_x, T_mean_gyro_y, T_mean_gyro_z, ...
    T_std_acc_x, T_std_acc_y, T_std_acc_z, T_std_gyro_x, T_std_gyro_y, T_std_gyro_z, ...
    T_Wpca1_acc_x, T_Wpca1_acc_y, T_Wpca1_acc_z, T_Wpca1_gyro_x, T_Wpca1_gyro_y, T_Wpca1_gyro_z ];
    
    % Create a label of predictions
    label = predict(SVM, humanActivityData);
    
    % Simply check accuracy of method
    for j=1:64
        %fprintf("Checking Index %u\n", i+j-1);
        if(label(j) == result(i+j-1))
            accuracy = accuracy+1;
        end
    end
    
%     % Indicate the progress
%     if( mod(i, size(result,1)/100 ) < 63)
%         fprintf("Predicting...\t%i percent complete\n", ceil(i/size(result,1)*100));
%     end
    
end

% Final accuracy measurement
accuracy = (accuracy/size(result,1))*100;
