/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_api.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 09-Dec-2019 01:55:25
 */

/* Include Files */
#include "_coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_api.h"
#include "_coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131483U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "REDUCED_CODEGEN_REALTIME_loadAndTestModel",/* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[128];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[128];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *total_acc_x_test, const char_T *identifier))[128];
static const mxArray *emlrt_marshallOut(const real_T u[4]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[128]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[128]
{
  real_T (*y)[128];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[128]
 */
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[128]
{
  real_T (*ret)[128];
  static const int32_T dims[2] = { 4, 32 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[128])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *total_acc_x_test
 *                const char_T *identifier
 * Return Type  : real_T (*)[128]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *total_acc_x_test, const char_T *identifier))[128]
{
  real_T (*y)[128];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(total_acc_x_test), &thisId);
  emlrtDestroyArray(&total_acc_x_test);
  return y;
}
/*
 * Arguments    : const real_T u[4]
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const real_T u[4])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 4 };

  y = NULL;
  m = emlrtCreateNumericArray(1, iv, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void REDUCED_CODEGEN_REALTIME_loadAndTestModel_api(const mxArray * const prhs[3],
  int32_T nlhs, const mxArray *plhs[1])
{
  real_T (*label)[4];
  real_T (*total_acc_x_test)[128];
  real_T (*total_acc_y_test)[128];
  real_T (*total_acc_z_test)[128];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  label = (real_T (*)[4])mxMalloc(sizeof(real_T [4]));

  /* Marshall function inputs */
  total_acc_x_test = emlrt_marshallIn(&st, emlrtAlias(prhs[0]),
    "total_acc_x_test");
  total_acc_y_test = emlrt_marshallIn(&st, emlrtAlias(prhs[1]),
    "total_acc_y_test");
  total_acc_z_test = emlrt_marshallIn(&st, emlrtAlias(prhs[2]),
    "total_acc_z_test");

  /* Invoke the target function */
  REDUCED_CODEGEN_REALTIME_loadAndTestModel(*total_acc_x_test, *total_acc_y_test,
    *total_acc_z_test, *label);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*label);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void REDUCED_CODEGEN_REALTIME_loadAndTestModel_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  REDUCED_CODEGEN_REALTIME_loadAndTestModel_xil_terminate();
  REDUCED_CODEGEN_REALTIME_loadAndTestModel_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void REDUCED_CODEGEN_REALTIME_loadAndTestModel_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_api.c
 *
 * [EOF]
 */
