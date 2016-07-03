void single(){
    // startup tasks
  if (effectInit == false) {
    effectInit = true;
    effectDelay = 15;
  }
  for (byte x = 0; x < kMatrixWidth; x++){
    for (byte y = 0; y < kMatrixHeight; y++){
     leds[XY(x,y)] = CRGB::Blue;
    }
    FastLED.show();
    for (byte y = 0; y < kMatrixHeight; y++){
     leds[XY(x,y)] = CRGB::Black;
    }
    delay(500);
  }
}
