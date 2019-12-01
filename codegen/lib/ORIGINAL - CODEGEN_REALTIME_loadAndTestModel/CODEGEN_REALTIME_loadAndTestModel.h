/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CODEGEN_REALTIME_loadAndTestModel.h
 *
 * Code generation for function 'CODEGEN_REALTIME_loadAndTestModel'
 *
 */

#ifndef CODEGEN_REALTIME_LOADANDTESTMODEL_H
#define CODEGEN_REALTIME_LOADANDTESTMODEL_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void CODEGEN_REALTIME_loadAndTestModel(const double total_acc_x_test[256],
  const double total_acc_y_test[256], const double total_acc_z_test[256], const
  double body_gyro_x_test[256], const double body_gyro_y_test[256], const double
  body_gyro_z_test[256], double label[16]);

#endif

/* End of code generation (CODEGEN_REALTIME_loadAndTestModel.h) */
