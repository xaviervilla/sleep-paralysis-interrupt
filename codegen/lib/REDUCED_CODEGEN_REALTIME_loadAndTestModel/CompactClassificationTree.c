/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 09-Dec-2019 01:55:25
 */

/* Include Files */
#include "CompactClassificationTree.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double obj_Children[6]
 *                const double obj_CutPoint[3]
 *                const double obj_PruneList_data[]
 *                const bool obj_NanCutPoints[3]
 *                const double obj_ClassNames[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[6]
 *                const double X[24]
 *                double labels[4]
 * Return Type  : void
 */
void c_CompactClassificationTree_pre(const double obj_Children[6], const double
  obj_CutPoint[3], const double obj_PruneList_data[], const bool
  obj_NanCutPoints[3], const double obj_ClassNames[2], const double obj_Cost[4],
  const double obj_ClassProbability[6], const double X[24], double labels[4])
{
  int m;
  signed char node[4];
  int obj_ClassProbability_tmp;
  double b_obj_ClassProbability[8];
  double d;
  double d1;
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[0]) || obj_NanCutPoints[m]))
  {
    if (X[0] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  node[0] = (signed char)(m + 1);
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[1]) || obj_NanCutPoints[m]))
  {
    if (X[1] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  node[1] = (signed char)(m + 1);
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[2]) || obj_NanCutPoints[m]))
  {
    if (X[2] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  node[2] = (signed char)(m + 1);
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[3]) || obj_NanCutPoints[m]))
  {
    if (X[3] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  node[3] = (signed char)(m + 1);
  for (m = 0; m < 2; m++) {
    obj_ClassProbability_tmp = m << 2;
    b_obj_ClassProbability[obj_ClassProbability_tmp] = obj_ClassProbability
      [(node[0] + 3 * m) - 1];
    b_obj_ClassProbability[obj_ClassProbability_tmp + 1] = obj_ClassProbability
      [(node[1] + 3 * m) - 1];
    b_obj_ClassProbability[obj_ClassProbability_tmp + 2] = obj_ClassProbability
      [(node[2] + 3 * m) - 1];
    b_obj_ClassProbability[obj_ClassProbability_tmp + 3] = obj_ClassProbability
      [(node[3] + 3 * m) - 1];
  }

  for (m = 0; m < 4; m++) {
    d = b_obj_ClassProbability[m + 4];
    d1 = b_obj_ClassProbability[m] * obj_Cost[0] + d * obj_Cost[1];
    d = b_obj_ClassProbability[m] * obj_Cost[2] + d * obj_Cost[3];
    if ((d1 > d) || (rtIsNaN(d1) && (!rtIsNaN(d)))) {
      obj_ClassProbability_tmp = 2;
    } else {
      obj_ClassProbability_tmp = 1;
    }

    node[m] = (signed char)obj_ClassProbability_tmp;
  }

  labels[0] = obj_ClassNames[node[0] - 1];
  labels[1] = obj_ClassNames[node[1] - 1];
  labels[2] = obj_ClassNames[node[2] - 1];
  labels[3] = obj_ClassNames[node[3] - 1];
}

/*
 * File trailer for CompactClassificationTree.c
 *
 * [EOF]
 */
