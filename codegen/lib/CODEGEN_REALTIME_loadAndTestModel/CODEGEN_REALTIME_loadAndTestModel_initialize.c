/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CODEGEN_REALTIME_loadAndTestModel_initialize.c
 *
 * Code generation for function 'CODEGEN_REALTIME_loadAndTestModel_initialize'
 *
 */

/* Include files */
#include "CODEGEN_REALTIME_loadAndTestModel_initialize.h"
#include "CODEGEN_REALTIME_loadAndTestModel.h"
#include "CODEGEN_REALTIME_loadAndTestModel_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void CODEGEN_REALTIME_loadAndTestModel_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_CODEGEN_REALTIME_loadAndTestModel = true;
}

/* End of code generation (CODEGEN_REALTIME_loadAndTestModel_initialize.c) */
