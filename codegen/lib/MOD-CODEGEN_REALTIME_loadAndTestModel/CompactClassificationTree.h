/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 12-Dec-2019 18:03:22
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex
  [11], const double obj_Children[22], const double obj_CutPoint[11], const
  double obj_PruneList_data[], const bool obj_NanCutPoints[11], const double
  obj_ClassNames[2], const double obj_Cost[4], const double
  obj_ClassProbability[22], const double X[18], double labels[2]);

#endif

/*
 * File trailer for CompactClassificationTree.h
 *
 * [EOF]
 */
