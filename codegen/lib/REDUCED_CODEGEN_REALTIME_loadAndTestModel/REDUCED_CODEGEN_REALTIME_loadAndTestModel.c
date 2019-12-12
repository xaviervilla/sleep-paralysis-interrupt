/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: REDUCED_CODEGEN_REALTIME_loadAndTestModel.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 11-Dec-2019 20:06:08
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
  int i;
  creal_T b_y1[4];
  double b[128];
  int i1;
  creal_T c_y1[4];
  double SVM_CutPredictorIndex[9];
  double SVM_Children[18];
  double SVM_CutPoint[9];
  double SVM_PruneList_data[9];
  int SVM_PruneList_size[1];
  bool SVM_NanCutPoints[9];
  bool expl_temp[9];
  double SVM_ClassNames[2];
  c_classreg_learning_coderutils_ b_expl_temp;
  double c_expl_temp[2];
  bool d_expl_temp[2];
  double SVM_Cost[4];
  double SVM_ClassProbability[18];
  double dv[4];
  double dv1[4];
  double dv2[4];
  double dv3[36];
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
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 32; i1++) {
      b[i1 + (i << 5)] = total_acc_x_test[i + (i1 << 2)];
    }
  }

  b_y1[0].re = b[0];
  b_y1[1].re = b[32];
  b_y1[2].re = b[64];
  b_y1[3].re = b[96];
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 32; i1++) {
      b[i1 + (i << 5)] = total_acc_y_test[i + (i1 << 2)];
    }
  }

  c_y1[0].re = b[0];
  c_y1[1].re = b[32];
  c_y1[2].re = b[64];
  c_y1[3].re = b[96];
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 32; i1++) {
      b[i1 + (i << 5)] = total_acc_z_test[i + (i1 << 2)];
    }
  }

  /*  Create a matrix of all the features */
  c_CompactClassificationTree_Com(SVM_CutPredictorIndex, SVM_Children,
    SVM_CutPoint, SVM_PruneList_data, SVM_PruneList_size, SVM_NanCutPoints,
    expl_temp, SVM_ClassNames, T_wpca1_acc_x_size, &b_expl_temp, c_expl_temp,
    d_expl_temp, SVM_Cost, SVM_ClassProbability);

  /*  Create a label of predictions */
  b_std(total_acc_x_test, dv);
  b_std(total_acc_y_test, dv1);
  b_std(total_acc_z_test, dv2);
  dv3[0] = dv[0];
  dv3[4] = dv1[0];
  dv3[8] = dv2[0];
  dv3[12] = T_wpca1_acc_x_data[0];
  dv3[16] = T_wpca1_acc_y_data[0];
  dv3[20] = T_wpca1_acc_z_data[0];
  dv3[24] = b_y1[0].re;
  dv3[28] = c_y1[0].re;
  dv3[32] = b[0];
  dv3[1] = dv[1];
  dv3[5] = dv1[1];
  dv3[9] = dv2[1];
  dv3[13] = T_wpca1_acc_x_data[1];
  dv3[17] = T_wpca1_acc_y_data[1];
  dv3[21] = T_wpca1_acc_z_data[1];
  dv3[25] = b_y1[1].re;
  dv3[29] = c_y1[1].re;
  dv3[33] = b[32];
  dv3[2] = dv[2];
  dv3[6] = dv1[2];
  dv3[10] = dv2[2];
  dv3[14] = T_wpca1_acc_x_data[2];
  dv3[18] = T_wpca1_acc_y_data[2];
  dv3[22] = T_wpca1_acc_z_data[2];
  dv3[26] = b_y1[2].re;
  dv3[30] = c_y1[2].re;
  dv3[34] = b[64];
  dv3[3] = dv[3];
  dv3[7] = dv1[3];
  dv3[11] = dv2[3];
  dv3[15] = T_wpca1_acc_x_data[3];
  dv3[19] = T_wpca1_acc_y_data[3];
  dv3[23] = T_wpca1_acc_z_data[3];
  dv3[27] = b_y1[3].re;
  dv3[31] = c_y1[3].re;
  dv3[35] = b[96];
  c_CompactClassificationTree_pre(SVM_CutPredictorIndex, SVM_Children,
    SVM_CutPoint, SVM_PruneList_data, SVM_NanCutPoints, SVM_ClassNames, SVM_Cost,
    SVM_ClassProbability, dv3, label);
}

/*
 * File trailer for REDUCED_CODEGEN_REALTIME_loadAndTestModel.c
 *
 * [EOF]
 */
