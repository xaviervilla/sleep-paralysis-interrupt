/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Wmean_api.h
 *
 * Code generation for function '_coder_Wmean_api'
 *
 */

#ifndef _CODER_WMEAN_API_H
#define _CODER_WMEAN_API_H

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
extern void Wmean(real_T X[2048], real_T Y[16]);
extern void Wmean_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray
                      *plhs[1]);
extern void Wmean_atexit(void);
extern void Wmean_initialize(void);
extern void Wmean_terminate(void);
extern void Wmean_xil_shutdown(void);
extern void Wmean_xil_terminate(void);

#endif

/* End of code generation (_coder_Wmean_api.h) */
