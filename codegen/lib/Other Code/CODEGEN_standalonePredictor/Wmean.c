/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Wmean.c
 *
 * Code generation for function 'Wmean'
 *
 */

/* Include files */
#include "Wmean.h"
#include "CODEGEN_standalonePredictor.h"
#include "CODEGEN_standalonePredictor_data.h"
#include "CODEGEN_standalonePredictor_initialize.h"
#include "Wpca1.h"
#include "Wstd.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void Wmean(const double X[2048], double Y[16])
{
  int k;
  int xoffset;
  int j;
  if (isInitialized_CODEGEN_standalonePredictor == false) {
    CODEGEN_standalonePredictor_initialize();
  }

  /*  Copyright (c) 2015, MathWorks, Inc. */
  memcpy(&Y[0], &X[0], 16U * sizeof(double));
  for (k = 0; k < 127; k++) {
    xoffset = (k + 1) << 4;
    for (j = 0; j < 16; j++) {
      Y[j] += X[xoffset + j];
    }
  }

  for (k = 0; k < 16; k++) {
    Y[k] /= 128.0;
  }
}

/* End of code generation (Wmean.c) */
