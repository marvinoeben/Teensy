
//float perfect_speed[6]={0.2, 0.2, 0.2, 0.2, 0.2, 0.2};
//float perfect_position[6]={0,(NUM_LEDS/6*1),(NUM_LEDS/6*2),(NUM_LEDS/6*3),(NUM_LEDS/6*4),(NUM_LEDS/6*5)};
//int perfect_length=( sizeof(perfect_speed) / sizeof(float) );
//float cars_color[6]={RED,YELLOW,GREEN,CYAN,BLUE,MAGENTA};


//float earth_position[6]={0,(NUM_LEDS/6*1),(NUM_LEDS/6*2),(NUM_LEDS/6*3),(NUM_LEDS/6*4),(NUM_LEDS/6*5)};


int earth_position[6][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8} };

int earth_direction[6][2] = { {1,0}, {0,1}, {1,0}, {0,1},{1,0} };

float earth_color[6]={RED,YELLOW,GREEN,CYAN,BLUE,MAGENTA};


int get_random_direction() {

  int r=random8(99999) % 5;

  if (r == 2) r=-1;
  if (r > 2) r=0;

  return r;
}

void earthcore_reset(int earth) {

  int x_direction=get_random_direction();
  int y_direction=0;

  if (x_direction == 0) {
    while (y_direction == 0) {
      y_direction=get_random_direction();
    }
  }

  earth_direction[earth][0]=x_direction;
  earth_direction[earth][1]=y_direction;


  earth_position[earth][0]=8;
  earth_position[earth][1]=2;

  if (x_direction == 0) earth_position[earth][0]=random8(kMatrixWidth);
  if (x_direction == 1) earth_position[earth][0]=0;
  if (x_direction == -1) earth_position[earth][0]=kMatrixWidth;


  if (y_direction == 0) earth_position[earth][1]=random8(kMatrixHeight);
  if (y_direction == 1) earth_position[earth][1]=0;
  if (y_direction == -1) earth_position[earth][1]=kMatrixHeight;

}

void earthcore(boolean glasses) {  // Effect by NpZ
  int sat=255;
  if (glasses) sat=0;

  EVERY_N_MILLISECONDS(50) {
    fadeAll(75);
  }

  EVERY_N_MILLISECONDS(100) {
    for( unsigned int i = 0; i < sizeof(earth_position)/sizeof(earth_position[0]); i = i + 1 ) {

      leds[XY(earth_position[i][0],earth_position[i][1])] = CHSV(earth_color[i], sat, tweaked_brightness);

      earth_position[i][0]+=earth_direction[i][0];
      earth_position[i][1]+=earth_direction[i][1];

      if ( (earth_position[i][0] < 0) || (earth_position[i][0] >= kMatrixWidth) || (earth_position[i][1] < 0) || (earth_position[i][1] >= kMatrixHeight) ) earthcore_reset(i);

    }


  }
}
