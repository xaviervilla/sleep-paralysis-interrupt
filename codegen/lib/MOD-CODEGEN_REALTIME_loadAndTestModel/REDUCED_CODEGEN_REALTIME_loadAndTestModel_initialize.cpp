/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 11-Dec-2019 20:06:08
 */

/* Include Files */
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_REDUCED_CODEGEN_REALTIME_loadAndTestModel = true;
}

/*
 * File trailer for REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize.c
 *
 * [EOF]
 */
