#include "sbus.h" // Include the SBUS library

using bfs::SbusRx;    // Bring SbusRx into the current scope
using bfs::SbusData;  // Bring SbusData into the current scope

// Define your RX and TX pins
const int8_t RX_PIN = 16; // Replace with your actual RX pin


/* SBUS object for reading SBUS */
SbusRx sbus_rx(&Serial2, RX_PIN,-1, true, false); // Adjust the last two bools as needed
/* SBUS object for writing SBUS */

SbusData data;

void setup()
 {
  /* Serial to display data */
  Serial.begin(115200);

  /* Begin the SBUS communication */
  sbus_rx.Begin(); // Initialize SBUS receiver

}

void loop() 
{
  if (sbus_rx.Read()) 
  { // Check if new SBUS data is available
    /* Grab the received data */
    data = sbus_rx.data(); // Retrieve the received SBUS data

    /* Display the received data */
    for (int8_t i = 0; i < data.NUM_CH; i++)
     {
      Serial.print(data.ch[i]); // Print channel value
      Serial.print("\t"); // Tab for formatting
     }

    /* Display lost frames and failsafe data */
    Serial.print(data.lost_frame); // Print lost frames
    Serial.print("\t");
    Serial.println(data.failsafe); // Print failsafe status


  }
}