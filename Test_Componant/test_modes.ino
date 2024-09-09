#include "sbus.h" // Include the SBUS library

using bfs::SbusRx;    // Bring SbusRx into the current scope
using bfs::SbusData;  // Bring SbusData into the current scope

// Define your RX pin
const int8_t RX_PIN = 16; // Replace with your actual RX pin

/* SBUS object for reading SBUS */
SbusRx sbus_rx(&Serial2, RX_PIN, -1, false, false); // TX pin not used
/* SBUS data structure */
SbusData data;

void setup() 
{
  /* Serial to display data */
  Serial.begin(115200);
  while (!Serial) {} // Wait for serial to connect

  /* Begin the SBUS communication */
  sbus_rx.Begin(); // Initialize SBUS receiver
}

void loop()
 {
  if (sbus_rx.Read()) 
  { // Check if new SBUS data is available
    /* Grab the received data */
    data = sbus_rx.data(); // Retrieve the received SBUS data

    /* Display the received channel values */
    for (int8_t i = 0; i < data.NUM_CH; i++) 
    {
      Serial.print(data.ch[i]); // Print channel value
      Serial.print("\t"); // Tab for formatting
    }

    /* Display lost frames and failsafe data */
    Serial.print(data.lost_frame); // Print lost frames
    Serial.print("\t");
    Serial.println(data.failsafe); // Print failsafe status

    // Check each channel for mode activation // change the value according to the RF transmitter 
    if (data.ch[0] == 100) 
    {
      Serial.println("Mode 1 activated");
    } else if (data.ch[1] == 100) 
    {
      Serial.println("Mode 2 activated");
    } else if (data.ch[2] == 100) 
    {
      Serial.println("Mode 3 activated");
    } else if (data.ch[3] == 100) 
    {
      Serial.println("Mode 4 activated");
    }
  }
}