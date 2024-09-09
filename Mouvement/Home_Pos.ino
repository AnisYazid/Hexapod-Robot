#include <Wire.h>
#include <Adafruit_PCA9685.h>

// Create PCA9685 objects for left and right sides
Adafruit_PCA9685 pwmLeft = Adafruit_PCA9685();
Adafruit_PCA9685 pwmRight = Adafruit_PCA9685();

// Define constants
const int NUM_SERVOS_PER_SIDE = 9; // 3 legs * 3 servos each
const int SERVOMIN = 900;   // Minimum pulse length in microseconds
const int SERVOMAX = 2100;  // Maximum pulse length in microseconds

// Define initial angles for standing position (in degrees)
int standingPositionsLeft[NUM_SERVOS_PER_SIDE] = 
{
  100, 100, 100, // Left front leg
  100, 100, 100, // Left middle leg
  100, 100, 100  // Left rear leg
};

int standingPositionsRight[NUM_SERVOS_PER_SIDE] = 
{
  100, 100, 100, // Right front leg
  100, 100, 100, // Right middle leg
  100, 100, 100  // Right rear leg
};

// Function to convert degrees to PWM pulse width
uint16_t servoAngleToPWM(int angle) 
{
  return map(angle, 0, 200, SERVOMIN, SERVOMAX);
}

// Function to set the servos to the home position
void home() 
{
  // Set left servos to home position
  pwmLeft.setPWM(0, 0, servoAngleToPWM(standingPositionsLeft[0])); // Left front leg - Servo 1
  pwmLeft.setPWM(1, 0, servoAngleToPWM(standingPositionsLeft[1])); // Left front leg - Servo 2
  pwmLeft.setPWM(2, 0, servoAngleToPWM(standingPositionsLeft[2])); // Left front leg - Servo 3
  
  pwmLeft.setPWM(3, 0, servoAngleToPWM(standingPositionsLeft[3])); // Left middle leg - Servo 1
  pwmLeft.setPWM(4, 0, servoAngleToPWM(standingPositionsLeft[4])); // Left middle leg - Servo 2
  pwmLeft.setPWM(5, 0, servoAngleToPWM(standingPositionsLeft[5])); // Left middle leg - Servo 3
  
  pwmLeft.setPWM(6, 0, servoAngleToPWM(standingPositionsLeft[6])); // Left rear leg - Servo 1
  pwmLeft.setPWM(7, 0, servoAngleToPWM(standingPositionsLeft[7])); // Left rear leg - Servo 2
  pwmLeft.setPWM(8, 0, servoAngleToPWM(standingPositionsLeft[8])); // Left rear leg - Servo 3

  // Set right servos to home position
  pwmRight.setPWM(0, 0, servoAngleToPWM(standingPositionsRight[0])); // Right front leg - Servo 1
  pwmRight.setPWM(1, 0, servoAngleToPWM(standingPositionsRight[1])); // Right front leg - Servo 2
  pwmRight.setPWM(2, 0, servoAngleToPWM(standingPositionsRight[2])); // Right front leg - Servo 3
  
  pwmRight.setPWM(3, 0, servoAngleToPWM(standingPositionsRight[3])); // Right middle leg - Servo 1
  pwmRight.setPWM(4, 0, servoAngleToPWM(standingPositionsRight[4])); // Right middle leg - Servo 2
  pwmRight.setPWM(5, 0, servoAngleToPWM(standingPositionsRight[5])); // Right middle leg - Servo 3
  
  pwmRight.setPWM(6, 0, servoAngleToPWM(standingPositionsRight[6])); // Right rear leg - Servo 1
  pwmRight.setPWM(7, 0, servoAngleToPWM(standingPositionsRight[7])); // Right rear leg - Servo 2
  pwmRight.setPWM(8, 0, servoAngleToPWM(standingPositionsRight[8])); // Right rear leg - Servo 3

}

void setup() 
{
  // Initialize the PCA9685 boards
  pwmLeft.begin();
  pwmLeft.setPWMFreq(60); // Set frequency to 60 Hz for left servos

  pwmRight.begin();
  pwmRight.setPWMFreq(60); // Set frequency to 60 Hz for right servos

}

void loop() 
{
   // Call the home function to set initial positions
  home();
}