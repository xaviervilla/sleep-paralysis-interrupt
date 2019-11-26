/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Nov-2019 01:41:57
 */

/* Include Files */
#include "CompactClassificationTree.h"
#include "CODEGEN_standalonePredictor.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double obj_CutPredictorIndex[177]
 *                const double obj_Children[354]
 *                const double obj_CutPoint[177]
 *                const double obj_PruneList_data[]
 *                const boolean_T obj_NanCutPoints[177]
 *                const double obj_ClassNames[5]
 *                const double obj_Cost[25]
 *                const double obj_ClassProbability[885]
 *                const double X[18]
 * Return Type  : double
 */
double c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[177],
  const double obj_Children[354], const double obj_CutPoint[177], const double
  obj_PruneList_data[], const boolean_T obj_NanCutPoints[177], const double
  obj_ClassNames[5], const double obj_Cost[25], const double
  obj_ClassProbability[885], const double X[18])
{
  int m;
  int i;
  double unusedU4[5];
  double d;
  int k;
  boolean_T exitg1;
  double ex;
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[(int)
           obj_CutPredictorIndex[m] - 1]) || obj_NanCutPoints[m])) {
    if (X[(int)obj_CutPredictorIndex[m] - 1] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 5; i++) {
    d = 0.0;
    for (k = 0; k < 5; k++) {
      d += obj_ClassProbability[m + 177 * k] * obj_Cost[k + 5 * i];
    }

    unusedU4[i] = d;
  }

  if (!rtIsNaN(unusedU4[0])) {
    m = 1;
  } else {
    m = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
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
    for (k = i; k < 6; k++) {
      d = unusedU4[k - 1];
      if (ex > d) {
        ex = d;
        m = k;
      }
    }
  }

  return obj_ClassNames[m - 1];
}

/*
 * File trailer for CompactClassificationTree.c
 *
 * [EOF]
 */
