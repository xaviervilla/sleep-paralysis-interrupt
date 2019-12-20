function [trainedClassifier, validationAccuracy] = trainClassifier(trainingData)
% [trainedClassifier, validationAccuracy] = trainClassifier(trainingData)
% returns a trained classifier and its accuracy. This code recreates the
% classification model trained in Classification Learner app. Use the
% generated code to automate training the same model with new data, or to
% learn how to programmatically train models.
%
%  Input:
%      trainingData: a table containing the same predictor and response
%       columns as imported into the app.
%
%  Output:
%      trainedClassifier: a struct containing the trained classifier. The
%       struct contains various fields with information about the trained
%       classifier.
%
%      trainedClassifier.predictFcn: a function to make predictions on new
%       data.
%
%      validationAccuracy: a double containing the accuracy in percent. In
%       the app, the History list displays this overall accuracy score for
%       each model.
%
% Use the code to train the model with new data. To retrain your
% classifier, call the function from the command line with your original
% data or new data as the input argument trainingData.
%
% For example, to retrain a classifier trained with the original data set
% T, enter:
%   [trainedClassifier, validationAccuracy] = trainClassifier(T)
%
% To make predictions with the returned 'trainedClassifier' on new data T2,
% use
%   yfit = trainedClassifier.predictFcn(T2)
%
% T2 must be a table containing at least the same predictor columns as used
% during training. For details, enter:
%   trainedClassifier.HowToPredict

% Auto-generated by MATLAB on 19-Dec-2019 21:43:05


% Extract predictors and response
% This code processes the data into the right shape for training the
% model.
inputTable = trainingData;
predictorNames = {'Wmean_total_acc_x', 'Wmean_total_acc_y', 'Wmean_total_acc_z', 'Wstd_total_acc_x', 'Wstd_total_acc_y', 'Wstd_total_acc_z', 'Wpca1_total_acc_x', 'Wpca1_total_acc_y', 'Wpca1_total_acc_z', 'Wfreq_total_acc_x', 'Wfreq_total_acc_y', 'Wfreq_total_acc_z'};
predictors = inputTable(:, predictorNames);
response = inputTable.activity;
isCategoricalPredictor = [false, false, false, false, false, false, false, false, false, false, false, false];

% Train a classifier
% This code specifies all the classifier options and trains the classifier.
classificationTree = fitctree(...
    predictors, ...
    response, ...
    'SplitCriterion', 'gdi', ...
    'MaxNumSplits', 100, ...
    'Surrogate', 'off', ...
    'ClassNames', [0; 1]);

% Create the result struct with predict function
predictorExtractionFcn = @(t) t(:, predictorNames);
treePredictFcn = @(x) predict(classificationTree, x);
trainedClassifier.predictFcn = @(x) treePredictFcn(predictorExtractionFcn(x));

% Add additional fields to the result struct
trainedClassifier.RequiredVariables = {'Wfreq_total_acc_x', 'Wfreq_total_acc_y', 'Wfreq_total_acc_z', 'Wmean_total_acc_x', 'Wmean_total_acc_y', 'Wmean_total_acc_z', 'Wpca1_total_acc_x', 'Wpca1_total_acc_y', 'Wpca1_total_acc_z', 'Wstd_total_acc_x', 'Wstd_total_acc_y', 'Wstd_total_acc_z'};
trainedClassifier.ClassificationTree = classificationTree;
trainedClassifier.About = 'This struct is a trained model exported from Classification Learner R2019b.';
trainedClassifier.HowToPredict = sprintf('To make predictions on a new table, T, use: \n  yfit = c.predictFcn(T) \nreplacing ''c'' with the name of the variable that is this struct, e.g. ''trainedModel''. \n \nThe table, T, must contain the variables returned by: \n  c.RequiredVariables \nVariable formats (e.g. matrix/vector, datatype) must match the original training data. \nAdditional variables are ignored. \n \nFor more information, see <a href="matlab:helpview(fullfile(docroot, ''stats'', ''stats.map''), ''appclassification_exportmodeltoworkspace'')">How to predict using an exported model</a>.');

% Extract predictors and response
% This code processes the data into the right shape for training the
% model.
inputTable = trainingData;
predictorNames = {'Wmean_total_acc_x', 'Wmean_total_acc_y', 'Wmean_total_acc_z', 'Wstd_total_acc_x', 'Wstd_total_acc_y', 'Wstd_total_acc_z', 'Wpca1_total_acc_x', 'Wpca1_total_acc_y', 'Wpca1_total_acc_z', 'Wfreq_total_acc_x', 'Wfreq_total_acc_y', 'Wfreq_total_acc_z'};
predictors = inputTable(:, predictorNames);
response = inputTable.activity;
isCategoricalPredictor = [false, false, false, false, false, false, false, false, false, false, false, false];

% Perform cross-validation
partitionedModel = crossval(trainedClassifier.ClassificationTree, 'KFold', 10);

% Compute validation predictions
[validationPredictions, validationScores] = kfoldPredict(partitionedModel);

% Compute validation accuracy
validationAccuracy = 1 - kfoldLoss(partitionedModel, 'LossFun', 'ClassifError');
