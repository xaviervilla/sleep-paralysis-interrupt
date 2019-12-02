/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Wstd.c
 *
 * Code generation for function 'Wstd'
 *
 */

/* Include files */
#include "Wstd.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double Wstd(const double X[8])
{
  double Y;
  double xbar;
  int k;
  double scale;
  double d;
  double t;

  /*  Copyright (c) 2015, MathWorks, Inc. */
  xbar = X[0];
  for (k = 0; k < 7; k++) {
    xbar += X[k + 1];
  }

  xbar /= 8.0;
  Y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 8; k++) {
    d = fabs(X[k] - xbar);
    if (d > scale) {
      t = scale / d;
      Y = Y * t * t + 1.0;
      scale = d;
    } else {
      t = d / scale;
      Y += t * t;
    }
  }

  Y = scale * sqrt(Y);
  Y /= 2.6457513110645907;
  return Y;
}

/* End of code generation (Wstd.c) */
