int vrain_i=0;

void vrain(boolean glasses) {
  EVERY_N_MILLISECONDS(15) {
    fadeAll(90);
  }
  int sat=255;
  if (glasses) sat=0;
  EVERY_N_MILLISECONDS(35) {

        float sin_x;
        int i=0;
        while (i<=kMatrixHeight) {
          sin_x=round(sin((vrain_i+(i*2)) * M_PI / 30) * ceil(kMatrixWidth/2) + ceil(kMatrixWidth/2) );
          leds[XY(sin_x, i)] = CHSV(cycleHue, sat, tweaked_brightness/2);

          sin_x=round(-sin((vrain_i+(i*2)) * M_PI / 30) * ceil(kMatrixWidth/2) + ceil(kMatrixWidth/2) );
          leds[XY(sin_x, i)] = CHSV(cycleHue, sat, tweaked_brightness/2);

          i++;
        }

      vrain_i++;
  }
}

void hrain(boolean glasses) {
  EVERY_N_MILLISECONDS(15) {
    fadeAll(90);
  }



  int sat=255;
  if (glasses) sat=0;
  EVERY_N_MILLISECONDS(35) {
//chsv_all_except(0, 0, 0, 0);
        float sin_y;
        int i=0;
        while (i<=kMatrixWidth) {
          sin_y=round(sin((vrain_i+(i*2)) * M_PI / 30) * ceil(kMatrixHeight/2) + ceil(kMatrixHeight/2) );
          leds[XY(i, sin_y)] = CHSV(cycleHue, sat, tweaked_brightness);

          sin_y=round(-sin((vrain_i+(i*2)) * M_PI / 30) * ceil(kMatrixHeight/2) + ceil(kMatrixHeight/2) );
          leds[XY(i, sin_y)] = CHSV(cycleHue, sat, tweaked_brightness);

          i++;
        }

      vrain_i++;
  }
}
