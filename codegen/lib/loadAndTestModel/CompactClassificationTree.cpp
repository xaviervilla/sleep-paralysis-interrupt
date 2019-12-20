/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 19-Dec-2019 22:53:17
 */

/* Include Files */
#include "CompactClassificationTree.h"
#include "loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double obj_CutPredictorIndex[21]
 *                const double obj_Children[42]
 *                const double obj_CutPoint[21]
 *                const double obj_PruneList_data[]
 *                const bool obj_NanCutPoints[21]
 *                const double obj_ClassNames[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[42]
 *                const double X[12]
 * Return Type  : double
 */
double c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[21],
  const double obj_Children[42], const double obj_CutPoint[21], const double
  obj_PruneList_data[], const bool obj_NanCutPoints[21], const double
  obj_ClassNames[2], const double obj_Cost[4], const double
  obj_ClassProbability[42], const double X[12])
{
  int m;
  double unusedU4_idx_1;
  double unusedU4_idx_0;
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[(int)
           obj_CutPredictorIndex[m] - 1]) || obj_NanCutPoints[m])) {
    if (X[(int)obj_CutPredictorIndex[m] - 1] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  unusedU4_idx_1 = obj_ClassProbability[m + 21];
  unusedU4_idx_0 = obj_ClassProbability[m] * obj_Cost[0] + unusedU4_idx_1 *
    obj_Cost[1];
  unusedU4_idx_1 = obj_ClassProbability[m] * obj_Cost[2] + unusedU4_idx_1 *
    obj_Cost[3];
  if ((unusedU4_idx_0 > unusedU4_idx_1) || (rtIsNaN(unusedU4_idx_0) && (!rtIsNaN
        (unusedU4_idx_1)))) {
    m = 1;
  } else {
    m = 0;
  }

  return obj_ClassNames[m];
}

/*
 * File trailer for CompactClassificationTree.c
 *
 * [EOF]
 */
