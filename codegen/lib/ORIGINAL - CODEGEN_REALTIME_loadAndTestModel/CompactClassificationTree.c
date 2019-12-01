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
#include "CODEGEN_REALTIME_loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[177],
  const double obj_Children[354], const double obj_CutPoint[177], const double
  obj_PruneList_data[], const bool obj_NanCutPoints[177], const double
  obj_ClassNames[5], const double obj_Cost[25], const double
  obj_ClassProbability[885], const double X[288], double labels[16])
{
  int n;
  int i;
  int m;
  unsigned char node[16];
  double b_obj_ClassProbability[80];
  double unusedU4[80];
  double d;
  int k;
  bool exitg1;
  double ex;
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

    node[n] = (unsigned char)(m + 1);
  }

  for (i = 0; i < 5; i++) {
    for (n = 0; n < 16; n++) {
      b_obj_ClassProbability[n + (i << 4)] = obj_ClassProbability[(node[n] + 177
        * i) - 1];
    }
  }

  for (i = 0; i < 16; i++) {
    for (n = 0; n < 5; n++) {
      d = 0.0;
      for (m = 0; m < 5; m++) {
        d += b_obj_ClassProbability[i + (m << 4)] * obj_Cost[m + 5 * n];
      }

      unusedU4[i + (n << 4)] = d;
    }
  }

  for (n = 0; n < 16; n++) {
    if (!rtIsNaN(unusedU4[n])) {
      m = 1;
    } else {
      m = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 6)) {
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
      for (k = i; k < 6; k++) {
        d = unusedU4[n + ((k - 1) << 4)];
        if (ex > d) {
          ex = d;
          m = k;
        }
      }
    }

    node[n] = (unsigned char)m;
    labels[n] = obj_ClassNames[node[n] - 1];
  }
}

/* End of code generation (CompactClassificationTree.c) */
