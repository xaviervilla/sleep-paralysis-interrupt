/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Wpca1.c
 *
 * Code generation for function 'Wpca1'
 *
 */

/* Include files */
#include "Wpca1.h"
#include "Wpca1_data.h"
#include "Wpca1_emxutil.h"
#include "Wpca1_initialize.h"
#include "pca.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void Wpca1(const double X[8192], double Y_data[], int Y_size[2])
{
  int p;
  int irow;
  static double x[8192];
  int naninfo_nRowsWithNaNs;
  int naninfo_nNaNsInRow[64];
  int j;
  bool naninfo_isNaN[8192];
  int i;
  bool noNaNs;
  int DOF;
  double wcol;
  double xcol;
  emxArray_real_T *xNoNaNs;
  static double coeff_data[8064];
  int coeff_size[2];
  double score_data[4032];
  int score_size[2];
  double latent_data[63];
  int latent_size[1];
  double WNoNaNs_data[64];
  double explained_data[63];
  int explained_size[1];
  double mu[128];
  double d;
  static double varargout_1_data[8064];
  int WNoNaNs_size[1];
  double b_score_data[4032];
  int b_score_size[2];
  double tsquared_data[4096];
  int tsquared_size[2];
  double absc;
  if (isInitialized_Wpca1 == false) {
    Wpca1_initialize();
  }

  /*  Copyright (c) 2015, MathWorks, Inc. */
  for (p = 0; p < 8192; p++) {
    x[p] = X[p];
  }

  irow = 0;
  naninfo_nRowsWithNaNs = 0;
  memset(&naninfo_nNaNsInRow[0], 0, 64U * sizeof(int));
  for (p = 0; p < 8192; p++) {
    naninfo_isNaN[p] = rtIsNaN(X[p]);
  }

  for (j = 0; j < 128; j++) {
    for (i = 0; i < 64; i++) {
      if (naninfo_isNaN[i + (j << 6)]) {
        naninfo_nNaNsInRow[i]++;
        irow++;
      }
    }
  }

  for (i = 0; i < 64; i++) {
    if (naninfo_nNaNsInRow[i] > 0) {
      naninfo_nRowsWithNaNs++;
    }
  }

  noNaNs = (irow <= 0);
  DOF = 64 - naninfo_nRowsWithNaNs;
  if (64 - naninfo_nRowsWithNaNs >= 1) {
    DOF = 63 - naninfo_nRowsWithNaNs;
  }

  if (!noNaNs) {
    for (j = 0; j < 128; j++) {
      wcol = 0.0;
      xcol = 0.0;
      for (i = 0; i < 64; i++) {
        d = X[i + (j << 6)];
        if (!rtIsNaN(d)) {
          wcol++;
          xcol += d;
        }
      }

      mu[j] = xcol / wcol;
    }
  } else {
    for (j = 0; j < 128; j++) {
      wcol = 0.0;
      xcol = 0.0;
      for (i = 0; i < 64; i++) {
        wcol++;
        xcol += X[i + (j << 6)];
      }

      mu[j] = xcol / wcol;
    }
  }

  for (j = 0; j < 128; j++) {
    for (i = 0; i < 64; i++) {
      p = i + (j << 6);
      x[p] -= mu[j];
    }
  }

  if (noNaNs) {
    localSVD(x, DOF, coeff_data, coeff_size, score_data, score_size, latent_data,
             latent_size, WNoNaNs_data, explained_data, explained_size);
  } else {
    emxInit_real_T(&xNoNaNs, 2);
    p = xNoNaNs->size[0] * xNoNaNs->size[1];
    xNoNaNs->size[0] = 64 - naninfo_nRowsWithNaNs;
    xNoNaNs->size[1] = 128;
    emxEnsureCapacity_real_T(xNoNaNs, p);
    WNoNaNs_size[0] = 64 - naninfo_nRowsWithNaNs;
    irow = -1;
    for (i = 0; i < 64; i++) {
      if (naninfo_nNaNsInRow[i] == 0) {
        irow++;
        for (j = 0; j < 128; j++) {
          xNoNaNs->data[irow + xNoNaNs->size[0] * j] = x[i + (j << 6)];
        }

        WNoNaNs_data[irow] = 1.0;
      }
    }

    b_localSVD(xNoNaNs, DOF, WNoNaNs_data, WNoNaNs_size, coeff_data, coeff_size,
               b_score_data, b_score_size, latent_data, latent_size,
               tsquared_data, tsquared_size, explained_data, explained_size);
    p = b_score_size[1] - 1;
    irow = -1;
    emxFree_real_T(&xNoNaNs);
    for (i = 0; i < 64; i++) {
      if (naninfo_nNaNsInRow[i] > 0) {
        for (j = 0; j <= p; j++) {
          tsquared_data[i + 64 * j] = rtNaN;
        }
      } else {
        irow++;
        for (j = 0; j <= p; j++) {
          tsquared_data[i + 64 * j] = b_score_data[irow + b_score_size[0] * j];
        }
      }
    }

    score_size[0] = 64;
    score_size[1] = b_score_size[1];
    p = 64 * b_score_size[1];
    if (0 <= p - 1) {
      memcpy(&score_data[0], &tsquared_data[0], p * sizeof(double));
    }
  }

  if (1 < DOF) {
    irow = 1;
    memcpy(&varargout_1_data[0], &coeff_data[0], 128U * sizeof(double));
    Y_size[0] = 64;
    Y_size[1] = 1;
    memcpy(&Y_data[0], &score_data[0], 64U * sizeof(double));
  } else {
    irow = coeff_size[1];
    p = coeff_size[0] * coeff_size[1];
    if (0 <= p - 1) {
      memcpy(&varargout_1_data[0], &coeff_data[0], p * sizeof(double));
    }

    Y_size[0] = 64;
    Y_size[1] = score_size[1];
    p = score_size[0] * score_size[1];
    if (0 <= p - 1) {
      memcpy(&Y_data[0], &score_data[0], p * sizeof(double));
    }
  }

  for (j = 0; j < irow; j++) {
    wcol = 0.0;
    xcol = 1.0;
    for (i = 0; i < 128; i++) {
      d = varargout_1_data[i + 128 * j];
      absc = fabs(d);
      if (absc > wcol) {
        wcol = absc;
        xcol = d;
        if (d < 0.0) {
          xcol = -1.0;
        } else if (d > 0.0) {
          xcol = 1.0;
        } else {
          if (d == 0.0) {
            xcol = 0.0;
          }
        }
      }
    }

    if (xcol < 0.0) {
      for (i = 0; i < 128; i++) {
        p = i + 128 * j;
        varargout_1_data[p] = -varargout_1_data[p];
      }

      for (i = 0; i < 64; i++) {
        p = i + 64 * j;
        Y_data[p] = -Y_data[p];
      }
    }
  }
}

/* End of code generation (Wpca1.c) */
