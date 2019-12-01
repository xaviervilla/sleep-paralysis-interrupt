/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Wmean.cpp
 *
 * Code generation for function 'Wmean'
 *
 */

/* Include files */
#include "Wmean.h"
#include <cstring>

/* Function Definitions */
void Wmean(const double X[2048], double Y[16])
{
  int k;
  int xoffset;
  int j;

  /*  Copyright (c) 2015, MathWorks, Inc. */
  std::memcpy(&Y[0], &X[0], 16U * sizeof(double));
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

/* End of code generation (Wmean.cpp) */
