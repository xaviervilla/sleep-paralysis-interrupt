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
#include "CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern double b_xdotc(int n, const double x_data[], int ix0, const double
                      y_data[], int iy0);
extern double xdotc(int n, const double x[256], int ix0, const double y[256],
                    int iy0);

#endif

/* End of code generation (xdotc.h) */
