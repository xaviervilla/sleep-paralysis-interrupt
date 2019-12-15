/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xrot.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 15-Dec-2019 01:21:20
 */

/* Include Files */
#include "xrot.h"
#include "loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : double x[4]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void b_xrot(double x[4], int ix0, int iy0, double c, double s)
{
  int ix;
  int iy;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
  iy++;
  ix++;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
}

/*
 * Arguments    : int n
 *                double x_data[]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void c_xrot(int n, double x_data[], int ix0, int iy0, double c, double s)
{
  int ix;
  int iy;
  int k;
  double temp;
  if (n >= 1) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      temp = c * x_data[ix] + s * x_data[iy];
      x_data[iy] = c * x_data[iy] - s * x_data[ix];
      x_data[ix] = temp;
      iy++;
      ix++;
    }
  }
}

/*
 * Arguments    : double x[1024]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void xrot(double x[1024], int ix0, int iy0, double c, double s)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 32; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

/*
 * File trailer for xrot.c
 *
 * [EOF]
 */
