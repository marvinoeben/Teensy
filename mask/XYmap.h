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
const uint8_t kMatrixWidth = 15;
const uint8_t kMatrixHeight = 3;

// Pixel layout
//
//      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
//   +---------------------------------------------
// 0 |  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
// 1 | 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15
// 2 | 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44

#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds[ NUM_LEDS ];

// This function will return the right 'led index number' for
// a given set of X and Y coordinates on your RGB Shades.
// This code, plus the supporting 80-byte table is much smaller
// and much faster than trying to calculate the pixel ID with code.
#define LAST_VISIBLE_LED 44
uint8_t XY( uint8_t x, uint8_t y)
{
  // any out of bounds address maps to the first hidden pixel
  if( (x >= kMatrixWidth) || (y >= kMatrixHeight) ) {
    return (LAST_VISIBLE_LED + 1);
  }

  const uint8_t ShadesTable[] = {
     0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
     29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15,
     30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44
    };

  uint8_t i = (y * kMatrixWidth) + x;
  uint8_t j = ShadesTable[i];
  return j;
}
