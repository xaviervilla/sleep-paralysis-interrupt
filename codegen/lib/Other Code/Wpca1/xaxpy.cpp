/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.cpp
 *
 * Code generation for function 'xaxpy'
 *
 */

/* Include files */
#include "xaxpy.h"
#include "Wpca1.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_xaxpy(int n, double a, const double x[2048], int ix0, double y[16], int
             iy0)
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
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

void c_xaxpy(int n, double a, const double x[16], int ix0, double y[2048], int
             iy0)
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
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

void d_xaxpy(int n, double a, int ix0, double y[256], int iy0)
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

void e_xaxpy(int n, double a, int ix0, double y[16384], int iy0)
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

void g_xaxpy(int n, double a, const double x_data[], int ix0, double y_data[],
             int iy0)
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
      y_data[iy] += a * x_data[ix];
      ix++;
      iy++;
    }
  }
}

void xaxpy(int n, double a, int ix0, double y[2048], int iy0)
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

/* End of code generation (xaxpy.cpp) */
