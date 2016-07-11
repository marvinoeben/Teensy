void loop() {
  currentMillis = millis(); // save the current timer value

  int blink_interval=100;
  if (millis() > 10000) blink_interval=500;

  if ((millis() % (blink_interval*2)) < blink_interval) digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);




  int loop_duration=210;
  int skip_seconds=0;
  int second_now = ((millis() / 1000) + skip_seconds) % loop_duration;
  int second_all = ((millis() / 1000) + skip_seconds);


  if (second_all < 60) {
    if (second_now < 0) {}
    else if (second_now < 20) earthcore(true);
    else if (second_now < 40) vrain(true);
    //else if (second_now < 40) hrain(true);
    else if (second_now < 60) cars(perfect_speed, perfect_position, cars_color, perfect_length, false, true, -1);
  } else {
      if (1==2) {}
      else if (second_now < 30) cars(perfect_speed, perfect_position, cars_color, perfect_length, false, false, -1);
      else if (second_now < 60) earthcore(false);
      //else if (second_now < 90) hrain(false);
      else if (second_now < 90) vrain(false);
      else if (second_now < 120) _rider();
      else if (second_now < 150) glitter();
      else if (second_now < 180) sideRain();
      else if (second_now < 210) radar();

  }





  hueCycle(1); // increment the global hue value

  FastLED.show(); // send the contents of the led memory to the LEDs
 }
