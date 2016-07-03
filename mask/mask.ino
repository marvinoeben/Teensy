// Include FastLED library and other useful files
#include <FastLED.h>
#include <EEPROM.h>
#include "XYmap.h"
#include "utils.h"
#include "effects.h"
#include "vrain.h"

#define DATA_PIN 14

// Number of leds defined in XYmap.h

void setup() {
      // Uncomment/edit one of the following lines for your leds arrangement.
      FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
      FastLED.setBrightness(50); // MN: Can't change this value on the fly so need to be included as Hue value in every function.

	  pinMode(13, OUTPUT);

}

#include "runfile.h" #kleine comment
