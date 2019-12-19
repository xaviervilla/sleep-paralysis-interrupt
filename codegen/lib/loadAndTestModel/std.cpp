/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: std.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 15-Dec-2019 01:50:49
 */

/* Include Files */
#include "std.h"
#include "loadAndTestModel.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : const double x[64]
 *                double y[2]
 * Return Type  : void
 */
void b_std(const double x[64], double y[2])
{
  int j;
  int k;
  double xbar;
  double xv[32];
  double yv;
  double scale;
  double d;
  double t;
  y[0] = 0.0;
  y[1] = 0.0;
  for (j = 0; j < 2; j++) {
    for (k = 0; k < 32; k++) {
      xv[k] = x[j + (k << 1)];
    }

    xbar = xv[0];
    for (k = 0; k < 31; k++) {
      xbar += xv[k + 1];
    }

    xbar /= 32.0;
    yv = 0.0;
    scale = 3.3121686421112381E-170;
    for (k = 0; k < 32; k++) {
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
    y[j] = yv / 5.6568542494923806;
  }
}

/*
 * File trailer for std.c
 *
 * [EOF]
 */