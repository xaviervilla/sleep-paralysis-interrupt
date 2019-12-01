/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Wstd.cpp
 *
 * Code generation for function 'Wstd'
 *
 */

/* Include files */
#include "Wstd.h"
#include <cmath>

/* Function Definitions */
void Wstd(const double X[2048], double Y[16])
{
  int j;
  int k;
  double xbar;
  double xv[128];
  double yv;
  double scale;
  double d;
  double t;

  /*  Copyright (c) 2015, MathWorks, Inc. */
  for (j = 0; j < 16; j++) {
    for (k = 0; k < 128; k++) {
      xv[k] = X[j + (k << 4)];
    }

    xbar = xv[0];
    for (k = 0; k < 127; k++) {
      xbar += xv[k + 1];
    }

    xbar /= 128.0;
    yv = 0.0;
    scale = 3.3121686421112381E-170;
    for (k = 0; k < 128; k++) {
      d = std::abs(xv[k] - xbar);
      if (d > scale) {
        t = scale / d;
        yv = yv * t * t + 1.0;
        scale = d;
      } else {
        t = d / scale;
        yv += t * t;
      }
    }

    yv = scale * std::sqrt(yv);
    Y[j] = yv / 11.269427669584644;
  }
}

/* End of code generation (Wstd.cpp) */
