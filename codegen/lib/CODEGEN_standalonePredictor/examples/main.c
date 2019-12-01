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
#include "CODEGEN_standalonePredictor.h"
#include "CODEGEN_standalonePredictor_terminate.h"
#include "Wmean.h"
#include "Wpca1.h"
#include "Wstd.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_16x128_real_T(double result[2048]);
static void argInit_16x18_real_T(double result[288]);
static double argInit_real_T(void);
static void main_CODEGEN_standalonePredictor(void);
static void main_Wmean(void);
static void main_Wpca1(void);
static void main_Wstd(void);

/* Function Definitions */
static void argInit_16x128_real_T(double result[2048])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 16; idx0++) {
    for (idx1 = 0; idx1 < 128; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + (idx1 << 4)] = argInit_real_T();
    }
  }
}

static void argInit_16x18_real_T(double result[288])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 16; idx0++) {
    for (idx1 = 0; idx1 < 18; idx1++) {
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

static void main_CODEGEN_standalonePredictor(void)
{
  double dv[288];
  double label[16];

  /* Initialize function 'CODEGEN_standalonePredictor' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'CODEGEN_standalonePredictor'. */
  argInit_16x18_real_T(dv);
  CODEGEN_standalonePredictor(dv, label);
}

static void main_Wmean(void)
{
  double dv[2048];
  double Y[16];

  /* Initialize function 'Wmean' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'Wmean'. */
  argInit_16x128_real_T(dv);
  Wmean(dv, Y);
}

static void main_Wpca1(void)
{
  double dv[2048];
  double Y_data[240];
  int Y_size[2];

  /* Initialize function 'Wpca1' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'Wpca1'. */
  argInit_16x128_real_T(dv);
  Wpca1(dv, Y_data, Y_size);
}

static void main_Wstd(void)
{
  double dv[2048];
  double Y[16];

  /* Initialize function 'Wstd' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'Wstd'. */
  argInit_16x128_real_T(dv);
  Wstd(dv, Y);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_CODEGEN_standalonePredictor();
  main_Wmean();
  main_Wpca1();
  main_Wstd();

  /* Terminate the application.
     You do not need to do this more than one time. */
  CODEGEN_standalonePredictor_terminate();
  return 0;
}

/* End of code generation (main.c) */
