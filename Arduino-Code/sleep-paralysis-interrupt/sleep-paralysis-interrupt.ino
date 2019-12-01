#include <CompactClassificationTree.h>
#include <xzsvdc.h>
#include <rt_nonfinite.h>
#include <xrotg.h>
#include <xnrm2.h>
#include <xrot.h>
#include <rtGetNaN.h>
#include <CODEGEN_standalonePredictor.h>
#include <CODEGEN_REALTIME_loadAndTestModel_terminate.h>
#include <CODEGEN_REALTIME_loadAndTestModel_data.h>
#include <rtwtypes.h>
#include <rtGetInf.h>
#include <CODEGEN_REALTIME_loadAndTestModel.h>
#include <CODEGEN_REALTIME_loadAndTestModel_types.h>
#include <Wstd.h>
#include <Wpca1.h>
#include <xaxpy.h>
#include <CODEGEN_REALTIME_loadAndTestModel_initialize.h>
#include <xswap.h>
#include <xdotc.h>
#include <pca.h>

/*
 * ANDES Lab - University of California, Merced
 * 
 * This code takes samples from an MPU650 chip and uses a classifier 
 * to activate a trigger when sleep paralysis is detected
 *
 * @author  Xavier Villa - UCM ANDES Lab
 * @date    2019/11/30
 *
 */

/* Include files */


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  //main_CODEGEN_REALTIME_loadAndTestModel();

  /* Terminate the application.
     You do not need to do this more than one time. */
  //CODEGEN_REALTIME_loadAndTestModel_terminate();
}

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
