int vrain_i=0;

void vrain() {

  float x=0;





  EVERY_N_MILLISECONDS(25) {

      fadeAll(90);
//      if (vrain_i > kMatrixWidth) vrain_i=0;
      int y=0;
      //while (y<kMatrixHeight) {
        float sin_x=round(sin(vrain_i * M_PI / 100) * (kMatrixWidth/2) + (kMatrixWidth/2) );

        leds[XY(sin_x, 0)] = CHSV(120, 255, 255);

        sin_x=round(sin(vrain_i * M_PI / 100) * (kMatrixWidth/2) + (kMatrixWidth/2) );

        leds[XY(sin_x, 1)] = CHSV(0, 255, 255);


        //y++;

      //}
      vrain_i++;
  }
}
