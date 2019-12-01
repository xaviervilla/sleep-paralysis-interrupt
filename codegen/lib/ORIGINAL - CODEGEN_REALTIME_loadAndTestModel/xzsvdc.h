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
#include "CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void b_xzsvdc(double A_data[], const int A_size[2], double U_data[], int
                     U_size[2], double S_data[], int S_size[1], double V_data[],
                     int V_size[2]);
extern void xzsvdc(double A[256], double U[256], double S[16], double V[256]);

#endif

/* End of code generation (xzsvdc.h) */
