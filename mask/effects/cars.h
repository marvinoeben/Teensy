
float perfect_speed[6]={0.2, 0.2, 0.2, 0.2, 0.2, 0.2};
float perfect_position[6]={0,(NUM_LEDS/6*1),(NUM_LEDS/6*2),(NUM_LEDS/6*3),(NUM_LEDS/6*4),(NUM_LEDS/6*5)};
int perfect_length=( sizeof(perfect_speed) / sizeof(float) );
float cars_color[6]={RED,YELLOW,GREEN,CYAN,BLUE,MAGENTA};


int find_led(int led) { // Function by NpZ
   while (led < 0) led+=NUM_LEDS;
   int ret = led % NUM_LEDS;

   return ret;
}

void cars(float speed[], float position[], float color[], int length, boolean bounce, boolean glasses, int hue){  // Effect by NpZ
  int new_pos_int;
  float new_pos_float;
  boolean except[NUM_LEDS] = { false };
  boolean move;
  //int dothue, dotsat;
  for ( int i = 0; i < length; i++ ) {
    move=true;
    new_pos_float=position[i]+(speed[i]*tweaked_speed);
    new_pos_int=find_led(new_pos_float);

    if (bounce) {
      for ( int j = 0; j < length; j++ ) {
        if ((find_led(position[j]) == new_pos_int) && (j != i)) {
          speed[i]=speed[i]*-1;
          move=false;
        }
      }
    }

    if (move) {
      position[i]=new_pos_float;

      if (glasses) leds[new_pos_int] = CHSV(color[i], 0, tweaked_brightness);
      else leds[new_pos_int] = CHSV(color[i], 255, tweaked_brightness);

      /*
      if (glasses) {
        if (hue != -1) {
          dothue=hue;
          dotsat=255;
        } else {
          dothue=cars_color[i];
          dotsat=0;
        }
        leds[new_pos_int] = CHSV(dothue, dotsat, tweaked_brightness);

      } else {
        leds[new_pos_int] = CHSV(cars_color[i], 255, tweaked_brightness);
      }
      */


      except[new_pos_int]=true;
    }
  }
  chsv_all_except(0, 0, 0, except);
}
