/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xswap.h
 *
 * Code generation for function 'xswap'
 *
 */

#ifndef XSWAP_H
#define XSWAP_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void b_xswap(double x[4]);
extern void c_xswap(double x_data[], int iy0);
extern void xswap(double x[64], int ix0, int iy0);

#endif

/* End of code generation (xswap.h) */