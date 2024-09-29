#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x42); // Ensure this is the correct I2C address

const int SERVOMIN = 600;   // Minimum pulse width in microseconds
const int SERVOMAX = 2400;  // Maximum pulse width in microseconds

void setup() 
{
    Serial.begin(115200); // Start serial communication for debugging
    pwm.begin();
    pwm.setPWMFreq(50); // Set frequency to 50 Hz for servos

    // Start at minimum position
    setServoPosition(SERVOMIN);
    delay(2000); // Allow time for the servo to reach the position
}

void loop() 
{
    // Ramp up to maximum
    rampServo(SERVOMIN, SERVOMAX, 2000); // Ramp from min to max in 2000 ms
    delay(2000); // Wait at max position

    // Ramp down to minimum
    rampServo(SERVOMAX, SERVOMIN, 2000); // Ramp from max to min in 2000 ms
    delay(2000); // Wait at min position
}

// Function to set the servo position
void setServoPosition(int pulseWidth)
{
    int pwmValue = map(pulseWidth, 0, 20000, 0, 4095); // Map to 12-bit PWM value (0-4095)
    pwm.setPWM(0, 0, pwmValue); // Set the PWM value for channel 0
}

// Cubic easing function
float cubicEaseInOut(float t)
 {
    if (t < 0.5) 
    {
        return 4 * t * t * t;
    } else {
        float f = (t - 1);
        return 1 + 4 * f * f * f;
    }
}

// Function to ramp the servo position with easing
void rampServo(int startPulse, int endPulse, int duration) {
    int steps = 100; // Number of steps for the ramp
    for (int i = 0; i <= steps; i++) 
    {
        float t = (float)i / (float)steps; // Normalize time
        float easedValue = cubicEaseInOut(t); // Get eased value

        // Interpolate pulse width using the eased value
        int pulseWidth = startPulse + (endPulse - startPulse) * easedValue;
        setServoPosition(pulseWidth); // Set the PWM value
        delay(duration / (steps*2)); // Wait for the step duration
    }
}