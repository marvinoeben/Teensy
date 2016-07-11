// Shimmering noise, uses global hue cycle
void glitter() {

  EVERY_N_MILLISECONDS(100) {
    fadeAll(75);
  }

  EVERY_N_MILLISECONDS(50) {

    int pos = random16(NUM_LEDS);
    leds[pos] += CHSV( cycleHue + random8(64), 255, tweaked_brightness);


  }

}
