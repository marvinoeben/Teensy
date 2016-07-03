
int vrain_x=0;
int vrain_x_inc=1;
void vrain() {


  fadeAll(75);

  EVERY_N_MILLISECONDS(100) {


      int y=0;
      while (y<kMatrixHeight) {
        leds[XY(vrain_x+y, y)] = CHSV(120, 255, 255);
        y++;
      }

      vrain_x=vrain_x+vrain_x_inc;
      if (vrain_x > kMatrixWidth) vrain_x_inc=-1;
      if (vrain_x <= 0) vrain_x_inc=1;

  }
}
