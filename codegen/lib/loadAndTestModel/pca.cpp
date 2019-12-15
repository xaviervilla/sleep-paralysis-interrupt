/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pca.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 15-Dec-2019 01:50:49
 */

/* Include Files */
#include "pca.h"
#include "loadAndTestModel.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double x[64]
 *                double varargout_1_data[]
 *                int varargout_1_size[2]
 *                double varargout_2_data[]
 *                int varargout_2_size[2]
 * Return Type  : void
 */
void pca(const double x[64], double varargout_1_data[], int varargout_1_size[2],
         double varargout_2_data[], int varargout_2_size[2])
{
  int wcol;
  int irow;
  int naninfo_nNaNsInRow[2];
  int minDOFnsv;
  int j;
  double b_x[64];
  bool naninfo_isNaN[64];
  bool noNaNs;
  int DOF;
  double mu[32];
  double xcol;
  double score_data[4];
  double latent_data[2];
  double coeff_data[64];
  double sgn;
  int i;
  int x_size[2];
  double x_data[64];
  int score_size[2];
  int latent_size[1];
  int coeff_size[2];
  double b_score_data[2];
  double absc;
  wcol = 0;
  irow = 0;
  naninfo_nNaNsInRow[0] = 0;
  naninfo_nNaNsInRow[1] = 0;
  for (minDOFnsv = 0; minDOFnsv < 64; minDOFnsv++) {
    b_x[minDOFnsv] = x[minDOFnsv];
    naninfo_isNaN[minDOFnsv] = rtIsNaN(x[minDOFnsv]);
  }

  for (j = 0; j < 32; j++) {
    minDOFnsv = j << 1;
    if (naninfo_isNaN[minDOFnsv]) {
      naninfo_nNaNsInRow[0]++;
      wcol++;
    }

    if (naninfo_isNaN[minDOFnsv + 1]) {
      naninfo_nNaNsInRow[1]++;
      wcol++;
    }
  }

  if (naninfo_nNaNsInRow[0] > 0) {
    irow = 1;
  }

  if (naninfo_nNaNsInRow[1] > 0) {
    irow++;
  }

  noNaNs = (wcol <= 0);
  DOF = 2 - irow;
  if (2 - irow >= 1) {
    DOF = 1 - irow;
  }

  if (!noNaNs) {
    for (j = 0; j < 32; j++) {
      wcol = 0;
      xcol = 0.0;
      minDOFnsv = j << 1;
      if (!rtIsNaN(x[minDOFnsv])) {
        wcol = 1;
        xcol = x[minDOFnsv];
      }

      sgn = x[minDOFnsv + 1];
      if (!rtIsNaN(sgn)) {
        wcol++;
        xcol += sgn;
      }

      mu[j] = xcol / (double)wcol;
    }
  } else {
    for (j = 0; j < 32; j++) {
      wcol = j << 1;
      mu[j] = (x[wcol] + x[wcol + 1]) / 2.0;
    }
  }

  for (j = 0; j < 32; j++) {
    wcol = j << 1;
    b_x[wcol] -= mu[j];
    wcol++;
    b_x[wcol] -= mu[j];
  }

  if (noNaNs) {
    xzsvdc(b_x, score_data, latent_data, coeff_data);
    score_data[0] *= latent_data[0];
    score_data[1] *= latent_data[0];
    varargout_2_size[0] = 2;
    varargout_2_size[1] = DOF;
    if (0 <= DOF - 1) {
      varargout_2_data[0] = score_data[0];
      varargout_2_data[1] = score_data[1];
    }

    varargout_1_size[0] = 32;
    varargout_1_size[1] = DOF;
    if (0 <= DOF - 1) {
      memcpy(&varargout_1_data[0], &coeff_data[0], 32U * sizeof(double));
    }
  } else {
    minDOFnsv = 2 - irow;
    irow = -1;
    for (i = 0; i < 2; i++) {
      if (naninfo_nNaNsInRow[i] == 0) {
        irow++;
        for (j = 0; j < 32; j++) {
          coeff_data[irow + minDOFnsv * j] = b_x[i + (j << 1)];
        }
      }
    }

    x_size[0] = minDOFnsv;
    x_size[1] = 32;
    wcol = minDOFnsv * 32;
    if (0 <= wcol - 1) {
      memcpy(&x_data[0], &coeff_data[0], wcol * sizeof(double));
    }

    irow = minDOFnsv - 1;
    b_xzsvdc(x_data, x_size, score_data, score_size, latent_data, latent_size,
             coeff_data, coeff_size);
    wcol = score_size[1];
    for (j = 0; j < wcol; j++) {
      for (i = 0; i <= irow; i++) {
        minDOFnsv = i + score_size[0] * j;
        score_data[minDOFnsv] *= latent_data[j];
      }
    }

    minDOFnsv = score_size[1];
    if (DOF < minDOFnsv) {
      minDOFnsv = DOF;
    }

    if ((0 <= minDOFnsv - 1) && (0 <= irow)) {
      memcpy(&b_score_data[0], &score_data[0], (irow + 1) * sizeof(double));
    }

    varargout_1_size[0] = 32;
    varargout_1_size[1] = minDOFnsv;
    if (0 <= minDOFnsv - 1) {
      memcpy(&varargout_1_data[0], &coeff_data[0], 32U * sizeof(double));
    }

    wcol = minDOFnsv - 1;
    irow = -1;
    if (naninfo_nNaNsInRow[0] > 0) {
      if (0 <= wcol) {
        score_data[0] = rtNaN;
      }
    } else {
      irow = 0;
      if (0 <= wcol) {
        score_data[0] = b_score_data[0];
      }
    }

    if (naninfo_nNaNsInRow[1] > 0) {
      if (0 <= wcol) {
        score_data[1] = rtNaN;
      }
    } else {
      irow++;
      if (0 <= wcol) {
        score_data[1] = b_score_data[irow];
      }
    }

    varargout_2_size[0] = 2;
    varargout_2_size[1] = minDOFnsv;
    wcol = 2 * minDOFnsv;
    if (0 <= wcol - 1) {
      memcpy(&varargout_2_data[0], &score_data[0], wcol * sizeof(double));
    }
  }

  wcol = varargout_1_size[1];
  for (j = 0; j < wcol; j++) {
    xcol = 0.0;
    sgn = 1.0;
    for (i = 0; i < 32; i++) {
      absc = fabs(varargout_1_data[i]);
      if (absc > xcol) {
        xcol = absc;
        sgn = varargout_1_data[i];
        if (varargout_1_data[i] < 0.0) {
          sgn = -1.0;
        } else if (varargout_1_data[i] > 0.0) {
          sgn = 1.0;
        } else {
          if (varargout_1_data[i] == 0.0) {
            sgn = 0.0;
          }
        }
      }
    }

    if (sgn < 0.0) {
      for (i = 0; i < 32; i++) {
        varargout_1_data[i] = -varargout_1_data[i];
      }

      varargout_2_data[0] = -varargout_2_data[0];
      varargout_2_data[1] = -varargout_2_data[1];
    }
  }
}

/*
 * File trailer for pca.c
 *
 * [EOF]
 */
