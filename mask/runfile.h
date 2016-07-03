void loop() {
  currentMillis = millis(); // save the current timer value

  int blink_interval=100;
  if (millis() > 10000) blink_interval=500;

  if ((millis() % (blink_interval*2)) < blink_interval) digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);

  int loop_duration=135;
  int loop=floor(millis()/loop_duration/1000);
  int loop_progress=(millis()/1000) % loop_duration;

  //if (loop_progress < 50000) vrain();
  if (loop_progress < 15) radar();
  //if (loop_progress < 5) debug();
  else if (loop_progress < 30) rider();
  else if (loop_progress < 38) _rider();
  else if (loop_progress < 45) threeSine();
  else if (loop_progress < 60) plasma();
  else if (loop_progress < 75) { confetti(); fadeAll(1);  }
  else if (loop_progress < 90) glitter();
  else if (loop_progress < 105) slantBars();
  else if (loop_progress < 120) colorFill();
  else if (loop_progress < 135) sideRain();

  hueCycle(1); // increment the global hue value

  FastLED.show(); // send the contents of the led memory to the LEDs
 }
