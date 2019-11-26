/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzsvdc.h
 *
 * Code generation for function 'xzsvdc'
 *
 */

#ifndef XZSVDC_H
#define XZSVDC_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Wpca1_types.h"

/* Function Declarations */
extern void b_xzsvdc(emxArray_real_T *A, double U_data[], int U_size[2], double
                     S_data[], int S_size[1], emxArray_real_T *V);
extern void xzsvdc(double A[8192], double U[4096], double S[64], double V[8192]);

#endif

/* End of code generation (xzsvdc.h) */
