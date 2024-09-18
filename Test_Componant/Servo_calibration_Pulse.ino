#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41); // Use the correct I2C address i am using the the right one 

const int SERVOMIN = 800;   // Minimum pulse width in microseconds
const int SERVOMAX = 2700;  // Maximum pulse width in microseconds

void setup() 
{ 
  Serial.begin(115200); // Start serial communication for debugging
  pwm.begin();
  pwm.setPWMFreq(50); // Set frequency to 50 Hz for servos
}

void loop() 
{
  // Convert microseconds to PWM values
  int pulseMin = map(SERVOMIN, 0, 20000, 0, 4095); // Map 900 µs to PWM value
  int pulseMax = map(SERVOMAX, 0, 20000, 0, 4095); // Map 2100 µs to PWM value
  
  // Swing to minimum position
  pwm.setPWM(14, 0, pulseMin); // Send the PWM value for minimum
  delay(2000); 

  // Swing to maximum position
  pwm.setPWM(14, 0, pulseMax); // Send the PWM value for maximum
  delay(2000); 

}
