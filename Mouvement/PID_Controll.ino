#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <MPU6050_light.h> // Include the MPU6050 library

// Define addresses for the two PCA9685 modules
Adafruit_PWMServoDriver pwm_R = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver pwm_L = Adafruit_PWMServoDriver(0x42);

MPU6050 mpu(Wire); // Create MPU6050 object

// Define pulse values for each servo
#define SERVO1_A1_MIN_PULSE 600
#define SERVO1_A1_MAX_PULSE 2600
#define SERVO1_A2_MIN_PULSE 600
#define SERVO1_A2_MAX_PULSE 2600
#define SERVO1_A3_MIN_PULSE 600
#define SERVO1_A3_MAX_PULSE 2600
// Add definitions for other servos as needed

// PID Variables
float Kp = 1.0;    // Proportional gain
float Ki = 0.1;    // Integral gain
float Kd = 0.01;   // Derivative gain
float integral = 0;
float lastError = 0;

// Current angles array
float currentAngles[18] = {0}; // Array to keep track of current angles of each servo

// Function to set servo position
void setServoPosition(Adafruit_PWMServoDriver &pwm, int channel, int angle) {
    int pulseWidth;
    switch (channel) {
        case 0: pulseWidth = map(angle, 0, 180, SERVO1_A1_MIN_PULSE, SERVO1_A1_MAX_PULSE); break;
        case 1: pulseWidth = map(angle, 0, 180, SERVO1_A2_MIN_PULSE, SERVO1_A2_MAX_PULSE); break;
        case 2: pulseWidth = map(angle, 0, 180, SERVO1_A3_MIN_PULSE, SERVO1_A3_MAX_PULSE); break;
        // Add other cases for additional servos
        default: pulseWidth = SERVO1_A1_MIN_PULSE; break;
    }

    // Calculate the PWM value
    int pulseValue = int(float(pulseWidth) / 1000000 * 50 * 4096);
    pwm.setPWM(channel, 0, pulseValue);
}

// Function to initialize the MPU6050
void setup() {
    Serial.begin(9600);
    Wire.begin();

    // Initialize MPU6050
    byte status = mpu.begin();
    Serial.print(F("MPU6050 status: "));
    Serial.println(status);
    while (status != 0) { } // Stop everything if could not connect to MPU6050

    Serial.println(F("Calculating offsets, do not move MPU6050"));
    delay(1000);
    mpu.calcOffsets(true, true); // Gyro and accelerometer
    Serial.println("Done!\n");

    // Initialize PWM drivers
    pwm_R.begin();
    pwm_R.setPWMFreq(50); // Set frequency to 50 Hz for servos
    pwm_L.begin();
    pwm_L.setPWMFreq(50); // Set frequency to 50 Hz for servos
}

// Function to read the current angle from MPU6050
float readGyroAngle() {
    mpu.update(); // Update MPU6050 readings
    return mpu.getAngleX(); // Get the angle around the X-axis
}

// PID Control Function
void applyPID(float desiredAngle) {
    float input = readGyroAngle(); // Read the current angle
    float error = desiredAngle - input;
    
    float pTerm = Kp * error;
    integral += error;
    float iTerm = Ki * integral;
    float derivative = error - lastError;
    float dTerm = Kd * derivative;
    
    float output = pTerm + iTerm + dTerm;

    // Update current angles based on output
    for (int i = 0; i < 18; i++) {
        // Calculate the new position for each servo
        int newPosition = constrain(currentAngles[i] + output, 0, 180);
        setServoPosition((i < 9) ? pwm_L : pwm_R, i % 9, newPosition);
        currentAngles[i] = newPosition; // Update current angle
    }

    lastError = error; // Save for the next iteration
}

// Home position function using PID control
void home() {
    int desiredPositions[18] = {
        90,   // A1
        105,  // A2
        160,  // A3
        85,   // B1
        120,  // B2
        170,  // B3
        90,   // C1
        120,  // C2
        185,  // C3
        80,   // D1
        65,   // D2
        25,   // D3
        85,   // E1
        60,   // E2
        5,    // E3
        100,  // F1
        60    // F2
    };

    // Set desired positions first
    for (int i = 0; i < 18; i++) {
        setServoPosition((i < 9) ? pwm_L : pwm_R, i % 9, desiredPositions[i]);
        currentAngles[i] = desiredPositions[i]; // Initialize current angles
    }

    // Apply PID to correct tilt
    applyPID(0); // Assuming we want to keep the robot level (0 degrees)
}


// Main loop
void loop() 
{
    // Call the home function to adjust the servos
    home();
    
    // Uncomment to call other movement functions like forward()
    // forward();

    // Add a small delay to avoid overwhelming the MPU6050
    delay(50);
}