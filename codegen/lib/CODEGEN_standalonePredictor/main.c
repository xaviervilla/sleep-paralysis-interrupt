/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Nov-2019 01:41:57
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "CODEGEN_standalonePredictor.h"
#include "CODEGEN_standalonePredictor_terminate.h"
#include "rt_nonfinite.h"
#include <stdio.h>

/* Function Declarations */
static void argInit_1x18_real_T(double result[18]);
static double argInit_real_T(void);
static void main_CODEGEN_standalonePredictor(void);

/* Function Definitions */

/*
 * Arguments    : double result[18]
 * Return Type  : void
 */
static void argInit_1x18_real_T(double result[18])
{
  int idx1;

  double array[] = {0.993803410156250, -0.267531330468750, 0.138709816484375, 0.152279713164062, -0.00787989265937500, 0.0457176749843750, 0.0195818074856650, 0.00987385575178295, 0.0199929389673216, 0.103505772635315, 0.142741010368918, 0.0308176315517541, 1.99672762984948, -3.07567753821980, 0.656751382569072, 1.95526599496885, 0.339599757508311, 0.128134427754891};

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 18; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = array[idx1]; //argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_CODEGEN_standalonePredictor(void)
{
  double dv[18];
  double label;

  /* Initialize function 'CODEGEN_standalonePredictor' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'CODEGEN_standalonePredictor'. */
  argInit_1x18_real_T(dv);
  label = CODEGEN_standalonePredictor(dv);
  printf("Label = %f\n", label);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_CODEGEN_standalonePredictor();

  /* Terminate the application.
     You do not need to do this more than one time. */
  CODEGEN_standalonePredictor_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
