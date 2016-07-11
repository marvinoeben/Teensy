int rider_inc_x=1;
int rider_x=0;

void _rider() {

  int y=0;

  EVERY_N_MILLISECONDS(25) {


        fadeAll(90);
  }

  EVERY_N_MILLISECONDS(50) {

    while (y<kMatrixHeight) {
      leds[XY(rider_x, y)] = CHSV(cycleHue, 255, (tweaked_brightness/3));
      y++;
    }
    rider_x=rider_x+rider_inc_x;

    if (rider_x > kMatrixWidth) rider_inc_x=-1;
    if (rider_x <= 0) rider_inc_x=1;

  }

}
