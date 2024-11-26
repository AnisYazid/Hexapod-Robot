#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm_R = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver pwm_L = Adafruit_PWMServoDriver(0x42);

// Define pulse width limits for each servo (example values, adjust as needed)
#define SERVO1_A1_MIN_PULSE 600 
#define SERVO1_A1_MAX_PULSE 2600 
#define SERVO1_A2_MIN_PULSE 600 
#define SERVO1_A2_MAX_PULSE 2600 
#define SERVO1_A3_MIN_PULSE 600 
#define SERVO1_A3_MAX_PULSE 2600 
#define SERVO1_B1_MIN_PULSE 600 
#define SERVO1_B1_MAX_PULSE 2600 
#define SERVO1_B2_MIN_PULSE 600 
#define SERVO1_B2_MAX_PULSE 2600 
#define SERVO1_B3_MIN_PULSE 600 
#define SERVO1_B3_MAX_PULSE 2600 
#define SERVO1_C1_MIN_PULSE 600 
#define SERVO1_C1_MAX_PULSE 2600 
#define SERVO1_C2_MIN_PULSE 600 
#define SERVO1_C2_MAX_PULSE 2600 
#define SERVO1_C3_MIN_PULSE 600 
#define SERVO1_C3_MAX_PULSE 2600 
#define SERVO2_D1_MIN_PULSE 600 
#define SERVO2_D1_MAX_PULSE 2600 
#define SERVO2_D2_MIN_PULSE 600 
#define SERVO2_D2_MAX_PULSE 2600 
#define SERVO2_D3_MIN_PULSE 600 
#define SERVO2_D3_MAX_PULSE 2600 
#define SERVO2_E1_MIN_PULSE 600 
#define SERVO2_E1_MAX_PULSE 2600 
#define SERVO2_E2_MIN_PULSE 600 
#define SERVO2_E2_MAX_PULSE 2600 
#define SERVO2_E3_MIN_PULSE 600 
#define SERVO2_E3_MAX_PULSE 2600 
#define SERVO2_F1_MIN_PULSE 600 
#define SERVO2_F1_MAX_PULSE 2600 
#define SERVO2_F2_MIN_PULSE 600 
#define SERVO2_F2_MAX_PULSE 2600 
#define SERVO2_F3_MIN_PULSE 600 
#define SERVO2_F3_MAX_PULSE 2600 


float results[200];
float start = 50;       // Starting value
float endValue = 120;   // Ending value
float duration = 0.25;     // Duration in seconds
int frames = 150;       // Number of frames for the animation


void setup() 
{
    pwm_R.begin();
    pwm_R.setPWMFreq(50); // Set frequency to 50 Hz for servos
    pwm_L.begin();
    pwm_L.setPWMFreq(50); // Set frequency to 50 Hz for servos
 
  
}

void cubicInOutEasing(float start, float endValue, float duration, int frames) {
    float t_values[frames];
    for (int i = 0; i < frames; i++) {
        t_values[i] = (float)i / (frames - 1); // Normalized time from 0 to 1
    }
    for (int i = 0; i < frames; i++) {
        float t = t_values[i];
        if (t < 0.5) {
            results[i] = start + (endValue - start) * (4 * t * t * t); // Ease In
        } else {
            results[i] = start + (endValue - start) * (1 - ((-2 * t + 2) * (-2 * t + 2) * (-2 * t + 2)) / 2); // Ease Out
        }
    }
}

void setServoPosition(Adafruit_PWMServoDriver &pwm, int channel, int angle) {
    int pulseWidth;
    switch (channel) {
        case 0: pulseWidth = map(angle, 0, 180, SERVO1_A1_MIN_PULSE, SERVO1_A1_MAX_PULSE); break;
        case 1: pulseWidth = map(angle, 0, 180, SERVO1_A2_MIN_PULSE, SERVO1_A2_MAX_PULSE); break;
        case 2: pulseWidth = map(angle, 0, 180, SERVO1_A3_MIN_PULSE, SERVO1_A3_MAX_PULSE); break;
        case 3: pulseWidth = map(angle, 0, 180, SERVO1_B1_MIN_PULSE, SERVO1_B1_MAX_PULSE); break;
        case 4: pulseWidth = map(angle, 0, 180, SERVO1_B2_MIN_PULSE, SERVO1_B2_MAX_PULSE); break;
        case 5: pulseWidth = map(angle, 0, 180, SERVO1_B3_MIN_PULSE, SERVO1_B3_MAX_PULSE); break;
        case 6: pulseWidth = map(angle, 0, 180, SERVO1_C1_MIN_PULSE, SERVO1_C1_MAX_PULSE); break;
        case 7: pulseWidth = map(angle, 0, 180, SERVO1_C2_MIN_PULSE, SERVO1_C2_MAX_PULSE); break;
        case 8: pulseWidth = map(angle, 0, 180, SERVO1_C3_MIN_PULSE, SERVO1_C3_MAX_PULSE); break;
        case 9: pulseWidth = map(angle, 0, 180, SERVO2_D1_MIN_PULSE, SERVO2_D1_MAX_PULSE); break;
        case 10: pulseWidth = map(angle, 0, 180, SERVO2_D2_MIN_PULSE, SERVO2_D2_MAX_PULSE); break;
        case 11: pulseWidth = map(angle, 0, 180, SERVO2_D3_MIN_PULSE, SERVO2_D3_MAX_PULSE); break;
        case 12: pulseWidth = map(angle, 0, 180, SERVO2_E1_MIN_PULSE, SERVO2_E1_MAX_PULSE); break;
        case 13: pulseWidth = map(angle, 0, 180, SERVO2_E2_MIN_PULSE, SERVO2_E2_MAX_PULSE); break;
        case 14: pulseWidth = map(angle, 0, 180, SERVO2_E3_MIN_PULSE, SERVO2_E3_MAX_PULSE); break;
        case 15: pulseWidth = map(angle, 0, 180, SERVO2_F1_MIN_PULSE, SERVO2_F1_MAX_PULSE); break;
        case 16: pulseWidth = map(angle, 0, 180, SERVO2_F2_MIN_PULSE, SERVO2_F2_MAX_PULSE); break;
        case 17: pulseWidth = map(angle, 0, 180, SERVO2_F3_MIN_PULSE, SERVO2_F3_MAX_PULSE); break;
        default: pulseWidth = SERVO1_A1_MIN_PULSE; break; // Default case
    }
    int pulseValue = int(float(pulseWidth) / 1000000 * 50 * 4096);
    pwm.setPWM(channel, 0, pulseValue);
}

void UP_DW() 
{
 cubicInOutEasing(start, endValue, duration, frames);
  for (int i = 0; i < frames; i++) 
    {
    setServoPosition(pwm_L, 2, 90);      // A1
    setServoPosition(pwm_L, 1, results[i]);     // A2
    setServoPosition(pwm_L, 0, results[i]);     // A3
    
    setServoPosition(pwm_L, 6, 90);      // B1
    setServoPosition(pwm_L, 5, results[i]);     // B2
    setServoPosition(pwm_L, 4, results[i]);     // B3
    
    setServoPosition(pwm_L, 15, 90);     // C1
    setServoPosition(pwm_L, 14, results[i]);    // C2
    setServoPosition(pwm_L, 13, results[i]);    // C3
   
    setServoPosition(pwm_R, 15, 90);     // D1
    setServoPosition(pwm_R, 14, results[i]);     // D2
    setServoPosition(pwm_R, 13, results[i]);     // D3
   
    setServoPosition(pwm_R, 6, 90);      // E1
    setServoPosition(pwm_R, 5, results[i]);      // E2
    setServoPosition(pwm_R, 4, results[i]);       // E3
   
    setServoPosition(pwm_R, 2, 90);     // F1
    setServoPosition(pwm_R, 1, results[i]);      // F2
    setServoPosition(pwm_R, 0, results[i]);       // F3
        
        delay((duration * 1000) / frames); // Delay to match the frame rate
    }

    delay(2000);
    cubicInOutEasing(endValue, start, duration, frames);
      for (int i = 0; i < frames; i++) 
    {
    setServoPosition(pwm_L, 2, 90);      // A1
    setServoPosition(pwm_L, 1, results[i]);     // A2
    setServoPosition(pwm_L, 0, results[i]);     // A3
    
    setServoPosition(pwm_L, 6, 90);      // B1
    setServoPosition(pwm_L, 5, results[i]);     // B2
    setServoPosition(pwm_L, 4, results[i]);     // B3
    
    setServoPosition(pwm_L, 15, 90);     // C1
    setServoPosition(pwm_L, 14, results[i]);    // C2
    setServoPosition(pwm_L, 13, results[i]);    // C3
   
    setServoPosition(pwm_R, 15, 90);     // D1
    setServoPosition(pwm_R, 14, results[i]);     // D2
    setServoPosition(pwm_R, 13, results[i]);     // D3
   
    setServoPosition(pwm_R, 6, 90);      // E1
    setServoPosition(pwm_R, 5, results[i]);      // E2
    setServoPosition(pwm_R, 4, results[i]);       // E3
   
    setServoPosition(pwm_R, 2, 90);     // F1
    setServoPosition(pwm_R, 1, results[i]);      // F2
    setServoPosition(pwm_R, 0, results[i]);       // F3
        
        delay((duration * 1000) / frames); // Delay to match the frame rate
    }

    delay(2000);
}



void D_G() {


    // Interpolate angles for a smooth transition
    cubicInOutEasing(120, 50, duration, frames); // For T values (PWM_L increasing)
    cubicInOutEasing(50, 120, duration, frames); // For A values (PWM_R decreasing)

    for (int i = 0; i < frames; i++)
    {
        // Tilt for left servos
        setServoPosition(pwm_L, 2, 90);          // A1
        setServoPosition(pwm_L, 1, results[i]);  // A2
        setServoPosition(pwm_L, 0, results[i]);  // A3

        setServoPosition(pwm_L, 6, 90);          // B1
        setServoPosition(pwm_L, 5, results[i]);  // B2
        setServoPosition(pwm_L, 4, results[i]);  // B3

        setServoPosition(pwm_L, 15, 90);         // C1
        setServoPosition(pwm_L, 14, results[i]); // C2
        setServoPosition(pwm_L, 13, results[i]); // C3

        // Tilt for right servos
        setServoPosition(pwm_R, 15, 90);         // D1
        setServoPosition(pwm_R, 14, results[frames - i - 1]); // D2 (decreasing)
        setServoPosition(pwm_R, 13, results[frames - i - 1]); // D3 (decreasing)

        setServoPosition(pwm_R, 6, 90);          // E1
        setServoPosition(pwm_R, 5, results[frames - i - 1]);  // E2 (decreasing)
        setServoPosition(pwm_R, 4, results[frames - i - 1]);  // E3 (decreasing)

        setServoPosition(pwm_R, 2, 90);          // F1
        setServoPosition(pwm_R, 1, results[frames - i - 1]);  // F2 (decreasing)
        setServoPosition(pwm_R, 0, results[frames - i - 1]);  // F3 (decreasing)

        // Delay to match the frame rate
        delay((duration * 1000) / frames);
    }


delay(2000);



}



void loop() {

   D_G(); // Call the function to update servo positions
}