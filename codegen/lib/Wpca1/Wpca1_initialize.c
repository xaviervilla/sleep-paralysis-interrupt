/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Wpca1_initialize.c
 *
 * Code generation for function 'Wpca1_initialize'
 *
 */

/* Include files */
#include "Wpca1_initialize.h"
#include "Wpca1.h"
#include "Wpca1_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Wpca1_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_Wpca1 = true;
}

/* End of code generation (Wpca1_initialize.c) */
