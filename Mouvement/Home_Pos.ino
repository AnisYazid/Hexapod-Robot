#include <Arduino.h>
#include "ServoEasing.hpp" // Include the ServoEasing library

// Define easing types
#define ENABLE_EASE_CUBIC

// Define addresses for the two PCA9685 modules
#define PCA9685_ADDRESS_1 0x42
#define PCA9685_ADDRESS_2 0x41

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Create ServoEasing objects for each servo in both PCA9685 modules
ServoEasing Servo1_A1(PCA9685_ADDRESS_1); // Servo 1 on PCA9685 Module 1
ServoEasing Servo1_A2(PCA9685_ADDRESS_1); // Servo 2 on PCA9685 Module 1
ServoEasing Servo1_A3(PCA9685_ADDRESS_1); // Servo 3 on PCA9685 Module 1
ServoEasing Servo1_B1(PCA9685_ADDRESS_1); // Servo 4 on PCA9685 Module 1
ServoEasing Servo1_B2(PCA9685_ADDRESS_1); // Servo 5 on PCA9685 Module 1
ServoEasing Servo1_B3(PCA9685_ADDRESS_1); // Servo 6 on PCA9685 Module 1
ServoEasing Servo1_C1(PCA9685_ADDRESS_1); // Servo 7 on PCA9685 Module 1
ServoEasing Servo1_C2(PCA9685_ADDRESS_1); // Servo 8 on PCA9685 Module 1
ServoEasing Servo1_C3(PCA9685_ADDRESS_1); // Servo 9 on PCA9685 Module 1

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

ServoEasing Servo2_D1(PCA9685_ADDRESS_2); // Servo 1 on PCA9685 Module 2
ServoEasing Servo2_D2(PCA9685_ADDRESS_2); // Servo 2 on PCA9685 Module 2
ServoEasing Servo2_D3(PCA9685_ADDRESS_2); // Servo 3 on PCA9685 Module 2
ServoEasing Servo2_E1(PCA9685_ADDRESS_2); // Servo 4 on PCA9685 Module 2
ServoEasing Servo2_E2(PCA9685_ADDRESS_2); // Servo 5 on PCA9685 Module 2
ServoEasing Servo2_E3(PCA9685_ADDRESS_2); // Servo 6 on PCA9685 Module 2
ServoEasing Servo2_F1(PCA9685_ADDRESS_2); // Servo 7 on PCA9685 Module 2
ServoEasing Servo2_F2(PCA9685_ADDRESS_2); // Servo 8 on PCA9685 Module 2
ServoEasing Servo2_F3(PCA9685_ADDRESS_2); // Servo 9 on PCA9685 Module 2

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Define pulse values for each servo

#define SERVO1_A1_MIN_PULSE 600 // Minimum pulse width for Servo 1 on Module 1
#define SERVO1_A1_MAX_PULSE 2600 // Maximum pulse width for Servo 1 on Module 1

#define SERVO1_A2_MIN_PULSE 600 // Minimum pulse width for Servo 2 on Module 1
#define SERVO1_A2_MAX_PULSE 2600 // Maximum pulse width for Servo 2 on Module 1

#define SERVO1_A3_MIN_PULSE 600 // Minimum pulse width for Servo 3 on Module 1
#define SERVO1_A3_MAX_PULSE 2600 // Maximum pulse width for Servo 3 on Module 1

#define SERVO1_B1_MIN_PULSE 600 // Minimum pulse width for Servo 4 on Module 1
#define SERVO1_B1_MAX_PULSE 2600 // Maximum pulse width for Servo 4 on Module 1

#define SERVO1_B2_MIN_PULSE 600 // Minimum pulse width for Servo 5 on Module 1
#define SERVO1_B2_MAX_PULSE 2600 // Maximum pulse width for Servo 5 on Module 1

#define SERVO1_B3_MIN_PULSE 600 // Minimum pulse width for Servo 6 on Module 1
#define SERVO1_B3_MAX_PULSE 2500 // Maximum pulse width for Servo 6 on Module 1

#define SERVO1_C1_MIN_PULSE 600 // Minimum pulse width for Servo 7 on Module 1
#define SERVO1_C1_MAX_PULSE 2600 // Maximum pulse width for Servo 7 on Module 1

#define SERVO1_C2_MIN_PULSE 500 // Minimum pulse width for Servo 8 on Module 1
#define SERVO1_C2_MAX_PULSE 2600 // Maximum pulse width for Servo 8 on Module 1

#define SERVO1_C3_MIN_PULSE 800 // Minimum pulse width for Servo 9 on Module 1
#define SERVO1_C3_MAX_PULSE 2700 // Maximum pulse width for Servo 9 on Module 1

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define SERVO2_D1_MIN_PULSE 500 // Minimum pulse width for Servo 1 on Module 2
#define SERVO2_D1_MAX_PULSE 2500 // Maximum pulse width for Servo 1 on Module 2

#define SERVO2_D2_MIN_PULSE 700 // Minimum pulse width for Servo 2 on Module 2
#define SERVO2_D2_MAX_PULSE 2600 // Maximum pulse width for Servo 2 on Module 2

#define SERVO2_D3_MIN_PULSE 800 // Minimum pulse width for Servo 3 on Module 2
#define SERVO2_D3_MAX_PULSE 2700 // Maximum pulse width for Servo 3 on Module 2

#define SERVO2_E1_MIN_PULSE 600 // Minimum pulse width for Servo 4 on Module 2
#define SERVO2_E1_MAX_PULSE 2600 // Maximum pulse width for Servo 4 on Module 2

#define SERVO2_E2_MIN_PULSE 500 // Minimum pulse width for Servo 5 on Module 2
#define SERVO2_E2_MAX_PULSE 2600 // Maximum pulse width for Servo 5 on Module 2

#define SERVO2_E3_MIN_PULSE 600 // Minimum pulse width for Servo 6 on Module 2
#define SERVO2_E3_MAX_PULSE 2600 // Maximum pulse width for Servo 6 on Module 2

#define SERVO2_F1_MIN_PULSE 600 // Minimum pulse width for Servo 7 on Module 2
#define SERVO2_F1_MAX_PULSE 2600 // Maximum pulse width for Servo 7 on Module 2

#define SERVO2_F2_MIN_PULSE 500 // Minimum pulse width for Servo 8 on Module 2
#define SERVO2_F2_MAX_PULSE 2700 // Maximum pulse width for Servo 8 on Module 2

#define SERVO2_F3_MIN_PULSE 600 // Minimum pulse width for Servo 9 on Module 2
#define SERVO2_F3_MAX_PULSE 2600 // Maximum pulse width for Servo 9 on Module 2

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define START_DEGREE_VALUE 0 // Initial position for all servos
#define DEFAULT_SPEED 10      // Default speed for all servos

// Define home positions for servos (to be set later)
int homePositions[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0,  // Servo 1 to 9 on Module 1
                         0, 0, 0, 0, 0, 0, 0, 0}; // Servo 1 to 9 on Module 2

// Simplified mapping function
unsigned int mapDegreeToPulse(int degree, unsigned int minPulse, unsigned int maxPulse)
{
    return (degree * (maxPulse - minPulse) / 180) + minPulse;
}

// Function to set all servos to their home positions
void home() 
{
    // Move all servos to their home positions
    Servo1_A1.easeTo(mapDegreeToPulse(homePositions[0], SERVO1_A1_MIN_PULSE, SERVO1_A1_MAX_PULSE));
    Servo1_A2.easeTo(mapDegreeToPulse(homePositions[1], SERVO1_A2_MIN_PULSE, SERVO1_A2_MAX_PULSE));
    Servo1_A3.easeTo(mapDegreeToPulse(homePositions[2], SERVO1_A3_MIN_PULSE, SERVO1_A3_MAX_PULSE));
    Servo1_B1.easeTo(mapDegreeToPulse(homePositions[3], SERVO1_B1_MIN_PULSE, SERVO1_B1_MAX_PULSE));
    Servo1_B2.easeTo(mapDegreeToPulse(homePositions[4], SERVO1_B2_MIN_PULSE, SERVO1_B2_MAX_PULSE));
    Servo1_B3.easeTo(mapDegreeToPulse(homePositions[5], SERVO1_B3_MIN_PULSE, SERVO1_B3_MAX_PULSE));
    Servo1_C1.easeTo(mapDegreeToPulse(homePositions[6], SERVO1_C1_MIN_PULSE, SERVO1_C1_MAX_PULSE));
    Servo1_C2.easeTo(mapDegreeToPulse(homePositions[7], SERVO1_C2_MIN_PULSE, SERVO1_C2_MAX_PULSE));
    Servo1_C3.easeTo(mapDegreeToPulse(homePositions[8], SERVO1_C3_MIN_PULSE, SERVO1_C3_MAX_PULSE));

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Servo2_D1.easeTo(mapDegreeToPulse(homePositions[9] , SERVO2_D1_MIN_PULSE, SERVO2_D1_MAX_PULSE));
    Servo2_D2.easeTo(mapDegreeToPulse(homePositions[10], SERVO2_D2_MIN_PULSE, SERVO2_D2_MAX_PULSE));
    Servo2_D3.easeTo(mapDegreeToPulse(homePositions[11], SERVO2_D3_MIN_PULSE, SERVO2_D3_MAX_PULSE));
    Servo2_E1.easeTo(mapDegreeToPulse(homePositions[12], SERVO2_E1_MIN_PULSE, SERVO2_E1_MAX_PULSE));
    Servo2_E2.easeTo(mapDegreeToPulse(homePositions[13], SERVO2_E2_MIN_PULSE, SERVO2_E2_MAX_PULSE));
    Servo2_E3.easeTo(mapDegreeToPulse(homePositions[14], SERVO2_E3_MIN_PULSE, SERVO2_E3_MAX_PULSE));
    Servo2_F1.easeTo(mapDegreeToPulse(homePositions[15], SERVO2_F1_MIN_PULSE, SERVO2_F1_MAX_PULSE));
    Servo2_F2.easeTo(mapDegreeToPulse(homePositions[16], SERVO2_F2_MIN_PULSE, SERVO2_F2_MAX_PULSE));
    Servo2_F3.easeTo(mapDegreeToPulse(homePositions[17], SERVO2_F3_MIN_PULSE, SERVO2_F3_MAX_PULSE));
}

void setup()
 {
    Serial.begin(115200);
    
    // Initialize the PCA9685 modules and attach the servos
    if (Servo1_A1.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_A2.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_A3.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_B1.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_B2.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_B3.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_C1.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_C2.InitializeAndCheckI2CConnection(&Serial) ||
        Servo1_C3.InitializeAndCheckI2CConnection(&Serial)) 
        {
        Serial.println("Failed to connect to PCA9685 Module 1.");
        while (true);
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (Servo2_D1.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_D2.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_D3.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_E1.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_E2.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_E3.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_F1.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_F2.InitializeAndCheckI2CConnection(&Serial) ||
        Servo2_F3.InitializeAndCheckI2CConnection(&Serial)) 
        {
        Serial.println("Failed to connect to PCA9685 Module 2.");
        while (true);
        }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Attach all servos on Module 1 with pulse ranges
    Servo1_A1.attach(0, START_DEGREE_VALUE, SERVO1_1_MIN_PULSE, SERVO1_1_MAX_PULSE);
    Servo1_A2.attach(1, START_DEGREE_VALUE, SERVO1_2_MIN_PULSE, SERVO1_2_MAX_PULSE);
    Servo1_A3.attach(2, START_DEGREE_VALUE, SERVO1_3_MIN_PULSE, SERVO1_3_MAX_PULSE);
    Servo1_B1.attach(3, START_DEGREE_VALUE, SERVO1_4_MIN_PULSE, SERVO1_4_MAX_PULSE);
    Servo1_B2.attach(4, START_DEGREE_VALUE, SERVO1_5_MIN_PULSE, SERVO1_5_MAX_PULSE);
    Servo1_B3.attach(5, START_DEGREE_VALUE, SERVO1_6_MIN_PULSE, SERVO1_6_MAX_PULSE);
    Servo1_C1.attach(6, START_DEGREE_VALUE, SERVO1_7_MIN_PULSE, SERVO1_7_MAX_PULSE);
    Servo1_C2.attach(7, START_DEGREE_VALUE, SERVO1_8_MIN_PULSE, SERVO1_8_MAX_PULSE);
    Servo1_C3.attach(8, START_DEGREE_VALUE, SERVO1_9_MIN_PULSE, SERVO1_9_MAX_PULSE);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Attach all servos on Module 2 with pulse ranges
    Servo2_D1.attach(0, START_DEGREE_VALUE, SERVO2_1_MIN_PULSE, SERVO2_1_MAX_PULSE);
    Servo2_D2.attach(1, START_DEGREE_VALUE, SERVO2_2_MIN_PULSE, SERVO2_2_MAX_PULSE);
    Servo2_D3.attach(2, START_DEGREE_VALUE, SERVO2_3_MIN_PULSE, SERVO2_3_MAX_PULSE);
    Servo2_E1.attach(3, START_DEGREE_VALUE, SERVO2_4_MIN_PULSE, SERVO2_4_MAX_PULSE);
    Servo2_E2.attach(4, START_DEGREE_VALUE, SERVO2_5_MIN_PULSE, SERVO2_5_MAX_PULSE);
    Servo2_E3.attach(5, START_DEGREE_VALUE, SERVO2_6_MIN_PULSE, SERVO2_6_MAX_PULSE);
    Servo2_F1.attach(6, START_DEGREE_VALUE, SERVO2_7_MIN_PULSE, SERVO2_7_MAX_PULSE);
    Servo2_F2.attach(7, START_DEGREE_VALUE, SERVO2_8_MIN_PULSE, SERVO2_8_MAX_PULSE);
    Servo2_F3.attach(8, START_DEGREE_VALUE, SERVO2_9_MIN_PULSE, SERVO2_9_MAX_PULSE);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////    

    // Set default easing type and speed for all servos
    Servo1_A1.setEasingType(EASE_CUBIC); Servo1_1.setSpeed(DEFAULT_SPEED);
    Servo1_A2.setEasingType(EASE_CUBIC); Servo1_2.setSpeed(DEFAULT_SPEED);
    Servo1_A3.setEasingType(EASE_CUBIC); Servo1_3.setSpeed(DEFAULT_SPEED);
    Servo1_B1.setEasingType(EASE_CUBIC); Servo1_4.setSpeed(DEFAULT_SPEED);
    Servo1_B2.setEasingType(EASE_CUBIC); Servo1_5.setSpeed(DEFAULT_SPEED);
    Servo1_B3.setEasingType(EASE_CUBIC); Servo1_6.setSpeed(DEFAULT_SPEED);
    Servo1_C1.setEasingType(EASE_CUBIC); Servo1_7.setSpeed(DEFAULT_SPEED);
    Servo1_C2.setEasingType(EASE_CUBIC); Servo1_8.setSpeed(DEFAULT_SPEED);
    Servo1_C3.setEasingType(EASE_CUBIC); Servo1_9.setSpeed(DEFAULT_SPEED);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Servo2_D1.setEasingType(EASE_CUBIC); Servo2_1.setSpeed(DEFAULT_SPEED);
    Servo2_D2.setEasingType(EASE_CUBIC); Servo2_2.setSpeed(DEFAULT_SPEED);
    Servo2_D3.setEasingType(EASE_CUBIC); Servo2_3.setSpeed(DEFAULT_SPEED);
    Servo2_E1.setEasingType(EASE_CUBIC); Servo2_4.setSpeed(DEFAULT_SPEED);
    Servo2_E2.setEasingType(EASE_CUBIC); Servo2_5.setSpeed(DEFAULT_SPEED);
    Servo2_E3.setEasingType(EASE_CUBIC); Servo2_6.setSpeed(DEFAULT_SPEED);
    Servo2_F1.setEasingType(EASE_CUBIC); Servo2_7.setSpeed(DEFAULT_SPEED);
    Servo2_F2.setEasingType(EASE_CUBIC); Servo2_8.setSpeed(DEFAULT_SPEED);
    Servo2_F3.setEasingType(EASE_CUBIC); Servo2_9.setSpeed(DEFAULT_SPEED);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////    

    // Wait for the servos to reach the start position
    delay(500);
}

void loop()
 {
    // Call home function to move servos to their home positions
    home();
    delay(2000); // Wait before repeating
}