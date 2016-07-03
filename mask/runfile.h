functionList effectList[] = {//single, // Made by Marvin
                             //inward, // Made by Marvin
                             rider,
                             threeSine,
                             plasma,
                             confetti,
                             glitter,
                             slantBars,
                             colorFill,
                             sideRain
                            };
const byte numEffects = (sizeof(effectList)/sizeof(effectList[0]));

void loop() {
  currentMillis = millis(); // save the current timer value

  if ((millis() % 1000) < 500) digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);

  // switch to a new effect every cycleTime milliseconds
  if (currentMillis - cycleMillis > cycleTime && autoCycle == true) {
    cycleMillis = currentMillis;
    if (++currentEffect >= numEffects) currentEffect = 0; // loop to start of effect list
    effectInit = false; // trigger effect initialization when new effect is selected
  }

  // increment the global hue value every hueTime milliseconds
  if (currentMillis - hueMillis > hueTime) {
    hueMillis = currentMillis;
    hueCycle(1); // increment the global hue value
  }

  // run the currently selected effect every effectDelay milliseconds
  if (currentMillis - effectMillis > effectDelay) {
    effectMillis = currentMillis;
    effectList[currentEffect](); // run the selected effect function
    random16_add_entropy(1); // make the random values a bit more random-ish
  }

  // run a fade effect too if the confetti effect is running
  if (effectList[currentEffect] == confetti) fadeAll(1);

  FastLED.show(); // send the contents of the led memory to the LEDs
 }
