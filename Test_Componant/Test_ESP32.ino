#include <Adafruit_NeoPixel.h>

#define LED_PIN     48  // Adjust according to your board's LED pin
#define LED_COUNT   1   // Only one integrated NeoPixel

// Create an instance of the NeoPixel strip
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();          // Initialize the NeoPixel strip
  strip.show();           // Initialize all pixels to 'off'
}

void loop() {
  // Cycle through colors
  colorWipe(strip.Color(255, 0, 0), 500); // Red
  colorWipe(strip.Color(0, 255, 0), 500); // Green
  colorWipe(strip.Color(0, 0, 255), 500); // Blue
  colorWipe(strip.Color(255, 255, 0), 500); // Yellow
  colorWipe(strip.Color(0, 255, 255), 500); // Cyan
  colorWipe(strip.Color(255, 0, 255), 500); // Magenta
  colorWipe(strip.Color(255, 255, 255), 500); // White
  colorWipe(strip.Color(0, 0, 0), 500); // Off
}

// Fill the NeoPixel strip with a color
void colorWipe(uint32_t color, int wait) {
  strip.setPixelColor(0, color); // Set the color for the single NeoPixel
  strip.show();                  // Update the strip
  delay(wait);                   // Wait for a moment
}