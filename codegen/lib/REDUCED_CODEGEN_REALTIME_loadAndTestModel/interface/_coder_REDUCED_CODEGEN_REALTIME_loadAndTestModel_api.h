/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 12-Dec-2019 18:03:22
 */

#ifndef _CODER_REDUCED_CODEGEN_REALTIME_LOADANDTESTMODEL_API_H
#define _CODER_REDUCED_CODEGEN_REALTIME_LOADANDTESTMODEL_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void REDUCED_CODEGEN_REALTIME_loadAndTestModel(real_T total_acc_x_test[64],
  real_T total_acc_y_test[64], real_T total_acc_z_test[64], real_T label[2]);
extern void REDUCED_CODEGEN_REALTIME_loadAndTestModel_api(const mxArray * const
  prhs[3], int32_T nlhs, const mxArray *plhs[1]);
extern void REDUCED_CODEGEN_REALTIME_loadAndTestModel_atexit(void);
extern void REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize(void);
extern void REDUCED_CODEGEN_REALTIME_loadAndTestModel_terminate(void);
extern void REDUCED_CODEGEN_REALTIME_loadAndTestModel_xil_shutdown(void);
extern void REDUCED_CODEGEN_REALTIME_loadAndTestModel_xil_terminate(void);

#endif

/*
 * File trailer for _coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_api.h
 *
 * [EOF]
 */
