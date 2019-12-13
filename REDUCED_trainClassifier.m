function [trainedClassifier] = REDUCED_trainClassifier(trainingData)

inputTable = trainingData;
predictorNames = {'Wstd_total_acc_x', 'Wstd_total_acc_y', 'Wstd_total_acc_z', 'Wpca1_total_acc_x', 'Wpca1_total_acc_y', 'Wpca1_total_acc_z', 'Wfft_total_acc_x', 'Wfft_total_acc_y', 'Wfft_total_acc_z'};
predictors = inputTable(:, predictorNames);
response = inputTable.activity;
classificationTree = fitctree(...
predictors, ...
response, ...
'SplitCriterion', 'twoing', ...
'MaxNumSplits', 5, ...
'Surrogate', 'off', ...
'ClassNames', [0; 1]);

predictorExtractionFcn = @(t) t(:, predictorNames);
treePredictFcn = @(x) predict(classificationTree, x);
trainedClassifier.predictFcn = @(x) treePredictFcn(predictorExtractionFcn(x));

trainedClassifier.RequiredVariables = {'Wstd_total_acc_x', 'Wstd_total_acc_y', 'Wstd_total_acc_z', 'Wpca1_total_acc_x', 'Wpca1_total_acc_y', 'Wpca1_total_acc_z', 'Wfft_total_acc_x', 'Wfft_total_acc_y', 'Wfft_total_acc_z'};
trainedClassifier.ClassificationTree = classificationTree;
