/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pca.c
 *
 * Code generation for function 'pca'
 *
 */

/* Include files */
#include "pca.h"
#include "Wpca1.h"
#include "Wpca1_emxutil.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void b_localTSquared(const double score_data[], const int score_size[2],
  const double latent_data[], const int latent_size[1], int DOF, double
  tsquared_data[], int tsquared_size[2]);
static void localTSquared(const double score[4096], const double latent[64], int
  DOF, double tsquared[64]);

/* Function Definitions */
static void b_localTSquared(const double score_data[], const int score_size[2],
  const double latent_data[], const int latent_size[1], int DOF, double
  tsquared_data[], int tsquared_size[2])
{
  int q;
  double absx;
  int exponent;
  int m;
  int k;
  double d;
  if ((score_size[0] == 0) || (score_size[1] == 0)) {
    tsquared_size[0] = score_size[0];
    tsquared_size[1] = score_size[1];
    exponent = score_size[0] * score_size[1];
    if (0 <= exponent - 1) {
      memcpy(&tsquared_data[0], &score_data[0], exponent * sizeof(double));
    }
  } else {
    if (DOF > 1) {
      absx = fabs(latent_data[0]);
      if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
        if (absx <= 2.2250738585072014E-308) {
          absx = 4.94065645841247E-324;
        } else {
          frexp(absx, &exponent);
          absx = ldexp(1.0, (int)(exponent - 53L));
        }
      } else {
        absx = rtNaN;
      }

      absx *= 128.0;
      q = 0;
      exponent = latent_size[0];
      for (k = 0; k < exponent; k++) {
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
    exponent = score_size[0];
    if (0 <= exponent - 1) {
      memset(&tsquared_data[0], 0, exponent * sizeof(double));
    }

    for (exponent = 0; exponent < q; exponent++) {
      absx = sqrt(latent_data[exponent]);
      for (k = 0; k < m; k++) {
        d = score_data[k + score_size[0] * exponent] / absx;
        tsquared_data[k] += d * d;
      }
    }
  }
}

static void localTSquared(const double score[4096], const double latent[64], int
  DOF, double tsquared[64])
{
  int q;
  double absx;
  int exponent;
  int i;
  double d;
  if (DOF > 1) {
    absx = fabs(latent[0]);
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        absx = ldexp(1.0, (int)(exponent - 53L));
      }
    } else {
      absx = rtNaN;
    }

    absx *= 128.0;
    q = 0;
    for (exponent = 0; exponent < 64; exponent++) {
      if (latent[exponent] > absx) {
        q++;
      }
    }
  } else {
    q = 0;
  }

  memset(&tsquared[0], 0, 64U * sizeof(double));
  for (exponent = 0; exponent < q; exponent++) {
    absx = sqrt(latent[exponent]);
    for (i = 0; i < 64; i++) {
      d = score[i + (exponent << 6)] / absx;
      tsquared[i] += d * d;
    }
  }
}

void b_localSVD(emxArray_real_T *x, int DOF, const double Weights_data[], const
                int Weights_size[1], double coeffOut_data[], int coeffOut_size[2],
                double scoreOut_data[], int scoreOut_size[2], double
                latentOut_data[], int latentOut_size[1], double tsquared_data[],
                int tsquared_size[2], double explained_data[], int
                explained_size[1])
{
  int nx;
  double OmegaSqrt_data[64];
  int k;
  int nrows;
  int j;
  emxArray_real_T *b_x;
  int i;
  emxArray_real_T *coeff;
  double score_data[4096];
  int score_size[2];
  double latent_data[64];
  int latent_size[1];
  int minDOFnsv;
  double y;
  nx = Weights_size[0L];
  if (0 <= nx - 1) {
    memcpy(&OmegaSqrt_data[0], &Weights_data[0], nx * sizeof(double));
  }

  nx = Weights_size[0];
  for (k = 0; k < nx; k++) {
    OmegaSqrt_data[k] = sqrt(OmegaSqrt_data[k]);
  }

  nrows = x->size[0] - 1;
  for (j = 0; j < 128; j++) {
    for (i = 0; i <= nrows; i++) {
      x->data[i + x->size[0] * j] *= OmegaSqrt_data[i];
    }
  }

  emxInit_real_T(&b_x, 2);
  k = b_x->size[0] * b_x->size[1];
  b_x->size[0] = x->size[0];
  b_x->size[1] = 128;
  emxEnsureCapacity_real_T(b_x, k);
  nx = x->size[0] * x->size[1] - 1;
  for (k = 0; k <= nx; k++) {
    b_x->data[k] = x->data[k];
  }

  emxInit_real_T(&coeff, 2);
  b_xzsvdc(b_x, score_data, score_size, latent_data, latent_size, coeff);
  nx = score_size[1];
  emxFree_real_T(&b_x);
  for (j = 0; j < nx; j++) {
    for (i = 0; i <= nrows; i++) {
      k = i + score_size[0] * j;
      score_data[k] = score_data[k] / OmegaSqrt_data[i] * latent_data[j];
    }

    latent_data[j] = latent_data[j] * latent_data[j] / (double)DOF;
  }

  b_localTSquared(score_data, score_size, latent_data, latent_size, DOF,
                  tsquared_data, tsquared_size);
  minDOFnsv = score_size[1];
  if (DOF < minDOFnsv) {
    minDOFnsv = DOF;
  }

  scoreOut_size[0] = nrows + 1;
  scoreOut_size[1] = minDOFnsv;
  latentOut_size[0] = minDOFnsv;
  coeffOut_size[0] = 128;
  coeffOut_size[1] = minDOFnsv;
  for (j = 0; j < minDOFnsv; j++) {
    for (i = 0; i <= nrows; i++) {
      scoreOut_data[i + scoreOut_size[0] * j] = score_data[i + score_size[0] * j];
    }

    latentOut_data[j] = latent_data[j];
    for (i = 0; i < 128; i++) {
      nx = i + 128 * j;
      coeffOut_data[nx] = coeff->data[nx];
    }
  }

  emxFree_real_T(&coeff);
  if (minDOFnsv == 0) {
    y = 0.0;
  } else {
    y = latentOut_data[0];
    for (k = 2; k <= minDOFnsv; k++) {
      y += latentOut_data[k - 1];
    }
  }

  explained_size[0L] = minDOFnsv;
  for (k = 0; k < minDOFnsv; k++) {
    explained_data[k] = 100.0 * latentOut_data[k] / y;
  }
}

void localSVD(const double x[8192], int DOF, double coeffOut_data[], int
              coeffOut_size[2], double scoreOut_data[], int scoreOut_size[2],
              double latentOut_data[], int latentOut_size[1], double tsquared[64],
              double explained_data[], int explained_size[1])
{
  int i;
  static double b_x[8192];
  double score[4096];
  double latent[64];
  static double coeff[8192];
  int j;
  int b_i;
  int score_tmp;
  double y;
  for (i = 0; i < 8192; i++) {
    b_x[i] = x[i];
  }

  xzsvdc(b_x, score, latent, coeff);
  for (j = 0; j < 64; j++) {
    for (b_i = 0; b_i < 64; b_i++) {
      score_tmp = b_i + (j << 6);
      score[score_tmp] *= latent[j];
    }

    latent[j] = latent[j] * latent[j] / (double)DOF;
  }

  localTSquared(score, latent, DOF, tsquared);
  scoreOut_size[0] = 64;
  scoreOut_size[1] = DOF;
  latentOut_size[0] = DOF;
  coeffOut_size[0] = 128;
  coeffOut_size[1] = DOF;
  for (j = 0; j < DOF; j++) {
    memcpy(&scoreOut_data[j * 64], &score[j * 64], 64U * sizeof(double));
    latentOut_data[j] = latent[j];
    memcpy(&coeffOut_data[j * 128], &coeff[j * 128], 128U * sizeof(double));
  }

  if (DOF == 0) {
    y = 0.0;
  } else {
    y = latentOut_data[0];
    for (j = 2; j <= DOF; j++) {
      y += latentOut_data[j - 1];
    }
  }

  explained_size[0L] = DOF;
  for (j = 0; j < DOF; j++) {
    explained_data[j] = 100.0 * latentOut_data[j] / y;
  }
}

/* End of code generation (pca.c) */
