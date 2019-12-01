/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xrot.c
 *
 * Code generation for function 'xrot'
 *
 */

/* Include files */
#include "xrot.h"
#include "CODEGEN_standalonePredictor.h"
#include "Wmean.h"
#include "Wpca1.h"
#include "Wstd.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_xrot(double x[256], int ix0, int iy0, double c, double s)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 16; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

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

void xrot(double x[16384], int ix0, int iy0, double c, double s)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 128; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

/* End of code generation (xrot.c) */
