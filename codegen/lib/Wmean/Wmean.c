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
#include <string.h>

/* Function Definitions */
void Wmean(const double X[8192], double Y[64])
{
  int k;
  int xoffset;
  int j;

  /*  Copyright (c) 2015, MathWorks, Inc. */
  memcpy(&Y[0], &X[0], 64U * sizeof(double));
  for (k = 0; k < 127; k++) {
    xoffset = (k + 1) << 6;
    for (j = 0; j < 64; j++) {
      Y[j] += X[xoffset + j];
    }
  }

  for (k = 0; k < 64; k++) {
    Y[k] /= 128.0;
  }
}

/* End of code generation (Wmean.c) */
