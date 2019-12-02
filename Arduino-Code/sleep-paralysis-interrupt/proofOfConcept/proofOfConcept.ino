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
//#include <REDUCED_CODEGEN_REALTIME_loadAndTestModel_terminate.h>

#define LED_PIN 13

MPU6050 accel;

int16_t ax, ay, az;
double total_acc_x[8];
double total_acc_y[8];
double total_acc_z[8];
uint8_t label;
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

void sample16()
{
  uint8_t i = 0;
  for (i = 0; i < 8; i++) {
    accel.getAcceleration(&ax, &ay, &az);
    total_acc_x[i] = ax/16384.0;
    total_acc_y[i] = ay/16384.0;
    total_acc_z[i] = az/16384.0;
    delay(50);
  }

  label = REDUCED_CODEGEN_REALTIME_loadAndTestModel(total_acc_x, total_acc_y, total_acc_z);
  //REDUCED_CODEGEN_REALTIME_loadAndTestModel_terminate();
}

void loop() {

  sample16();

  Serial.println(label);
  
  if(label == 3){
    isWalking = true;
    digitalWrite(LED_PIN, isWalking);
    delay(200);
  }  
  else{
    isWalking = false;
    digitalWrite(LED_PIN, isWalking);
    delay(200);
  }
}
