/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationTree.c
 *
 * Code generation for function 'CompactClassificationTree'
 *
 */

/* Include files */
#include "CompactClassificationTree.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[17],
  const double obj_Children[34], const double obj_CutPoint[17], const double
  obj_PruneList_data[], const bool obj_NanCutPoints[17], const double
  obj_ClassNames[4], const double obj_Cost[16], const double
  obj_ClassProbability[68], const double X[96], double labels[16])
{
  int n;
  int i;
  int m;
  signed char node[16];
  double d;
  double b_obj_ClassProbability[64];
  double ex;
  double unusedU4[64];
  double d1;
  int k;
  bool exitg1;
  for (n = 0; n < 16; n++) {
    m = 0;
    while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[n + (((int)
               obj_CutPredictorIndex[m] - 1) << 4)]) || obj_NanCutPoints[m])) {
      if (X[n + (((int)obj_CutPredictorIndex[m] - 1) << 4)] < obj_CutPoint[m]) {
        m = (int)obj_Children[m << 1] - 1;
      } else {
        m = (int)obj_Children[(m << 1) + 1] - 1;
      }
    }

    node[n] = (signed char)(m + 1);
  }

  for (i = 0; i < 4; i++) {
    for (n = 0; n < 16; n++) {
      b_obj_ClassProbability[n + (i << 4)] = obj_ClassProbability[(node[n] + 17 *
        i) - 1];
    }
  }

  for (i = 0; i < 16; i++) {
    d = b_obj_ClassProbability[i + 16];
    ex = b_obj_ClassProbability[i + 32];
    d1 = b_obj_ClassProbability[i + 48];
    for (n = 0; n < 4; n++) {
      m = n << 2;
      unusedU4[i + (n << 4)] = ((b_obj_ClassProbability[i] * obj_Cost[m] + d *
        obj_Cost[m + 1]) + ex * obj_Cost[m + 2]) + d1 * obj_Cost[m + 3];
    }
  }

  for (n = 0; n < 16; n++) {
    if (!rtIsNaN(unusedU4[n])) {
      m = 1;
    } else {
      m = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (!rtIsNaN(unusedU4[n + ((k - 1) << 4)])) {
          m = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (m == 0) {
      m = 1;
    } else {
      ex = unusedU4[n + ((m - 1) << 4)];
      i = m + 1;
      for (k = i; k < 5; k++) {
        d = unusedU4[n + ((k - 1) << 4)];
        if (ex > d) {
          ex = d;
          m = k;
        }
      }
    }

    node[n] = (signed char)m;
    labels[n] = obj_ClassNames[node[n] - 1];
  }
}

/* End of code generation (CompactClassificationTree.c) */
