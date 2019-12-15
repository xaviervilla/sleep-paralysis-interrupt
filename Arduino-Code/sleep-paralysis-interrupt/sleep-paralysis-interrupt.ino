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

#define numWin 2
#define winSize 32 //4sec*32hz
double label[numWin];
double total_acc_x[winSize*(numWin*2-1)];
double total_acc_y[winSize*(numWin*2-1)];
double total_acc_z[winSize*(numWin*2-1)];
bool dataDisplay = true;//true; // this controls whether we are testing ML functions or recording data
bool trainerTest = true;
int counter = 0;

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

int allTrue(const double* myArr){
    for(int i = 0; i < numWin; i++){
        if (0 == label[i]) { return 0; }
        else{ return 1; }
    }
    return 1;
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

  mpuInterrupt = false;
}

void loop() {
      
    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize) {
        if (mpuInterrupt && fifoCount < packetSize) {
          // try to get out of the infinite loop 
          fifoCount = mpu.getFIFOCount();        // Print time between samples for debugging
        }
    }

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
    
        // Print time between samples for debugging
//        timer = (millis()-timer);
//        Serial.printf("time between samples: %lu\n", timer);
//        timer = millis();

        // display initial world-frame acceleration, adjusted to remove gravity
        // and rotated based on known orientation from quaternion
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetAccel(&aa, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
        mpu.dmpGetLinearAccelInWorld(&aaWorld, &aaReal, &q);

        //Fill the 16 byte buffers
        total_acc_x[counter] = aa.x+aa.x*.6;
        total_acc_y[counter] = aa.y+aa.y*.6;
        total_acc_z[counter] = aa.z+aa.z*.6;
        counter++;
        if(counter == winSize*numWin){
            if (dataDisplay){
                // print it in a format that can be exported to csv
                for(int i = 0; i < winSize; i++){
                    //Serial.printf("(counter-winSize)+i: %u\n", (counter-winSize)+i);
                    Serial.print(total_acc_x[(counter-winSize)+i]);
                    Serial.print(F(", "));
                    Serial.print(total_acc_y[(counter-winSize)+i]);
                    Serial.print(F(", "));
                    Serial.println(total_acc_z[(counter-winSize)+i]);
                }
            }
            if (trainerTest){
                // blink to indicate activity
                digitalWrite(LED_PIN, HIGH);
                REDUCED_CODEGEN_REALTIME_loadAndTestModel(total_acc_x, total_acc_y, total_acc_z, label);    
                digitalWrite(LED_PIN, LOW);     
                //Serial.printf("counter-winSize: %u\n", counter-winSize);

                // Serial.printf("Label[0]:%f  \tLabel[1]:%f\n", label[0], label[1]);

                if(label[0]==1 || label[1]==1){
                    Serial.println("SP DETECTED");
                    blinkState = true;
                }
                else{
                    blinkState = false;
                }
            }
            //if(counter/winSize == numWin*2-1){
                counter = 0;
            //}
        }
        // Update LED state
        digitalWrite(LED_PIN, blinkState);
    }
    else{
            // Don't fully understand this case, but without setting interrupt to false, sometimes the main loop iterates too many times and becomes buggy
            //mpuInterrupt = false;
            //Serial.println(F("Bad?"));
    }
}
