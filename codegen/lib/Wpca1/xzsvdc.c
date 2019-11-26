/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzsvdc.c
 *
 * Code generation for function 'xzsvdc'
 *
 */

/* Include files */
#include "xzsvdc.h"
#include "Wpca1.h"
#include "Wpca1_emxutil.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void b_xzsvdc(emxArray_real_T *A, double U_data[], int U_size[2], double S_data[],
              int S_size[1], emxArray_real_T *V)
{
  int n;
  int qp1q;
  double s_data[65];
  double e[128];
  double work_data[64];
  int jj;
  static double Vf[16384];
  int ii;
  int y;
  int q;
  int m;
  int qp1;
  int k;
  int qq;
  int nmq;
  bool apply_transform;
  double nrm;
  int qjj;
  double r;
  double snorm;
  bool exitg1;
  double scale;
  double sm;
  double sqds;
  double b;
  n = A->size[0];
  qp1q = (signed char)(A->size[0] + 1);
  if (0 <= qp1q - 1) {
    memset(&s_data[0], 0, qp1q * sizeof(double));
  }

  memset(&e[0], 0, 128U * sizeof(double));
  qp1q = (signed char)A->size[0];
  if (0 <= qp1q - 1) {
    memset(&work_data[0], 0, qp1q * sizeof(double));
  }

  U_size[0] = (signed char)A->size[0];
  U_size[1] = (signed char)A->size[0];
  qp1q = (signed char)A->size[0] * (signed char)A->size[0];
  if (0 <= qp1q - 1) {
    memset(&U_data[0], 0, qp1q * sizeof(double));
  }

  for (jj = 0; jj < 16384; jj++) {
    Vf[jj] = 0.0;
  }

  if (A->size[0] == 0) {
    for (ii = 0; ii < 128; ii++) {
      Vf[ii + (ii << 7)] = 1.0;
    }
  } else {
    if (A->size[0] > 1) {
      y = A->size[0] - 1;
    } else {
      y = 0;
    }

    qp1q = A->size[0];
    if (y > qp1q) {
      qp1q = y;
    }

    for (q = 0; q < qp1q; q++) {
      qp1 = q + 2;
      qq = (q + n * q) + 1;
      nmq = n - q;
      apply_transform = false;
      if (q + 1 <= y) {
        nrm = c_xnrm2(nmq, A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A->data[qq - 1] < 0.0) {
            r = -nrm;
            s_data[q] = -nrm;
          } else {
            r = nrm;
            s_data[q] = nrm;
          }

          if (fabs(r) >= 1.0020841800044864E-292) {
            nrm = 1.0 / r;
            jj = (qq + nmq) - 1;
            for (k = qq; k <= jj; k++) {
              A->data[k - 1] *= nrm;
            }
          } else {
            jj = (qq + nmq) - 1;
            for (k = qq; k <= jj; k++) {
              A->data[k - 1] /= s_data[q];
            }
          }

          A->data[qq - 1]++;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }

      for (jj = qp1; jj < 129; jj++) {
        qjj = q + n * (jj - 1);
        if (apply_transform) {
          f_xaxpy(nmq, -(d_xdotc(nmq, A, qq, A, qjj + 1) / A->data[q + A->size[0]
                         * q]), qq, A, qjj + 1);
        }

        e[jj - 1] = A->data[qjj];
      }

      if (q + 1 <= y) {
        for (ii = q + 1; ii <= n; ii++) {
          U_data[(ii + U_size[0] * q) - 1] = A->data[(ii + A->size[0] * q) - 1];
        }
      }

      if (q + 1 <= n) {
        nrm = b_xnrm2(127 - q, e, q + 2);
        if (nrm == 0.0) {
          e[q] = 0.0;
        } else {
          if (e[q + 1] < 0.0) {
            e[q] = -nrm;
          } else {
            e[q] = nrm;
          }

          nrm = e[q];
          if (fabs(e[q]) >= 1.0020841800044864E-292) {
            nrm = 1.0 / e[q];
            for (k = qp1; k < 129; k++) {
              e[k - 1] *= nrm;
            }
          } else {
            for (k = qp1; k < 129; k++) {
              e[k - 1] /= nrm;
            }
          }

          e[q + 1]++;
          e[q] = -e[q];
          if (q + 2 <= n) {
            if (qp1 <= n) {
              memset(&work_data[qp1 + -1], 0, ((n - qp1) + 1) * sizeof(double));
            }

            for (jj = qp1; jj < 129; jj++) {
              g_xaxpy(nmq - 1, e[jj - 1], A, (q + n * (jj - 1)) + 2, work_data,
                      q + 2);
            }

            for (jj = qp1; jj < 129; jj++) {
              h_xaxpy(nmq - 1, -e[jj - 1] / e[q + 1], work_data, q + 2, A, (q +
                       n * (jj - 1)) + 2);
            }
          }
        }

        for (ii = qp1; ii < 129; ii++) {
          Vf[(ii + (q << 7)) - 1] = e[ii - 1];
        }
      }
    }

    m = n;
    s_data[y] = A->data[y + A->size[0] * y];
    if (n < n + 1) {
      s_data[n] = 0.0;
    }

    e[n] = 0.0;
    if (y + 1 <= n) {
      for (jj = y + 1; jj <= n; jj++) {
        for (ii = 0; ii < n; ii++) {
          U_data[ii + U_size[0] * (jj - 1)] = 0.0;
        }

        U_data[(jj + U_size[0] * (jj - 1)) - 1] = 1.0;
      }
    }

    for (q = y; q >= 1; q--) {
      qp1 = q + 1;
      qp1q = n - q;
      nmq = qp1q + 1;
      qq = (q + n * (q - 1)) - 1;
      if (s_data[q - 1] != 0.0) {
        for (jj = qp1; jj <= n; jj++) {
          qjj = q + n * (jj - 1);
          i_xaxpy(qp1q + 1, -(e_xdotc(nmq, U_data, qq + 1, U_data, qjj) /
                              U_data[qq]), qq + 1, U_data, qjj);
        }

        for (ii = q; ii <= n; ii++) {
          jj = (ii + U_size[0] * (q - 1)) - 1;
          U_data[jj] = -U_data[jj];
        }

        U_data[qq]++;
        for (ii = 0; ii <= q - 2; ii++) {
          U_data[ii + U_size[0] * (q - 1)] = 0.0;
        }
      } else {
        for (ii = 0; ii < n; ii++) {
          U_data[ii + U_size[0] * (q - 1)] = 0.0;
        }

        U_data[qq] = 1.0;
      }
    }

    for (q = 127; q >= 0; q--) {
      if ((q + 1 <= n) && (e[q] != 0.0)) {
        qp1 = q + 2;
        qp1q = (q + (q << 7)) + 2;
        for (jj = qp1; jj < 129; jj++) {
          nmq = (q + ((jj - 1) << 7)) + 2;
          e_xaxpy(127 - q, -(c_xdotc(127 - q, Vf, qp1q, Vf, nmq) / Vf[qp1q - 1]),
                  qp1q, Vf, nmq);
        }
      }

      memset(&Vf[q * 128], 0, 128U * sizeof(double));
      Vf[q + (q << 7)] = 1.0;
    }

    qjj = 0;
    snorm = 0.0;
    for (q = 0; q <= n; q++) {
      if (s_data[q] != 0.0) {
        nrm = fabs(s_data[q]);
        r = s_data[q] / nrm;
        s_data[q] = nrm;
        if (q + 1 < n + 1) {
          e[q] /= r;
        }

        if (q + 1 <= n) {
          qp1q = n * q;
          jj = qp1q + n;
          for (k = qp1q + 1; k <= jj; k++) {
            U_data[k - 1] *= r;
          }
        }
      }

      if ((q + 1 < n + 1) && (e[q] != 0.0)) {
        nrm = fabs(e[q]);
        r = nrm / e[q];
        e[q] = nrm;
        s_data[q + 1] *= r;
        qp1q = (q + 1) << 7;
        jj = qp1q + 128;
        for (k = qp1q + 1; k <= jj; k++) {
          Vf[k - 1] *= r;
        }
      }

      snorm = fmax(snorm, fmax(fabs(s_data[q]), fabs(e[q])));
    }

    while ((m + 1 > 0) && (qjj < 75)) {
      ii = m;
      exitg1 = false;
      while (!(exitg1 || (ii == 0))) {
        nrm = fabs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s_data[ii - 1]) + fabs
              (s_data[ii]))) || (nrm <= 1.0020841800044864E-292) || ((qjj > 20) &&
             (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg1 = true;
        } else {
          ii--;
        }
      }

      if (ii == m) {
        qp1q = 4;
      } else {
        nmq = m + 1;
        qp1q = m + 1;
        exitg1 = false;
        while ((!exitg1) && (qp1q >= ii)) {
          nmq = qp1q;
          if (qp1q == ii) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (qp1q < m + 1) {
              nrm = fabs(e[qp1q - 1]);
            }

            if (qp1q > ii + 1) {
              nrm += fabs(e[qp1q - 2]);
            }

            r = fabs(s_data[qp1q - 1]);
            if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
                 1.0020841800044864E-292)) {
              s_data[qp1q - 1] = 0.0;
              exitg1 = true;
            } else {
              qp1q--;
            }
          }
        }

        if (nmq == ii) {
          qp1q = 3;
        } else if (nmq == m + 1) {
          qp1q = 1;
        } else {
          qp1q = 2;
          ii = nmq;
        }
      }

      switch (qp1q) {
       case 1:
        r = e[m - 1];
        e[m - 1] = 0.0;
        for (k = m; k >= ii + 1; k--) {
          xrotg(&s_data[k - 1], &r, &sqds, &sm);
          if (k > ii + 1) {
            b = e[k - 2];
            r = -sm * b;
            e[k - 2] = b * sqds;
          }

          xrot(Vf, ((k - 1) << 7) + 1, (m << 7) + 1, sqds, sm);
        }
        break;

       case 2:
        r = e[ii - 1];
        e[ii - 1] = 0.0;
        for (k = ii + 1; k <= m + 1; k++) {
          xrotg(&s_data[k - 1], &r, &sqds, &sm);
          b = e[k - 1];
          r = -sm * b;
          e[k - 1] = b * sqds;
          c_xrot(n, U_data, n * (k - 1) + 1, n * (ii - 1) + 1, sqds, sm);
        }
        break;

       case 3:
        nrm = s_data[m - 1];
        r = e[m - 1];
        scale = fmax(fmax(fmax(fmax(fabs(s_data[m]), fabs(nrm)), fabs(r)), fabs
                          (s_data[ii])), fabs(e[ii]));
        sm = s_data[m] / scale;
        nrm /= scale;
        r /= scale;
        sqds = s_data[ii] / scale;
        b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
        nrm = sm * r;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          r = sqrt(b * b + nrm);
          if (b < 0.0) {
            r = -r;
          }

          r = nrm / (b + r);
        } else {
          r = 0.0;
        }

        r += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[ii] / scale);
        for (k = ii + 1; k <= m; k++) {
          xrotg(&r, &nrm, &sqds, &sm);
          if (k > ii + 1) {
            e[k - 2] = r;
          }

          nrm = e[k - 1];
          b = s_data[k - 1];
          e[k - 1] = sqds * nrm - sm * b;
          r = sm * s_data[k];
          s_data[k] *= sqds;
          xrot(Vf, ((k - 1) << 7) + 1, (k << 7) + 1, sqds, sm);
          s_data[k - 1] = sqds * b + sm * nrm;
          xrotg(&s_data[k - 1], &r, &sqds, &sm);
          r = sqds * e[k - 1] + sm * s_data[k];
          s_data[k] = -sm * e[k - 1] + sqds * s_data[k];
          nrm = sm * e[k];
          e[k] *= sqds;
          if (k < n) {
            c_xrot(n, U_data, n * (k - 1) + 1, n * k + 1, sqds, sm);
          }
        }

        e[m - 1] = r;
        qjj++;
        break;

       default:
        if (s_data[ii] < 0.0) {
          s_data[ii] = -s_data[ii];
          qp1q = ii << 7;
          jj = qp1q + 128;
          for (k = qp1q + 1; k <= jj; k++) {
            Vf[k - 1] = -Vf[k - 1];
          }
        }

        qp1 = ii + 1;
        while ((ii + 1 < n + 1) && (s_data[ii] < s_data[qp1])) {
          nrm = s_data[ii];
          s_data[ii] = s_data[qp1];
          s_data[qp1] = nrm;
          xswap(Vf, (ii << 7) + 1, ((ii + 1) << 7) + 1);
          if (ii + 1 < n) {
            c_xswap(n, U_data, n * ii + 1, n * (ii + 1) + 1);
          }

          ii = qp1;
          qp1++;
        }

        qjj = 0;
        m--;
        break;
      }
    }
  }

  S_size[0] = n;
  jj = V->size[0] * V->size[1];
  V->size[0] = 128;
  V->size[1] = n;
  emxEnsureCapacity_real_T(V, jj);
  for (k = 0; k < n; k++) {
    S_data[k] = s_data[k];
    for (qp1q = 0; qp1q < 128; qp1q++) {
      V->data[qp1q + 128 * k] = Vf[qp1q + (k << 7)];
    }
  }
}

void xzsvdc(double A[8192], double U[4096], double S[64], double V[8192])
{
  double s[65];
  double e[128];
  double work[64];
  int qp1jj;
  int q;
  static double Vf[16384];
  int m;
  int qp1;
  int iter;
  int qq;
  bool apply_transform;
  double nrm;
  int k;
  int qjj;
  double snorm;
  double r;
  long exitg1;
  bool exitg2;
  double scale;
  double sm;
  double sqds;
  double b;
  memset(&s[0], 0, 65U * sizeof(double));
  memset(&e[0], 0, 128U * sizeof(double));
  memset(&work[0], 0, 64U * sizeof(double));
  memset(&U[0], 0, 4096U * sizeof(double));
  for (qp1jj = 0; qp1jj < 16384; qp1jj++) {
    Vf[qp1jj] = 0.0;
  }

  for (q = 0; q < 64; q++) {
    qp1 = q + 2;
    iter = q << 6;
    qq = (q + iter) + 1;
    apply_transform = false;
    if (q + 1 <= 63) {
      nrm = xnrm2(64 - q, A, qq);
      if (nrm > 0.0) {
        apply_transform = true;
        if (A[qq - 1] < 0.0) {
          nrm = -nrm;
        }

        s[q] = nrm;
        if (fabs(nrm) >= 1.0020841800044864E-292) {
          nrm = 1.0 / nrm;
          qp1jj = (qq - q) + 63;
          for (k = qq; k <= qp1jj; k++) {
            A[k - 1] *= nrm;
          }
        } else {
          qp1jj = (qq - q) + 63;
          for (k = qq; k <= qp1jj; k++) {
            A[k - 1] /= s[q];
          }
        }

        A[qq - 1]++;
        s[q] = -s[q];
      } else {
        s[q] = 0.0;
      }
    }

    for (k = qp1; k < 129; k++) {
      qjj = q + ((k - 1) << 6);
      if (apply_transform) {
        xaxpy(64 - q, -(xdotc(64 - q, A, qq, A, qjj + 1) / A[q + (q << 6)]), qq,
              A, qjj + 1);
      }

      e[k - 1] = A[qjj];
    }

    if (q + 1 <= 63) {
      for (k = q + 1; k < 65; k++) {
        qp1jj = (k + iter) - 1;
        U[qp1jj] = A[qp1jj];
      }
    }

    nrm = b_xnrm2(127 - q, e, q + 2);
    if (nrm == 0.0) {
      e[q] = 0.0;
    } else {
      if (e[q + 1] < 0.0) {
        e[q] = -nrm;
      } else {
        e[q] = nrm;
      }

      nrm = e[q];
      if (fabs(e[q]) >= 1.0020841800044864E-292) {
        nrm = 1.0 / e[q];
        for (k = qp1; k < 129; k++) {
          e[k - 1] *= nrm;
        }
      } else {
        for (k = qp1; k < 129; k++) {
          e[k - 1] /= nrm;
        }
      }

      e[q + 1]++;
      e[q] = -e[q];
      if (q + 2 <= 64) {
        for (k = qp1; k < 65; k++) {
          work[k - 1] = 0.0;
        }

        for (k = qp1; k < 129; k++) {
          b_xaxpy(63 - q, e[k - 1], A, (q + ((k - 1) << 6)) + 2, work, q + 2);
        }

        for (k = qp1; k < 129; k++) {
          c_xaxpy(63 - q, -e[k - 1] / e[q + 1], work, q + 2, A, (q + ((k - 1) <<
                    6)) + 2);
        }
      }
    }

    for (k = qp1; k < 129; k++) {
      Vf[(k + (q << 7)) - 1] = e[k - 1];
    }
  }

  m = 63;
  s[63] = A[4095];
  s[64] = 0.0;
  e[64] = 0.0;
  memset(&U[4032], 0, 64U * sizeof(double));
  U[4095] = 1.0;
  for (q = 62; q >= 0; q--) {
    qp1 = q + 2;
    iter = q << 6;
    qq = q + iter;
    if (s[q] != 0.0) {
      for (k = qp1; k < 65; k++) {
        qjj = (q + ((k - 1) << 6)) + 1;
        d_xaxpy(64 - q, -(b_xdotc(64 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
                qjj);
      }

      for (k = q + 1; k < 65; k++) {
        qp1jj = (k + iter) - 1;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + iter] = 0.0;
      }
    } else {
      memset(&U[iter], 0, 64U * sizeof(double));
      U[qq] = 1.0;
    }
  }

  for (q = 127; q >= 0; q--) {
    if ((q + 1 <= 64) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (q << 7)) + 2;
      for (k = qp1; k < 129; k++) {
        qp1jj = (q + ((k - 1) << 7)) + 2;
        e_xaxpy(127 - q, -(c_xdotc(127 - q, Vf, qjj, Vf, qp1jj) / Vf[qjj - 1]),
                qjj, Vf, qp1jj);
      }
    }

    memset(&Vf[q * 128], 0, 128U * sizeof(double));
    Vf[q + (q << 7)] = 1.0;
  }

  iter = 0;
  snorm = 0.0;
  for (q = 0; q < 65; q++) {
    if (s[q] != 0.0) {
      nrm = fabs(s[q]);
      r = s[q] / nrm;
      s[q] = nrm;
      if (q + 1 < 65) {
        e[q] /= r;
      }

      if (q + 1 <= 64) {
        qjj = q << 6;
        qp1jj = qjj + 64;
        for (k = qjj + 1; k <= qp1jj; k++) {
          U[k - 1] *= r;
        }
      }
    }

    if ((q + 1 < 65) && (e[q] != 0.0)) {
      nrm = fabs(e[q]);
      r = nrm / e[q];
      e[q] = nrm;
      s[q + 1] *= r;
      qjj = (q + 1) << 7;
      qp1jj = qjj + 128;
      for (k = qjj + 1; k <= qp1jj; k++) {
        Vf[k - 1] *= r;
      }
    }

    snorm = fmax(snorm, fmax(fabs(s[q]), fabs(e[q])));
  }

  while ((m + 2 > 0) && (iter < 75)) {
    k = m;
    do {
      exitg1 = 0L;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1L;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s[k]) + fabs(s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((iter > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1L;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0L);

    if (k + 1 == m + 1) {
      qjj = 4;
    } else {
      qp1jj = m + 2;
      qjj = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qjj >= k + 1)) {
        qp1jj = qjj;
        if (qjj == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }

          if (qjj > k + 2) {
            nrm += fabs(e[qjj - 2]);
          }

          r = fabs(s[qjj - 1]);
          if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
               1.0020841800044864E-292)) {
            s[qjj - 1] = 0.0;
            exitg2 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qp1jj == k + 1) {
        qjj = 3;
      } else if (qp1jj == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        q = qp1jj;
      }
    }

    switch (qjj) {
     case 1:
      r = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= q + 1; k--) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        if (k > q + 1) {
          b = e[k - 2];
          r = -sqds * b;
          e[k - 2] = b * sm;
        }

        xrot(Vf, ((k - 1) << 7) + 1, ((m + 1) << 7) + 1, sm, sqds);
      }
      break;

     case 2:
      r = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = -sqds * b;
        e[k - 1] = b * sm;
        b_xrot(U, ((k - 1) << 6) + 1, ((q - 1) << 6) + 1, sm, sqds);
      }
      break;

     case 3:
      qjj = m + 1;
      nrm = s[m + 1];
      scale = fmax(fmax(fmax(fmax(fabs(nrm), fabs(s[m])), fabs(e[m])), fabs(s[q])),
                   fabs(e[q]));
      sm = nrm / scale;
      nrm = s[m] / scale;
      r = e[m] / scale;
      sqds = s[q] / scale;
      b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
      nrm = sm * r;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        r = sqrt(b * b + nrm);
        if (b < 0.0) {
          r = -r;
        }

        r = nrm / (b + r);
      } else {
        r = 0.0;
      }

      r += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qjj; k++) {
        xrotg(&r, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[k - 2] = r;
        }

        nrm = e[k - 1];
        b = s[k - 1];
        e[k - 1] = sm * nrm - sqds * b;
        r = sqds * s[k];
        s[k] *= sm;
        xrot(Vf, ((k - 1) << 7) + 1, (k << 7) + 1, sm, sqds);
        s[k - 1] = sm * b + sqds * nrm;
        xrotg(&s[k - 1], &r, &sm, &sqds);
        r = sm * e[k - 1] + sqds * s[k];
        s[k] = -sqds * e[k - 1] + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        if (k < 64) {
          b_xrot(U, ((k - 1) << 6) + 1, (k << 6) + 1, sm, sqds);
        }
      }

      e[m] = r;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        qjj = q << 7;
        qp1jj = qjj + 128;
        for (k = qjj + 1; k <= qp1jj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 65) && (s[q] < s[qp1])) {
        nrm = s[q];
        s[q] = s[qp1];
        s[qp1] = nrm;
        xswap(Vf, (q << 7) + 1, ((q + 1) << 7) + 1);
        if (q + 1 < 64) {
          b_xswap(U, (q << 6) + 1, ((q + 1) << 6) + 1);
        }

        q = qp1;
        qp1++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  for (k = 0; k < 64; k++) {
    S[k] = s[k];
    memcpy(&V[k * 128], &Vf[k * 128], 128U * sizeof(double));
  }
}

/* End of code generation (xzsvdc.c) */
