/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xswap.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 19-Dec-2019 22:53:17
 */

/* Include Files */
#include "xswap.h"
#include "loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : double x[4]
 * Return Type  : void
 */
void b_xswap(double x[4])
{
  double temp;
  temp = x[0];
  x[0] = x[2];
  x[2] = temp;
  temp = x[1];
  x[1] = x[3];
  x[3] = temp;
}

/*
 * Arguments    : double x_data[]
 *                int iy0
 * Return Type  : void
 */
void c_xswap(double x_data[], int iy0)
{
  int iy;
  double temp;
  iy = iy0 - 1;
  temp = x_data[0];
  x_data[0] = x_data[iy];
  x_data[iy] = temp;
  iy++;
  temp = x_data[1];
  x_data[1] = x_data[iy];
  x_data[iy] = temp;
}

/*
 * Arguments    : double x[1024]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[1024], int ix0, int iy0)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 32; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

/*
 * File trailer for xswap.c
 *
 * [EOF]
 */
