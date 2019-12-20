/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: loadAndTestModel.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 20-Dec-2019 12:06:10
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
  double SVM_PruneList_data[27];
  static const signed char iv[27] = { 6, 0, 6, 2, 6, 2, 2, 6, 0, 1, 2, 0, 0, 5,
    0, 1, 0, 0, 0, 4, 0, 0, 0, 0, 3, 0, 0 };

  double d_y[12];
  static const double SVM_CutPredictorIndex[27] = { 6.0, 0.0, 12.0, 6.0, 2.0,
    5.0, 4.0, 1.0, 0.0, 4.0, 5.0, 0.0, 0.0, 4.0, 0.0, 4.0, 0.0, 0.0, 0.0, 10.0,
    0.0, 0.0, 0.0, 0.0, 3.0, 0.0, 0.0 };

  static const double SVM_Children[54] = { 2.0, 3.0, 0.0, 0.0, 4.0, 5.0, 6.0,
    7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 0.0, 0.0, 16.0, 17.0,
    18.0, 19.0, 0.0, 0.0, 0.0, 0.0, 20.0, 21.0, 0.0, 0.0, 22.0, 23.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 24.0, 25.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 26.0,
    27.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_CutPoint[27] = { 322.35255825015952, 0.0, 2.25,
    7399.02153153064, -6837.0546875, 6111.0823937303921, 2561.4536910251081,
    -5010.203125, 0.0, 209.92175584452667, 6255.50060560032, 0.0, 0.0,
    998.39503167533371, 0.0, 204.09060570843712, 0.0, 0.0, 0.0, 1.75, 0.0, 0.0,
    0.0, 0.0, -8997.0625, 0.0, 0.0 };

  static const bool SVM_NanCutPoints[27] = { false, true, false, false, false,
    false, false, false, true, false, false, true, true, false, true, false,
    true, true, true, false, true, true, true, true, false, true, true };

  static const double SVM_ClassProbability[54] = { 0.99724137931034418, 1.0,
    0.957492029755579, 0.99127182044887785, 0.76258992805755343,
    0.99368686868686873, 0.8, 0.34, 1.0, 0.99612903225806448,
    0.88235294117647056, 0.33333333333333337, 1.0, 0.19512195121951217, 1.0,
    0.94285714285714284, 0.99864864864864866, 0.0, 1.0, 0.1081081081081081, 1.0,
    0.97058823529411764, 0.0, 1.0, 0.029411764705882353, 1.0, 0.0,
    0.0027586206896558093, 0.0, 0.042507970244421059, 0.0087281795511222424,
    0.23741007194244654, 0.0063131313131313477, 0.19999999999999998, 0.66, 0.0,
    0.0038709677419355047, 0.11764705882352938, 0.66666666666666663, 0.0,
    0.80487804878048774, 0.0, 0.057142857142857134, 0.0013513513513513586, 1.0,
    0.0, 0.89189189189189189, 0.0, 0.029411764705882346, 1.0, 0.0,
    0.97058823529411764, 0.0, 1.0 };

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
  for (k = 0; k < 27; k++) {
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
