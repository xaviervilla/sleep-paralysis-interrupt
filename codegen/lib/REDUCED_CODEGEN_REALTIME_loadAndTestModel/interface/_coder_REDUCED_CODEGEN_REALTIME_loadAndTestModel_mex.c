/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_mex.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 09-Dec-2019 01:55:25
 */

/* Include Files */
#include "_coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_mex.h"
#include "_coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void c_REDUCED_CODEGEN_REALTIME_load(int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
void c_REDUCED_CODEGEN_REALTIME_load(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        41, "REDUCED_CODEGEN_REALTIME_loadAndTestModel");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 41,
                        "REDUCED_CODEGEN_REALTIME_loadAndTestModel");
  }

  /* Call the function. */
  REDUCED_CODEGEN_REALTIME_loadAndTestModel_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(REDUCED_CODEGEN_REALTIME_loadAndTestModel_atexit);

  /* Module initialization. */
  REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize();

  /* Dispatch the entry-point. */
  c_REDUCED_CODEGEN_REALTIME_load(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  REDUCED_CODEGEN_REALTIME_loadAndTestModel_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_mex.c
 *
 * [EOF]
 */
