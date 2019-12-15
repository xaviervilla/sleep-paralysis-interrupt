/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 15-Dec-2019 01:50:49
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
#include "loadAndTestModel.h"
#include "loadAndTestModel_terminate.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_2x32_real_T(double result[64]);
static double argInit_real_T(void);
static void main_loadAndTestModel(void);

/* Function Definitions */

/*
 * Arguments    : double result[64]
 * Return Type  : void
 */
static void argInit_2x32_real_T(double result[64])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < 32; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + (idx1 << 1)] = argInit_real_T();
    }
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
static void main_loadAndTestModel(void)
{
  double total_acc_x_test_tmp_tmp[64];
  double label[2];

  /* Initialize function 'loadAndTestModel' input arguments. */
  /* Initialize function input argument 'total_acc_x_test'. */
  argInit_2x32_real_T(total_acc_x_test_tmp_tmp);

  /* Initialize function input argument 'total_acc_y_test'. */
  /* Initialize function input argument 'total_acc_z_test'. */
  /* Call the entry-point 'loadAndTestModel'. */
  loadAndTestModel(total_acc_x_test_tmp_tmp, total_acc_x_test_tmp_tmp,
                   total_acc_x_test_tmp_tmp, label);
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
  main_loadAndTestModel();

  /* Terminate the application.
     You do not need to do this more than one time. */
  loadAndTestModel_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
