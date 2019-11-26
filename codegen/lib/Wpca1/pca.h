/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pca.h
 *
 * Code generation for function 'pca'
 *
 */

#ifndef PCA_H
#define PCA_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Wpca1_types.h"

/* Function Declarations */
extern void b_localSVD(emxArray_real_T *x, int DOF, const double Weights_data[],
  const int Weights_size[1], double coeffOut_data[], int coeffOut_size[2],
  double scoreOut_data[], int scoreOut_size[2], double latentOut_data[], int
  latentOut_size[1], double tsquared_data[], int tsquared_size[2], double
  explained_data[], int explained_size[1]);
extern void localSVD(const double x[8192], int DOF, double coeffOut_data[], int
                     coeffOut_size[2], double scoreOut_data[], int
                     scoreOut_size[2], double latentOut_data[], int
                     latentOut_size[1], double tsquared[64], double
                     explained_data[], int explained_size[1]);

#endif

/* End of code generation (pca.h) */
