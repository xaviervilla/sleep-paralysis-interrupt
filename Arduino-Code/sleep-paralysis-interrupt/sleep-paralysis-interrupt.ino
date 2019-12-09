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
#include "MPU6050_6Axis_MotionApps_V6_12.h"

#define INTERRUPT_PIN 2
#define LED_PIN 13

MPU6050 mpu;
unsigned long timer = 0;
bool blinkState = false;

double label[4];
#define maxSize 128 //4sec*32hz
double total_acc_x[maxSize];
double total_acc_y[maxSize];
double total_acc_z[maxSize];
bool dataDisplay = true;//true; // this controls whether we are testing ML functions or recording data
bool trainerTest = true;
uint8_t counter = 0;

// MPU control/status vars
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 gy;         // [x, y, z]            gyro sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// packet structure for InvenSense teapot demo
uint8_t teapotPacket[14] = { '$', 0x02, 0,0, 0,0, 0,0, 0,0, 0x00, 0x00, '\r', '\n' };

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}

void setup() {
  Wire.begin();
  Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
  Serial.begin(115200);
  delay(500);
  
  // initialize device
  Serial.println(F("Initializing I2C devices..."));
  mpu.initialize();
  Serial.println(F("Testing device connections..."));
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
  Serial.println(F("Initializing DMP..."));
  devStatus = mpu.dmpInitialize();
  delay(500);

  // Calibration settings for my sensor
  mpu.setXAccelOffset(-298);
  mpu.setYAccelOffset(-3408);
  mpu.setZAccelOffset(867);
  mpu.setXGyroOffset(19);
  mpu.setYGyroOffset(-4);
  mpu.setZGyroOffset(11);
  
  //set digital low pass filter to 20 hz
  mpu.setDLPFMode(MPU6050_DLPF_BW_20);
  // set the SMPLRT_DIV divider to 15 which brings the sample rate down to 1,000/(15+1) ~ 32hz 
  mpu.setRate(15);
 
  // turn on the DMP, now that it's ready
  Serial.println(F("Enabling DMP..."));
  mpu.setDMPEnabled(true);
  
  // enable Arduino interrupt detection
  pinMode(INTERRUPT_PIN, INPUT); 
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
  mpuIntStatus = mpu.getIntStatus(); 
  
  // set our DMP Ready flag so the main loop() function knows it's okay to use it
  Serial.println(F("DMP ready! Waiting for first interrupt..."));
  
  // get expected DMP packet size for later comparison
  packetSize = mpu.dmpGetFIFOPacketSize();

  delay(1000);
}

void loop() {
      
    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize) {
        if (mpuInterrupt && fifoCount < packetSize) {
          // try to get out of the infinite loop 
          fifoCount = mpu.getFIFOCount();
        }
    }

    mpuInterrupt = false;
    timer = (millis()-timer);
    //Serial.printf("time between samples: %lu\n", timer);
    timer = millis();
    // reset interrupt flag and get INT_STATUS byte
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & _BV(MPU6050_INTERRUPT_FIFO_OFLOW_BIT)) || fifoCount >= 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
        fifoCount = mpu.getFIFOCount();
        Serial.println(F("FIFO overflow!"));

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
    } else if (mpuIntStatus & _BV(MPU6050_INTERRUPT_DMP_INT_BIT)) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

        // display initial world-frame acceleration, adjusted to remove gravity
        // and rotated based on known orientation from quaternion
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetAccel(&aa, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
        mpu.dmpGetLinearAccelInWorld(&aaWorld, &aaReal, &q);

        //Fill the 16 byte buffers
        total_acc_x[counter] = aaWorld.x;
        total_acc_y[counter] = aaWorld.y;
        total_acc_z[counter] = aaWorld.z;
        counter++;
        if(counter == maxSize){
            counter = 0;
            if (dataDisplay){
                // print it in a format that can be exported to csv
                for(int i = 0; i < maxSize; i++){
                    Serial.print(total_acc_x[i]);
                    Serial.print(", ");
                    Serial.print(total_acc_y[i]);
                    Serial.print(", ");
                    Serial.println(total_acc_z[i]);
                }
            }
            if (trainerTest){
                REDUCED_CODEGEN_REALTIME_loadAndTestModel(total_acc_x, total_acc_y, total_acc_z, label);
                Serial.print(label[0]);
                Serial.print(F("\t"));
                Serial.print(label[1]);
                Serial.print(F("\t"));
                Serial.print(label[2]);
                Serial.print(F("\t"));
                Serial.println(label[3]);
                if(label[0] && label[1] && label[2] && label[3]){
                    blinkState = true;
                }
                else{
                    blinkState = false;
                }
            }
        }
        /*
        bool label[2];
        double total_acc_x[16];
        double total_acc_y[16];
        double total_acc_z[16];
        uint8_t counter = 0;
        */

        // blink LED to indicate activity
        //blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState);
    }
}
    
//    for(uint8_t j = 0; j < 2; j++){
//      for (uint8_t i = 0; i < 8; i++) {
//        int16_t ax, ay, az;
//        mpu.getAcceleration(&ax, &ay, &az);
//        total_acc_x[i + (j<<3)] = ax/(double)16384;
//        total_acc_y[i + (j<<3)] = ay/(double)16384;
//        total_acc_z[i + (j<<3)] = az/(double)16384;
//      }
//    }
    //REDUCED_CODEGEN_REALTIME_loadAndTestModel(total_acc_x, total_acc_x, total_acc_x, label);
