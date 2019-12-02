/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xrot.h
 *
 * Code generation for function 'xrot'
 *
 */

#ifndef XROT_H
#define XROT_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void b_xrot(double x[4], int ix0, int iy0, double c, double s);
extern void c_xrot(int n, double x_data[], int ix0, int iy0, double c, double s);
extern void xrot(double x[64], int ix0, int iy0, double c, double s);

#endif

/* End of code generation (xrot.h) */