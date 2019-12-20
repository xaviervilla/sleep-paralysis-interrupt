/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: loadAndTestModel.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 20-Dec-2019 14:56:44
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
  double SVM_PruneList_data[31];
  static const signed char iv[31] = { 5, 4, 5, 0, 4, 3, 5, 4, 1, 0, 2, 3, 0, 0,
    4, 0, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0 };

  double d_y[12];
  static const double SVM_CutPredictorIndex[31] = { 6.0, 6.0, 12.0, 0.0, 2.0,
    6.0, 5.0, 2.0, 6.0, 0.0, 6.0, 2.0, 0.0, 0.0, 1.0, 0.0, 6.0, 5.0, 4.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_Children[62] = { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 0.0,
    0.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 0.0, 0.0,
    18.0, 19.0, 20.0, 21.0, 0.0, 0.0, 0.0, 0.0, 22.0, 23.0, 0.0, 0.0, 24.0, 25.0,
    26.0, 27.0, 28.0, 29.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 30.0, 31.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_CutPoint[31] = { 793.58597872494261,
    322.35255825015952, 2.25, 0.0, -11374.046875, 794.27012561313188,
    935.10928615483635, -11547.921875, 719.9600528894814, 0.0, 7399.02153153064,
    -8828.125, 0.0, 0.0, -7432.609375, 0.0, 724.04569922490327,
    6111.0823937303921, 2561.4536910251081, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    6255.50060560032, 0.0, 0.0, 0.0, 0.0 };

  static const bool SVM_NanCutPoints[31] = { false, false, false, true, false,
    false, false, false, false, true, false, false, true, true, false, true,
    false, false, false, true, true, true, true, true, true, true, false, true,
    true, true, true };

  static const double SVM_ClassProbability[62] = { 0.995730615617682,
    0.99935298346513279, 0.91339869281045749, 1.0, 0.97435897435897423,
    0.99054820415879008, 0.42168674698795205, 0.80487804878048785,
    0.99677419354838714, 0.0, 0.99242424242424232, 0.02222222222222224,
    0.89473684210526327, 1.0, 0.20000000000000004, 1.0, 0.97058823529411775,
    0.99613899613899626, 0.8, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.88235294117647067, 0.33333333333333337, 1.0, 0.0, 1.0, 0.00426938438231807,
    0.000647016534867233, 0.086601307189542565, 0.0, 0.025641025641025769,
    0.0094517958412098663, 0.57831325301204806, 0.19512195121951215,
    0.0032258064516129145, 1.0, 0.0075757575757576055, 0.97777777777777786,
    0.10526315789473682, 0.0, 0.79999999999999993, 0.0, 0.029411764705882346,
    0.0038610038610038784, 0.19999999999999996, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 0.11764705882352935, 0.66666666666666663, 0.0, 1.0, 0.0 };

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
  for (k = 0; k < 31; k++) {
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
