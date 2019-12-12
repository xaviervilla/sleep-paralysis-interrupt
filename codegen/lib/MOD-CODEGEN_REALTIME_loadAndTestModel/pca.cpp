/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pca.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 11-Dec-2019 20:06:08
 */

/* Include Files */
#include "pca.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void b_localSVD(double x_data[], const int x_size[2], int DOF, const
  double Weights_data[], const int Weights_size[1], double coeffOut_data[], int
  coeffOut_size[2], double scoreOut_data[], int scoreOut_size[2], double
  latentOut_data[], int latentOut_size[1], double tsquared_data[], int
  tsquared_size[2], double explained_data[], int explained_size[1]);
static void localSVD(const double x[128], int DOF, double coeffOut_data[], int
                     coeffOut_size[2], double scoreOut_data[], int
                     scoreOut_size[2], double latentOut_data[], int
                     latentOut_size[1], double tsquared[4], double
                     explained_data[], int explained_size[1]);

/* Function Definitions */

/*
 * Arguments    : double x_data[]
 *                const int x_size[2]
 *                int DOF
 *                const double Weights_data[]
 *                const int Weights_size[1]
 *                double coeffOut_data[]
 *                int coeffOut_size[2]
 *                double scoreOut_data[]
 *                int scoreOut_size[2]
 *                double latentOut_data[]
 *                int latentOut_size[1]
 *                double tsquared_data[]
 *                int tsquared_size[2]
 *                double explained_data[]
 *                int explained_size[1]
 * Return Type  : void
 */
static void b_localSVD(double x_data[], const int x_size[2], int DOF, const
  double Weights_data[], const int Weights_size[1], double coeffOut_data[], int
  coeffOut_size[2], double scoreOut_data[], int scoreOut_size[2], double
  latentOut_data[], int latentOut_size[1], double tsquared_data[], int
  tsquared_size[2], double explained_data[], int explained_size[1])
{
  int nx;
  double OmegaSqrt_data[4];
  int k;
  int nrows;
  int b_x_size[2];
  int i;
  double b_x_data[128];
  double score_data[16];
  int score_size[2];
  double latent_data[4];
  int latent_size[1];
  double coeff_data[128];
  int coeff_size[2];
  int q;
  double absx;
  int m;
  double d;
  nx = Weights_size[0];
  if (0 <= nx - 1) {
    memcpy(&OmegaSqrt_data[0], &Weights_data[0], nx * sizeof(double));
  }

  nx = Weights_size[0];
  for (k = 0; k < nx; k++) {
    OmegaSqrt_data[k] = sqrt(OmegaSqrt_data[k]);
  }

  nrows = x_size[0] - 1;
  for (k = 0; k < 32; k++) {
    for (i = 0; i <= nrows; i++) {
      nx = i + x_size[0] * k;
      x_data[nx] *= OmegaSqrt_data[i];
    }
  }

  b_x_size[0] = x_size[0];
  b_x_size[1] = 32;
  nx = x_size[0] * x_size[1] - 1;
  if (0 <= nx) {
    memcpy(&b_x_data[0], &x_data[0], (nx + 1) * sizeof(double));
  }

  b_xzsvdc(b_x_data, b_x_size, score_data, score_size, latent_data, latent_size,
           coeff_data, coeff_size);
  nx = score_size[1];
  for (k = 0; k < nx; k++) {
    for (i = 0; i <= nrows; i++) {
      m = i + score_size[0] * k;
      score_data[m] = score_data[m] / OmegaSqrt_data[i] * latent_data[k];
    }

    latent_data[k] = latent_data[k] * latent_data[k] / (double)DOF;
  }

  if ((score_size[0] == 0) || (score_size[1] == 0)) {
    tsquared_size[0] = score_size[0];
    tsquared_size[1] = score_size[1];
    nx = score_size[0] * score_size[1];
    if (0 <= nx - 1) {
      memcpy(&tsquared_data[0], &score_data[0], nx * sizeof(double));
    }
  } else {
    if (DOF > 1) {
      absx = fabs(latent_data[0]);
      if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
        if (absx <= 2.2250738585072014E-308) {
          absx = 4.94065645841247E-324;
        } else {
          frexp(absx, &q);
          absx = ldexp(1.0, q - 53);
        }
      } else {
        absx = rtNaN;
      }

      absx *= 32.0;
      q = 0;
      nx = latent_size[0];
      for (k = 0; k < nx; k++) {
        if (latent_data[k] > absx) {
          q++;
        }
      }
    } else {
      q = 0;
    }

    m = score_size[0];
    tsquared_size[0] = score_size[0];
    tsquared_size[1] = 1;
    nx = score_size[0];
    if (0 <= nx - 1) {
      memset(&tsquared_data[0], 0, nx * sizeof(double));
    }

    for (k = 0; k < q; k++) {
      absx = sqrt(latent_data[k]);
      for (i = 0; i < m; i++) {
        d = score_data[i + score_size[0] * k] / absx;
        tsquared_data[i] += d * d;
      }
    }
  }

  m = score_size[1];
  if (DOF < m) {
    m = DOF;
  }

  scoreOut_size[0] = nrows + 1;
  scoreOut_size[1] = m;
  latentOut_size[0] = m;
  coeffOut_size[0] = 32;
  coeffOut_size[1] = m;
  for (k = 0; k < m; k++) {
    for (i = 0; i <= nrows; i++) {
      scoreOut_data[i + scoreOut_size[0] * k] = score_data[i + score_size[0] * k];
    }

    latentOut_data[k] = latent_data[k];
    memcpy(&coeffOut_data[k * 32], &coeff_data[k * 32], 32U * sizeof(double));
  }

  if (m == 0) {
    absx = 0.0;
  } else {
    absx = latentOut_data[0];
    for (k = 2; k <= m; k++) {
      absx += latentOut_data[k - 1];
    }
  }

  explained_size[0] = m;
  for (nx = 0; nx < m; nx++) {
    explained_data[nx] = 100.0 * latentOut_data[nx] / absx;
  }
}

/*
 * Arguments    : const double x[128]
 *                int DOF
 *                double coeffOut_data[]
 *                int coeffOut_size[2]
 *                double scoreOut_data[]
 *                int scoreOut_size[2]
 *                double latentOut_data[]
 *                int latentOut_size[1]
 *                double tsquared[4]
 *                double explained_data[]
 *                int explained_size[1]
 * Return Type  : void
 */
static void localSVD(const double x[128], int DOF, double coeffOut_data[], int
                     coeffOut_size[2], double scoreOut_data[], int
                     scoreOut_size[2], double latentOut_data[], int
                     latentOut_size[1], double tsquared[4], double
                     explained_data[], int explained_size[1])
{
  double b_x[128];
  double score[16];
  double latent[4];
  double coeff[128];
  int j;
  int q;
  int score_tmp;
  double absx;
  int exponent;
  double d;
  memcpy(&b_x[0], &x[0], 128U * sizeof(double));
  xzsvdc(b_x, score, latent, coeff);
  for (j = 0; j < 4; j++) {
    q = j << 2;
    score[q] *= latent[j];
    score_tmp = q + 1;
    score[score_tmp] *= latent[j];
    score_tmp = q + 2;
    score[score_tmp] *= latent[j];
    q += 3;
    score[q] *= latent[j];
  }

  latent[0] = latent[0] * latent[0] / (double)DOF;
  latent[1] = latent[1] * latent[1] / (double)DOF;
  latent[2] = latent[2] * latent[2] / (double)DOF;
  latent[3] = latent[3] * latent[3] / (double)DOF;
  if (DOF > 1) {
    absx = fabs(latent[0]);
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        absx = ldexp(1.0, exponent - 53);
      }
    } else {
      absx = rtNaN;
    }

    absx *= 32.0;
    q = 0;
    if (latent[0] > absx) {
      q = 1;
    }

    if (latent[1] > absx) {
      q++;
    }

    if (latent[2] > absx) {
      q++;
    }

    if (latent[3] > absx) {
      q++;
    }
  } else {
    q = 0;
  }

  tsquared[0] = 0.0;
  tsquared[1] = 0.0;
  tsquared[2] = 0.0;
  tsquared[3] = 0.0;
  for (j = 0; j < q; j++) {
    absx = sqrt(latent[j]);
    score_tmp = j << 2;
    d = score[score_tmp] / absx;
    tsquared[0] += d * d;
    d = score[score_tmp + 1] / absx;
    tsquared[1] += d * d;
    d = score[score_tmp + 2] / absx;
    tsquared[2] += d * d;
    d = score[score_tmp + 3] / absx;
    tsquared[3] += d * d;
  }

  scoreOut_size[0] = 4;
  scoreOut_size[1] = DOF;
  latentOut_size[0] = DOF;
  coeffOut_size[0] = 32;
  coeffOut_size[1] = DOF;
  for (j = 0; j < DOF; j++) {
    q = j << 2;
    scoreOut_data[4 * j] = score[q];
    scoreOut_data[4 * j + 1] = score[q + 1];
    scoreOut_data[4 * j + 2] = score[q + 2];
    scoreOut_data[4 * j + 3] = score[q + 3];
    latentOut_data[j] = latent[j];
    memcpy(&coeffOut_data[j * 32], &coeff[j * 32], 32U * sizeof(double));
  }

  if (DOF == 0) {
    absx = 0.0;
  } else {
    absx = latentOut_data[0];
    for (q = 2; q <= DOF; q++) {
      absx += latentOut_data[q - 1];
    }
  }

  explained_size[0] = DOF;
  for (score_tmp = 0; score_tmp < DOF; score_tmp++) {
    explained_data[score_tmp] = 100.0 * latentOut_data[score_tmp] / absx;
  }
}

/*
 * Arguments    : const double x[128]
 *                double varargout_1_data[]
 *                int varargout_1_size[2]
 *                double varargout_2_data[]
 *                int varargout_2_size[2]
 * Return Type  : void
 */
void pca(const double x[128], double varargout_1_data[], int varargout_1_size[2],
         double varargout_2_data[], int varargout_2_size[2])
{
  int wcol;
  int naninfo_nRowsWithNaNs;
  int naninfo_nNaNsInRow[4];
  int irow;
  int j;
  double b_x[128];
  bool naninfo_isNaN[128];
  bool noNaNs;
  int DOF;
  double mu[32];
  double xcol;
  int xNoNaNs_size[2];
  double coeff_data[96];
  int coeff_size[2];
  double score_data[12];
  int score_size[2];
  double latent_data[3];
  int latent_size[1];
  double WNoNaNs_data[4];
  double explained_data[3];
  int explained_size[1];
  double d;
  int WNoNaNs_size[1];
  double xNoNaNs_data[128];
  double b_score_data[12];
  int b_score_size[2];
  double tsquared_data[16];
  int tsquared_size[2];
  double sgn;
  double absc;
  wcol = 0;
  naninfo_nRowsWithNaNs = 0;
  naninfo_nNaNsInRow[0] = 0;
  naninfo_nNaNsInRow[1] = 0;
  naninfo_nNaNsInRow[2] = 0;
  naninfo_nNaNsInRow[3] = 0;
  for (irow = 0; irow < 128; irow++) {
    b_x[irow] = x[irow];
    naninfo_isNaN[irow] = rtIsNaN(x[irow]);
  }

  for (j = 0; j < 32; j++) {
    irow = j << 2;
    if (naninfo_isNaN[irow]) {
      naninfo_nNaNsInRow[0]++;
      wcol++;
    }

    if (naninfo_isNaN[irow + 1]) {
      naninfo_nNaNsInRow[1]++;
      wcol++;
    }

    if (naninfo_isNaN[irow + 2]) {
      naninfo_nNaNsInRow[2]++;
      wcol++;
    }

    if (naninfo_isNaN[irow + 3]) {
      naninfo_nNaNsInRow[3]++;
      wcol++;
    }
  }

  if (naninfo_nNaNsInRow[0] > 0) {
    naninfo_nRowsWithNaNs = 1;
  }

  if (naninfo_nNaNsInRow[1] > 0) {
    naninfo_nRowsWithNaNs++;
  }

  if (naninfo_nNaNsInRow[2] > 0) {
    naninfo_nRowsWithNaNs++;
  }

  if (naninfo_nNaNsInRow[3] > 0) {
    naninfo_nRowsWithNaNs++;
  }

  noNaNs = (wcol <= 0);
  DOF = 4 - naninfo_nRowsWithNaNs;
  if (4 - naninfo_nRowsWithNaNs >= 1) {
    DOF = 3 - naninfo_nRowsWithNaNs;
  }

  if (!noNaNs) {
    for (j = 0; j < 32; j++) {
      wcol = 0;
      xcol = 0.0;
      irow = j << 2;
      if (!rtIsNaN(x[irow])) {
        wcol = 1;
        xcol = x[irow];
      }

      d = x[irow + 1];
      if (!rtIsNaN(d)) {
        wcol++;
        xcol += d;
      }

      d = x[irow + 2];
      if (!rtIsNaN(d)) {
        wcol++;
        xcol += d;
      }

      d = x[irow + 3];
      if (!rtIsNaN(d)) {
        wcol++;
        xcol += d;
      }

      mu[j] = xcol / (double)wcol;
    }
  } else {
    for (j = 0; j < 32; j++) {
      wcol = j << 2;
      mu[j] = (((x[wcol] + x[wcol + 1]) + x[wcol + 2]) + x[wcol + 3]) / 4.0;
    }
  }

  for (j = 0; j < 32; j++) {
    wcol = j << 2;
    b_x[wcol] -= mu[j];
    irow = wcol + 1;
    b_x[irow] -= mu[j];
    irow = wcol + 2;
    b_x[irow] -= mu[j];
    wcol += 3;
    b_x[wcol] -= mu[j];
  }

  if (noNaNs) {
    localSVD(b_x, DOF, coeff_data, coeff_size, score_data, score_size,
             latent_data, latent_size, WNoNaNs_data, explained_data,
             explained_size);
  } else {
    xNoNaNs_size[0] = 4 - naninfo_nRowsWithNaNs;
    xNoNaNs_size[1] = 32;
    WNoNaNs_size[0] = 4 - naninfo_nRowsWithNaNs;
    irow = -1;
    for (naninfo_nRowsWithNaNs = 0; naninfo_nRowsWithNaNs < 4;
         naninfo_nRowsWithNaNs++) {
      if (naninfo_nNaNsInRow[naninfo_nRowsWithNaNs] == 0) {
        irow++;
        for (j = 0; j < 32; j++) {
          xNoNaNs_data[irow + xNoNaNs_size[0] * j] = b_x[naninfo_nRowsWithNaNs +
            (j << 2)];
        }

        WNoNaNs_data[irow] = 1.0;
      }
    }

    b_localSVD(xNoNaNs_data, xNoNaNs_size, DOF, WNoNaNs_data, WNoNaNs_size,
               coeff_data, coeff_size, b_score_data, b_score_size, latent_data,
               latent_size, tsquared_data, tsquared_size, explained_data,
               explained_size);
    wcol = b_score_size[1] - 1;
    irow = -1;
    if (naninfo_nNaNsInRow[0] > 0) {
      for (j = 0; j <= wcol; j++) {
        tsquared_data[4 * j] = rtNaN;
      }
    } else {
      irow = 0;
      for (j = 0; j <= wcol; j++) {
        tsquared_data[4 * j] = b_score_data[b_score_size[0] * j];
      }
    }

    if (naninfo_nNaNsInRow[1] > 0) {
      for (j = 0; j <= wcol; j++) {
        tsquared_data[4 * j + 1] = rtNaN;
      }
    } else {
      irow++;
      for (j = 0; j <= wcol; j++) {
        tsquared_data[4 * j + 1] = b_score_data[irow + b_score_size[0] * j];
      }
    }

    if (naninfo_nNaNsInRow[2] > 0) {
      for (j = 0; j <= wcol; j++) {
        tsquared_data[4 * j + 2] = rtNaN;
      }
    } else {
      irow++;
      for (j = 0; j <= wcol; j++) {
        tsquared_data[4 * j + 2] = b_score_data[irow + b_score_size[0] * j];
      }
    }

    if (naninfo_nNaNsInRow[3] > 0) {
      for (j = 0; j <= wcol; j++) {
        tsquared_data[4 * j + 3] = rtNaN;
      }
    } else {
      irow++;
      for (j = 0; j <= wcol; j++) {
        tsquared_data[4 * j + 3] = b_score_data[irow + b_score_size[0] * j];
      }
    }

    score_size[0] = 4;
    score_size[1] = b_score_size[1];
    wcol = 4 * b_score_size[1];
    if (0 <= wcol - 1) {
      memcpy(&score_data[0], &tsquared_data[0], wcol * sizeof(double));
    }
  }

  if (1 < DOF) {
    varargout_1_size[0] = 32;
    varargout_1_size[1] = 1;
    memcpy(&varargout_1_data[0], &coeff_data[0], 32U * sizeof(double));
    varargout_2_size[0] = 4;
    varargout_2_size[1] = 1;
    varargout_2_data[0] = score_data[0];
    varargout_2_data[1] = score_data[1];
    varargout_2_data[2] = score_data[2];
    varargout_2_data[3] = score_data[3];
  } else {
    varargout_1_size[0] = 32;
    varargout_1_size[1] = coeff_size[1];
    wcol = coeff_size[0] * coeff_size[1];
    if (0 <= wcol - 1) {
      memcpy(&varargout_1_data[0], &coeff_data[0], wcol * sizeof(double));
    }

    varargout_2_size[0] = 4;
    varargout_2_size[1] = score_size[1];
    wcol = score_size[0] * score_size[1];
    if (0 <= wcol - 1) {
      memcpy(&varargout_2_data[0], &score_data[0], wcol * sizeof(double));
    }
  }

  irow = varargout_1_size[1];
  for (j = 0; j < irow; j++) {
    xcol = 0.0;
    sgn = 1.0;
    for (naninfo_nRowsWithNaNs = 0; naninfo_nRowsWithNaNs < 32;
         naninfo_nRowsWithNaNs++) {
      d = varargout_1_data[naninfo_nRowsWithNaNs + 32 * j];
      absc = fabs(d);
      if (absc > xcol) {
        xcol = absc;
        sgn = d;
        if (d < 0.0) {
          sgn = -1.0;
        } else if (d > 0.0) {
          sgn = 1.0;
        } else {
          if (d == 0.0) {
            sgn = 0.0;
          }
        }
      }
    }

    if (sgn < 0.0) {
      for (naninfo_nRowsWithNaNs = 0; naninfo_nRowsWithNaNs < 32;
           naninfo_nRowsWithNaNs++) {
        wcol = naninfo_nRowsWithNaNs + 32 * j;
        varargout_1_data[wcol] = -varargout_1_data[wcol];
      }

      varargout_2_data[4 * j] = -varargout_2_data[4 * j];
      wcol = 4 * j + 1;
      varargout_2_data[wcol] = -varargout_2_data[wcol];
      wcol = 4 * j + 2;
      varargout_2_data[wcol] = -varargout_2_data[wcol];
      wcol = 4 * j + 3;
      varargout_2_data[wcol] = -varargout_2_data[wcol];
    }
  }
}

/*
 * File trailer for pca.c
 *
 * [EOF]
 */
