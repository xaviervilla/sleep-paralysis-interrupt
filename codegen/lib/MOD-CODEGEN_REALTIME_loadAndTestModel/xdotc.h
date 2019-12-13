/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdotc.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 12-Dec-2019 18:03:22
 */

#ifndef XDOTC_H
#define XDOTC_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern double b_xdotc(const double x[4], const double y[4]);
extern double c_xdotc(int n, const double x[1024], int ix0, const double y[1024],
                      int iy0);
extern double d_xdotc(int n, const double x_data[], int ix0, const double
                      y_data[], int iy0);
extern double e_xdotc(int n, const double x_data[], const double y_data[], int
                      iy0);
extern double xdotc(int n, const double x[64], int ix0, const double y[64], int
                    iy0);

#endif

/*
 * File trailer for xdotc.h
 *
 * [EOF]
 */
