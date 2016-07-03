int radar_n = 5; // Number of colors
//  int speed = 5;
int radar_x = 0;
int radar_y = 0;
const float radar_pi = 2 *  3.1415;
float radar_angle = 0;
void radar() {
  fadeAll(75);
  EVERY_N_MILLISECONDS(10) {
    for (int k = 0; k < radar_n; k++ ){
      radar_x = 0;
      radar_y = 0;
      float radar_angle2 = radar_angle + k * radar_pi / radar_n;
      int i = 0;
      while (i < 11) {
        radar_x = cos(radar_angle2)*i;
        radar_y = sin(radar_angle2)*i;
        leds[XY((kMatrixWidth/2)+radar_x, (kMatrixHeight/2)+radar_y)] = CHSV(round(k * 255 / radar_n), 255, 255);
        i++;
      }
    }
  radar_angle += radar_pi/100;
  }
}
