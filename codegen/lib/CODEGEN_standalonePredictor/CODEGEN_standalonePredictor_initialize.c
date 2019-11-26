/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CODEGEN_standalonePredictor_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Nov-2019 01:41:57
 */

/* Include Files */
#include "CODEGEN_standalonePredictor_initialize.h"
#include "CODEGEN_standalonePredictor.h"
#include "CODEGEN_standalonePredictor_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void CODEGEN_standalonePredictor_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_CODEGEN_standalonePredictor = true;
}

/*
 * File trailer for CODEGEN_standalonePredictor_initialize.c
 *
 * [EOF]
 */
