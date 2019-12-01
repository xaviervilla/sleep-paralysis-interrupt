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
#include <string.h>

/* Function Definitions */
void Wstd(const double X[256], double Y[16])
{
  int j;
  int k;
  double xbar;
  double xv[16];
  double yv;
  double scale;
  double d;
  double t;

  /*  Copyright (c) 2015, MathWorks, Inc. */
  memset(&Y[0], 0, 16U * sizeof(double));
  for (j = 0; j < 16; j++) {
    for (k = 0; k < 16; k++) {
      xv[k] = X[j + (k << 4)];
    }

    xbar = xv[0];
    for (k = 0; k < 15; k++) {
      xbar += xv[k + 1];
    }

    xbar /= 16.0;
    yv = 0.0;
    scale = 3.3121686421112381E-170;
    for (k = 0; k < 16; k++) {
      d = fabs(xv[k] - xbar);
      if (d > scale) {
        t = scale / d;
        yv = yv * t * t + 1.0;
        scale = d;
      } else {
        t = d / scale;
        yv += t * t;
      }
    }

    yv = scale * sqrt(yv);
    Y[j] = yv / 3.872983346207417;
  }
}

/* End of code generation (Wstd.c) */
