// Include FastLED library and other useful files
#include <FastLED.h>
#include <EEPROM.h>
#include "XYmap.h"
#include "utils.h"
#include "effects.h"

#define DATA_PIN 14
#define CLOCK_PIN    5
// Number of leds defined in XYmap.h

void setup() { 
      // Uncomment/edit one of the following lines for your leds arrangement.
      FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
      FastLED.setBrightness(50);
}

void loop() {
//  plasma();
//  threeSine();
//  threeDee();
//  confetti();
//  rider();
//  glitter();
  slantBars();
//  colorFill();
//  sideRain();
  FastLED.show();
 }

