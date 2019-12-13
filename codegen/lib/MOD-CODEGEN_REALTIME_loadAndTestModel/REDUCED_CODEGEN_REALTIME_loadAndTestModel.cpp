/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: REDUCED_CODEGEN_REALTIME_loadAndTestModel.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 12-Dec-2019 18:03:22
 */

/* Include Files */
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "CompactClassificationTree.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_data.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize.h"
#include "pca.h"
#include "rt_nonfinite.h"
#include "std.h"

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
void REDUCED_CODEGEN_REALTIME_loadAndTestModel(const double total_acc_x_test[64],
  const double total_acc_y_test[64], const double total_acc_z_test[64], double
  label[2])
{
  double unusedU0_data[32];
  int unusedU0_size[2];
  double T_wpca1_acc_x_data[2];
  int T_wpca1_acc_x_size[2];
  double T_wpca1_acc_y_data[2];
  double T_wpca1_acc_z_data[2];
  int i;
  creal_T b_y1[2];
  double b[64];
  int i1;
  creal_T c_y1[2];
  double SVM_ClassNames[2];
  double SVM_Cost[4];
  double SVM_PruneList_data[11];
  static const signed char iv[11] = { 4, 2, 4, 1, 0, 0, 3, 0, 0, 0, 0 };

  double dv[2];
  double dv1[2];
  double dv2[2];
  double dv3[18];
  static const double SVM_CutPredictorIndex[11] = { 6.0, 5.0, 3.0, 5.0, 0.0, 0.0,
    2.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_Children[22] = { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
    9.0, 0.0, 0.0, 0.0, 0.0, 10.0, 11.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const double SVM_CutPoint[11] = { 13344.780099321903,
    70027.428297165869, 1798.4241161137211, -78138.989822905714, 0.0, 0.0,
    2874.9726170009067, 0.0, 0.0, 0.0, 0.0 };

  static const bool SVM_NanCutPoints[11] = { false, false, false, false, true,
    true, false, true, true, true, true };

  static const double SVM_ClassProbability[22] = { 0.838630806845965,
    0.94999999999999984, 0.43820224719101131, 0.977346278317152,
    0.18181818181818177, 1.0, 0.23076923076923092, 0.3, 1.0, 0.0,
    0.93750000000000011, 0.16136919315403503, 0.050000000000000183,
    0.5617977528089888, 0.022653721682847981, 0.81818181818181812, 0.0,
    0.76923076923076916, 0.70000000000000007, 0.0, 1.0, 0.0625 };

  if (isInitialized_REDUCED_CODEGEN_REALTIME_loadAndTestModel == false) {
    REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize();
  }

  /*  Calculate std of all samples for each channel */
  /*  Calculate pca of all samples for each channel */
  pca(total_acc_x_test, unusedU0_data, unusedU0_size, T_wpca1_acc_x_data,
      T_wpca1_acc_x_size);
  pca(total_acc_y_test, unusedU0_data, unusedU0_size, T_wpca1_acc_y_data,
      T_wpca1_acc_x_size);
  pca(total_acc_z_test, unusedU0_data, unusedU0_size, T_wpca1_acc_z_data,
      T_wpca1_acc_x_size);

  /*  Calculate std of all samples for each channel */
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 32; i1++) {
      b[i1 + (i << 5)] = total_acc_x_test[i + (i1 << 1)];
    }
  }

  b_y1[0].re = b[0];
  b_y1[1].re = b[32];
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 32; i1++) {
      b[i1 + (i << 5)] = total_acc_y_test[i + (i1 << 1)];
    }
  }

  c_y1[0].re = b[0];
  c_y1[1].re = b[32];
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 32; i1++) {
      b[i1 + (i << 5)] = total_acc_z_test[i + (i1 << 1)];
    }
  }

  /*  Create a matrix of all the features */
  SVM_ClassNames[0] = 0.0;
  SVM_ClassNames[1] = 1.0;
  for (i = 0; i < 11; i++) {
    SVM_PruneList_data[i] = iv[i];
  }

  SVM_Cost[0] = 0.0;
  SVM_Cost[1] = 1.0;
  SVM_Cost[2] = 1.0;
  SVM_Cost[3] = 0.0;

  /*  Create a label of predictions */
  b_std(total_acc_x_test, dv);
  b_std(total_acc_y_test, dv1);
  b_std(total_acc_z_test, dv2);
  dv3[0] = dv[0];
  dv3[2] = dv1[0];
  dv3[4] = dv2[0];
  dv3[6] = T_wpca1_acc_x_data[0];
  dv3[8] = T_wpca1_acc_y_data[0];
  dv3[10] = T_wpca1_acc_z_data[0];
  dv3[12] = b_y1[0].re;
  dv3[14] = c_y1[0].re;
  dv3[16] = b[0];
  dv3[1] = dv[1];
  dv3[3] = dv1[1];
  dv3[5] = dv2[1];
  dv3[7] = T_wpca1_acc_x_data[1];
  dv3[9] = T_wpca1_acc_y_data[1];
  dv3[11] = T_wpca1_acc_z_data[1];
  dv3[13] = b_y1[1].re;
  dv3[15] = c_y1[1].re;
  dv3[17] = b[32];
  c_CompactClassificationTree_pre(SVM_CutPredictorIndex, SVM_Children,
    SVM_CutPoint, SVM_PruneList_data, SVM_NanCutPoints, SVM_ClassNames, SVM_Cost,
    SVM_ClassProbability, dv3, label);
}

/*
 * File trailer for REDUCED_CODEGEN_REALTIME_loadAndTestModel.c
 *
 * [EOF]
 */
