#include <Arduino.h>
#include "ServoEasing.hpp" // Include the ServoEasing library

// Define easing types
#define ENABLE_EASE_CUBIC

// Define addresses for the two PCA9685 modules
#define PCA9685_ADDRESS_1 0x40
#define PCA9685_ADDRESS_2 0x41

// Create ServoEasing objects for each servo in both PCA9685 modules
ServoEasing Servo1_1(PCA9685_ADDRESS_1); // Servo 1 on PCA9685 Module 1
ServoEasing Servo1_2(PCA9685_ADDRESS_1); // Servo 2 on PCA9685 Module 1
ServoEasing Servo1_3(PCA9685_ADDRESS_1); // Servo 3 on PCA9685 Module 1
ServoEasing Servo1_4(PCA9685_ADDRESS_1); // Servo 4 on PCA9685 Module 1
ServoEasing Servo1_5(PCA9685_ADDRESS_1); // Servo 5 on PCA9685 Module 1
ServoEasing Servo1_6(PCA9685_ADDRESS_1); // Servo 6 on PCA9685 Module 1
ServoEasing Servo1_7(PCA9685_ADDRESS_1); // Servo 7 on PCA9685 Module 1
ServoEasing Servo1_8(PCA9685_ADDRESS_1); // Servo 8 on PCA9685 Module 1
ServoEasing Servo1_9(PCA9685_ADDRESS_1); // Servo 9 on PCA9685 Module 1

ServoEasing Servo2_1(PCA9685_ADDRESS_2); // Servo 1 on PCA9685 Module 2
ServoEasing Servo2_2(PCA9685_ADDRESS_2); // Servo 2 on PCA9685 Module 2
ServoEasing Servo2_3(PCA9685_ADDRESS_2); // Servo 3 on PCA9685 Module 2
ServoEasing Servo2_4(PCA9685_ADDRESS_2); // Servo 4 on PCA9685 Module 2
ServoEasing Servo2_5(PCA9685_ADDRESS_2); // Servo 5 on PCA9685 Module 2
ServoEasing Servo2_6(PCA9685_ADDRESS_2); // Servo 6 on PCA9685 Module 2
ServoEasing Servo2_7(PCA9685_ADDRESS_2); // Servo 7 on PCA9685 Module 2
ServoEasing Servo2_8(PCA9685_ADDRESS_2); // Servo 8 on PCA9685 Module 2
ServoEasing Servo2_9(PCA9685_ADDRESS_2); // Servo 9 on PCA9685 Module 2

// Define pulse values for each servo
#define SERVO1_1_MIN_PULSE 1000 // Minimum pulse width for Servo 1 on Module 1
#define SERVO1_1_MAX_PULSE 2000 // Maximum pulse width for Servo 1 on Module 1
#define SERVO1_2_MIN_PULSE 1100 // Minimum pulse width for Servo 2 on Module 1
#define SERVO1_2_MAX_PULSE 2100 // Maximum pulse width for Servo 2 on Module 1
#define SERVO1_3_MIN_PULSE 1200 // Minimum pulse width for Servo 3 on Module 1
#define SERVO1_3_MAX_PULSE 2200 // Maximum pulse width for Servo 3 on Module 1
#define SERVO1_4_MIN_PULSE 1300 // Minimum pulse width for Servo 4 on Module 1
#define SERVO1_4_MAX_PULSE 2300 // Maximum pulse width for Servo 4 on Module 1
#define SERVO1_5_MIN_PULSE 1400 // Minimum pulse width for Servo 5 on Module 1
#define SERVO1_5_MAX_PULSE 2400 // Maximum pulse width for Servo 5 on Module 1
#define SERVO1_6_MIN_PULSE 1500 // Minimum pulse width for Servo 6 on Module 1
#define SERVO1_6_MAX_PULSE 2500 // Maximum pulse width for Servo 6 on Module 1
#define SERVO1_7_MIN_PULSE 1600 // Minimum pulse width for Servo 7 on Module 1
#define SERVO1_7_MAX_PULSE 2600 // Maximum pulse width for Servo 7 on Module 1
#define SERVO1_8_MIN_PULSE 1700 // Minimum pulse width for Servo 8 on Module 1
#define SERVO1_8_MAX_PULSE 2700 // Maximum pulse width for Servo 8 on Module 1
#define SERVO1_9_MIN_PULSE 1800 // Minimum pulse width for Servo 9 on Module 1
#define SERVO1_9_MAX_PULSE 2800 // Maximum pulse width for Servo 9 on Module 1

#define SERVO2_1_MIN_PULSE 1000 // Minimum pulse width for Servo 1 on Module 2
#define SERVO2_1_MAX_PULSE 2000 // Maximum pulse width for Servo 1 on Module 2
// Repeat for other servos...
#define SERVO2_2_MIN_PULSE 1100 // Minimum pulse width for Servo 2
#define SERVO2_2_MAX_PULSE 2100 // Maximum pulse width for Servo 2
#define SERVO2_3_MIN_PULSE 1200 // Minimum pulse width for Servo 3
#define SERVO2_3_MAX_PULSE 2200 // Maximum pulse width for Servo 3
#define SERVO2_4_MIN_PULSE 1300 // Minimum pulse width for Servo 4
#define SERVO2_4_MAX_PULSE 2300 // Maximum pulse width for Servo 4
#define SERVO2_5_MIN_PULSE 1400 // Minimum pulse width for Servo 5
#define SERVO2_5_MAX_PULSE 2400 // Maximum pulse width for Servo 5
#define SERVO2_6_MIN_PULSE 1500 // Minimum pulse width for Servo 6
#define SERVO2_6_MAX_PULSE 2500 // Maximum pulse width for Servo 6
#define SERVO2_7_MIN_PULSE 1600 // Minimum pulse width for Servo 7
#define SERVO2_7_MAX_PULSE 2600 // Maximum pulse width for Servo 7
#define SERVO2_8_MIN_PULSE 1700 // Minimum pulse width for Servo 8
#define SERVO2_8_MAX_PULSE 2700 // Maximum pulse width for Servo 8
#define SERVO2_9_MIN_PULSE 1800 // Minimum pulse width for Servo 9
#define SERVO2_9_MAX_PULSE 2800 // Maximum pulse width for Servo 9

#define START_DEGREE_VALUE 0 // Initial position for all servos
#define DEFAULT_SPEED 10      // Default speed for all servos

// Simplified mapping function
unsigned int mapDegreeToPulse(int degree, unsigned int minPulse, unsigned int maxPulse) {
    return (degree * (maxPulse - minPulse) / 180) + minPulse;
}

void setup() {
    Serial.begin(115200);
    
    // Initialize the PCA9685 modules and attach the servos
    if (Servo1_1.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_2.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_3.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_4.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_5.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_6.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_7.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_8.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_9.InitializeAndCheckI2CConnection(&Serial)) {
        Serial.println("Failed to connect to PCA9685 Module 1.");
        while (true);
    }

    if (Servo2_1.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_2.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_3.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_4.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_5.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_6.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_7.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_8.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_9.InitializeAndCheckI2CConnection(&Serial)) {
        Serial.println("Failed to connect to PCA9685 Module 2.");
        while (true);
    }

    // Attach all servos on Module 1 with pulse ranges
    Servo1_1.attach(0, START_DEGREE_VALUE, SERVO1_1_MIN_PULSE, SERVO1_1_MAX_PULSE);
    Servo1_2.attach(1, START_DEGREE_VALUE, SERVO1_2_MIN_PULSE, SERVO1_2_MAX_PULSE);
    Servo1_3.attach(2, START_DEGREE_VALUE, SERVO1_3_MIN_PULSE, SERVO1_3_MAX_PULSE);
    Servo1_4.attach(3, START_DEGREE_VALUE, SERVO1_4_MIN_PULSE, SERVO1_4_MAX_PULSE);
    Servo1_5.attach(4, START_DEGREE_VALUE, SERVO1_5_MIN_PULSE, SERVO1_5_MAX_PULSE);
    Servo1_6.attach(5, START_DEGREE_VALUE, SERVO1_6_MIN_PULSE, SERVO1_6_MAX_PULSE);
    Servo1_7.attach(6, START_DEGREE_VALUE, SERVO1_7_MIN_PULSE, SERVO1_7_MAX_PULSE);
    Servo1_8.attach(7, START_DEGREE_VALUE, SERVO1_8_MIN_PULSE, SERVO1_8_MAX_PULSE);
    Servo1_9.attach(8, START_DEGREE_VALUE, SERVO1_9_MIN_PULSE, SERVO1_9_MAX_PULSE);

    // Attach all servos on Module 2 with pulse ranges
    Servo2_1.attach(0, START_DEGREE_VALUE, SERVO2_1_MIN_PULSE, SERVO2_1_MAX_PULSE);
    Servo2_2.attach(1, START_DEGREE_VALUE, SERVO2_2_MIN_PULSE, SERVO2_2_MAX_PULSE);
    Servo2_3.attach(2, START_DEGREE_VALUE, SERVO2_3_MIN_PULSE, SERVO2_3_MAX_PULSE);
    Servo2_4.attach(3, START_DEGREE_VALUE, SERVO2_4_MIN_PULSE, SERVO2_4_MAX_PULSE);
    Servo2_5.attach(4, START_DEGREE_VALUE, SERVO2_5_MIN_PULSE, SERVO2_5_MAX_PULSE);
    Servo2_6.attach(5, START_DEGREE_VALUE, SERVO2_6_MIN_PULSE, SERVO2_6_MAX_PULSE);
    Servo2_7.attach(6, START_DEGREE_VALUE, SERVO2_7_MIN_PULSE, SERVO2_7_MAX_PULSE);
    Servo2_8.attach(7, START_DEGREE_VALUE, SERVO2_8_MIN_PULSE, SERVO2_8_MAX_PULSE);
    Servo2_9.attach(8, START_DEGREE_VALUE, SERVO2_9_MIN_PULSE, SERVO2_9_MAX_PULSE);

    // Set default easing type and speed for all servos
    Servo1_1.setEasingType(EASE_CUBIC); Servo1_1.setSpeed(DEFAULT_SPEED);
    Servo1_2.setEasingType(EASE_CUBIC); Servo1_2.setSpeed(DEFAULT_SPEED);
    Servo1_3.setEasingType(EASE_CUBIC); Servo1_3.setSpeed(DEFAULT_SPEED);
    Servo1_4.setEasingType(EASE_CUBIC); Servo1_4.setSpeed(DEFAULT_SPEED);
    Servo1_5.setEasingType(EASE_CUBIC); Servo1_5.setSpeed(DEFAULT_SPEED);
    Servo1_6.setEasingType(EASE_CUBIC); Servo1_6.setSpeed(DEFAULT_SPEED);
    Servo1_7.setEasingType(EASE_CUBIC); Servo1_7.setSpeed(DEFAULT_SPEED);
    Servo1_8.setEasingType(EASE_CUBIC); Servo1_8.setSpeed(DEFAULT_SPEED);
    Servo1_9.setEasingType(EASE_CUBIC); Servo1_9.setSpeed(DEFAULT_SPEED);

    Servo2_1.setEasingType(EASE_CUBIC); Servo2_1.setSpeed(DEFAULT_SPEED);
    Servo2_2.setEasingType(EASE_CUBIC); Servo2_2.setSpeed(DEFAULT_SPEED);
    Servo2_3.setEasingType(EASE_CUBIC); Servo2_3.setSpeed(DEFAULT_SPEED);
    Servo2_4.setEasingType(EASE_CUBIC); Servo2_4.setSpeed(DEFAULT_SPEED);
    Servo2_5.setEasingType(EASE_CUBIC); Servo2_5.setSpeed(DEFAULT_SPEED);
    Servo2_6.setEasingType(EASE_CUBIC); Servo2_6.setSpeed(DEFAULT_SPEED);
    Servo2_7.setEasingType(EASE_CUBIC); Servo2_7.setSpeed(DEFAULT_SPEED);
    Servo2_8.setEasingType(EASE_CUBIC); Servo2_8.setSpeed(DEFAULT_SPEED);
    Servo2_9.setEasingType(EASE_CUBIC); Servo2_9.setSpeed(DEFAULT_SPEED);

    // Wait for the servos to reach the start position
    delay(500);
}

void loop() 
{
    // Example: Move all servos in the first PCA9685 to 90 degrees
    Servo1_1.easeTo(mapDegreeToPulse(90, SERVO1_1_MIN_PULSE, SERVO1_1_MAX_PULSE));
    Servo1_2.easeTo(mapDegreeToPulse(90, SERVO1_2_MIN_PULSE, SERVO1_2_MAX_PULSE));
    Servo1_3.easeTo(mapDegreeToPulse(90, SERVO1_3_MIN_PULSE, SERVO1_3_MAX_PULSE));
    Servo1_4.easeTo(mapDegreeToPulse(90, SERVO1_4_MIN_PULSE, SERVO1_4_MAX_PULSE));
    Servo1_5.easeTo(mapDegreeToPulse(90, SERVO1_5_MIN_PULSE, SERVO1_5_MAX_PULSE));
    Servo1_6.easeTo(mapDegreeToPulse(90, SERVO1_6_MIN_PULSE, SERVO1_6_MAX_PULSE));
    Servo1_7.easeTo(mapDegreeToPulse(90, SERVO1_7_MIN_PULSE, SERVO1_7_MAX_PULSE));
    Servo1_8.easeTo(mapDegreeToPulse(90, SERVO1_8_MIN_PULSE, SERVO1_8_MAX_PULSE));
    Servo1_9.easeTo(mapDegreeToPulse(90, SERVO1_9_MIN_PULSE, SERVO1_9_MAX_PULSE));
    
    delay(2000); // Wait for a while

    // Example: Move all servos in the second PCA9685 to 180 degrees
    Servo2_1.startEaseTo(mapDegreeToPulse(180, SERVO2_1_MIN_PULSE, SERVO2_1_MAX_PULSE));
    Servo2_2.startEaseTo(mapDegreeToPulse(180, SERVO2_2_MIN_PULSE, SERVO2_2_MAX_PULSE));
    Servo2_3.startEaseTo(mapDegreeToPulse(180, SERVO2_3_MIN_PULSE, SERVO2_3_MAX_PULSE));
    Servo2_4.startEaseTo(mapDegreeToPulse(180, SERVO2_4_MIN_PULSE, SERVO2_4_MAX_PULSE));
    Servo2_5.startEaseTo(mapDegreeToPulse(180, SERVO2_5_MIN_PULSE, SERVO2_5_MAX_PULSE));
    Servo2_6.startEaseTo(mapDegreeToPulse(180, SERVO2_6_MIN_PULSE, SERVO2_6_MAX_PULSE));
    Servo2_7.startEaseTo(mapDegreeToPulse(180, SERVO2_7_MIN_PULSE, SERVO2_7_MAX_PULSE));
    Servo2_8.startEaseTo(mapDegreeToPulse(180, SERVO2_8_MIN_PULSE, SERVO2_8_MAX_PULSE));
    Servo2_9.startEaseTo(mapDegreeToPulse(180, SERVO2_9_MIN_PULSE, SERVO2_9_MAX_PULSE));
    
    delay(2000); // Wait for a while
}