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
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern double b_xdotc(const double x[4], const double y[4]);
extern double c_xdotc(int n, const double x[64], int ix0, const double y[64],
                      int iy0);
extern double d_xdotc(int n, const double x_data[], int ix0, const double
                      y_data[], int iy0);
extern double e_xdotc(int n, const double x_data[], const double y_data[], int
                      iy0);
extern double xdotc(int n, const double x[16], int ix0, const double y[16], int
                    iy0);

#endif

/* End of code generation (xdotc.h) */
