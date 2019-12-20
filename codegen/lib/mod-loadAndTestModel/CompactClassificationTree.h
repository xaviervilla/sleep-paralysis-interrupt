/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 20-Dec-2019 14:56:44
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "loadAndTestModel_types.h"

/* Function Declarations */
extern double c_CompactClassificationTree_pre(const double
  obj_CutPredictorIndex[31], const double obj_Children[62], const double
  obj_CutPoint[31], const double obj_PruneList_data[], const bool
  obj_NanCutPoints[31], const double obj_ClassNames[2], const double obj_Cost[4],
  const double obj_ClassProbability[62], const double X[12]);

#endif

/*
 * File trailer for CompactClassificationTree.h
 *
 * [EOF]
 */
