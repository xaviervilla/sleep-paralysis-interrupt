/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xrot.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 11-Dec-2019 20:06:08
 */

#ifndef XROT_H
#define XROT_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void b_xrot(double x[16], int ix0, int iy0, double c, double s);
extern void c_xrot(int n, double x_data[], int ix0, int iy0, double c, double s);
extern void xrot(double x[1024], int ix0, int iy0, double c, double s);

#endif

/*
 * File trailer for xrot.h
 *
 * [EOF]
 */
