/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_loadAndTestModel_api.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 19-Dec-2019 22:53:17
 */

/* Include Files */
#include "_coder_loadAndTestModel_api.h"
#include "_coder_loadAndTestModel_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131483U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "loadAndTestModel",                  /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[64];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[64];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *total_acc_x_test, const char_T *identifier))[64];
static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[64]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[64]
{
  real_T (*y)[64];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[64]
 */
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[64]
{
  real_T (*ret)[64];
  static const int32_T dims[2] = { 1, 64 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[64])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *total_acc_x_test
 *                const char_T *identifier
 * Return Type  : real_T (*)[64]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *total_acc_x_test, const char_T *identifier))[64]
{
  real_T (*y)[64];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(total_acc_x_test), &thisId);
  emlrtDestroyArray(&total_acc_x_test);
  return y;
}
/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void loadAndTestModel_api(const mxArray * const prhs[3], int32_T nlhs, const
  mxArray *plhs[1])
{
  real_T (*total_acc_x_test)[64];
  real_T (*total_acc_y_test)[64];
  real_T (*total_acc_z_test)[64];
  real_T label;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  total_acc_x_test = emlrt_marshallIn(&st, emlrtAlias(prhs[0]),
    "total_acc_x_test");
  total_acc_y_test = emlrt_marshallIn(&st, emlrtAlias(prhs[1]),
    "total_acc_y_test");
  total_acc_z_test = emlrt_marshallIn(&st, emlrtAlias(prhs[2]),
    "total_acc_z_test");

  /* Invoke the target function */
  label = loadAndTestModel(*total_acc_x_test, *total_acc_y_test,
    *total_acc_z_test);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(label);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void loadAndTestModel_atexit(void)
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
  loadAndTestModel_xil_terminate();
  loadAndTestModel_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void loadAndTestModel_initialize(void)
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
void loadAndTestModel_terminate(void)
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
 * File trailer for _coder_loadAndTestModel_api.c
 *
 * [EOF]
 */
