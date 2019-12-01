/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.h
 *
 * Code generation for function 'xaxpy'
 *
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "Wpca1_types.h"

/* Function Declarations */
extern void b_xaxpy(int n, double a, const double x[2048], int ix0, double y[16],
                    int iy0);
extern void c_xaxpy(int n, double a, const double x[16], int ix0, double y[2048],
                    int iy0);
extern void d_xaxpy(int n, double a, int ix0, double y[256], int iy0);
extern void e_xaxpy(int n, double a, int ix0, double y[16384], int iy0);
extern void f_xaxpy(int n, double a, int ix0, double y_data[], int iy0);
extern void g_xaxpy(int n, double a, const double x_data[], int ix0, double
                    y_data[], int iy0);
extern void xaxpy(int n, double a, int ix0, double y[2048], int iy0);

#endif

/* End of code generation (xaxpy.h) */
