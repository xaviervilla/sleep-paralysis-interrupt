/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Wpca1_api.h
 *
 * Code generation for function '_coder_Wpca1_api'
 *
 */

#ifndef _CODER_WPCA1_API_H
#define _CODER_WPCA1_API_H

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
extern void Wpca1(real_T X[8192], real_T Y_data[], int32_T Y_size[2]);
extern void Wpca1_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray
                      *plhs[1]);
extern void Wpca1_atexit(void);
extern void Wpca1_initialize(void);
extern void Wpca1_terminate(void);
extern void Wpca1_xil_shutdown(void);
extern void Wpca1_xil_terminate(void);

#endif

/* End of code generation (_coder_Wpca1_api.h) */
