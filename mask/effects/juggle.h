void juggle(boolean colors, int hue) { // Effect by Andrew Tuline - https://github.com/atuline
  int juggle_speed=1  ;
  int juggle_amount=4;
  int sat=255;

  int tweaked_brightness=200;
  int tweaked_speed=1;

  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 100);
  byte dothue = 0;
  if ((colors) || (hue != -1)) sat=255;
  else sat=0;

  for( int i = 0; i < juggle_amount; i++) {
     if (hue != -1) dothue=hue;
     if (tweaked_speed >= 1) leds[beatsin16(i+juggle_speed+tweaked_speed,0,NUM_LEDS)] |= CHSV(dothue, sat, tweaked_brightness);
     else leds[beatsin16(i+(juggle_speed*tweaked_speed),0,NUM_LEDS)] |= CHSV(dothue, sat, tweaked_brightness);
    dothue += (255/juggle_amount);
  }
}
