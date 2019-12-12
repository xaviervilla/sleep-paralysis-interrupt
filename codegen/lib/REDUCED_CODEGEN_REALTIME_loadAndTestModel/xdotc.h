/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdotc.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 11-Dec-2019 20:06:08
 */

#ifndef XDOTC_H
#define XDOTC_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern double b_xdotc(int n, const double x[16], int ix0, const double y[16],
                      int iy0);
extern double c_xdotc(int n, const double x[1024], int ix0, const double y[1024],
                      int iy0);
extern double d_xdotc(int n, const double x_data[], int ix0, const double
                      y_data[], int iy0);
extern double xdotc(int n, const double x[128], int ix0, const double y[128],
                    int iy0);

#endif

/*
 * File trailer for xdotc.h
 *
 * [EOF]
 */
