#include "FastLED.h"
#include <pixeltypes.h>

// Shooting Stars
// Desc: Simulating a shooting star, featuring the star and its trail.
//       The trail size, amount of shooting stars, and speed of movement
//       can be customized using the #define parameters
// Tanner Gordon
// December 17, 2020

// note: this code features some testing, please ignore :)

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    876
#define BRIGHTNESS  200

#define POINT_START 0

#define NUM_TRAILS 3

//#define SPEED 60 // slow
//#define SPEED 20 // faster
//#define SPEED 10 // really  fast
#define SPEED 7 // a nice in between
//#define SPEED 5 // gtfo //  requires 20 for LENGTH_OF_BLACK
//#define SPEED 2 // god mode // requires 30

#define LENGTH 50 // 50 good

#define LENGTH_OF_BLACK 7 // 10, 20, 30

CRGB leds[NUM_LEDS];


void setup() {
  delay(1000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);
//    .setDither(BRIGHTNESS < 255);
//
//  // set master brightness control
//  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(115200);
}

void loop()
{
// TEST TO FIND BEST GRADE OF BLUE
// TEST SUCCESS
//  ~ FINDINGS ~ //
// 135 - 165 IS BEST RANGE OF COLORS FOR BLUE
// CHSV(135, 100, 100); being aqua-marine
// CHSV(165, 100, 100); being purple

//  for (int i = 0; i < 100; i++) {
//    leds[i] = CHSV(i*3, 200, 200);
//    Serial.println(i + 700);
//    if (i*3 < 135 or i*3 > 165) {
//      leds[i] = CRGB::Black;
//    }
//    FastLED.show();
//  }
//  int SPEED = 0;
  
  test();
  FastLED.show();
  
}

void test()
{
  unsigned long s = millis() / SPEED + POINT_START % NUM_LEDS;
  if (s >= NUM_LEDS) {
    s = s % NUM_LEDS - 1;
  }
//  leds[s] = CHSV(0,0,100);
//  trail(s);
fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
  for (int i = 1; i < NUM_TRAILS + 1; i++) {
    trail((s + i*(NUM_LEDS / NUM_TRAILS)) % NUM_LEDS);
  }
}

void trail(unsigned long s)
{
  int t = 0;
  for (int i = 0; i < LENGTH; i++) {
    t = (int)s - i;
    if (t < 0) {
      t = t + NUM_LEDS;
    }

    //set
//    leds[t] = CHSV(0,i*5,250); // 150 blue, 250 - i*5
    if (i == 0) {
      leds[t] = CHSV(150,i*5,250);
    }
    if (i > 0 and i < 15) {
      leds[t] = CHSV(150,90 +i*3,(170 - i*2)); // i * 5, 170  - i*3
    }
    if (i >= 15 and i < 40) { // 27
      leds[t] = CHSV(150,90 +i*3,random_off(170 - i*2));
    }
    if (i >= 40) {
      leds[t] = CHSV(150,90 +i*3,random_off_range(170 - i*2, 10));
    }


  }
}

int check(int n)
{
  if (n < 0 or n > NUM_LEDS - 1) {
    return 0;
  }
  return n;
}

int random_off(int n) {
  if (random8(2) == 1) {
    return 0;
  }
  return n;
}

int random_off_range(int n, int max_n) {
  if (random8(max_n) == 1) {
    return n;
  }
  return 0;
}
