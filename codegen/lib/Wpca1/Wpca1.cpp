/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Wpca1.cpp
 *
 * Code generation for function 'Wpca1'
 *
 */

/* Include files */
#include "Wpca1.h"
#include "Wpca1_data.h"
#include "Wpca1_initialize.h"
#include "pca.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

/* Function Definitions */
void Wpca1(const double X[2048], double Y_data[], int Y_size[2])
{
  double x[2048];
  int irow;
  int naninfo_nRowsWithNaNs;
  int i;
  int p;
  int naninfo_nNaNsInRow[16];
  int j;
  bool naninfo_isNaN[2048];
  bool noNaNs;
  int DOF;
  double wcol;
  double xcol;
  int xNoNaNs_size[2];
  double coeff_data[1920];
  int coeff_size[2];
  double score_data[240];
  int score_size[2];
  double latent_data[15];
  int latent_size[1];
  double WNoNaNs_data[16];
  double explained_data[15];
  int explained_size[1];
  double mu[128];
  double d;
  int WNoNaNs_size[1];
  double varargout_1_data[1920];
  double xNoNaNs_data[2048];
  double b_score_data[240];
  int b_score_size[2];
  double tsquared_data[256];
  int tsquared_size[2];
  double absc;
  if (isInitialized_Wpca1 == false) {
    Wpca1_initialize();
  }

  /*  Copyright (c) 2015, MathWorks, Inc. */
  std::memcpy(&x[0], &X[0], 2048U * sizeof(double));
  irow = 0;
  naninfo_nRowsWithNaNs = 0;
  for (i = 0; i < 16; i++) {
    naninfo_nNaNsInRow[i] = 0;
  }

  for (p = 0; p < 2048; p++) {
    naninfo_isNaN[p] = rtIsNaN(X[p]);
  }

  for (j = 0; j < 128; j++) {
    for (i = 0; i < 16; i++) {
      if (naninfo_isNaN[i + (j << 4)]) {
        naninfo_nNaNsInRow[i]++;
        irow++;
      }
    }
  }

  for (i = 0; i < 16; i++) {
    if (naninfo_nNaNsInRow[i] > 0) {
      naninfo_nRowsWithNaNs++;
    }
  }

  noNaNs = (irow <= 0);
  DOF = 16 - naninfo_nRowsWithNaNs;
  if (16 - naninfo_nRowsWithNaNs >= 1) {
    DOF = 15 - naninfo_nRowsWithNaNs;
  }

  if (!noNaNs) {
    for (j = 0; j < 128; j++) {
      wcol = 0.0;
      xcol = 0.0;
      for (i = 0; i < 16; i++) {
        d = X[i + (j << 4)];
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
      for (i = 0; i < 16; i++) {
        wcol++;
        xcol += X[i + (j << 4)];
      }

      mu[j] = xcol / wcol;
    }
  }

  for (j = 0; j < 128; j++) {
    for (i = 0; i < 16; i++) {
      p = i + (j << 4);
      x[p] -= mu[j];
    }
  }

  if (noNaNs) {
    localSVD(x, DOF, coeff_data, coeff_size, score_data, score_size, latent_data,
             latent_size, WNoNaNs_data, explained_data, explained_size);
  } else {
    xNoNaNs_size[0] = 16 - naninfo_nRowsWithNaNs;
    xNoNaNs_size[1] = 128;
    WNoNaNs_size[0] = 16 - naninfo_nRowsWithNaNs;
    irow = -1;
    for (i = 0; i < 16; i++) {
      if (naninfo_nNaNsInRow[i] == 0) {
        irow++;
        for (j = 0; j < 128; j++) {
          xNoNaNs_data[irow + xNoNaNs_size[0] * j] = x[i + (j << 4)];
        }

        WNoNaNs_data[irow] = 1.0;
      }
    }

    b_localSVD(xNoNaNs_data, xNoNaNs_size, DOF, WNoNaNs_data, WNoNaNs_size,
               coeff_data, coeff_size, b_score_data, b_score_size, latent_data,
               latent_size, tsquared_data, tsquared_size, explained_data,
               explained_size);
    p = b_score_size[1] - 1;
    irow = -1;
    for (i = 0; i < 16; i++) {
      if (naninfo_nNaNsInRow[i] > 0) {
        for (j = 0; j <= p; j++) {
          tsquared_data[i + 16 * j] = rtNaN;
        }
      } else {
        irow++;
        for (j = 0; j <= p; j++) {
          tsquared_data[i + 16 * j] = b_score_data[irow + b_score_size[0] * j];
        }
      }
    }

    score_size[0] = 16;
    score_size[1] = b_score_size[1];
    p = 16 * b_score_size[1];
    if (0 <= p - 1) {
      std::memcpy(&score_data[0], &tsquared_data[0], p * sizeof(double));
    }
  }

  if (1 < DOF) {
    irow = 1;
    std::memcpy(&varargout_1_data[0], &coeff_data[0], 128U * sizeof(double));
    Y_size[0] = 16;
    Y_size[1] = 1;
    std::memcpy(&Y_data[0], &score_data[0], 16U * sizeof(double));
  } else {
    irow = coeff_size[1];
    p = coeff_size[0] * coeff_size[1];
    if (0 <= p - 1) {
      std::memcpy(&varargout_1_data[0], &coeff_data[0], p * sizeof(double));
    }

    Y_size[0] = 16;
    Y_size[1] = score_size[1];
    p = score_size[0] * score_size[1];
    if (0 <= p - 1) {
      std::memcpy(&Y_data[0], &score_data[0], p * sizeof(double));
    }
  }

  for (j = 0; j < irow; j++) {
    wcol = 0.0;
    xcol = 1.0;
    for (i = 0; i < 128; i++) {
      d = varargout_1_data[i + 128 * j];
      absc = std::abs(d);
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

      for (i = 0; i < 16; i++) {
        p = i + 16 * j;
        Y_data[p] = -Y_data[p];
      }
    }
  }
}

/* End of code generation (Wpca1.cpp) */
