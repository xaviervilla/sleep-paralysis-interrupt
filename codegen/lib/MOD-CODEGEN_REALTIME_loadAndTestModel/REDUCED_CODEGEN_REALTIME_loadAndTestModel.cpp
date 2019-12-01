/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * REDUCED_CODEGEN_REALTIME_loadAndTestModel.c
 *
 * Code generation for function 'REDUCED_CODEGEN_REALTIME_loadAndTestModel'
 *
 */

/* Include files */
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "CompactClassificationTree.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_data.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize.h"
#include "Wstd.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void REDUCED_CODEGEN_REALTIME_loadAndTestModel(const double total_acc_x_test[256],
  const double total_acc_y_test[256], const double total_acc_z_test[256], double
  label[16])
{
  double y[16];
  int k;
  int xoffset;
  double b_y[16];
  int j;
  double c_y[16];
  double SVM_ClassNames[4];
  double b_I[16];
  double SVM_PruneList_data[17];
  static const signed char iv[17] = { 6, 5, 1, 0, 4, 0, 0, 2, 3, 0, 2, 0, 3, 0,
    0, 0, 0 };

  double dv[16];
  double SVM_Cost[16];
  double dv1[16];
  static const double SVM_CutPredictorIndex[17] = { 4.0, 1.0, 1.0, 0.0, 2.0, 0.0,
    0.0, 3.0, 1.0, 0.0, 3.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_Children[34] = { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 0.0,
    0.0, 8.0, 9.0, 0.0, 0.0, 0.0, 0.0, 10.0, 11.0, 12.0, 13.0, 0.0, 0.0, 14.0,
    15.0, 0.0, 0.0, 16.0, 17.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_CutPoint[17] = { 0.10902012795745872,
    0.38674240585937508, 0.71475862570312521, 0.0, -0.066491563359375, 0.0, 0.0,
    0.24559143137499995, 1.0032276589843749, 0.0, 0.303617298046875, 0.0,
    -0.15842286234374997, 0.0, 0.0, 0.0, 0.0 };

  static const bool SVM_NanCutPoints[17] = { false, false, false, true, false,
    true, true, false, false, true, false, true, false, true, true, true, true };

  static const double SVM_ClassProbability[68] = { 0.1913764961915127,
    0.34514145141451408, 0.0012169151201703941, 1.0, 0.0, 0.8, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.17491838955386313,
    0.31611316113161136, 0.00030422878004259852, 0.0, 0.48271975957926377, 0.2,
    0.0, 0.080308880308881753, 0.86393562545720315, 0.066396761133604432,
    0.36666666666666653, 0.995827538247566, 0.71759259259259,
    0.70967741935483875, 0.0, 0.0, 0.74162679425837086, 0.44681719260065228,
    0.00073800738007381449, 0.998478856099787, 0.0, 0.0011269722013523876, 0.0,
    1.0, 0.0023166023166023546, 0.0, 0.0016194331983805938, 0.01666666666666667,
    0.0, 0.0, 0.032258064516129045, 0.0, 0.0, 0.0, 0.18688792165397192,
    0.33800738007380071, 0.0, 0.0, 0.5161532682193839, 0.0, 0.0,
    0.91737451737451592, 0.13606437454279677, 0.931983805668015,
    0.61666666666666681, 0.0041724617524339985, 0.28240740740740994,
    0.25806451612903236, 1.0, 1.0, 0.2583732057416292 };

  double d_y[96];
  if (isInitialized_REDUCED_CODEGEN_REALTIME_loadAndTestModel == false) {
    REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize();
  }

  /*      total_acc_x_test */
  /*  Calculate mean of all 128 samples for each channel */
  /*  Copyright (c) 2015, MathWorks, Inc. */
  memcpy(&y[0], &total_acc_x_test[0], 16U * sizeof(double));
  for (k = 0; k < 15; k++) {
    xoffset = (k + 1) << 4;
    for (j = 0; j < 16; j++) {
      y[j] += total_acc_x_test[xoffset + j];
    }
  }

  /*  Copyright (c) 2015, MathWorks, Inc. */
  memcpy(&b_y[0], &total_acc_y_test[0], 16U * sizeof(double));
  for (k = 0; k < 15; k++) {
    xoffset = (k + 1) << 4;
    for (j = 0; j < 16; j++) {
      b_y[j] += total_acc_y_test[xoffset + j];
    }
  }

  /*  Copyright (c) 2015, MathWorks, Inc. */
  memcpy(&c_y[0], &total_acc_z_test[0], 16U * sizeof(double));
  for (k = 0; k < 15; k++) {
    xoffset = (k + 1) << 4;
    for (j = 0; j < 16; j++) {
      c_y[j] += total_acc_z_test[xoffset + j];
    }
  }

  /*  Calculate std of all 128 samples for each channel */
  /*      % Calculate pca of all 128 samples for each channel */
  /*      T_Wpca1_acc_x = Wpca1(total_acc_x_test(:,:)); */
  /*      T_Wpca1_acc_y = Wpca1(total_acc_y_test(:,:)); */
  /*      T_Wpca1_acc_z = Wpca1(total_acc_z_test(:,:)); */
  /*  Create a matrix of all the features */
  /* , T_Wpca1_acc_x, T_Wpca1_acc_y, T_Wpca1_acc_z]; */
  /*  Create a label of predictions */
  /*  Load the classifier from file */
  SVM_ClassNames[0] = 1.0;
  SVM_ClassNames[1] = 2.0;
  SVM_ClassNames[2] = 3.0;
  SVM_ClassNames[3] = 4.0;
  for (k = 0; k < 17; k++) {
    SVM_PruneList_data[k] = iv[k];
  }

  memset(&b_I[0], 0, 16U * sizeof(double));
  b_I[0] = 1.0;
  b_I[5] = 1.0;
  b_I[10] = 1.0;
  b_I[15] = 1.0;
  Wstd(total_acc_x_test, dv);
  for (k = 0; k < 16; k++) {
    SVM_Cost[k] = 1.0 - b_I[k];
    b_I[k] = dv[k];
  }

  Wstd(total_acc_y_test, dv);
  Wstd(total_acc_z_test, dv1);
  for (k = 0; k < 16; k++) {
    d_y[k] = y[k] / 16.0;
    d_y[k + 16] = b_y[k] / 16.0;
    d_y[k + 32] = c_y[k] / 16.0;
    d_y[k + 48] = b_I[k];
    d_y[k + 64] = dv[k];
    d_y[k + 80] = dv1[k];
  }

  c_CompactClassificationTree_pre(SVM_CutPredictorIndex, SVM_Children,
    SVM_CutPoint, SVM_PruneList_data, SVM_NanCutPoints, SVM_ClassNames, SVM_Cost,
    SVM_ClassProbability, d_y, label);
}

/* End of code generation (REDUCED_CODEGEN_REALTIME_loadAndTestModel.c) */
