/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzsvdc.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 09-Dec-2019 01:55:25
 */

/* Include Files */
#include "xzsvdc.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
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

/*
 * Arguments    : double A_data[]
 *                const int A_size[2]
 *                double U_data[]
 *                int U_size[2]
 *                double S_data[]
 *                int S_size[1]
 *                double V_data[]
 *                int V_size[2]
 * Return Type  : void
 */
void b_xzsvdc(double A_data[], const int A_size[2], double U_data[], int U_size
              [2], double S_data[], int S_size[1], double V_data[], int V_size[2])
{
  int n;
  int qp1q;
  double s_data[5];
  double e[32];
  double work_data[4];
  double Vf[1024];
  int ii;
  int y;
  int q;
  int k;
  int m;
  int qp1;
  int qq;
  int nmq;
  bool apply_transform;
  double nrm;
  int jj;
  int qjj;
  double r;
  double snorm;
  bool exitg1;
  double scale;
  double sm;
  double sqds;
  double b;
  n = A_size[0];
  qp1q = (signed char)(A_size[0] + 1);
  if (0 <= qp1q - 1) {
    memset(&s_data[0], 0, qp1q * sizeof(double));
  }

  memset(&e[0], 0, 32U * sizeof(double));
  qp1q = (signed char)A_size[0];
  if (0 <= qp1q - 1) {
    memset(&work_data[0], 0, qp1q * sizeof(double));
  }

  U_size[0] = (signed char)A_size[0];
  U_size[1] = (signed char)A_size[0];
  qp1q = (signed char)A_size[0] * (signed char)A_size[0];
  if (0 <= qp1q - 1) {
    memset(&U_data[0], 0, qp1q * sizeof(double));
  }

  memset(&Vf[0], 0, 1024U * sizeof(double));
  if (A_size[0] == 0) {
    for (ii = 0; ii < 32; ii++) {
      Vf[ii + (ii << 5)] = 1.0;
    }
  } else {
    if (A_size[0] > 1) {
      y = A_size[0] - 1;
    } else {
      y = 0;
    }

    qp1q = A_size[0];
    if (y > qp1q) {
      qp1q = y;
    }

    for (q = 0; q < qp1q; q++) {
      qp1 = q + 2;
      qq = (q + n * q) + 1;
      nmq = n - q;
      apply_transform = false;
      if (q + 1 <= y) {
        nrm = c_xnrm2(nmq, A_data, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A_data[qq - 1] < 0.0) {
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
              A_data[k - 1] *= nrm;
            }
          } else {
            jj = (qq + nmq) - 1;
            for (k = qq; k <= jj; k++) {
              A_data[k - 1] /= s_data[q];
            }
          }

          A_data[qq - 1]++;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }

      for (jj = qp1; jj < 33; jj++) {
        qjj = q + n * (jj - 1);
        if (apply_transform) {
          f_xaxpy(nmq, -(d_xdotc(nmq, A_data, qq, A_data, qjj + 1) / A_data[q +
                         A_size[0] * q]), qq, A_data, qjj + 1);
        }

        e[jj - 1] = A_data[qjj];
      }

      if (q + 1 <= y) {
        for (ii = q + 1; ii <= n; ii++) {
          U_data[(ii + U_size[0] * q) - 1] = A_data[(ii + A_size[0] * q) - 1];
        }
      }

      if (q + 1 <= n) {
        nrm = b_xnrm2(31 - q, e, q + 2);
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
            for (k = qp1; k < 33; k++) {
              e[k - 1] *= nrm;
            }
          } else {
            for (k = qp1; k < 33; k++) {
              e[k - 1] /= nrm;
            }
          }

          e[q + 1]++;
          e[q] = -e[q];
          if (q + 2 <= n) {
            if (qp1 <= n) {
              memset(&work_data[qp1 + -1], 0, ((n - qp1) + 1) * sizeof(double));
            }

            for (jj = qp1; jj < 33; jj++) {
              g_xaxpy(nmq - 1, e[jj - 1], A_data, (q + n * (jj - 1)) + 2,
                      work_data, q + 2);
            }

            for (jj = qp1; jj < 33; jj++) {
              g_xaxpy(nmq - 1, -e[jj - 1] / e[q + 1], work_data, q + 2, A_data,
                      (q + n * (jj - 1)) + 2);
            }
          }
        }

        for (ii = qp1; ii < 33; ii++) {
          Vf[(ii + (q << 5)) - 1] = e[ii - 1];
        }
      }
    }

    m = A_size[0];
    s_data[y] = A_data[y + A_size[0] * y];
    if (A_size[0] < A_size[0] + 1) {
      s_data[A_size[0]] = 0.0;
    }

    e[A_size[0]] = 0.0;
    if (y + 1 <= A_size[0]) {
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
          f_xaxpy(qp1q + 1, -(d_xdotc(nmq, U_data, qq + 1, U_data, qjj) /
                              U_data[qq]), qq + 1, U_data, qjj);
        }

        for (ii = q; ii <= n; ii++) {
          qp1q = (ii + U_size[0] * (q - 1)) - 1;
          U_data[qp1q] = -U_data[qp1q];
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

    for (q = 31; q >= 0; q--) {
      if ((q + 1 <= n) && (e[q] != 0.0)) {
        qp1 = q + 2;
        qp1q = (q + (q << 5)) + 2;
        for (jj = qp1; jj < 33; jj++) {
          nmq = (q + ((jj - 1) << 5)) + 2;
          e_xaxpy(31 - q, -(c_xdotc(31 - q, Vf, qp1q, Vf, nmq) / Vf[qp1q - 1]),
                  qp1q, Vf, nmq);
        }
      }

      memset(&Vf[q * 32], 0, 32U * sizeof(double));
      Vf[q + (q << 5)] = 1.0;
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
        qp1q = (q + 1) << 5;
        jj = qp1q + 32;
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

          xrot(Vf, ((k - 1) << 5) + 1, (m << 5) + 1, sqds, sm);
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
          xrot(Vf, ((k - 1) << 5) + 1, (k << 5) + 1, sqds, sm);
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
          qp1q = ii << 5;
          jj = qp1q + 32;
          for (k = qp1q + 1; k <= jj; k++) {
            Vf[k - 1] = -Vf[k - 1];
          }
        }

        qp1 = ii + 1;
        while ((ii + 1 < n + 1) && (s_data[ii] < s_data[qp1])) {
          nrm = s_data[ii];
          s_data[ii] = s_data[qp1];
          s_data[qp1] = nrm;
          xswap(Vf, (ii << 5) + 1, ((ii + 1) << 5) + 1);
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

  S_size[0] = A_size[0];
  V_size[0] = 32;
  V_size[1] = A_size[0];
  for (k = 0; k < n; k++) {
    S_data[k] = s_data[k];
    memcpy(&V_data[k * 32], &Vf[k * 32], 32U * sizeof(double));
  }
}

/*
 * Arguments    : double A[128]
 *                double U[16]
 *                double S[4]
 *                double V[128]
 * Return Type  : void
 */
void xzsvdc(double A[128], double U[16], double S[4], double V[128])
{
  double e[32];
  double work[4];
  double Vf[1024];
  bool apply_transform;
  double nrm;
  double s[5];
  int k;
  int qjj;
  double r;
  int m;
  int q;
  int qp1;
  int qp1jj;
  int qq;
  double snorm;
  int exitg1;
  bool exitg2;
  double scale;
  double sm;
  double sqds;
  double b;
  memset(&e[0], 0, 32U * sizeof(double));
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  work[3] = 0.0;
  memset(&U[0], 0, 16U * sizeof(double));
  memset(&Vf[0], 0, 1024U * sizeof(double));
  apply_transform = false;
  nrm = xnrm2(4, A, 1);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[0] < 0.0) {
      nrm = -nrm;
    }

    if (fabs(nrm) >= 1.0020841800044864E-292) {
      r = 1.0 / nrm;
      for (k = 1; k < 5; k++) {
        A[k - 1] *= r;
      }
    } else {
      for (k = 1; k < 5; k++) {
        A[k - 1] /= nrm;
      }
    }

    A[0]++;
    s[0] = -nrm;
  } else {
    s[0] = 0.0;
  }

  for (k = 2; k < 33; k++) {
    qjj = (k - 1) << 2;
    if (apply_transform) {
      xaxpy(4, -(xdotc(4, A, 1, A, qjj + 1) / A[0]), 1, A, qjj + 1);
    }

    e[k - 1] = A[qjj];
  }

  for (k = 1; k < 5; k++) {
    U[k - 1] = A[k - 1];
  }

  nrm = b_xnrm2(31, e, 2);
  if (nrm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      e[0] = -nrm;
    } else {
      e[0] = nrm;
    }

    r = e[0];
    if (fabs(e[0]) >= 1.0020841800044864E-292) {
      r = 1.0 / e[0];
      for (k = 2; k < 33; k++) {
        e[k - 1] *= r;
      }
    } else {
      for (k = 2; k < 33; k++) {
        e[k - 1] /= r;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (k = 2; k < 5; k++) {
      work[k - 1] = 0.0;
    }

    for (k = 2; k < 33; k++) {
      b_xaxpy(3, e[k - 1], A, ((k - 1) << 2) + 2, work, 2);
    }

    for (k = 2; k < 33; k++) {
      c_xaxpy(3, -e[k - 1] / e[1], work, 2, A, ((k - 1) << 2) + 2);
    }
  }

  memcpy(&Vf[1], &e[1], 31U * sizeof(double));
  apply_transform = false;
  nrm = xnrm2(3, A, 6);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[5] < 0.0) {
      nrm = -nrm;
    }

    if (fabs(nrm) >= 1.0020841800044864E-292) {
      r = 1.0 / nrm;
      for (k = 6; k < 9; k++) {
        A[k - 1] *= r;
      }
    } else {
      for (k = 6; k < 9; k++) {
        A[k - 1] /= nrm;
      }
    }

    A[5]++;
    s[1] = -nrm;
  } else {
    s[1] = 0.0;
  }

  for (k = 3; k < 33; k++) {
    qjj = ((k - 1) << 2) + 1;
    if (apply_transform) {
      xaxpy(3, -(xdotc(3, A, 6, A, qjj + 1) / A[5]), 6, A, qjj + 1);
    }

    e[k - 1] = A[qjj];
  }

  for (k = 2; k < 5; k++) {
    U[k + 3] = A[k + 3];
  }

  nrm = b_xnrm2(30, e, 3);
  if (nrm == 0.0) {
    e[1] = 0.0;
  } else {
    if (e[2] < 0.0) {
      e[1] = -nrm;
    } else {
      e[1] = nrm;
    }

    r = e[1];
    if (fabs(e[1]) >= 1.0020841800044864E-292) {
      r = 1.0 / e[1];
      for (k = 3; k < 33; k++) {
        e[k - 1] *= r;
      }
    } else {
      for (k = 3; k < 33; k++) {
        e[k - 1] /= r;
      }
    }

    e[2]++;
    e[1] = -e[1];
    for (k = 3; k < 5; k++) {
      work[k - 1] = 0.0;
    }

    for (k = 3; k < 33; k++) {
      b_xaxpy(2, e[k - 1], A, ((k - 1) << 2) + 3, work, 3);
    }

    for (k = 3; k < 33; k++) {
      c_xaxpy(2, -e[k - 1] / e[2], work, 3, A, ((k - 1) << 2) + 3);
    }
  }

  memcpy(&Vf[34], &e[2], 30U * sizeof(double));
  apply_transform = false;
  nrm = xnrm2(2, A, 11);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[10] < 0.0) {
      nrm = -nrm;
    }

    if (fabs(nrm) >= 1.0020841800044864E-292) {
      r = 1.0 / nrm;
      for (k = 11; k < 13; k++) {
        A[k - 1] *= r;
      }
    } else {
      for (k = 11; k < 13; k++) {
        A[k - 1] /= nrm;
      }
    }

    A[10]++;
    s[2] = -nrm;
  } else {
    s[2] = 0.0;
  }

  for (k = 4; k < 33; k++) {
    qjj = ((k - 1) << 2) + 2;
    if (apply_transform) {
      xaxpy(2, -(xdotc(2, A, 11, A, qjj + 1) / A[10]), 11, A, qjj + 1);
    }

    e[k - 1] = A[qjj];
  }

  for (k = 3; k < 5; k++) {
    U[k + 7] = A[k + 7];
  }

  nrm = b_xnrm2(29, e, 4);
  if (nrm == 0.0) {
    e[2] = 0.0;
  } else {
    if (e[3] < 0.0) {
      e[2] = -nrm;
    } else {
      e[2] = nrm;
    }

    r = e[2];
    if (fabs(e[2]) >= 1.0020841800044864E-292) {
      r = 1.0 / e[2];
      for (k = 4; k < 33; k++) {
        e[k - 1] *= r;
      }
    } else {
      for (k = 4; k < 33; k++) {
        e[k - 1] /= r;
      }
    }

    e[3]++;
    e[2] = -e[2];
    work[3] = 0.0;
    for (k = 4; k < 33; k++) {
      b_xaxpy(1, e[k - 1], A, ((k - 1) << 2) + 4, work, 4);
    }

    for (k = 4; k < 33; k++) {
      c_xaxpy(1, -e[k - 1] / e[3], work, 4, A, ((k - 1) << 2) + 4);
    }
  }

  memcpy(&Vf[67], &e[3], 29U * sizeof(double));
  for (k = 5; k < 33; k++) {
    e[k - 1] = A[((k - 1) << 2) + 3];
  }

  nrm = b_xnrm2(28, e, 5);
  if (nrm == 0.0) {
    e[3] = 0.0;
  } else {
    if (e[4] < 0.0) {
      e[3] = -nrm;
    } else {
      e[3] = nrm;
    }

    r = e[3];
    if (fabs(e[3]) >= 1.0020841800044864E-292) {
      r = 1.0 / e[3];
      for (k = 5; k < 33; k++) {
        e[k - 1] *= r;
      }
    } else {
      for (k = 5; k < 33; k++) {
        e[k - 1] /= r;
      }
    }

    e[4]++;
    e[3] = -e[3];
  }

  memcpy(&Vf[100], &e[4], 28U * sizeof(double));
  m = 3;
  s[3] = A[15];
  s[4] = 0.0;
  e[4] = 0.0;
  U[12] = 0.0;
  U[13] = 0.0;
  U[14] = 0.0;
  U[15] = 1.0;
  for (q = 2; q >= 0; q--) {
    qp1 = q + 2;
    qp1jj = q << 2;
    qq = q + qp1jj;
    if (s[q] != 0.0) {
      for (k = qp1; k < 5; k++) {
        qjj = (q + ((k - 1) << 2)) + 1;
        d_xaxpy(4 - q, -(b_xdotc(4 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
                qjj);
      }

      for (k = q + 1; k < 5; k++) {
        qjj = (k + qp1jj) - 1;
        U[qjj] = -U[qjj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + qp1jj] = 0.0;
      }
    } else {
      U[qp1jj] = 0.0;
      U[qp1jj + 1] = 0.0;
      U[qp1jj + 2] = 0.0;
      U[qp1jj + 3] = 0.0;
      U[qq] = 1.0;
    }
  }

  for (q = 31; q >= 0; q--) {
    if ((q + 1 <= 4) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (q << 5)) + 2;
      for (k = qp1; k < 33; k++) {
        qp1jj = (q + ((k - 1) << 5)) + 2;
        e_xaxpy(31 - q, -(c_xdotc(31 - q, Vf, qjj, Vf, qp1jj) / Vf[qjj - 1]),
                qjj, Vf, qp1jj);
      }
    }

    memset(&Vf[q * 32], 0, 32U * sizeof(double));
    Vf[q + (q << 5)] = 1.0;
  }

  qp1 = 0;
  snorm = 0.0;
  for (q = 0; q < 5; q++) {
    if (s[q] != 0.0) {
      nrm = fabs(s[q]);
      r = s[q] / nrm;
      s[q] = nrm;
      if (q + 1 < 5) {
        e[q] /= r;
      }

      if (q + 1 <= 4) {
        qjj = q << 2;
        qp1jj = qjj + 4;
        for (k = qjj + 1; k <= qp1jj; k++) {
          U[k - 1] *= r;
        }
      }
    }

    if ((q + 1 < 5) && (e[q] != 0.0)) {
      nrm = fabs(e[q]);
      r = nrm / e[q];
      e[q] = nrm;
      s[q + 1] *= r;
      qjj = (q + 1) << 5;
      qp1jj = qjj + 32;
      for (k = qjj + 1; k <= qp1jj; k++) {
        Vf[k - 1] *= r;
      }
    }

    snorm = fmax(snorm, fmax(fabs(s[q]), fabs(e[q])));
  }

  while ((m + 2 > 0) && (qp1 < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s[k]) + fabs(s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((qp1 > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);

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

        xrot(Vf, ((k - 1) << 5) + 1, ((m + 1) << 5) + 1, sm, sqds);
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
        b_xrot(U, ((k - 1) << 2) + 1, ((q - 1) << 2) + 1, sm, sqds);
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
        xrot(Vf, ((k - 1) << 5) + 1, (k << 5) + 1, sm, sqds);
        s[k - 1] = sm * b + sqds * nrm;
        xrotg(&s[k - 1], &r, &sm, &sqds);
        r = sm * e[k - 1] + sqds * s[k];
        s[k] = -sqds * e[k - 1] + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        if (k < 4) {
          b_xrot(U, ((k - 1) << 2) + 1, (k << 2) + 1, sm, sqds);
        }
      }

      e[m] = r;
      qp1++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        qjj = q << 5;
        qp1jj = qjj + 32;
        for (k = qjj + 1; k <= qp1jj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 5) && (s[q] < s[qp1])) {
        nrm = s[q];
        s[q] = s[qp1];
        s[qp1] = nrm;
        xswap(Vf, (q << 5) + 1, ((q + 1) << 5) + 1);
        if (q + 1 < 4) {
          b_xswap(U, (q << 2) + 1, ((q + 1) << 2) + 1);
        }

        q = qp1;
        qp1++;
      }

      qp1 = 0;
      m--;
      break;
    }
  }

  for (k = 0; k < 4; k++) {
    S[k] = s[k];
    memcpy(&V[k * 32], &Vf[k * 32], 32U * sizeof(double));
  }
}

/*
 * File trailer for xzsvdc.c
 *
 * [EOF]
 */
