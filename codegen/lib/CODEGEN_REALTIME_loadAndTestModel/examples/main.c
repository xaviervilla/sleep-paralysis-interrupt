/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
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

/* Include files */
#include "main.h"
#include "CODEGEN_REALTIME_loadAndTestModel.h"
#include "CODEGEN_REALTIME_loadAndTestModel_terminate.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_16x16_real_T(double result[256]);
static double argInit_real_T(void);
static void main_CODEGEN_REALTIME_loadAndTestModel(void);

/* Function Definitions */
static void argInit_16x16_real_T(double result[256])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 16; idx0++) {
    for (idx1 = 0; idx1 < 16; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + (idx1 << 4)] = argInit_real_T();
    }
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_CODEGEN_REALTIME_loadAndTestModel(void)
{
  double total_acc_x_test_tmp_tmp[256];
  double dv[256];
  double dv1[256];
  double dv2[256];
  double label[16];

  /* Initialize function 'CODEGEN_REALTIME_loadAndTestModel' input arguments. */
  /* Initialize function input argument 'total_acc_x_test'. */
  argInit_16x16_real_T(total_acc_x_test_tmp_tmp);

  /* Initialize function input argument 'total_acc_y_test'. */
  /* Initialize function input argument 'total_acc_z_test'. */
  /* Initialize function input argument 'body_gyro_x_test'. */
  /* Initialize function input argument 'body_gyro_y_test'. */
  /* Initialize function input argument 'body_gyro_z_test'. */
  /* Call the entry-point 'CODEGEN_REALTIME_loadAndTestModel'. */
  argInit_16x16_real_T(dv);
  argInit_16x16_real_T(dv1);
  argInit_16x16_real_T(dv2);
  CODEGEN_REALTIME_loadAndTestModel(total_acc_x_test_tmp_tmp,
    total_acc_x_test_tmp_tmp, total_acc_x_test_tmp_tmp, dv, dv1, dv2, label);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_CODEGEN_REALTIME_loadAndTestModel();

  /* Terminate the application.
     You do not need to do this more than one time. */
  CODEGEN_REALTIME_loadAndTestModel_terminate();
  return 0;
}

/* End of code generation (main.c) */