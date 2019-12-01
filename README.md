# sleep-paralysis-interrupt
A machine learning classifier that detects sleep paralysis

# To do:
 - [x] Set up MATLAB 2019B
 - [x] Install Matlab Coder, DSP ToolBox, Classification Learner and other dependencies
 - [x] Use signal processing to find characteristics of accelerometer data for different activities
 - [x] Compute Mean, Standard Deviation, and Principle Component Analysis Coeeficients of accelerometer data
 - [x] Create a classifier that analyzes and labels accelerometer data based on the characteristics
 - [x] Read documentation for Matlab Coder and Classification Learner, figure out what is required for c code translation
 - [x] Convert classification learner into C
 - [x] Go back into Matlab and simulate a live stream of accelerometer data
 - [x] Get classifier to work with live stream of data (smaller bursts of samples 16, 64, 128 etc.)
 - [x] Get real-time classifier converted into C
 - [x] Compile in C for an Atmel 8 bit system
 - [x] Configure the generated C code as a library for Arduino IDE
 - [x] Get code to compile in the IDE with random sample data
 - [x] Get code to **FIT** on an Atmega328P... *\*sigh*
 - [x] Remove Gyroscope from the classifier and data stream to save dynamic memory
 - [x] Remove PCA computations completely from the library to save program storage space
 - [x] Optimize classifier for new data stream without PCA and Gyroscope
 - [x] Recompile Matlab into C code after each of the above steps  
 - [ ] Finally load the code onto an Arduino
 - [ ] Find a good library for MPU6050 accelerometer chip
 - [ ] Format data in a way that allows the matlab functions to be called
 - [ ] Solder up the mpu6050 and turn on an LED when walking is detected
 - [ ] Record better accelerometer data for training and predicting
 - [ ] Turn Arduino light on when Sleep paralysis is detected
 - [ ] Improve accuracy and reduce false alarms using some type of counter to measure confidence
 - [ ] 
