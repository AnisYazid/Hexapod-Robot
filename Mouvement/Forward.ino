#include <Arduino.h>
#include "ServoEasing.hpp" // Include the ServoEasing library

#define PCA9685_ADDRESS_1 0x40
#define PCA9685_ADDRESS_2 0x41

// Create ServoEasing objects for each servo
ServoEasing Servo1_A1(PCA9685_ADDRESS_1);
ServoEasing Servo1_A2(PCA9685_ADDRESS_1);
ServoEasing Servo1_A3(PCA9685_ADDRESS_1);
ServoEasing Servo1_B1(PCA9685_ADDRESS_1);
ServoEasing Servo1_B2(PCA9685_ADDRESS_1);
ServoEasing Servo1_B3(PCA9685_ADDRESS_1);
ServoEasing Servo1_C1(PCA9685_ADDRESS_1);
ServoEasing Servo1_C2(PCA9685_ADDRESS_1);
ServoEasing Servo1_C3(PCA9685_ADDRESS_1);

ServoEasing Servo2_D1(PCA9685_ADDRESS_2);
ServoEasing Servo2_D2(PCA9685_ADDRESS_2);
ServoEasing Servo2_D3(PCA9685_ADDRESS_2);
ServoEasing Servo2_E1(PCA9685_ADDRESS_2);
ServoEasing Servo2_E2(PCA9685_ADDRESS_2);
ServoEasing Servo2_E3(PCA9685_ADDRESS_2);
ServoEasing Servo2_F1(PCA9685_ADDRESS_2);
ServoEasing Servo2_F2(PCA9685_ADDRESS_2);
ServoEasing Servo2_F3(PCA9685_ADDRESS_2);

// Define pulse values for each servo
#define SERVO1_A1_MIN_PULSE 1000
#define SERVO1_A1_MAX_PULSE 2000
#define SERVO1_A2_MIN_PULSE 1000
#define SERVO1_A2_MAX_PULSE 2000
#define SERVO1_A3_MIN_PULSE 1000
#define SERVO1_A3_MAX_PULSE 2000
#define SERVO1_B1_MIN_PULSE 1000
#define SERVO1_B1_MAX_PULSE 2000
#define SERVO1_B2_MIN_PULSE 1000
#define SERVO1_B2_MAX_PULSE 2000
#define SERVO1_B3_MIN_PULSE 1000
#define SERVO1_B3_MAX_PULSE 2000
#define SERVO1_C1_MIN_PULSE 1000
#define SERVO1_C1_MAX_PULSE 2000
#define SERVO1_C2_MIN_PULSE 1000
#define SERVO1_C2_MAX_PULSE 2000
#define SERVO1_C3_MIN_PULSE 1000
#define SERVO1_C3_MAX_PULSE 2000

#define SERVO2_D1_MIN_PULSE 1000
#define SERVO2_D1_MAX_PULSE 2000
#define SERVO2_D2_MIN_PULSE 1000
#define SERVO2_D2_MAX_PULSE 2000
#define SERVO2_D3_MIN_PULSE 1000
#define SERVO2_D3_MAX_PULSE 2000
#define SERVO2_E1_MIN_PULSE 1000
#define SERVO2_E1_MAX_PULSE 2000
#define SERVO2_E2_MIN_PULSE 1000
#define SERVO2_E2_MAX_PULSE 2000
#define SERVO2_E3_MIN_PULSE 1000
#define SERVO2_E3_MAX_PULSE 2000
#define SERVO2_F1_MIN_PULSE 1000
#define SERVO2_F1_MAX_PULSE 2000
#define SERVO2_F2_MIN_PULSE 1000
#define SERVO2_F2_MAX_PULSE 2000
#define SERVO2_F3_MIN_PULSE 1000
#define SERVO2_F3_MAX_PULSE 2000

// Mapping function
unsigned int mapDegreeToPulse(int degree, unsigned int minPulse, unsigned int maxPulse) {
    return (degree * (maxPulse - minPulse) / 180) + minPulse;
}

// Forward movement function
void For() 
{
   /* Servo1_A1.easeTo(mapDegreeToPulse(80, SERVO1_A1_MIN_PULSE, SERVO1_A1_MAX_PULSE)); 
    Servo1_B2.easeTo(mapDegreeToPulse(80, SERVO1_B2_MIN_PULSE, SERVO1_B2_MAX_PULSE)); 
    Servo1_A2.easeTo(mapDegreeToPulse(80, SERVO1_A2_MIN_PULSE, SERVO1_A2_MAX_PULSE)); */

}

void setup() {
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

    // Attach all servos on Module 1 with pulse ranges
    Servo1_A1.attach(0, 0, SERVO1_A1_MIN_PULSE, SERVO1_A1_MAX_PULSE);
    Servo1_A2.attach(1, 0, SERVO1_A2_MIN_PULSE, SERVO1_A2_MAX_PULSE);
    Servo1_A3.attach(2, 0, SERVO1_A3_MIN_PULSE, SERVO1_A3_MAX_PULSE);
    Servo1_B1.attach(3, 0, SERVO1_B1_MIN_PULSE, SERVO1_B1_MAX_PULSE);
    Servo1_B2.attach(4, 0, SERVO1_B2_MIN_PULSE, SERVO1_B2_MAX_PULSE);
    Servo1_B3.attach(5, 0, SERVO1_B3_MIN_PULSE, SERVO1_B3_MAX_PULSE);
    Servo1_C1.attach(6, 0, SERVO1_C1_MIN_PULSE, SERVO1_C1_MAX_PULSE);
    Servo1_C2.attach(7, 0, SERVO1_C2_MIN_PULSE, SERVO1_C2_MAX_PULSE);
    Servo1_C3.attach(8, 0, SERVO1_C3_MIN_PULSE, SERVO1_C3_MAX_PULSE);

    // Attach all servos on Module 2 with pulse ranges
    Servo2_D1.attach(0, 0, SERVO2_D1_MIN_PULSE, SERVO2_D1_MAX_PULSE);
    Servo2_D2.attach(1, 0, SERVO2_D2_MIN_PULSE, SERVO2_D2_MAX_PULSE);
    Servo2_D3.attach(2, 0, SERVO2_D3_MIN_PULSE, SERVO2_D3_MAX_PULSE);
    Servo2_E1.attach(3, 0, SERVO2_E1_MIN_PULSE, SERVO2_E1_MAX_PULSE);
    Servo2_E2.attach(4, 0, SERVO2_E2_MIN_PULSE, SERVO2_E2_MAX_PULSE);
    Servo2_E3.attach(5, 0, SERVO2_E3_MIN_PULSE, SERVO2_E3_MAX_PULSE);
    Servo2_F1.attach(6, 0, SERVO2_F1_MIN_PULSE, SERVO2_F1_MAX_PULSE);
    Servo2_F2.attach(7, 0, SERVO2_F2_MIN_PULSE, SERVO2_F2_MAX_PULSE);
    Servo2_F3.attach(8, 0, SERVO2_F3_MIN_PULSE, SERVO2_F3_MAX_PULSE);

    delay(500); // Allow servos to initialize
}

void loop() 
{
    For(); // Call the forward movement function
    delay(2000); // Wait before repeating
}