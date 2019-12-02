/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * std.c
 *
 * Code generation for function 'std'
 *
 */

/* Include files */
#include "std.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
void b_std(const double x[16], double y[2])
{
  int j;
  int k;
  double xbar;
  double xv[8];
  double yv;
  double scale;
  double d;
  double t;
  y[0] = 0.0;
  y[1] = 0.0;
  for (j = 0; j < 2; j++) {
    for (k = 0; k < 8; k++) {
      xv[k] = x[j + (k << 1)];
    }

    xbar = xv[0];
    for (k = 0; k < 7; k++) {
      xbar += xv[k + 1];
    }

    xbar /= 8.0;
    yv = 0.0;
    scale = 3.3121686421112381E-170;
    for (k = 0; k < 8; k++) {
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
    y[j] = yv / 2.8284271247461903;
  }
}

/* End of code generation (std.c) */
