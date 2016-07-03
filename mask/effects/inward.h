// Inward spiral.
void inward(){
  // attempting to end at the tip of the nose;
  // Hardcode the route!
  const uint8_t routeMap[] = {
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,
    45,46,47,48,49,50,51,
    52,53,54,55,56,57,
    58,59,60,61,62,63,64,
    29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,
    82,81,80,79,78,77,
    76,75,74,73,72,71,
    70,69,68,67,65,64,
    30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,
    83,84,85,86,87,88,
    89,90,91,
    92,93,94,95,96,97,
    98,110,
    109,108,107,106,
    105,104,103,
    102,101,100,99,
    121,116,115,
    111,
    112,113,118,119,123,
    122,
    121,116,115,
    114,117,120,
    121,116,117,118
  };
  const byte routeLength = (sizeof(routeMap)/sizeof(routeMap[0]));
  for (byte dot = 0; dot < routeLength; dot++){
            leds[routeMap[dot]] = CRGB::Blue;
            FastLED.show();
            // clear this led for the next time around the loop
            if (dot > 3){
              leds[routeMap[dot-2]] = CRGB::Black;
              delay(50);
            }
      }
}
