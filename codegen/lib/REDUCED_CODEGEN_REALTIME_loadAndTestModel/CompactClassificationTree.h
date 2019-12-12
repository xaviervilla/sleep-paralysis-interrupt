/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 11-Dec-2019 20:06:08
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void c_CompactClassificationTree_Com(double obj_CutPredictorIndex[9],
  double obj_Children[18], double obj_CutPoint[9], double obj_PruneList_data[],
  int obj_PruneList_size[1], bool obj_NanCutPoints[9], bool obj_InfCutPoints[9],
  double obj_ClassNames[2], int obj_ClassNamesLength[2],
  c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2], bool
  obj_ClassLogicalIndices[2], double obj_Cost[4], double obj_ClassProbability[18]);
extern void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[9],
  const double obj_Children[18], const double obj_CutPoint[9], const double
  obj_PruneList_data[], const bool obj_NanCutPoints[9], const double
  obj_ClassNames[2], const double obj_Cost[4], const double
  obj_ClassProbability[18], const double X[36], double labels[4]);

#endif

/*
 * File trailer for CompactClassificationTree.h
 *
 * [EOF]
 */
