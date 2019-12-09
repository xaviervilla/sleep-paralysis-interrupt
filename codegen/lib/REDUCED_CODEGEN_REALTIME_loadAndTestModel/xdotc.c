/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdotc.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 09-Dec-2019 01:55:25
 */

/* Include Files */
#include "xdotc.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                const double x[16]
 *                int ix0
 *                const double y[16]
 *                int iy0
 * Return Type  : double
 */
double b_xdotc(int n, const double x[16], int ix0, const double y[16], int iy0)
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
 *                const double x[128]
 *                int ix0
 *                const double y[128]
 *                int iy0
 * Return Type  : double
 */
double xdotc(int n, const double x[128], int ix0, const double y[128], int iy0)
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
