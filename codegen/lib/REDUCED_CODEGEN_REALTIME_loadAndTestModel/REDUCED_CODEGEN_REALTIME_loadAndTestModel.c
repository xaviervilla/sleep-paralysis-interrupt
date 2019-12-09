/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: REDUCED_CODEGEN_REALTIME_loadAndTestModel.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 09-Dec-2019 01:55:25
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
 * Arguments    : const double total_acc_x_test[128]
 *                const double total_acc_y_test[128]
 *                const double total_acc_z_test[128]
 *                double label[4]
 * Return Type  : void
 */
void REDUCED_CODEGEN_REALTIME_loadAndTestModel(const double total_acc_x_test[128],
  const double total_acc_y_test[128], const double total_acc_z_test[128], double
  label[4])
{
  double unusedU0_data[96];
  int unusedU0_size[2];
  double T_wpca1_acc_x_data[12];
  int T_wpca1_acc_x_size[2];
  double T_wpca1_acc_y_data[12];
  double T_wpca1_acc_z_data[12];
  double SVM_ClassNames[2];
  double SVM_PruneList_data[3];
  double dv[4];
  double SVM_Cost[4];
  double b_I[24];
  double dv1[4];
  static const double SVM_Children[6] = { 2.0, 3.0, 0.0, 0.0, 0.0, 0.0 };

  static const double SVM_CutPoint[3] = { 4865.8001042878095, 0.0, 0.0 };

  static const bool SVM_NanCutPoints[3] = { false, true, true };

  static const double SVM_ClassProbability[6] = { 0.87547169811320757,
    0.95473251028806583, 0.0, 0.12452830188679245, 0.045267489711934158, 1.0 };

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

  /*  Create a matrix of all the features */
  SVM_ClassNames[0] = 0.0;
  SVM_ClassNames[1] = 1.0;
  SVM_PruneList_data[0] = 1.0;
  SVM_PruneList_data[1] = 0.0;
  SVM_PruneList_data[2] = 0.0;

  /*  Create a label of predictions */
  b_std(total_acc_x_test, dv);
  SVM_Cost[0] = 0.0;
  b_I[0] = dv[0];
  SVM_Cost[1] = 1.0;
  b_I[1] = dv[1];
  SVM_Cost[2] = 1.0;
  b_I[2] = dv[2];
  SVM_Cost[3] = 0.0;
  b_I[3] = dv[3];
  b_std(total_acc_y_test, dv);
  b_std(total_acc_z_test, dv1);
  b_I[4] = dv[0];
  b_I[8] = dv1[0];
  b_I[12] = T_wpca1_acc_x_data[0];
  b_I[16] = T_wpca1_acc_y_data[0];
  b_I[20] = T_wpca1_acc_z_data[0];
  b_I[5] = dv[1];
  b_I[9] = dv1[1];
  b_I[13] = T_wpca1_acc_x_data[1];
  b_I[17] = T_wpca1_acc_y_data[1];
  b_I[21] = T_wpca1_acc_z_data[1];
  b_I[6] = dv[2];
  b_I[10] = dv1[2];
  b_I[14] = T_wpca1_acc_x_data[2];
  b_I[18] = T_wpca1_acc_y_data[2];
  b_I[22] = T_wpca1_acc_z_data[2];
  b_I[7] = dv[3];
  b_I[11] = dv1[3];
  b_I[15] = T_wpca1_acc_x_data[3];
  b_I[19] = T_wpca1_acc_y_data[3];
  b_I[23] = T_wpca1_acc_z_data[3];
  c_CompactClassificationTree_pre(SVM_Children, SVM_CutPoint, SVM_PruneList_data,
    SVM_NanCutPoints, SVM_ClassNames, SVM_Cost, SVM_ClassProbability, b_I, label);
}

/*
 * File trailer for REDUCED_CODEGEN_REALTIME_loadAndTestModel.c
 *
 * [EOF]
 */
