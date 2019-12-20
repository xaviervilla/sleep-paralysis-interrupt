/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: loadAndTestModel.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 19-Dec-2019 22:31:39
 */

/* Include Files */
#include "loadAndTestModel.h"
#include "CompactClassificationTree.h"
#include "Wfreq.h"
#include "loadAndTestModel_data.h"
#include "loadAndTestModel_initialize.h"
#include "pca.h"
#include "rt_nonfinite.h"
#include "std.h"

/* Function Definitions */

/*
 * Calculate mean of all samples for each channel
 * Arguments    : const double total_acc_x_test[64]
 *                const double total_acc_y_test[64]
 *                const double total_acc_z_test[64]
 * Return Type  : double
 */
double loadAndTestModel(const double total_acc_x_test[64], const double
  total_acc_y_test[64], const double total_acc_z_test[64])
{
  double y;
  double b_y;
  double c_y;
  int k;
  double b_total_acc_x_test[64];
  double unusedU0_data[32];
  int unusedU0_size[2];
  double T_wpca1_acc_x_data[2];
  int T_wpca1_acc_x_size[2];
  int total_acc_x_test_tmp;
  double T_wpca1_acc_y_data[2];
  double T_wpca1_acc_z_data[2];
  double SVM_ClassNames[2];
  double SVM_Cost[4];
  double SVM_PruneList_data[17];
  static const signed char iv[17] = { 3, 1, 3, 1, 0, 2, 3, 0, 1, 2, 0, 0, 0, 0,
    0, 0, 0 };

  double d_y[12];
  static const double SVM_CutPredictorIndex[17] = { 10.0, 6.0, 3.0, 5.0, 0.0,
    2.0, 2.0, 0.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_Children[34] = { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
    9.0, 0.0, 0.0, 10.0, 11.0, 12.0, 13.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_CutPoint[17] = { 2.25, 7320.1953213740126, 12398.84375,
    6178.9792274556248, 0.0, -11347.140625, -7012.5, 0.0, -3082.03125,
    -8347.15625, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const bool SVM_NanCutPoints[17] = { false, false, false, false, true,
    false, false, true, false, false, true, true, true, true, true, true, true };

  static const double SVM_ClassProbability[34] = { 0.9387442572741197,
    0.99027237354085607, 0.74820143884892076, 0.99407114624505932, 0.75,
    0.91836734693877542, 0.34146341463414631, 0.99796747967479671,
    0.8571428571428571, 0.6, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.061255742725880344, 0.00972762645914393, 0.25179856115107929,
    0.0059288537549406894, 0.25, 0.0816326530612246, 0.65853658536585358,
    0.0020325203252032444, 0.14285714285714282, 0.39999999999999997, 0.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.0 };

  if (isInitialized_loadAndTestModel == false) {
    loadAndTestModel_initialize();
  }

  y = total_acc_x_test[0];
  b_y = total_acc_y_test[0];
  c_y = total_acc_z_test[0];
  for (k = 0; k < 63; k++) {
    y += total_acc_x_test[k + 1];
    b_y += total_acc_y_test[k + 1];
    c_y += total_acc_z_test[k + 1];
  }

  /*  Calculate std of all samples for each channel */
  /*  Calculate pca of all samples for each channel */
  for (k = 0; k < 32; k++) {
    total_acc_x_test_tmp = k << 1;
    b_total_acc_x_test[total_acc_x_test_tmp] = total_acc_x_test[k];
    b_total_acc_x_test[total_acc_x_test_tmp + 1] = total_acc_x_test[k + 32];
  }

  pca(b_total_acc_x_test, unusedU0_data, unusedU0_size, T_wpca1_acc_x_data,
      T_wpca1_acc_x_size);
  for (k = 0; k < 32; k++) {
    total_acc_x_test_tmp = k << 1;
    b_total_acc_x_test[total_acc_x_test_tmp] = total_acc_y_test[k];
    b_total_acc_x_test[total_acc_x_test_tmp + 1] = total_acc_y_test[k + 32];
  }

  pca(b_total_acc_x_test, unusedU0_data, unusedU0_size, T_wpca1_acc_y_data,
      T_wpca1_acc_x_size);
  for (k = 0; k < 32; k++) {
    total_acc_x_test_tmp = k << 1;
    b_total_acc_x_test[total_acc_x_test_tmp] = total_acc_z_test[k];
    b_total_acc_x_test[total_acc_x_test_tmp + 1] = total_acc_z_test[k + 32];
  }

  pca(b_total_acc_x_test, unusedU0_data, unusedU0_size, T_wpca1_acc_z_data,
      T_wpca1_acc_x_size);

  /*  Calculate std of all samples for each channel */
  /*  Create a matrix of all the features */
  SVM_ClassNames[0] = 0.0;
  SVM_ClassNames[1] = 1.0;
  for (k = 0; k < 17; k++) {
    SVM_PruneList_data[k] = iv[k];
  }

  SVM_Cost[0] = 0.0;
  SVM_Cost[1] = 1.0;
  SVM_Cost[2] = 1.0;
  SVM_Cost[3] = 0.0;

  /*  Create a label of predictions */
  d_y[0] = y / 64.0;
  d_y[1] = b_y / 64.0;
  d_y[2] = c_y / 64.0;
  d_y[3] = b_std(total_acc_x_test);
  d_y[4] = b_std(total_acc_y_test);
  d_y[5] = b_std(total_acc_z_test);
  d_y[6] = T_wpca1_acc_x_data[0];
  d_y[7] = T_wpca1_acc_y_data[0];
  d_y[8] = T_wpca1_acc_z_data[0];
  d_y[9] = Wfreq(total_acc_x_test);
  d_y[10] = Wfreq(total_acc_y_test);
  d_y[11] = Wfreq(total_acc_z_test);
  return c_CompactClassificationTree_pre(SVM_CutPredictorIndex, SVM_Children,
    SVM_CutPoint, SVM_PruneList_data, SVM_NanCutPoints, SVM_ClassNames, SVM_Cost,
    SVM_ClassProbability, d_y);
}

/*
 * File trailer for loadAndTestModel.c
 *
 * [EOF]
 */
