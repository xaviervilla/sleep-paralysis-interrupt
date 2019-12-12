/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 11-Dec-2019 20:06:08
 */

/* Include Files */
#include "CompactClassificationTree.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : double obj_CutPredictorIndex[9]
 *                double obj_Children[18]
 *                double obj_CutPoint[9]
 *                double obj_PruneList_data[]
 *                int obj_PruneList_size[1]
 *                bool obj_NanCutPoints[9]
 *                bool obj_InfCutPoints[9]
 *                double obj_ClassNames[2]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                bool obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[18]
 * Return Type  : void
 */
void c_CompactClassificationTree_Com(double obj_CutPredictorIndex[9], double
  obj_Children[18], double obj_CutPoint[9], double obj_PruneList_data[], int
  obj_PruneList_size[1], bool obj_NanCutPoints[9], bool obj_InfCutPoints[9],
  double obj_ClassNames[2], int obj_ClassNamesLength[2],
  c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2], bool
  obj_ClassLogicalIndices[2], double obj_Cost[4], double obj_ClassProbability[18])
{
  static const double dv[9] = { 4865.8001042878095, 10989.470330014927, 0.0, 0.0,
    41921.429212909192, -41853.056813355208, 0.0, 0.0, 0.0 };

  int i;
  static const double dv1[18] = { 0.87547169811320757, 0.95473251028806583, 0.0,
    1.0, 0.75555555555555565, 0.87179487179487181, 0.0, 0.0, 0.97142857142857142,
    0.12452830188679245, 0.045267489711934158, 1.0, 0.0, 0.24444444444444444,
    0.12820512820512819, 1.0, 1.0, 0.028571428571428571 };

  static const bool bv[9] = { false, false, true, true, false, false, true, true,
    true };

  static const signed char iv[9] = { 1, 6, 0, 0, 8, 7, 0, 0, 0 };

  static const signed char iv1[18] = { 2, 3, 4, 5, 0, 0, 0, 0, 6, 7, 8, 9, 0, 0,
    0, 0, 0, 0 };

  static const signed char iv2[9] = { 2, 1, 0, 0, 1, 1, 0, 0, 0 };

  memcpy(&obj_CutPoint[0], &dv[0], 9U * sizeof(double));
  for (i = 0; i < 9; i++) {
    obj_NanCutPoints[i] = bv[i];
  }

  memcpy(&obj_ClassProbability[0], &dv1[0], 18U * sizeof(double));
  obj_ClassNames[0] = 0.0;
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNames[1] = 1.0;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 9; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 18; i++) {
    obj_Children[i] = iv1[i];
  }

  obj_PruneList_size[0] = 9;
  for (i = 0; i < 9; i++) {
    obj_InfCutPoints[i] = false;
    obj_PruneList_data[i] = iv2[i];
  }

  obj_Prior[0] = 0.87547169811320757;
  obj_Prior[1] = 0.12452830188679245;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[9]
 *                const double obj_Children[18]
 *                const double obj_CutPoint[9]
 *                const double obj_PruneList_data[]
 *                const bool obj_NanCutPoints[9]
 *                const double obj_ClassNames[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[18]
 *                const double X[36]
 *                double labels[4]
 * Return Type  : void
 */
void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[9],
  const double obj_Children[18], const double obj_CutPoint[9], const double
  obj_PruneList_data[], const bool obj_NanCutPoints[9], const double
  obj_ClassNames[2], const double obj_Cost[4], const double
  obj_ClassProbability[18], const double X[36], double labels[4])
{
  int m;
  signed char node[4];
  int obj_ClassProbability_tmp;
  double b_obj_ClassProbability[8];
  double d;
  double d1;
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[((int)
            obj_CutPredictorIndex[m] - 1) << 2]) || obj_NanCutPoints[m])) {
    if (X[((int)obj_CutPredictorIndex[m] - 1) << 2] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  node[0] = (signed char)(m + 1);
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[(((int)
             obj_CutPredictorIndex[m] - 1) << 2) + 1]) || obj_NanCutPoints[m]))
  {
    if (X[(((int)obj_CutPredictorIndex[m] - 1) << 2) + 1] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  node[1] = (signed char)(m + 1);
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[(((int)
             obj_CutPredictorIndex[m] - 1) << 2) + 2]) || obj_NanCutPoints[m]))
  {
    if (X[(((int)obj_CutPredictorIndex[m] - 1) << 2) + 2] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  node[2] = (signed char)(m + 1);
  m = 0;
  while (!((obj_PruneList_data[m] <= 0.0) || rtIsNaN(X[(((int)
             obj_CutPredictorIndex[m] - 1) << 2) + 3]) || obj_NanCutPoints[m]))
  {
    if (X[(((int)obj_CutPredictorIndex[m] - 1) << 2) + 3] < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }

  node[3] = (signed char)(m + 1);
  for (m = 0; m < 2; m++) {
    obj_ClassProbability_tmp = m << 2;
    b_obj_ClassProbability[obj_ClassProbability_tmp] = obj_ClassProbability
      [(node[0] + 9 * m) - 1];
    b_obj_ClassProbability[obj_ClassProbability_tmp + 1] = obj_ClassProbability
      [(node[1] + 9 * m) - 1];
    b_obj_ClassProbability[obj_ClassProbability_tmp + 2] = obj_ClassProbability
      [(node[2] + 9 * m) - 1];
    b_obj_ClassProbability[obj_ClassProbability_tmp + 3] = obj_ClassProbability
      [(node[3] + 9 * m) - 1];
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
