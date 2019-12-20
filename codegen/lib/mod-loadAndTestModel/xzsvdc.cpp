/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzsvdc.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 19-Dec-2019 22:31:39
 */

/* Include Files */
#include "xzsvdc.h"
#include "loadAndTestModel.h"
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
  int qjj;
  double s_data[3];
  double e[32];
  double work_data[2];
  double Vf[1024];
  int y;
  int ii;
  int i;
  int q;
  int m;
  int qp1;
  int qq;
  int nmq;
  int k;
  bool apply_transform;
  double nrm;
  double r;
  double snorm;
  bool exitg1;
  double scale;
  double sm;
  double sqds;
  double b;
  n = A_size[0];
  qjj = (signed char)(A_size[0] + 1);
  if (0 <= qjj - 1) {
    memset(&s_data[0], 0, qjj * sizeof(double));
  }

  memset(&e[0], 0, 32U * sizeof(double));
  qjj = (signed char)A_size[0];
  if (0 <= qjj - 1) {
    memset(&work_data[0], 0, qjj * sizeof(double));
  }

  U_size[0] = (signed char)A_size[0];
  U_size[1] = (signed char)A_size[0];
  qjj = (signed char)A_size[0] * (signed char)A_size[0];
  if (0 <= qjj - 1) {
    memset(&U_data[0], 0, qjj * sizeof(double));
  }

  memset(&Vf[0], 0, 1024U * sizeof(double));
  if (A_size[0] == 0) {
    for (ii = 0; ii < 32; ii++) {
      Vf[ii + (ii << 5)] = 1.0;
    }
  } else {
    y = (A_size[0] > 1);
    i = A_size[0];
    for (q = 0; q < i; q++) {
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
            s_data[0] = -nrm;
          } else {
            r = nrm;
            s_data[0] = nrm;
          }

          if (fabs(r) >= 1.0020841800044864E-292) {
            nrm = 1.0 / r;
            qjj = (qq + nmq) - 1;
            for (k = qq; k <= qjj; k++) {
              A_data[k - 1] *= nrm;
            }
          } else {
            qjj = (qq + nmq) - 1;
            for (k = qq; k <= qjj; k++) {
              A_data[k - 1] /= s_data[0];
            }
          }

          A_data[qq - 1]++;
          s_data[0] = -s_data[0];
        } else {
          s_data[0] = 0.0;
        }
      }

      for (k = qp1; k < 33; k++) {
        qjj = q + n * (k - 1);
        if (apply_transform) {
          f_xaxpy(nmq, -(d_xdotc(nmq, A_data, qq, A_data, qjj + 1) / A_data[q +
                         A_size[0] * q]), qq, A_data, qjj + 1);
        }

        e[k - 1] = A_data[qjj];
      }

      if ((q + 1 <= y) && (1 <= n)) {
        memcpy(&U_data[0], &A_data[0], n * sizeof(double));
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
            work_data[1] = 0.0;
            for (k = 0; k < 31; k++) {
              g_xaxpy(nmq - 1, e[k + 1], A_data, ((k + 1) << 1) + 2, work_data);
            }

            for (k = 0; k < 31; k++) {
              h_xaxpy(nmq - 1, -e[k + 1] / e[1], work_data, A_data, ((k + 1) <<
                       1) + 2);
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
      for (k = y + 1; k <= n; k++) {
        for (ii = 0; ii < n; ii++) {
          U_data[ii + U_size[0] * (k - 1)] = 0.0;
        }

        U_data[(k + U_size[0] * (k - 1)) - 1] = 1.0;
      }
    }

    for (q = y; q >= 1; q--) {
      if (s_data[0] != 0.0) {
        for (k = 2; k <= n; k++) {
          i_xaxpy(n, -(e_xdotc(n, U_data, U_data, n + 1) / U_data[0]), U_data, n
                  + 1);
        }

        for (ii = 1; ii <= n; ii++) {
          U_data[ii - 1] = -U_data[ii - 1];
        }

        U_data[0]++;
      } else {
        if (0 <= n - 1) {
          memset(&U_data[0], 0, n * sizeof(double));
        }

        U_data[0] = 1.0;
      }
    }

    for (q = 31; q >= 0; q--) {
      if ((q + 1 <= n) && (e[q] != 0.0)) {
        qp1 = q + 2;
        qjj = (q + (q << 5)) + 2;
        for (k = qp1; k < 33; k++) {
          qq = (q + ((k - 1) << 5)) + 2;
          e_xaxpy(31 - q, -(c_xdotc(31 - q, Vf, qjj, Vf, qq) / Vf[qjj - 1]), qjj,
                  Vf, qq);
        }
      }

      memset(&Vf[q * 32], 0, 32U * sizeof(double));
      Vf[q + (q << 5)] = 1.0;
    }

    nmq = 0;
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
          qjj = n * q;
          i = qjj + n;
          for (k = qjj + 1; k <= i; k++) {
            U_data[k - 1] *= r;
          }
        }
      }

      if ((q + 1 < n + 1) && (e[q] != 0.0)) {
        nrm = fabs(e[q]);
        r = nrm / e[q];
        e[q] = nrm;
        s_data[q + 1] *= r;
        qjj = (q + 1) << 5;
        i = qjj + 32;
        for (k = qjj + 1; k <= i; k++) {
          Vf[k - 1] *= r;
        }
      }

      snorm = fmax(snorm, fmax(fabs(s_data[q]), fabs(e[q])));
    }

    while ((m + 1 > 0) && (nmq < 75)) {
      ii = m;
      exitg1 = false;
      while (!(exitg1 || (ii == 0))) {
        nrm = fabs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s_data[ii - 1]) + fabs
              (s_data[ii]))) || (nrm <= 1.0020841800044864E-292) || ((nmq > 20) &&
             (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg1 = true;
        } else {
          ii--;
        }
      }

      if (ii == m) {
        qjj = 4;
      } else {
        qq = m + 1;
        qjj = m + 1;
        exitg1 = false;
        while ((!exitg1) && (qjj >= ii)) {
          qq = qjj;
          if (qjj == ii) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (qjj < m + 1) {
              nrm = fabs(e[qjj - 1]);
            }

            if (qjj > ii + 1) {
              nrm += fabs(e[qjj - 2]);
            }

            r = fabs(s_data[qjj - 1]);
            if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
                 1.0020841800044864E-292)) {
              s_data[qjj - 1] = 0.0;
              exitg1 = true;
            } else {
              qjj--;
            }
          }
        }

        if (qq == ii) {
          qjj = 3;
        } else if (qq == m + 1) {
          qjj = 1;
        } else {
          qjj = 2;
          ii = qq;
        }
      }

      switch (qjj) {
       case 1:
        r = e[m - 1];
        e[m - 1] = 0.0;
        for (k = m; k >= ii + 1; k--) {
          xrotg(&s_data[k - 1], &r, &sqds, &sm);
          if (k > ii + 1) {
            r = -sm * e[0];
            e[0] *= sqds;
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
            e[0] = r;
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
            c_xrot(2, U_data, 1, 3, sqds, sm);
          }
        }

        e[m - 1] = r;
        nmq++;
        break;

       default:
        if (s_data[ii] < 0.0) {
          s_data[ii] = -s_data[ii];
          qjj = ii << 5;
          i = qjj + 32;
          for (k = qjj + 1; k <= i; k++) {
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
            c_xswap(U_data, n + 1);
          }

          ii = qp1;
          qp1++;
        }

        nmq = 0;
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
 * Arguments    : double A[64]
 *                double U[4]
 *                double S[2]
 *                double V[64]
 * Return Type  : void
 */
void xzsvdc(double A[64], double U[4], double S[2], double V[64])
{
  double s[3];
  double e[32];
  double work[2];
  double Vf[1024];
  int q;
  int m;
  int qp1;
  int qq;
  bool apply_transform;
  double nrm;
  int qs;
  int qjj;
  double r;
  int k;
  double snorm;
  int exitg1;
  bool exitg2;
  double scale;
  double sm;
  double sqds;
  double b;
  s[0] = 0.0;
  memset(&e[0], 0, 32U * sizeof(double));
  work[0] = 0.0;
  U[0] = 0.0;
  U[1] = 0.0;
  memset(&Vf[0], 0, 1024U * sizeof(double));
  for (q = 0; q < 2; q++) {
    qp1 = q + 2;
    qq = (q + (q << 1)) + 1;
    apply_transform = false;
    if (q + 1 <= 1) {
      nrm = xnrm2(2, A, qq);
      if (nrm > 0.0) {
        apply_transform = true;
        if (A[qq - 1] < 0.0) {
          nrm = -nrm;
        }

        if (fabs(nrm) >= 1.0020841800044864E-292) {
          r = 1.0 / nrm;
          qs = qq + 1;
          for (k = qq; k <= qs; k++) {
            A[k - 1] *= r;
          }
        } else {
          qs = qq + 1;
          for (k = qq; k <= qs; k++) {
            A[k - 1] /= nrm;
          }
        }

        A[qq - 1]++;
        s[0] = -nrm;
      } else {
        s[0] = 0.0;
      }
    }

    for (qs = qp1; qs < 33; qs++) {
      qjj = q + ((qs - 1) << 1);
      if (apply_transform) {
        xaxpy(2 - q, -(xdotc(2 - q, A, qq, A, qjj + 1) / A[q + (q << 1)]), qq, A,
              qjj + 1);
      }

      e[qs - 1] = A[qjj];
    }

    if (q + 1 <= 1) {
      U[0] = A[0];
      U[1] = A[1];
    }

    nrm = b_xnrm2(31 - q, e, q + 2);
    if (nrm == 0.0) {
      e[q] = 0.0;
    } else {
      if (e[q + 1] < 0.0) {
        e[q] = -nrm;
      } else {
        e[q] = nrm;
      }

      r = e[q];
      if (fabs(e[q]) >= 1.0020841800044864E-292) {
        r = 1.0 / e[q];
        for (k = qp1; k < 33; k++) {
          e[k - 1] *= r;
        }
      } else {
        for (k = qp1; k < 33; k++) {
          e[k - 1] /= r;
        }
      }

      e[q + 1]++;
      e[q] = -e[q];
      if (q + 2 <= 2) {
        work[1] = 0.0;
        for (qs = 0; qs < 31; qs++) {
          b_xaxpy(1 - q, e[qs + 1], A, ((qs + 1) << 1) + 2, work);
        }

        for (qs = 0; qs < 31; qs++) {
          c_xaxpy(1 - q, -e[qs + 1] / e[1], work, A, ((qs + 1) << 1) + 2);
        }
      }
    }

    for (qq = qp1; qq < 33; qq++) {
      Vf[(qq + (q << 5)) - 1] = e[qq - 1];
    }
  }

  m = 1;
  s[1] = A[3];
  s[2] = 0.0;
  e[2] = 0.0;
  U[2] = 0.0;
  U[3] = 1.0;
  if (s[0] != 0.0) {
    d_xaxpy(-(b_xdotc(U, U) / U[0]), U);
    U[0] = -U[0];
    U[1] = -U[1];
    U[0]++;
  } else {
    U[1] = 0.0;
    U[0] = 1.0;
  }

  for (q = 31; q >= 0; q--) {
    if ((q + 1 <= 2) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (q << 5)) + 2;
      for (qs = qp1; qs < 33; qs++) {
        qq = (q + ((qs - 1) << 5)) + 2;
        e_xaxpy(31 - q, -(c_xdotc(31 - q, Vf, qjj, Vf, qq) / Vf[qjj - 1]), qjj,
                Vf, qq);
      }
    }

    memset(&Vf[q * 32], 0, 32U * sizeof(double));
    Vf[q + (q << 5)] = 1.0;
  }

  qp1 = 0;
  snorm = 0.0;
  for (q = 0; q < 3; q++) {
    if (s[q] != 0.0) {
      nrm = fabs(s[q]);
      r = s[q] / nrm;
      s[q] = nrm;
      if (q + 1 < 3) {
        e[q] /= r;
      }

      if (q + 1 <= 2) {
        qjj = q << 1;
        qs = qjj + 2;
        for (k = qjj + 1; k <= qs; k++) {
          U[k - 1] *= r;
        }
      }
    }

    if ((q + 1 < 3) && (e[q] != 0.0)) {
      nrm = fabs(e[q]);
      r = nrm / e[q];
      e[q] = nrm;
      s[q + 1] *= r;
      qjj = (q + 1) << 5;
      qs = qjj + 32;
      for (k = qjj + 1; k <= qs; k++) {
        Vf[k - 1] *= r;
      }
    }

    snorm = fmax(snorm, fmax(fabs(s[q]), fabs(e[q])));
  }

  while ((m + 2 > 0) && (qp1 < 75)) {
    qq = m;
    do {
      exitg1 = 0;
      q = qq + 1;
      if (qq + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[qq]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s[qq]) + fabs(s[qq + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((qp1 > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[qq] = 0.0;
          exitg1 = 1;
        } else {
          qq--;
        }
      }
    } while (exitg1 == 0);

    if (qq + 1 == m + 1) {
      qjj = 4;
    } else {
      qs = m + 2;
      qjj = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qjj >= qq + 1)) {
        qs = qjj;
        if (qjj == qq + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }

          if (qjj > qq + 2) {
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

      if (qs == qq + 1) {
        qjj = 3;
      } else if (qs == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        q = qs;
      }
    }

    switch (qjj) {
     case 1:
      r = e[m];
      e[m] = 0.0;
      qs = m + 1;
      for (k = qs; k >= q + 1; k--) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        if (k > q + 1) {
          r = -sqds * e[0];
          e[0] *= sm;
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
        b_xrot(U, ((k - 1) << 1) + 1, ((q - 1) << 1) + 1, sm, sqds);
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
          e[0] = r;
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
        if (k < 2) {
          b_xrot(U, 1, 3, sm, sqds);
        }
      }

      e[m] = r;
      qp1++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        qjj = q << 5;
        qs = qjj + 32;
        for (k = qjj + 1; k <= qs; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 3) && (s[q] < s[qp1])) {
        nrm = s[q];
        s[q] = s[qp1];
        s[qp1] = nrm;
        xswap(Vf, (q << 5) + 1, ((q + 1) << 5) + 1);
        if (q + 1 < 2) {
          b_xswap(U);
        }

        q = qp1;
        qp1++;
      }

      qp1 = 0;
      m--;
      break;
    }
  }

  for (k = 0; k < 2; k++) {
    S[k] = s[k];
    memcpy(&V[k * 32], &Vf[k * 32], 32U * sizeof(double));
  }
}

/*
 * File trailer for xzsvdc.c
 *
 * [EOF]
 */
