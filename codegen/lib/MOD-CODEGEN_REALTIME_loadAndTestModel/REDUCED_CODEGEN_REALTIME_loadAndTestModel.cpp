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
#include "pca.h"
#include "rt_nonfinite.h"
#include "std.h"

/* Function Definitions */
void REDUCED_CODEGEN_REALTIME_loadAndTestModel(const double total_acc_x_test[16],
  const double total_acc_y_test[16], const double total_acc_z_test[16], double
  label[2])
{
  double unusedU0_data[8];
  int unusedU0_size[2];
  double T_wpca1_acc_x_data[2];
  int T_wpca1_acc_x_size[2];
  double T_wpca1_acc_y_data[2];
  double T_wpca1_acc_z_data[2];
  double SVM_ClassNames[2];
  int i;
  double SVM_Cost[4];
  double SVM_PruneList_data[5];
  static const signed char iv[5] = { 2, 0, 1, 0, 0 };

  double dv[2];
  double dv1[2];
  double dv2[2];
  double dv3[12];
  static const double SVM_CutPredictorIndex[5] = { 1.0, 0.0, 4.0, 0.0, 0.0 };

  static const double SVM_Children[10] = { 2.0, 3.0, 0.0, 0.0, 4.0, 5.0, 0.0,
    0.0, 0.0, 0.0 };

  static const double SVM_CutPoint[5] = { 0.10902012795745872, 0.0,
    -1.0209189505188874, 0.0, 0.0 };

  static const bool SVM_NanCutPoints[5] = { false, true, false, true, true };

  static const double SVM_ClassProbability[10] = { 0.553182807399347,
    0.99926199261992621, 0.0015211439002129924, 1.0, 0.0, 0.44681719260065295,
    0.00073800738007381665, 0.998478856099787, 0.0, 1.0 };

  if (isInitialized_REDUCED_CODEGEN_REALTIME_loadAndTestModel == false) {
    REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize();
  }

  /*  Calculate mean of all samples for each channel */
  /*      T_mean_acc_x = mean(total_acc_x_test(:,:), 2); */
  /*      T_mean_acc_y = mean(total_acc_y_test(:,:), 2); */
  /*      T_mean_acc_z = mean(total_acc_z_test(:,:), 2); */
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
  for (i = 0; i < 5; i++) {
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
  dv3[1] = dv[1];
  dv3[3] = dv1[1];
  dv3[5] = dv2[1];
  dv3[7] = T_wpca1_acc_x_data[1];
  dv3[9] = T_wpca1_acc_y_data[1];
  dv3[11] = T_wpca1_acc_z_data[1];
  c_CompactClassificationTree_pre(SVM_CutPredictorIndex, SVM_Children,
    SVM_CutPoint, SVM_PruneList_data, SVM_NanCutPoints, SVM_ClassNames, SVM_Cost,
    SVM_ClassProbability, dv3, label);
}

/* End of code generation (REDUCED_CODEGEN_REALTIME_loadAndTestModel.c) */
