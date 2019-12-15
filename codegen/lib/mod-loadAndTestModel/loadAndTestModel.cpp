/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: loadAndTestModel.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 15-Dec-2019 01:21:20
 */

/* Include Files */
#include "loadAndTestModel.h"
#include "CompactClassificationTree.h"
#include "loadAndTestModel_data.h"
#include "loadAndTestModel_initialize.h"
#include "pca.h"
#include "rt_nonfinite.h"
#include "std.h"
#include <string.h>

/* Function Definitions */

/*
 * Calculate mean of all samples for each channel
 *      T_mean_acc_x = mean(total_acc_x_test(:,:), 2);
 *      T_mean_acc_y = mean(total_acc_y_test(:,:), 2);
 *      T_mean_acc_z = mean(total_acc_z_test(:,:), 2);
 * Arguments    : const double total_acc_x_test[64]
 *                const double total_acc_y_test[64]
 *                const double total_acc_z_test[64]
 *                double label[2]
 * Return Type  : void
 */
void loadAndTestModel(const double total_acc_x_test[64], const double
                      total_acc_y_test[64], const double total_acc_z_test[64],
                      double label[2])
{
  double reshapes_f1[2];
  double reshapes_f2[2];
  double reshapes_f3[2];
  double unusedU0_data[32];
  int unusedU0_size[2];
  double T_wpca1_acc_x_data[2];
  int T_wpca1_acc_x_size[2];
  double T_wpca1_acc_y_data[2];
  int T_wpca1_acc_y_size[2];
  double T_wpca1_acc_z_data[2];
  int T_wpca1_acc_z_size[2];
  int unnamed_idx_0;
  double reshapes_f7_idx_0;
  double b[64];
  int b_unnamed_idx_0;
  double reshapes_f7_idx_1;
  double reshapes_f8_idx_0;
  double reshapes_f8_idx_1;
  double SVM_ClassNames[2];
  double SVM_Cost[4];
  double SVM_PruneList_data[11];
  static const signed char iv[11] = { 5, 2, 4, 1, 0, 0, 3, 0, 0, 0, 0 };

  int c_unnamed_idx_0;
  double b_reshapes_f1[18];
  static const double SVM_CutPredictorIndex[11] = { 6.0, 5.0, 3.0, 5.0, 0.0, 0.0,
    2.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_Children[22] = { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
    9.0, 0.0, 0.0, 0.0, 0.0, 10.0, 11.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const double SVM_CutPoint[11] = { 10243.984493696515, 68483.6770389129,
    1798.4241161137211, -79680.257341773307, 0.0, 0.0, 2874.9726170009067, 0.0,
    0.0, 0.0, 0.0 };

  static const bool SVM_NanCutPoints[11] = { false, false, false, false, true,
    true, false, true, true, true, true };

  static const double SVM_ClassProbability[22] = { 0.80140186915887857, 0.95,
    0.36111111111111116, 0.97734627831715215, 0.1818181818181818,
    0.888888888888889, 0.18518518518518517, 0.3, 1.0, 0.0, 0.75,
    0.19859813084112135, 0.050000000000000031, 0.638888888888889,
    0.022653721682847912, 0.81818181818181812, 0.1111111111111111,
    0.81481481481481477, 0.70000000000000007, 0.0, 1.0, 0.25 };

  if (isInitialized_loadAndTestModel == false) {
    loadAndTestModel_initialize();
  }

  /*  Calculate std of all samples for each channel */
  b_std(total_acc_x_test, reshapes_f1);
  b_std(total_acc_y_test, reshapes_f2);
  b_std(total_acc_z_test, reshapes_f3);

  /*  Calculate pca of all samples for each channel */
  pca(total_acc_x_test, unusedU0_data, unusedU0_size, T_wpca1_acc_x_data,
      T_wpca1_acc_x_size);
  pca(total_acc_y_test, unusedU0_data, unusedU0_size, T_wpca1_acc_y_data,
      T_wpca1_acc_y_size);
  pca(total_acc_z_test, unusedU0_data, unusedU0_size, T_wpca1_acc_z_data,
      T_wpca1_acc_z_size);

  /*  Calculate std of all samples for each channel */
  for (unnamed_idx_0 = 0; unnamed_idx_0 < 2; unnamed_idx_0++) {
    for (b_unnamed_idx_0 = 0; b_unnamed_idx_0 < 32; b_unnamed_idx_0++) {
      b[b_unnamed_idx_0 + (unnamed_idx_0 << 5)] = total_acc_x_test[unnamed_idx_0
        + (b_unnamed_idx_0 << 1)];
    }
  }

  reshapes_f7_idx_0 = b[0];
  reshapes_f7_idx_1 = b[32];
  for (unnamed_idx_0 = 0; unnamed_idx_0 < 2; unnamed_idx_0++) {
    for (b_unnamed_idx_0 = 0; b_unnamed_idx_0 < 32; b_unnamed_idx_0++) {
      b[b_unnamed_idx_0 + (unnamed_idx_0 << 5)] = total_acc_y_test[unnamed_idx_0
        + (b_unnamed_idx_0 << 1)];
    }
  }

  reshapes_f8_idx_0 = b[0];
  reshapes_f8_idx_1 = b[32];
  for (unnamed_idx_0 = 0; unnamed_idx_0 < 2; unnamed_idx_0++) {
    for (b_unnamed_idx_0 = 0; b_unnamed_idx_0 < 32; b_unnamed_idx_0++) {
      b[b_unnamed_idx_0 + (unnamed_idx_0 << 5)] = total_acc_z_test[unnamed_idx_0
        + (b_unnamed_idx_0 << 1)];
    }
  }

  /*  Create a matrix of all the features */
  SVM_ClassNames[0] = 0.0;
  SVM_ClassNames[1] = 1.0;
  for (unnamed_idx_0 = 0; unnamed_idx_0 < 11; unnamed_idx_0++) {
    SVM_PruneList_data[unnamed_idx_0] = iv[unnamed_idx_0];
  }

  SVM_Cost[0] = 0.0;
  SVM_Cost[1] = 1.0;
  SVM_Cost[2] = 1.0;
  SVM_Cost[3] = 0.0;

  /*  Create a label of predictions */
  unnamed_idx_0 = T_wpca1_acc_x_size[1] << 1;
  b_unnamed_idx_0 = T_wpca1_acc_y_size[1] << 1;
  c_unnamed_idx_0 = T_wpca1_acc_z_size[1] << 1;
  b_reshapes_f1[0] = reshapes_f1[0];
  b_reshapes_f1[2] = reshapes_f2[0];
  b_reshapes_f1[4] = reshapes_f3[0];
  b_reshapes_f1[1] = reshapes_f1[1];
  b_reshapes_f1[3] = reshapes_f2[1];
  b_reshapes_f1[5] = reshapes_f3[1];
  if (0 <= unnamed_idx_0 - 1) {
    memcpy(&b_reshapes_f1[6], &T_wpca1_acc_x_data[0], unnamed_idx_0 * sizeof
           (double));
  }

  if (0 <= b_unnamed_idx_0 - 1) {
    memcpy(&b_reshapes_f1[8], &T_wpca1_acc_y_data[0], b_unnamed_idx_0 * sizeof
           (double));
  }

  if (0 <= c_unnamed_idx_0 - 1) {
    memcpy(&b_reshapes_f1[10], &T_wpca1_acc_z_data[0], c_unnamed_idx_0 * sizeof
           (double));
  }

  b_reshapes_f1[12] = reshapes_f7_idx_0;
  b_reshapes_f1[14] = reshapes_f8_idx_0;
  b_reshapes_f1[16] = b[0];
  b_reshapes_f1[13] = reshapes_f7_idx_1;
  b_reshapes_f1[15] = reshapes_f8_idx_1;
  b_reshapes_f1[17] = b[32];
  c_CompactClassificationTree_pre(SVM_CutPredictorIndex, SVM_Children,
    SVM_CutPoint, SVM_PruneList_data, SVM_NanCutPoints, SVM_ClassNames, SVM_Cost,
    SVM_ClassProbability, b_reshapes_f1, label);
}

/*
 * File trailer for loadAndTestModel.c
 *
 * [EOF]
 */
