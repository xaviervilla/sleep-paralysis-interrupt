/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 09-Dec-2019 01:55:25
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void b_xaxpy(int n, double a, const double x[128], int ix0, double y[4],
                    int iy0);
extern void c_xaxpy(int n, double a, const double x[4], int ix0, double y[128],
                    int iy0);
extern void d_xaxpy(int n, double a, int ix0, double y[16], int iy0);
extern void e_xaxpy(int n, double a, int ix0, double y[1024], int iy0);
extern void f_xaxpy(int n, double a, int ix0, double y_data[], int iy0);
extern void g_xaxpy(int n, double a, const double x_data[], int ix0, double
                    y_data[], int iy0);
extern void xaxpy(int n, double a, int ix0, double y[128], int iy0);

#endif

/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
