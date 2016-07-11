// Random pixels scroll sideways, uses current hue
int rainDirection=0;

int rainLoops=0;

void sideRain() {

  EVERY_N_MILLISECONDS(100) {

    scrollArray(rainDirection);
    byte randPixel = random8(kMatrixHeight);
    for (byte y = 0; y < kMatrixHeight; y++) leds[XY((kMatrixWidth - 1) * rainDirection, y)] = CRGB::Black;
    leds[XY((kMatrixWidth - 1)*rainDirection, randPixel)] = CHSV(cycleHue, 255, tweaked_brightness/2);
    rainLoops++;
    if (rainLoops % 100 == 0) rainDirection=1;
    if (rainLoops % 100 == 50) rainDirection=0;
  }
}
