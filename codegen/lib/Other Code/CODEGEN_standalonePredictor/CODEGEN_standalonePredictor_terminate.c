/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CODEGEN_standalonePredictor_terminate.c
 *
 * Code generation for function 'CODEGEN_standalonePredictor_terminate'
 *
 */

/* Include files */
#include "CODEGEN_standalonePredictor_terminate.h"
#include "CODEGEN_standalonePredictor.h"
#include "CODEGEN_standalonePredictor_data.h"
#include "Wmean.h"
#include "Wpca1.h"
#include "Wstd.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void CODEGEN_standalonePredictor_terminate(void)
{
  /* (no terminate code required) */
  isInitialized_CODEGEN_standalonePredictor = false;
}

/* End of code generation (CODEGEN_standalonePredictor_terminate.c) */
