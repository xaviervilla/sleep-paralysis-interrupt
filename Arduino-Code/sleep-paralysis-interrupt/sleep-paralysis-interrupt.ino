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
#include <MPU6050.h>

MPU6050 accel;

uint8_t certainty;

void setup() {
  Serial.begin(9600);
  
  accel.initialize();
  pinMode(13, OUTPUT);
  certainty = 0;
}

void loop() {
  
  bool label[2];
  double total_acc_x[16];
  double total_acc_y[16];
  double total_acc_z[16];
  while(1){
    for(uint8_t j = 0; j < 2; j++){
      for (uint8_t i = 0; i < 8; i++) {
        int16_t ax, ay, az;
        accel.getAcceleration(&ax, &ay, &az);
        total_acc_x[i + (j<<3)] = ax/(double)16384;
        total_acc_y[i + (j<<3)] = ay/(double)16384;
        total_acc_z[i + (j<<3)] = az/(double)16384;
        unsigned long currentMillis = millis();
        unsigned long previousMillis = currentMillis;
        while (millis()-previousMillis < 80){
        }
      }
    }

    REDUCED_CODEGEN_REALTIME_loadAndTestModel(total_acc_x, total_acc_x, total_acc_x, label);
    
    if(label[0]){
      if (certainty < 6){
        certainty++;
      }
    }
    else{
      if (certainty>=1){
        certainty--;
      }
    }
    digitalWrite(13, certainty/4);
  }
}
