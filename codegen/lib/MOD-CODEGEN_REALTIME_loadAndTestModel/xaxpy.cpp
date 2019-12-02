/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.c
 *
 * Code generation for function 'xaxpy'
 *
 */

/* Include files */
#include "xaxpy.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_xaxpy(int n, double a, const double x[16], int ix0, double y[2])
{
  if ((n >= 1) && (!(a == 0.0))) {
    y[1] += a * x[ix0 - 1];
  }
}

void c_xaxpy(int n, double a, const double x[2], double y[16], int iy0)
{
  int iy;
  if ((n >= 1) && (!(a == 0.0))) {
    iy = iy0 - 1;
    y[iy] += a * x[1];
  }
}

void d_xaxpy(double a, double y[4])
{
  if (!(a == 0.0)) {
    y[2] += a * y[0];
    y[3] += a * y[1];
  }
}

void e_xaxpy(int n, double a, int ix0, double y[64], int iy0)
{
  int ix;
  int iy;
  int i;
  int k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i = n - 1;
    for (k = 0; k <= i; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

void f_xaxpy(int n, double a, int ix0, double y_data[], int iy0)
{
  int ix;
  int iy;
  int i;
  int k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i = n - 1;
    for (k = 0; k <= i; k++) {
      y_data[iy] += a * y_data[ix];
      ix++;
      iy++;
    }
  }
}

void g_xaxpy(int n, double a, const double x_data[], int ix0, double y_data[])
{
  if ((n >= 1) && (!(a == 0.0))) {
    y_data[1] += a * x_data[ix0 - 1];
  }
}

void h_xaxpy(int n, double a, const double x_data[], double y_data[], int iy0)
{
  int iy;
  if ((n >= 1) && (!(a == 0.0))) {
    iy = iy0 - 1;
    y_data[iy] += a * x_data[1];
  }
}

void i_xaxpy(int n, double a, double y_data[], int iy0)
{
  int ix;
  int iy;
  int i;
  int k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = 0;
    iy = iy0 - 1;
    i = n - 1;
    for (k = 0; k <= i; k++) {
      y_data[iy] += a * y_data[ix];
      ix++;
      iy++;
    }
  }
}

void xaxpy(int n, double a, int ix0, double y[16], int iy0)
{
  int ix;
  int iy;
  int i;
  int k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i = n - 1;
    for (k = 0; k <= i; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* End of code generation (xaxpy.c) */
