/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xswap.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 09-Dec-2019 01:55:25
 */

#ifndef XSWAP_H
#define XSWAP_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void b_xswap(double x[16], int ix0, int iy0);
extern void c_xswap(int n, double x_data[], int ix0, int iy0);
extern void xswap(double x[1024], int ix0, int iy0);

#endif

/*
 * File trailer for xswap.h
 *
 * [EOF]
 */
