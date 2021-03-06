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
 - [X] Finally load the code onto an Arduino
 - [X] Find a good library for MPU6050 accelerometer chip
 - [X] Format data in a way that allows the matlab functions to be called
 - [x] Get MPU library and custom library to both fit on an Atmega328P
 - [X] Solder up the mpu6050 and turn on an LED when walking is detected
 - [X] Turn Arduino light on when Sleep paralysis is detected
 - [X] Determine the cause of classifier only working when accelerometer is in specific orientation
 - [X] Fix code to allow for different orientations of the accelerometer
 - [X] Reduce size of code for more stability
 - [X] Record better accelerometer data for training and predicting
 - [x] Make it easier to make fundamental changes and recompile all of the code to the arduino
 - [X] Improve accuracy and reduce false alarms using some type of counter to measure confidence
 - [X] Get more capable embedded controller, perhaps arduino mega or RPi zero
 - [X] Enable low pass filtering in MPU6050 of 30 Hz and sample rate of 200hz
 - [X] Set up interrupts to communicate with sensor through SPI instead of I2C
 - [X] Recompile code with much better sample frequency for better predictions on better platform
 - [X] Design wearable for overnight testing
 - [X] Come up with way to record overnight data, or at least data without tethering to PC??
 - [X] Possibly reenable mean function if it improves accuracy
 - [ ] Reinvestigate frequency domain characteristics and determine if necessary
 - [X] Disable gravity subtraction (world-frame view) for sensor data and re-train
 - [X] Investigate accuracy/memory tradeoff of KNN vs. Decision Tree models
 - [ ] Impliment sliding window of samples to improve speed of response rather than descrete sample windows
 - [ ] Record better quality SP data for training
