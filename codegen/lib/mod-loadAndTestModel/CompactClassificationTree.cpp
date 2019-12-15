/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 15-Dec-2019 01:21:20
 */

/* Include Files */
#include "CompactClassificationTree.h"
#include "loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double obj_CutPredictorIndex[11]
 *                const double obj_Children[22]
 *                const double obj_CutPoint[11]
 *                const double obj_PruneList_data[]
 *                const bool obj_NanCutPoints[11]
 *                const double obj_ClassNames[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[22]
 *                const double X[18]
 *                double labels[2]
 * Return Type  : void
 */
void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[11],
  const double obj_Children[22], const double obj_CutPoint[11], const double
  obj_PruneList_data[], const bool obj_NanCutPoints[11], const double
  obj_ClassNames[2], const double obj_Cost[4], const double
  obj_ClassProbability[22], const double X[18], double labels[2])
{
  int m;
  signed char node[2];
  double b_obj_ClassProbability[4];
  double d;
  double d1;
  int iidx;
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[((int)
            obj_CutPredictorIndex[m] - 1) << 1]) || obj_NanCutPoints[m])) {
    if (X[((int)obj_CutPredictorIndex[m] - 1) << 1] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  node[0] = (signed char)(m + 1);
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[(((int)
             obj_CutPredictorIndex[m] - 1) << 1) + 1]) || obj_NanCutPoints[m]))
  {
    if (X[(((int)obj_CutPredictorIndex[m] - 1) << 1) + 1] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  node[1] = (signed char)(m + 1);
  b_obj_ClassProbability[0] = obj_ClassProbability[node[0] - 1];
  b_obj_ClassProbability[1] = obj_ClassProbability[node[1] - 1];
  b_obj_ClassProbability[2] = obj_ClassProbability[node[0] + 10];
  b_obj_ClassProbability[3] = obj_ClassProbability[node[1] + 10];
  for (m = 0; m < 2; m++) {
    d = b_obj_ClassProbability[m + 2];
    d1 = b_obj_ClassProbability[m] * obj_Cost[0] + d * obj_Cost[1];
    d = b_obj_ClassProbability[m] * obj_Cost[2] + d * obj_Cost[3];
    if ((d1 > d) || (rtIsNaN(d1) && (!rtIsNaN(d)))) {
      iidx = 2;
    } else {
      iidx = 1;
    }

    node[m] = (signed char)iidx;
  }

  labels[0] = obj_ClassNames[node[0] - 1];
  labels[1] = obj_ClassNames[node[1] - 1];
}

/*
 * File trailer for CompactClassificationTree.c
 *
 * [EOF]
 */
