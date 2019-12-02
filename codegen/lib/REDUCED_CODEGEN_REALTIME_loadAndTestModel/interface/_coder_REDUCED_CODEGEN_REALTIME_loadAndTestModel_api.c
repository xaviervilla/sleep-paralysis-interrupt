/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_api.c
 *
 * Code generation for function '_coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_api'
 *
 */

/* Include files */
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
  emlrtMsgIdentifier *parentId))[8];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *total_acc_x_test, const char_T *identifier))[8];
static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8]
{
  real_T (*y)[8];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8]
{
  real_T (*ret)[8];
  static const int32_T dims[2] = { 1, 8 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[8])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *total_acc_x_test, const char_T *identifier))[8]
{
  real_T (*y)[8];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(total_acc_x_test), &thisId);
  emlrtDestroyArray(&total_acc_x_test);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void REDUCED_CODEGEN_REALTIME_loadAndTestModel_api(const mxArray * const prhs[3],
  int32_T nlhs, const mxArray *plhs[1])
{
  real_T (*total_acc_x_test)[8];
  real_T (*total_acc_y_test)[8];
  real_T (*total_acc_z_test)[8];
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
  label = REDUCED_CODEGEN_REALTIME_loadAndTestModel(*total_acc_x_test,
    *total_acc_y_test, *total_acc_z_test);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(label);
}

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

/* End of code generation (_coder_REDUCED_CODEGEN_REALTIME_loadAndTestModel_api.c) */
