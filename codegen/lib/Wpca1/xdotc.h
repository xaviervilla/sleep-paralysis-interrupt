/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdotc.h
 *
 * Code generation for function 'xdotc'
 *
 */

#ifndef XDOTC_H
#define XDOTC_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Wpca1_types.h"

/* Function Declarations */
extern double b_xdotc(int n, const double x[4096], int ix0, const double y[4096],
                      int iy0);
extern double c_xdotc(int n, const double x[16384], int ix0, const double y
                      [16384], int iy0);
extern double d_xdotc(int n, const emxArray_real_T *x, int ix0, const
                      emxArray_real_T *y, int iy0);
extern double e_xdotc(int n, const double x_data[], int ix0, const double
                      y_data[], int iy0);
extern double xdotc(int n, const double x[8192], int ix0, const double y[8192],
                    int iy0);

#endif

/* End of code generation (xdotc.h) */
