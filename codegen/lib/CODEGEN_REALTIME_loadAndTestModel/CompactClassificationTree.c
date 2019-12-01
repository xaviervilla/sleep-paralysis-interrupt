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
void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[5],
  const double obj_Children[10], const double obj_CutPoint[5], const double
  obj_PruneList_data[], const bool obj_NanCutPoints[5], const double
  obj_ClassNames[2], const double obj_Cost[4], const double
  obj_ClassProbability[10], const double X[288], double labels[16])
{
  int n;
  int m;
  signed char node[16];
  double d;
  double b_obj_ClassProbability[32];
  double d1;
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

  for (n = 0; n < 2; n++) {
    for (m = 0; m < 16; m++) {
      b_obj_ClassProbability[m + (n << 4)] = obj_ClassProbability[(node[m] + 5 *
        n) - 1];
    }
  }

  for (n = 0; n < 16; n++) {
    d = b_obj_ClassProbability[n + 16];
    d1 = b_obj_ClassProbability[n] * obj_Cost[0] + d * obj_Cost[1];
    d = b_obj_ClassProbability[n] * obj_Cost[2] + d * obj_Cost[3];
    if ((d1 > d) || (rtIsNaN(d1) && (!rtIsNaN(d)))) {
      m = 2;
    } else {
      m = 1;
    }

    node[n] = (signed char)m;
    labels[n] = obj_ClassNames[node[n] - 1];
  }
}

/* End of code generation (CompactClassificationTree.c) */
