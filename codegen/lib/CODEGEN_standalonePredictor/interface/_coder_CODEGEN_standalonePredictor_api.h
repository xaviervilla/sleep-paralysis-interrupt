/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_CODEGEN_standalonePredictor_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Nov-2019 01:41:57
 */

#ifndef _CODER_CODEGEN_STANDALONEPREDICTOR_API_H
#define _CODER_CODEGEN_STANDALONEPREDICTOR_API_H

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
extern real_T CODEGEN_standalonePredictor(real_T X[18]);
extern void CODEGEN_standalonePredictor_api(const mxArray * const prhs[1],
  int32_T nlhs, const mxArray *plhs[1]);
extern void CODEGEN_standalonePredictor_atexit(void);
extern void CODEGEN_standalonePredictor_initialize(void);
extern void CODEGEN_standalonePredictor_terminate(void);
extern void CODEGEN_standalonePredictor_xil_shutdown(void);
extern void CODEGEN_standalonePredictor_xil_terminate(void);

#endif

/*
 * File trailer for _coder_CODEGEN_standalonePredictor_api.h
 *
 * [EOF]
 */
