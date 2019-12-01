/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize.c
 *
 * Code generation for function 'REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize'
 *
 */

/* Include files */
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_REDUCED_CODEGEN_REALTIME_loadAndTestModel = true;
}

/* End of code generation (REDUCED_CODEGEN_REALTIME_loadAndTestModel_initialize.c) */
