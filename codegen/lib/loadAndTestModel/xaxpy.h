/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 19-Dec-2019 22:53:17
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "loadAndTestModel_types.h"

/* Function Declarations */
extern void b_xaxpy(int n, double a, const double x[64], int ix0, double y[2]);
extern void c_xaxpy(int n, double a, const double x[2], double y[64], int iy0);
extern void d_xaxpy(double a, double y[4]);
extern void e_xaxpy(int n, double a, int ix0, double y[1024], int iy0);
extern void f_xaxpy(int n, double a, int ix0, double y_data[], int iy0);
extern void g_xaxpy(int n, double a, const double x_data[], int ix0, double
                    y_data[]);
extern void h_xaxpy(int n, double a, const double x_data[], double y_data[], int
                    iy0);
extern void i_xaxpy(int n, double a, double y_data[], int iy0);
extern void xaxpy(int n, double a, int ix0, double y[64], int iy0);

#endif

/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
