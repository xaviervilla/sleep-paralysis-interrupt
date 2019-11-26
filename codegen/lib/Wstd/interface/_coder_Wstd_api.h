/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Wstd_api.h
 *
 * Code generation for function '_coder_Wstd_api'
 *
 */

#ifndef _CODER_WSTD_API_H
#define _CODER_WSTD_API_H

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
extern void Wstd(real_T X[8192], real_T Y[64]);
extern void Wstd_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray *
                     plhs[1]);
extern void Wstd_atexit(void);
extern void Wstd_initialize(void);
extern void Wstd_terminate(void);
extern void Wstd_xil_shutdown(void);
extern void Wstd_xil_terminate(void);

#endif

/* End of code generation (_coder_Wstd_api.h) */
