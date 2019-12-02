function label = REDUCED_CODEGEN_REALTIME_loadAndTestModel(total_acc_x_test, total_acc_y_test, total_acc_z_test)
    
    % Calculate mean of all samples for each channel
%     T_mean_acc_x = mean(total_acc_x_test(:,:), 2);
%     T_mean_acc_y = mean(total_acc_y_test(:,:), 2);
%     T_mean_acc_z = mean(total_acc_z_test(:,:), 2);

    % Calculate std of all samples for each channel
    T_std_acc_x = std(total_acc_x_test(:,:),1,2);
    T_std_acc_y = std(total_acc_y_test(:,:),1,2);
    T_std_acc_z = std(total_acc_z_test(:,:),1,2);

    % Calculate pca of all samples for each channel
    [~,T_wpca1_acc_x] = pca(total_acc_x_test(:,:),'NumComponents',1);
    [~,T_wpca1_acc_y] = pca(total_acc_y_test(:,:),'NumComponents',1);
    [~,T_wpca1_acc_z] = pca(total_acc_z_test(:,:),'NumComponents',1);
    
    % Create a matrix of all the features
    SVM = loadLearnerForCoder('myLearnerForCoder');
    
    % Create a label of predictions
    label = predict(SVM,[T_std_acc_x, T_std_acc_y, T_std_acc_z, T_wpca1_acc_x(:,1), T_wpca1_acc_y(:,1), T_wpca1_acc_z(:,1)]);
    
end