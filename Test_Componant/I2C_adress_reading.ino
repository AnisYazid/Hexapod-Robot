#include <Wire.h>

void setup() 
{
  Serial.begin(115200); // Start serial communication
  Wire.begin();         // Initialize I2C bus
  Serial.println("\nI2C Scanner");
}

void loop() 
{
  Serial.println("Scanning...");

  int count = 0;

  // Loop through possible I2C addresses
  for (byte address = 1; address < 127; address++) 
  {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      Serial.print(address < 16 ? "0" : ""); // Leading zero for single-digit hex
      Serial.print(address, HEX);
      Serial.println("  !");
      count++;
    } 
    else if (error == 4) 
    {
      Serial.print("Unknown error at address 0x");
      Serial.print(address < 16 ? "0" : ""); // Leading zero for single-digit hex
      Serial.println(address, HEX);
    }

    delay(10); // Short delay for stability
  }

  Serial.print(count == 0 ? "No I2C devices found" : "Found ");
  Serial.print(count);
  Serial.println(" I2C device(s).");

  delay(5000); // Wait before the next scan
}