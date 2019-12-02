#include "MPU6050.h"

MPU6050 accel;

int16_t ax, ay, az;

#define LED_PIN 13
bool blinkState = false;

void setup() {
    Serial.begin(9600);

    // initialize device
    Serial.println("Initializing I2C device...");
    accel.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accel.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    // configure Arduino LED pin for output
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // read raw accel/gyro measurements from device
    accel.getAcceleration(&ax, &ay, &az);

    // display tab-separated accel/gyro x/y/z values
    Serial.print("accel:\t");
    Serial.print(ax/16384.0); Serial.print("\t");
    Serial.print(ay/16384.0); Serial.print("\t");
    Serial.print(az/16384.0); Serial.print("\n");

    // Send the data in to our main function

    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
}
