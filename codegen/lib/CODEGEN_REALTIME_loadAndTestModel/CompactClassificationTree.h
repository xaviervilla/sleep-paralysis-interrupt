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
#include "CODEGEN_REALTIME_loadAndTestModel_types.h"

/* Function Declarations */
extern void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex
  [177], const double obj_Children[354], const double obj_CutPoint[177], const
  double obj_PruneList_data[], const bool obj_NanCutPoints[177], const double
  obj_ClassNames[5], const double obj_Cost[25], const double
  obj_ClassProbability[885], const double X[288], double labels[16]);

#endif

/* End of code generation (CompactClassificationTree.h) */
