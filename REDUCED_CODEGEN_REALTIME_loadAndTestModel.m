function label = REDUCED_CODEGEN_REALTIME_loadAndTestModel(total_acc_x_test, total_acc_y_test, total_acc_z_test)
    
%     total_acc_x_test
    
    % Calculate mean of all 128 samples for each channel
    T_mean_acc_x = Wmean(total_acc_x_test(:,:));
    T_mean_acc_y = Wmean(total_acc_y_test(:,:));
    T_mean_acc_z = Wmean(total_acc_z_test(:,:));

    % Calculate std of all 128 samples for each channel
    T_std_acc_x = Wstd(total_acc_x_test(:,:));
    T_std_acc_y = Wstd(total_acc_y_test(:,:));
    T_std_acc_z = Wstd(total_acc_z_test(:,:));

%     % Calculate pca of all 128 samples for each channel
%     T_Wpca1_acc_x = Wpca1(total_acc_x_test(:,:));
%     T_Wpca1_acc_y = Wpca1(total_acc_y_test(:,:));
%     T_Wpca1_acc_z = Wpca1(total_acc_z_test(:,:));

    % Create a matrix of all the features
    humanActivityData = [T_mean_acc_x, T_mean_acc_y, T_mean_acc_z, T_std_acc_x, T_std_acc_y, T_std_acc_z];%, T_Wpca1_acc_x, T_Wpca1_acc_y, T_Wpca1_acc_z];
    
    % Create a label of predictions
    label = CODEGEN_standalonePredictor(humanActivityData(:,1:6));
    
end