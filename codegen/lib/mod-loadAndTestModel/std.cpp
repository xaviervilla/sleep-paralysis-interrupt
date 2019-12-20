/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: std.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 20-Dec-2019 12:06:10
 */

/* Include Files */
#include "std.h"
#include "loadAndTestModel.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : const double x[64]
 * Return Type  : double
 */
double b_std(const double x[64])
{
  double y;
  double xbar;
  int k;
  double scale;
  double d;
  double t;
  xbar = x[0];
  for (k = 0; k < 63; k++) {
    xbar += x[k + 1];
  }

  xbar /= 64.0;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 64; k++) {
    d = fabs(x[k] - xbar);
    if (d > scale) {
      t = scale / d;
      y = y * t * t + 1.0;
      scale = d;
    } else {
      t = d / scale;
      y += t * t;
    }
  }

  y = scale * sqrt(y);
  y /= 7.9372539331937721;
  return y;
}

/*
 * File trailer for std.c
 *
 * [EOF]
 */
