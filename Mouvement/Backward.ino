#include <Wire.h>
#include <Adafruit_PWMServoDriver.h> // Include the PWM driver library

// Define addresses for the two PCA9685 modules
Adafruit_PWMServoDriver pwm_R = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver pwm_L = Adafruit_PWMServoDriver(0x42);

// Define pulse values for each servo

// Module 1 Servos/////////////////////////////////////////////////////////////////////

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

// Module 2 Servos //////////////////////////////////////////////////////////////////////////

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

void setup()
{
    Serial.begin(115200);
    pwm_R.begin();
    pwm_R.setPWMFreq(50); // Set frequency to 50 Hz for servos

    pwm_L.begin();
    pwm_L.setPWMFreq(50); // Set frequency to 50 Hz for servos
}

void loop()
{
    backward(); 
}

void backward() 
{
       setServoPosition(pwm_L, 1, 105);     // A2
       setServoPosition(pwm_R, 5, 60);      // E2
       setServoPosition(pwm_L, 14, 120);    // C2
       ////
       setServoPosition(pwm_L, 0, 160);     // A3
       setServoPosition(pwm_R, 4, 5);       // E3
       setServoPosition(pwm_L, 13, 185);    // C3

        delay(300);

       setServoPosition(pwm_L, 2, 90);      // A1
       setServoPosition(pwm_R, 6, 85);      // E1
       setServoPosition(pwm_L, 15, 90);     // C1
       //// 
       setServoPosition(pwm_R, 15, 80);     // D1
       setServoPosition(pwm_L, 6, 85);      // B1
       setServoPosition(pwm_R, 2, 100);     // F1

        delay(300);  

       setServoPosition(pwm_L, 1, 105);     // A2
       setServoPosition(pwm_R, 5, 60);      // E2
       setServoPosition(pwm_L, 14, 120);    // C2
       ////
       setServoPosition(pwm_L, 0, 160);     // A3
       setServoPosition(pwm_R, 4, 5);       // E3
       setServoPosition(pwm_L, 13, 185);    // C3

        delay(1000);

       //////////////////////////////////////////////////////////

       setServoPosition(pwm_R, 14, 65);     // D2
       setServoPosition(pwm_L, 5, 120);     // B2
       setServoPosition(pwm_L, 5, 120);     // B2
       ////
       setServoPosition(pwm_R, 13, 25);     // D3
       setServoPosition(pwm_L, 4, 170);     // B3
       setServoPosition(pwm_R, 0, 0);       // F3

        delay(300);

       setServoPosition(pwm_R, 15, 80);     // D1
       setServoPosition(pwm_L, 6, 85);      // B1
       setServoPosition(pwm_R, 2, 100);     // F1
       ////
       setServoPosition(pwm_L, 2, 90);      // A1
       setServoPosition(pwm_R, 6, 85);      // E1
       setServoPosition(pwm_L, 15, 90);     // C1

        delay(300);
       setServoPosition(pwm_R, 14, 65);     // D2
       setServoPosition(pwm_L, 5, 120);     // B2
       setServoPosition(pwm_L, 5, 120);     // B2
       ////
       setServoPosition(pwm_R, 13, 25);     // D3
       setServoPosition(pwm_L, 4, 170);     // B3
       setServoPosition(pwm_R, 0, 0);       // F3

        delay(1000);

}

void setServoPosition(Adafruit_PWMServoDriver &pwm, int channel, int angle) 
{
    int pulseWidth;

    // Determine pulseWidth based on the angle
    switch (channel) 
    {
        case 0: // A1
            pulseWidth = map(angle, 0, 180, SERVO1_A1_MIN_PULSE, SERVO1_A1_MAX_PULSE);
            break;
        case 1: // A2
            pulseWidth = map(angle, 0, 180, SERVO1_A2_MIN_PULSE, SERVO1_A2_MAX_PULSE);
            break;
        case 2: // A3
            pulseWidth = map(angle, 0, 180, SERVO1_A3_MIN_PULSE, SERVO1_A3_MAX_PULSE);
            break;
        case 3: // B1
            pulseWidth = map(angle, 0, 180, SERVO1_B1_MIN_PULSE, SERVO1_B1_MAX_PULSE);
            break;
        case 4: // B2
            pulseWidth = map(angle, 0, 180, SERVO1_B2_MIN_PULSE, SERVO1_B2_MAX_PULSE);
            break;
        case 5: // B3
            pulseWidth = map(angle, 0, 180, SERVO1_B3_MIN_PULSE, SERVO1_B3_MAX_PULSE);
            break;
        case 6: // C1
            pulseWidth = map(angle, 0, 180, SERVO1_C1_MIN_PULSE, SERVO1_C1_MAX_PULSE);
            break;
        case 7: // C2
            pulseWidth = map(angle, 0, 180, SERVO1_C2_MIN_PULSE, SERVO1_C2_MAX_PULSE);
            break;
        case 8: // C3
            pulseWidth = map(angle, 0, 180, SERVO1_C3_MIN_PULSE, SERVO1_C3_MAX_PULSE);
            break;
        case 9: // D1
            pulseWidth = map(angle, 0, 180, SERVO2_D1_MIN_PULSE, SERVO2_D1_MAX_PULSE);
            break;
        case 10: // D2
            pulseWidth = map(angle, 0, 180, SERVO2_D2_MIN_PULSE, SERVO2_D2_MAX_PULSE);
            break;
        case 11: // D3
            pulseWidth = map(angle, 0, 180, SERVO2_D3_MIN_PULSE, SERVO2_D3_MAX_PULSE);
            break;
        case 12: // E1
            pulseWidth = map(angle, 0, 180, SERVO2_E1_MIN_PULSE, SERVO2_E1_MAX_PULSE);
            break;
        case 13: // E2
            pulseWidth = map(angle, 0, 180, SERVO2_E2_MIN_PULSE, SERVO2_E2_MAX_PULSE);
            break;
        case 14: // E3
            pulseWidth = map(angle, 0, 180, SERVO2_E3_MIN_PULSE, SERVO2_E3_MAX_PULSE);
            break;
        case 15: // F1
            pulseWidth = map(angle, 0, 180, SERVO2_F1_MIN_PULSE, SERVO2_F1_MAX_PULSE);
            break;
        case 16: // F2
            pulseWidth = map(angle, 0, 180, SERVO2_F2_MIN_PULSE, SERVO2_F2_MAX_PULSE);
            break;
        case 17: // F3
            pulseWidth = map(angle, 0, 180, SERVO2_F3_MIN_PULSE, SERVO2_F3_MAX_PULSE);
            break;
        default:
            pulseWidth = SERVO1_A1_MIN_PULSE; // Default case if channel is not recognized
            break;
    }

    // Calculate the PWM value
    int pulseValue = int(float(pulseWidth) / 1000000 * 50 * 4096);
    
    // Set the PWM on the specified channel
    pwm.setPWM(channel, 0, pulseValue);
}