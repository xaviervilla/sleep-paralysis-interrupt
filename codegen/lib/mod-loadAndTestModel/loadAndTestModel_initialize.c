/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: loadAndTestModel_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 19-Dec-2019 22:53:17
 */

/* Include Files */
#include "loadAndTestModel_initialize.h"
#include "loadAndTestModel.h"
#include "loadAndTestModel_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void loadAndTestModel_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_loadAndTestModel = true;
}

/*
 * File trailer for loadAndTestModel_initialize.c
 *
 * [EOF]
 */
