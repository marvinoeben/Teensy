//              This special 'XY' code lets you program the RGB Shades
//              as a plain 16x5 matrix.
//
//              Writing to and reading from the 'holes' in the layout is
//              also allowed; holes retain their data, it's just not displayed.
//
//              You can also test to see if you're on or off the layout
//              like this
//                if( XY(x,y) > LAST_VISIBLE_LED ) { ...off the layout...}
//
//              X and Y bounds checking is also included, so it is safe
//              to just do this without checking x or y in your code:
//                leds[ XY(x,y) ] == CRGB::Red;
//              All out of bounds coordinates map to the first hidden pixel.
//
//     XY(x,y) takes x and y coordinates and returns an LED index number,
//             for use like this:  leds[ XY(x,y) ] == CRGB::Red;


// Params for width and height
const uint8_t kMatrixWidth = 17;
const uint8_t kMatrixHeight = 12;

// Pixel layout

#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds[ NUM_LEDS ];

// This function will return the right 'led index number' for
// a given set of X and Y coordinates on your RGB Shades.
// This code, plus the supporting 80-byte table is much smaller
// and much faster than trying to calculate the pixel ID with code.
#define LAST_VISIBLE_LED 123
uint8_t XY( uint8_t x, uint8_t y)
{
  // any out of bounds address maps to the first hidden pixel
  if( (x >= kMatrixWidth) || (y >= kMatrixHeight) ) {
    return (LAST_VISIBLE_LED + 1);
  }

  const uint8_t ShadesTable[] = {
    124,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,125,
    126,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,127,
    128,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,129,
    64,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,45,
    63,65,97,98,145,146,147,148,149,150,151,152,153,110,83,82,46,
    62,66,96,99,154,155,156,121,116,115,157,158,159,109,84,81,47,
    61,67,95,100,160,122,161,120,117,114,162,111,163,108,85,80,48,
    60,68,94,101,164,165,123,119,118,113,112,166,167,107,86,79,49,
    59,69,93,169,168,102,170,103,104,105,171,106,173,172,87,78,50,
    58,70,176,174,175,92,177,91,90,89,178,88,180,181,179,77,51,
    182,183,184,185,186,71,72,73,187,74,75,76,188,189,190,191,192,
    193,194,195,196,197,57,56,55,198,54,53,52,199,200,201,202,203
    };

  uint8_t i = (y * kMatrixWidth) + x;
  uint8_t j = ShadesTable[i];
  return j;
}
