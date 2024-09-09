#include <Wire.h>
#include <MPU6050.h>

// Create MPU6050 object
MPU6050 mpu;

// Calibration offsets
int16_t accelOffset[3] = {0, 0, 0}; // X, Y, Z
int16_t gyroOffset[3] = {0, 0, 0};  // X, Y, Z

void setup() 
{
  Serial.begin(115200);
  mpu.initialize();

  // Check if MPU6050 is connected
  if (!mpu.testConnection()) 
  {
    Serial.println("MPU6050 connection failed!");
    while (1); // Stop here if connection fails
  }

  // Gather initial data for calibration
  for (int i = 0; i < 1000; i++) 
  {
    Vector rawAccel = mpu.readRawAccel();
    Vector rawGyro = mpu.readRawGyro();
    
    // Accumulate the values
    accelOffset[0] += rawAccel.XAxis;
    accelOffset[1] += rawAccel.YAxis;
    accelOffset[2] += rawAccel.ZAxis;
    
    gyroOffset[0] += rawGyro.XAxis;
    gyroOffset[1] += rawGyro.YAxis;
    gyroOffset[2] += rawGyro.ZAxis;

    delay(1); // Short delay to allow for readings
  }

  // Average the values to get offsets
  accelOffset[0] /= 1000;
  accelOffset[1] /= 1000;
  accelOffset[2] /= 1000; // Z should be around +16384 (1g)

  gyroOffset[0] /= 1000;
  gyroOffset[1] /= 1000;
  gyroOffset[2] /= 1000;
}

void loop() 
{
  // Read and apply offsets
  Vector rawAccel = mpu.readRawAccel();
  Vector rawGyro = mpu.readRawGyro();
  
  // Apply offsets
  float accelX = rawAccel.XAxis - accelOffset[0];
  float accelY = rawAccel.YAxis - accelOffset[1];
  float accelZ = rawAccel.ZAxis - accelOffset[2];

  // Calculate tilt angles (in degrees)
  float angleX = atan2(accelY, sqrt(accelX * accelX + accelZ * accelZ)) * 180.0 / PI; // Positive for right, negative for left
  float angleY = atan2(accelX, sqrt(accelY * accelY + accelZ * accelZ)) * 180.0 / PI; // Positive for forward, negative for backward

  // Print only the tilt angles
  Serial.print("Tilt X: ");
  Serial.print(angleX);
  Serial.print(" degrees, Tilt Y: ");
  Serial.println(angleY);

  delay(1000); // Read every second
}