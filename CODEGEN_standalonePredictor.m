function label = CODEGEN_standalonePredictor(X)
% Load the classifier from file
SVM = loadLearnerForCoder('myLearnerForCoder');
label = predict(SVM, X);
end