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
const uint8_t kMatrixWidth = 19;
const uint8_t kMatrixHeight = 12;

// Pixel layout

#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds[ NUM_LEDS ];

// This function will return the right 'led index number' for
// a given set of X and Y coordinates on your RGB Shades.
// This code, plus the supporting 80-byte table is much smaller
// and much faster than trying to calculate the pixel ID with code.
#define LAST_VISIBLE_LED 97
uint8_t XY( uint8_t x, uint8_t y)
{
  // any out of bounds address maps to the first hidden pixel
  if( (x >= kMatrixWidth) || (y >= kMatrixHeight) ) {
    return (LAST_VISIBLE_LED + 1);
  }

  const uint8_t ShadesTable[] = {
    98,99,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,100,101,
    102,103,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,104,105,
    106,107,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,108,109,
    64,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,45,
    63,65,97,127,128,129,130,131,132,133,134,135,136,137,138,139,83,82,46,
    62,66,96,140,141,142,143,144,145,146,147,148,149,150,151,152,84,81,47,
    61,67,95,153,154,155,156,157,158,159,160,161,162,163,164,165,85,80,48,
    60,68,94,166,167,168,169,170,171,172,173,174,175,176,177,178,86,79,49,
    59,69,93,179,180,181,182,183,184,185,186,187,188,189,190,191,87,78,50,
    58,70,92,192,193,194,195,196,91,90,89,197,198,199,200,201,88,77,51,
    202,203,204,205,206,207,71,72,73,226,74,75,76,208,209,210,211,212,213,
    214,215,216,217,218,219,57,56,55,227,54,53,52,220,221,222,223,224,225
    };

  uint8_t i = (y * kMatrixWidth) + x;
  uint8_t j = ShadesTable[i];
  return j;
}
