/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Wfreq.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 19-Dec-2019 22:53:17
 */

/* Include Files */
#include "Wfreq.h"
#include "loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double X[64]
 * Return Type  : double
 */
double Wfreq(const double X[64])
{
  double promFreq;
  double twid_re;
  int k;
  int iy;
  double Y[64];
  int ix;
  int ju;
  int i;
  creal_T b_y1[64];
  int iDelta2;
  bool tst;
  double d;
  double temp_re;
  double temp_im;
  double twid_im;
  double im;
  int temp_re_tmp;
  int j;
  bool exitg1;
  static const double dv[33] = { 1.0, 0.99518472667219693, 0.98078528040323043,
    0.95694033573220882, 0.92387953251128674, 0.881921264348355,
    0.83146961230254524, 0.773010453362737, 0.70710678118654757,
    0.63439328416364549, 0.55557023301960218, 0.47139673682599764,
    0.38268343236508978, 0.29028467725446233, 0.19509032201612825,
    0.0980171403295606, 0.0, -0.0980171403295606, -0.19509032201612825,
    -0.29028467725446233, -0.38268343236508978, -0.47139673682599764,
    -0.55557023301960218, -0.63439328416364549, -0.70710678118654757,
    -0.773010453362737, -0.83146961230254524, -0.881921264348355,
    -0.92387953251128674, -0.95694033573220882, -0.98078528040323043,
    -0.99518472667219693, -1.0 };

  static const double dv1[33] = { 0.0, -0.0980171403295606, -0.19509032201612825,
    -0.29028467725446233, -0.38268343236508978, -0.47139673682599764,
    -0.55557023301960218, -0.63439328416364549, -0.70710678118654757,
    -0.773010453362737, -0.83146961230254524, -0.881921264348355,
    -0.92387953251128674, -0.95694033573220882, -0.98078528040323043,
    -0.99518472667219693, -1.0, -0.99518472667219693, -0.98078528040323043,
    -0.95694033573220882, -0.92387953251128674, -0.881921264348355,
    -0.83146961230254524, -0.773010453362737, -0.70710678118654757,
    -0.63439328416364549, -0.55557023301960218, -0.47139673682599764,
    -0.38268343236508978, -0.29028467725446233, -0.19509032201612825,
    -0.0980171403295606, -0.0 };

  int ihi;

  /*  Number of samples: */
  /*  Number of seconds: */
  twid_re = X[0];
  for (k = 0; k < 63; k++) {
    twid_re += X[k + 1];
  }

  twid_re /= 64.0;
  for (iy = 0; iy < 64; iy++) {
    Y[iy] = X[iy] - twid_re;
  }

  /*  100% this works correctly */
  /*      figure */
  /*      plot(t,Y) */
  /*      title('Panic Breathing Signal with Noise') */
  /*      xlabel('time (seconds)') */
  /*      hold off */
  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 63; i++) {
    b_y1[iy].re = Y[ix];
    b_y1[iy].im = 0.0;
    iDelta2 = 64;
    tst = true;
    while (tst) {
      iDelta2 >>= 1;
      ju ^= iDelta2;
      tst = ((ju & iDelta2) == 0);
    }

    iy = ju;
    ix++;
  }

  b_y1[iy].re = Y[ix];
  b_y1[iy].im = 0.0;
  for (i = 0; i <= 62; i += 2) {
    d = b_y1[i + 1].re;
    temp_re = d;
    twid_re = b_y1[i + 1].im;
    temp_im = twid_re;
    twid_im = b_y1[i].re;
    im = b_y1[i].im;
    d = b_y1[i].re - d;
    b_y1[i + 1].re = d;
    twid_re = b_y1[i].im - twid_re;
    b_y1[i + 1].im = twid_re;
    b_y1[i].re = twid_im + temp_re;
    b_y1[i].im = im + temp_im;
  }

  iy = 2;
  iDelta2 = 4;
  k = 16;
  ix = 61;
  while (k > 0) {
    for (i = 0; i < ix; i += iDelta2) {
      temp_re_tmp = i + iy;
      temp_re = b_y1[temp_re_tmp].re;
      temp_im = b_y1[temp_re_tmp].im;
      b_y1[temp_re_tmp].re = b_y1[i].re - b_y1[temp_re_tmp].re;
      b_y1[temp_re_tmp].im = b_y1[i].im - b_y1[temp_re_tmp].im;
      b_y1[i].re += temp_re;
      b_y1[i].im += temp_im;
    }

    ju = 1;
    for (j = k; j < 32; j += k) {
      twid_re = dv[j];
      twid_im = dv1[j];
      i = ju;
      ihi = ju + ix;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * b_y1[temp_re_tmp].re - twid_im * b_y1[temp_re_tmp].
          im;
        temp_im = twid_re * b_y1[temp_re_tmp].im + twid_im * b_y1[temp_re_tmp].
          re;
        b_y1[temp_re_tmp].re = b_y1[i].re - temp_re;
        b_y1[temp_re_tmp].im = b_y1[i].im - temp_im;
        b_y1[i].re += temp_re;
        b_y1[i].im += temp_im;
        i += iDelta2;
      }

      ju++;
    }

    k /= 2;
    iy = iDelta2;
    iDelta2 += iDelta2;
    ix -= iy;
  }

  for (iy = 0; iy < 64; iy++) {
    twid_re = b_y1[iy].re * b_y1[iy].re - b_y1[iy].im * -b_y1[iy].im;
    if (b_y1[iy].re * -b_y1[iy].im + b_y1[iy].im * b_y1[iy].re == 0.0) {
      twid_re /= 64.0;
    } else if (twid_re == 0.0) {
      twid_re = 0.0;
    } else {
      twid_re /= 64.0;
    }

    Y[iy] = twid_re;
  }

  if (!rtIsNaN(Y[0])) {
    iDelta2 = 1;
  } else {
    iDelta2 = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 65)) {
      if (!rtIsNaN(Y[k - 1])) {
        iDelta2 = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (iDelta2 == 0) {
    iDelta2 = 1;
  } else {
    twid_re = Y[iDelta2 - 1];
    iy = iDelta2 + 1;
    for (k = iy; k < 65; k++) {
      d = Y[k - 1];
      if (twid_re < d) {
        twid_re = d;
        iDelta2 = k;
      }
    }
  }

  promFreq = 0.5 * ((double)iDelta2 - 1.0) + 0.5;

  /*      figure */
  /*      plot(f(1:32),Pyy(1:32)) */
  /*      hold on */
  /*      plot(f(loc),pk,'or') */
  /*      title('Frequency component of Panic Breathing') */
  /*      xlabel('frequency (Hz)') */
  return promFreq;
}

/*
 * File trailer for Wfreq.c
 *
 * [EOF]
 */
