// Countdown
// Tanner Gordon
// 11/3/20

// Desc: Counts down a nice soothing sleep color from brighter to
//       darker as each light dissapears

// USER: User must change the DELAY parameter to one of the following
//       numbers for desired transition time


#include <FastLED.h>
#define NUM_LEDS 876
#define BRIGHTNESS 22 // was 28
CRGB leds[876];


#define R 60
#define G 20
#define B 4

//      FastLED.delay(100);  // takes ~2 mins  @ 100
//      FastLED.delay(250);  // takes ~4 mins  @ 250
//      FastLED.delay(400);  // takes 7-9 mins @ 300
//      FastLED.delay(1500); // takes 15 mins  @ 1500
//      FastLED.delay(3000); // takes 30 mins  @ 3000

#define DELAY 100
// change this ^^^^ //

bool check_off() {
  bool check = true;
  for (int i = 0; i < NUM_LEDS; i++) {
    if (leds[i] != CRGB(0,0,0)) {
      check = false;
    }
  }
  if (check == false) {
    return false;
  }
  return true;
}

void setup() {
  FastLED.addLeds<WS2812, 2, GRB>(leds,876);
  FastLED.setBrightness(BRIGHTNESS);
  
  fill_solid(leds, NUM_LEDS, CRGB(60,20,4));  
  
  for (int i = 0; check_off() == false; i++) {
    int random_led = random16(0, NUM_LEDS);
    if (leds[random_led] != CRGB(0,0,0)) {
      leds[random_led] = CRGB(0,0,0);
      FastLED.delay(DELAY);
    }
  FastLED.show();
  }

  
  fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
}

void loop() {
}
