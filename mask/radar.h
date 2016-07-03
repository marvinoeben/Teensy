void radar() {
  fadeAll(75);
  int n = 5; // Number of colors
  int speed = 5;
  int x = 0;
  int y = 0;
  const pi = 3.1415;
  float radar_angle;
  EVERY_N_MILLISECONDS(speed) {
  for (int k = 0; k < n; k++ ){
    x = 0;
    y = 0;
    radar_angle = k * pi / n;
    int i = 0;
    while (i < 11) {
      x = cos(radar_angle)*i;
      y = sin(radar_angle)*i;
      leds[XY((kMatrixWidth/2)+x, (kMatrixHeight/2)+y)] = CHSV(round(k * 255 / n), 255, 255);
      i++;
    }
    radar_angle+=(3.141596/100);
  }

  }
}
