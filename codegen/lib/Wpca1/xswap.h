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
#include "Wpca1_types.h"

/* Function Declarations */
extern void b_xswap(double x[4096], int ix0, int iy0);
extern void c_xswap(int n, double x_data[], int ix0, int iy0);
extern void xswap(double x[16384], int ix0, int iy0);

#endif

/* End of code generation (xswap.h) */
