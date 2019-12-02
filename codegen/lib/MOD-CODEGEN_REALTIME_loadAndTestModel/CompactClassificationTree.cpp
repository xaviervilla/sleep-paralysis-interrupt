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
double c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[17],
  const double obj_Children[34], const double obj_CutPoint[17], const double
  obj_PruneList_data[], const bool obj_NanCutPoints[17], const double
  obj_ClassNames[4], const double obj_Cost[16], const double
  obj_ClassProbability[68], const double X[6])
{
  int m;
  int i;
  double unusedU4[4];
  int k;
  bool exitg1;
  double ex;
  double d;
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[(int)
           obj_CutPredictorIndex[m] - 1]) || obj_NanCutPoints[m])) {
    if (X[(int)obj_CutPredictorIndex[m] - 1] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    k = i << 2;
    unusedU4[i] = ((obj_ClassProbability[m] * obj_Cost[k] +
                    obj_ClassProbability[m + 17] * obj_Cost[k + 1]) +
                   obj_ClassProbability[m + 34] * obj_Cost[k + 2]) +
      obj_ClassProbability[m + 51] * obj_Cost[k + 3];
  }

  if (!rtIsNaN(unusedU4[0])) {
    m = 1;
  } else {
    m = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!rtIsNaN(unusedU4[k - 1])) {
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
    ex = unusedU4[m - 1];
    i = m + 1;
    for (k = i; k < 5; k++) {
      d = unusedU4[k - 1];
      if (ex > d) {
        ex = d;
        m = k;
      }
    }
  }

  return obj_ClassNames[m - 1];
}

/* End of code generation (CompactClassificationTree.c) */
