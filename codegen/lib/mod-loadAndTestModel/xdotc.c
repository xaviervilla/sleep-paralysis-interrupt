/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdotc.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 15-Dec-2019 01:50:49
 */

/* Include Files */
#include "xdotc.h"
#include "loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double x[4]
 *                const double y[4]
 * Return Type  : double
 */
double b_xdotc(const double x[4], const double y[4])
{
  return x[0] * y[2] + x[1] * y[3];
}

/*
 * Arguments    : int n
 *                const double x[1024]
 *                int ix0
 *                const double y[1024]
 *                int iy0
 * Return Type  : double
 */
double c_xdotc(int n, const double x[1024], int ix0, const double y[1024], int
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

/*
 * Arguments    : int n
 *                const double x_data[]
 *                int ix0
 *                const double y_data[]
 *                int iy0
 * Return Type  : double
 */
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

/*
 * Arguments    : int n
 *                const double x_data[]
 *                const double y_data[]
 *                int iy0
 * Return Type  : double
 */
double e_xdotc(int n, const double x_data[], const double y_data[], int iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  d = 0.0;
  if (n >= 1) {
    ix = 0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x_data[ix] * y_data[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/*
 * Arguments    : int n
 *                const double x[64]
 *                int ix0
 *                const double y[64]
 *                int iy0
 * Return Type  : double
 */
double xdotc(int n, const double x[64], int ix0, const double y[64], int iy0)
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

/*
 * File trailer for xdotc.c
 *
 * [EOF]
 */
