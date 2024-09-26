#include <Arduino.h>

// Define easing types
#define ENABLE_EASE_CUBIC

#include "ServoEasing.hpp"

// Define address for the PCA9685 module
#define PCA9685_ADDRESS 0x40

// Create ServoEasing object for the single servo
ServoEasing Servo1(PCA9685_ADDRESS); // Servo on PCA9685 Module

// Define servo pin (custom pin)
#define SERVO1_PIN 0  // Pin for Servo 1 on Module

// Define pulse values for the servo
#define SERVO_MIN_PULSE 1000 // Minimum pulse width in microseconds 
#define SERVO_MAX_PULSE 2000 // Maximum pulse width in microseconds 

#define DEFAULT_SPEED 10      // Default speed for the servo

// Function to map degree to pulse width
unsigned int mapDegreeToPulse(int degree) 
{
    return map(degree, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
}

void setup() 
{
    Serial.begin(115200);
    
    // Initialize the PCA9685 module and attach the servo
    if (Servo1.InitializeAndCheckI2CConnection(&Serial)) {
        Serial.println("Failed to connect to PCA9685 Module.");
        while (true);
    }

    // Attach the servo with the initial pulse range
    Servo1.attach(SERVO1_PIN, mapDegreeToPulse(0), SERVO_MIN_PULSE, SERVO_MAX_PULSE);

    // Set default easing type and speed for the servo
    Servo1.setEasingType(EASE_CUBIC);
    Servo1.setSpeed(DEFAULT_SPEED);

    // Wait for the servo to reach the start position
    delay(500);
}

void loop()
 {
    // Move the servo to 90 degrees
    Servo1.easeTo(90);
    delay(2000); // Wait for a while

    // Move the servo back to the starting position
    Servo1.startEaseTo(0); // Using 0 for the starting position
    delay(2000); // Wait for a while
}