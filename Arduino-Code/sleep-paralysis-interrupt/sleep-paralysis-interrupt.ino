#include <REDUCED_CODEGEN_REALTIME_loadAndTestModel.h>


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
  main_REDUCED_CODEGEN_REALTIME_loadAndTestModel();
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
      result[idx0 + (idx1 << 4)] = 0;
    }
  }
}

static void main_REDUCED_CODEGEN_REALTIME_loadAndTestModel(void)
{
  double total_acc_x_test_tmp_tmp[256];
  double label[16];

  /* Initialize function 'REDUCED_CODEGEN_REALTIME_loadAndTestModel' input arguments. */
  /* Initialize function input argument 'total_acc_x_test'. */
  argInit_16x16_real_T(total_acc_x_test_tmp_tmp);

  /* Initialize function input argument 'total_acc_y_test'. */
  /* Initialize function input argument 'total_acc_z_test'. */
  /* Call the entry-point 'REDUCED_CODEGEN_REALTIME_loadAndTestModel'. */
  REDUCED_CODEGEN_REALTIME_loadAndTestModel(total_acc_x_test_tmp_tmp,
    total_acc_x_test_tmp_tmp, total_acc_x_test_tmp_tmp, label);
}
