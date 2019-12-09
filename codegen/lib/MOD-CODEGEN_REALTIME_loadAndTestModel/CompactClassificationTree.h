/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 09-Dec-2019 01:55:25
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void c_CompactClassificationTree_pre(const double obj_Children[6], const
  double obj_CutPoint[3], const double obj_PruneList_data[], const bool
  obj_NanCutPoints[3], const double obj_ClassNames[2], const double obj_Cost[4],
  const double obj_ClassProbability[6], const double X[24], double labels[4]);

#endif

/*
 * File trailer for CompactClassificationTree.h
 *
 * [EOF]
 */
