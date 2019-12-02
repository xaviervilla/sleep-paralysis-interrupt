/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationTree.h
 *
 * Code generation for function 'CompactClassificationTree'
 *
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "REDUCED_CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex
  [17], const double obj_Children[34], const double obj_CutPoint[17], const
  double obj_PruneList_data[], const bool obj_NanCutPoints[17], const double
  obj_ClassNames[4], const double obj_Cost[16], const double
  obj_ClassProbability[68], const double X[48], double labels[8]);

#endif

/* End of code generation (CompactClassificationTree.h) */
