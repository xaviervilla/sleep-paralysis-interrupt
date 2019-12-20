/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: loadAndTestModel.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 19-Dec-2019 22:53:17
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
  double SVM_PruneList_data[21];
  static const signed char iv[21] = { 4, 2, 4, 2, 0, 4, 1, 0, 2, 3, 0, 1, 0, 0,
    0, 0, 0, 0, 1, 0, 0 };

  double d_y[12];
  static const double SVM_CutPredictorIndex[21] = { 10.0, 6.0, 10.0, 5.0, 0.0,
    2.0, 6.0, 0.0, 2.0, 3.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.0, 0.0,
    0.0 };

  static const double SVM_Children[42] = { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
    9.0, 0.0, 0.0, 10.0, 11.0, 12.0, 13.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0, 0.0,
    0.0, 18.0, 19.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    20.0, 21.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_CutPoint[21] = { 2.25, 7320.1953213740126, 3.75,
    6178.9792274556248, 0.0, -6695.546875, 825.46730163309894, 0.0, -3082.03125,
    -6781.5, 0.0, 316.10397874536682, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    324.56544561119279, 0.0, 0.0 };

  static const bool SVM_NanCutPoints[21] = { false, false, false, false, true,
    false, false, true, false, false, true, false, true, true, true, true, true,
    true, false, true, true };

  static const double SVM_ClassProbability[42] = { 0.94878361075544193,
    0.99181669394435346, 0.79411764705882348, 0.99502487562189057, 0.75,
    0.52941176470588236, 0.97058823529411764, 0.99830220713073,
    0.8571428571428571, 0.085714285714285673, 1.0, 0.98936170212765961, 0.75,
    0.0, 1.0, 1.0, 0.0, 1.0, 0.89999999999999991, 0.0, 1.0, 0.051216389244558035,
    0.00818330605564647, 0.20588235294117646, 0.0049751243781094474, 0.25,
    0.47058823529411764, 0.029411764705882339, 0.001697792869269948,
    0.14285714285714282, 0.91428571428571426, 0.0, 0.01063829787234042, 0.25,
    1.0, 0.0, 0.0, 1.0, 0.0, 0.099999999999999992, 1.0, 0.0 };

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
  for (k = 0; k < 21; k++) {
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
