/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CODEGEN_REALTIME_loadAndTestModel.c
 *
 * Code generation for function 'CODEGEN_REALTIME_loadAndTestModel'
 *
 */

/* Include files */
#include "CODEGEN_REALTIME_loadAndTestModel.h"
#include "CODEGEN_REALTIME_loadAndTestModel_data.h"
#include "CODEGEN_REALTIME_loadAndTestModel_initialize.h"
#include "CODEGEN_standalonePredictor.h"
#include "Wpca1.h"
#include "Wstd.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void CODEGEN_REALTIME_loadAndTestModel(const double total_acc_x_test[256], const
  double total_acc_y_test[256], const double total_acc_z_test[256], const double
  body_gyro_x_test[256], const double body_gyro_y_test[256], const double
  body_gyro_z_test[256], double label[16])
{
  double y[16];
  int k;
  int xoffset;
  double b_y[16];
  int j;
  double c_y[16];
  double d_y[16];
  double e_y[16];
  double f_y[16];
  double T_Wpca1_acc_x_data[240];
  int T_Wpca1_acc_x_size[2];
  double T_Wpca1_acc_y_data[240];
  int T_Wpca1_acc_y_size[2];
  double T_Wpca1_acc_z_data[240];
  int T_Wpca1_acc_z_size[2];
  double T_Wpca1_gyro_x_data[240];
  int T_Wpca1_gyro_x_size[2];
  double T_Wpca1_gyro_y_data[240];
  int T_Wpca1_gyro_y_size[2];
  double T_Wpca1_gyro_z_data[240];
  int T_Wpca1_gyro_z_size[2];
  double dv[16];
  double dv1[16];
  double dv2[16];
  double dv3[16];
  double dv4[16];
  double dv5[16];
  double humanActivityData_data[1632];
  if (isInitialized_CODEGEN_REALTIME_loadAndTestModel == false) {
    CODEGEN_REALTIME_loadAndTestModel_initialize();
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

  /*  Copyright (c) 2015, MathWorks, Inc. */
  memcpy(&d_y[0], &body_gyro_x_test[0], 16U * sizeof(double));
  for (k = 0; k < 15; k++) {
    xoffset = (k + 1) << 4;
    for (j = 0; j < 16; j++) {
      d_y[j] += body_gyro_x_test[xoffset + j];
    }
  }

  /*  Copyright (c) 2015, MathWorks, Inc. */
  memcpy(&e_y[0], &body_gyro_y_test[0], 16U * sizeof(double));
  for (k = 0; k < 15; k++) {
    xoffset = (k + 1) << 4;
    for (j = 0; j < 16; j++) {
      e_y[j] += body_gyro_y_test[xoffset + j];
    }
  }

  /*  Copyright (c) 2015, MathWorks, Inc. */
  memcpy(&f_y[0], &body_gyro_z_test[0], 16U * sizeof(double));
  for (k = 0; k < 15; k++) {
    xoffset = (k + 1) << 4;
    for (j = 0; j < 16; j++) {
      f_y[j] += body_gyro_z_test[xoffset + j];
    }
  }

  /*  Calculate std of all 128 samples for each channel */
  /*  Calculate pca of all 128 samples for each channel */
  Wpca1(total_acc_x_test, T_Wpca1_acc_x_data, T_Wpca1_acc_x_size);
  Wpca1(total_acc_y_test, T_Wpca1_acc_y_data, T_Wpca1_acc_y_size);
  Wpca1(total_acc_z_test, T_Wpca1_acc_z_data, T_Wpca1_acc_z_size);
  Wpca1(body_gyro_x_test, T_Wpca1_gyro_x_data, T_Wpca1_gyro_x_size);
  Wpca1(body_gyro_y_test, T_Wpca1_gyro_y_data, T_Wpca1_gyro_y_size);
  Wpca1(body_gyro_z_test, T_Wpca1_gyro_z_data, T_Wpca1_gyro_z_size);

  /*  Create a matrix of all the features */
  Wstd(total_acc_x_test, dv);
  Wstd(total_acc_y_test, dv1);
  Wstd(total_acc_z_test, dv2);
  Wstd(body_gyro_x_test, dv3);
  Wstd(body_gyro_y_test, dv4);
  Wstd(body_gyro_z_test, dv5);
  for (k = 0; k < 16; k++) {
    humanActivityData_data[k] = y[k] / 16.0;
    humanActivityData_data[k + 16] = b_y[k] / 16.0;
    humanActivityData_data[k + 32] = c_y[k] / 16.0;
    humanActivityData_data[k + 48] = d_y[k] / 16.0;
    humanActivityData_data[k + 64] = e_y[k] / 16.0;
    humanActivityData_data[k + 80] = f_y[k] / 16.0;
    humanActivityData_data[k + 96] = dv[k];
    humanActivityData_data[k + 112] = dv1[k];
    humanActivityData_data[k + 128] = dv2[k];
    humanActivityData_data[k + 144] = dv3[k];
    humanActivityData_data[k + 160] = dv4[k];
    humanActivityData_data[k + 176] = dv5[k];
  }

  xoffset = T_Wpca1_acc_x_size[1L];
  for (k = 0; k < xoffset; k++) {
    memcpy(&humanActivityData_data[k * 16 + 192], &T_Wpca1_acc_x_data[k * 16],
           16U * sizeof(double));
  }

  xoffset = T_Wpca1_acc_y_size[1L];
  for (k = 0; k < xoffset; k++) {
    memcpy(&humanActivityData_data[(k * 16 + T_Wpca1_acc_x_size[1L] * 16) + 192],
           &T_Wpca1_acc_y_data[k * 16], 16U * sizeof(double));
  }

  xoffset = T_Wpca1_acc_z_size[1L];
  for (k = 0; k < xoffset; k++) {
    memcpy(&humanActivityData_data[(k * 16 + (T_Wpca1_acc_x_size[1L] +
             T_Wpca1_acc_y_size[1L]) * 16) + 192], &T_Wpca1_acc_z_data[k * 16],
           16U * sizeof(double));
  }

  xoffset = T_Wpca1_gyro_x_size[1L];
  for (k = 0; k < xoffset; k++) {
    memcpy(&humanActivityData_data[(k * 16 + ((T_Wpca1_acc_x_size[1L] +
              T_Wpca1_acc_y_size[1L]) + T_Wpca1_acc_z_size[1L]) * 16) + 192],
           &T_Wpca1_gyro_x_data[k * 16], 16U * sizeof(double));
  }

  xoffset = T_Wpca1_gyro_y_size[1L];
  for (k = 0; k < xoffset; k++) {
    memcpy(&humanActivityData_data[(k * 16 + (((T_Wpca1_acc_x_size[1L] +
               T_Wpca1_acc_y_size[1L]) + T_Wpca1_acc_z_size[1L]) +
             T_Wpca1_gyro_x_size[1L]) * 16) + 192], &T_Wpca1_gyro_y_data[k * 16],
           16U * sizeof(double));
  }

  xoffset = T_Wpca1_gyro_z_size[1L];
  for (k = 0; k < xoffset; k++) {
    memcpy(&humanActivityData_data[(k * 16 + ((((T_Wpca1_acc_x_size[1L] +
                T_Wpca1_acc_y_size[1L]) + T_Wpca1_acc_z_size[1L]) +
              T_Wpca1_gyro_x_size[1L]) + T_Wpca1_gyro_y_size[1L]) * 16) + 192],
           &T_Wpca1_gyro_z_data[k * 16], 16U * sizeof(double));
  }

  /*  Create a label of predictions */
  CODEGEN_standalonePredictor(*(double (*)[288])&humanActivityData_data[0],
    label);
}

/* End of code generation (CODEGEN_REALTIME_loadAndTestModel.c) */
