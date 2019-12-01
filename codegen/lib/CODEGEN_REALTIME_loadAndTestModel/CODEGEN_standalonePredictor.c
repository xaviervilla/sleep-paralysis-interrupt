/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CODEGEN_standalonePredictor.c
 *
 * Code generation for function 'CODEGEN_standalonePredictor'
 *
 */

/* Include files */
#include "CODEGEN_standalonePredictor.h"
#include "CODEGEN_REALTIME_loadAndTestModel.h"
#include "CompactClassificationTree.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void CODEGEN_standalonePredictor(const double X[288], double label[16])
{
  double SVM_ClassNames[2];
  int i;
  double SVM_Cost[4];
  double SVM_PruneList_data[5];
  static const signed char iv[5] = { 2, 0, 1, 0, 0 };

  static const double SVM_CutPredictorIndex[5] = { 7.0, 0.0, 1.0, 0.0, 0.0 };

  static const double SVM_Children[10] = { 2.0, 3.0, 0.0, 0.0, 4.0, 5.0, 0.0,
    0.0, 0.0, 0.0 };

  static const double SVM_CutPoint[5] = { 0.10902012795745872, 0.0,
    0.71475862570312521, 0.0, 0.0 };

  static const bool SVM_NanCutPoints[5] = { false, true, false, true, true };

  static const double SVM_ClassProbability[10] = { 0.553182807399347,
    0.99926199261992621, 0.0015211439002129924, 1.0, 0.0, 0.44681719260065295,
    0.00073800738007381665, 0.998478856099787, 0.0, 1.0 };

  /*  Load the classifier from file */
  SVM_ClassNames[0] = 1.0;
  SVM_ClassNames[1] = 2.0;
  for (i = 0; i < 5; i++) {
    SVM_PruneList_data[i] = iv[i];
  }

  SVM_Cost[0] = 0.0;
  SVM_Cost[1] = 1.0;
  SVM_Cost[2] = 1.0;
  SVM_Cost[3] = 0.0;
  c_CompactClassificationTree_pre(SVM_CutPredictorIndex, SVM_Children,
    SVM_CutPoint, SVM_PruneList_data, SVM_NanCutPoints, SVM_ClassNames, SVM_Cost,
    SVM_ClassProbability, X, label);
}

/* End of code generation (CODEGEN_standalonePredictor.c) */
