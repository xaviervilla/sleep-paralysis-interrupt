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

#include <REDUCED_CODEGEN_REALTIME_loadAndTestModel.h>
#include "MPU6050.h"
#include <REDUCED_CODEGEN_REALTIME_loadAndTestModel_terminate.h>

#define LED_PIN 13

MPU6050 accel;

int16_t ax, ay, az;
double label[16];
bool isWalking;

void setup() {
  Serial.begin(9600);
  
  Serial.println("Initializing I2C device...");
  accel.initialize();
  
  Serial.println("Testing device connections...");
  Serial.println(accel.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  
  pinMode(LED_PIN, OUTPUT);

  delay(1000);

}

static void sample16()
{
  uint8_t idx0;
  uint8_t idx1;
  double total_acc_x[64];
  double total_acc_y[64];
  double total_acc_z[64];
  for (idx0 = 0; idx0 < 8; idx0++) {
    for (idx1 = 0; idx1 < 8; idx1++) {
      accel.getAcceleration(&ax, &ay, &az);
      total_acc_x[idx0 + (idx1 << 3)] = ax/16384;
      total_acc_y[idx0 + (idx1 << 3)] = ay/16384;
      total_acc_z[idx0 + (idx1 << 3)] = az/16384;
      delay(10);
      
    }
  isWalking = !isWalking;
  digitalWrite(LED_PIN, isWalking);

  }
  REDUCED_CODEGEN_REALTIME_loadAndTestModel(total_acc_x, total_acc_y, total_acc_z, label);
  REDUCED_CODEGEN_REALTIME_loadAndTestModel_terminate();
}

void loop() {

  sample16();
  
  isWalking = !isWalking;
  delay(1000);
  digitalWrite(LED_PIN, isWalking);
  delay(1000);
  isWalking = !isWalking;
  digitalWrite(LED_PIN, isWalking);
}
