/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzsvdc.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 20-Dec-2019 14:56:44
 */

#ifndef XZSVDC_H
#define XZSVDC_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "loadAndTestModel_types.h"

/* Function Declarations */
extern void b_xzsvdc(double A_data[], const int A_size[2], double U_data[], int
                     U_size[2], double S_data[], int S_size[1], double V_data[],
                     int V_size[2]);
extern void xzsvdc(double A[64], double U[4], double S[2], double V[64]);

#endif

/*
 * File trailer for xzsvdc.h
 *
 * [EOF]
 */
