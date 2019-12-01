/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CODEGEN_standalonePredictor_initialize.c
 *
 * Code generation for function 'CODEGEN_standalonePredictor_initialize'
 *
 */

/* Include files */
#include "CODEGEN_standalonePredictor_initialize.h"
#include "CODEGEN_standalonePredictor.h"
#include "CODEGEN_standalonePredictor_data.h"
#include "Wmean.h"
#include "Wpca1.h"
#include "Wstd.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void CODEGEN_standalonePredictor_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_CODEGEN_standalonePredictor = true;
}

/* End of code generation (CODEGEN_standalonePredictor_initialize.c) */
