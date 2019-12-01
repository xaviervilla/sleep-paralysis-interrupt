/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CODEGEN_standalonePredictor_api.h
 *
 * Code generation for function '_coder_CODEGEN_standalonePredictor_api'
 *
 */

#ifndef _CODER_CODEGEN_STANDALONEPREDICTOR_API_H
#define _CODER_CODEGEN_STANDALONEPREDICTOR_API_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void CODEGEN_standalonePredictor(real_T X[288], real_T label[16]);
extern void CODEGEN_standalonePredictor_api(const mxArray * const prhs[1],
  int32_T nlhs, const mxArray *plhs[1]);
extern void CODEGEN_standalonePredictor_atexit(void);
extern void CODEGEN_standalonePredictor_initialize(void);
extern void CODEGEN_standalonePredictor_terminate(void);
extern void CODEGEN_standalonePredictor_xil_shutdown(void);
extern void CODEGEN_standalonePredictor_xil_terminate(void);
extern void Wmean(real_T X[2048], real_T Y[16]);
extern void Wmean_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray
                      *plhs[1]);
extern void Wpca1(real_T X[2048], real_T Y_data[], int32_T Y_size[2]);
extern void Wpca1_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray
                      *plhs[1]);
extern void Wstd(real_T X[2048], real_T Y[16]);
extern void Wstd_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray *
                     plhs[1]);

#endif

/* End of code generation (_coder_CODEGEN_standalonePredictor_api.h) */
