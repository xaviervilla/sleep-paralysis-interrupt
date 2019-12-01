/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdotc.cpp
 *
 * Code generation for function 'xdotc'
 *
 */

/* Include files */
#include "xdotc.h"
#include "Wpca1.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double b_xdotc(int n, const double x[256], int ix0, const double y[256], int iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  ix = ix0;
  iy = iy0;
  d = 0.0;
  for (k = 0; k < n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

double c_xdotc(int n, const double x[16384], int ix0, const double y[16384], int
               iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  ix = ix0;
  iy = iy0;
  d = 0.0;
  for (k = 0; k < n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

double d_xdotc(int n, const double x_data[], int ix0, const double y_data[], int
               iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x_data[ix - 1] * y_data[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

double xdotc(int n, const double x[2048], int ix0, const double y[2048], int iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  ix = ix0;
  iy = iy0;
  d = 0.0;
  for (k = 0; k < n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

/* End of code generation (xdotc.cpp) */
