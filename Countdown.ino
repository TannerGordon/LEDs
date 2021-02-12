// Countdown
// Tanner Gordon
// 11/3/20

// Desc: Counts down a nice soothing sleep color from brighter to
//       darker as each light dissapears

// Ideas: Could possibly make this universal so that it can run
//        alongside any light pattern so that the pattern is slowly
//        losing its leds


#include <FastLED.h>
#define NUM_LEDS 876
#define BRIGHTNESS 22 // was 28
CRGB leds[876];


#define R 60
#define G 20
#define B 4

////      FastLED.delay(100); // takes ~2 mins @ 100
//      FastLED.delay(250); //   takes ~4 mins @ 250
////      FastLED.delay(400);//         7-9 mins @ 300
////        FastLED.delay(1500);
////      FastLED.delay(3000);

#define DELAY 100


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

//void fade_to_black(int index, int r,int g,int b) {
//  for(int i = 0; i < 255; i++) {
//    leds[index] = CRGB(r-i,g-i,b-i);
//    if (r <= 0) {
//      r = 0;
//    }
//    if (g <= 0) {
//      g = 0;
//    }
//    if (b <= 0) {
//      b = 0;
//    }
//    FastLED.show();
//  }
//}

void setup() {
  FastLED.addLeds<WS2812, 2, GRB>(leds,876);
  FastLED.setBrightness(BRIGHTNESS);
  
  fill_solid(leds, NUM_LEDS, CRGB(60,20,4));  
//  int one = R;
//  int two = G;
//  int three = B;     
  for (int i = 0; check_off() == false; i++) {
    int random_led = random16(0, NUM_LEDS);
    if (leds[random_led] != CRGB(0,0,0)) {
      leds[random_led] = CRGB(0,0,0); // eventually make this fade
                                            // fade maybe
//      fade_to_black(random_led, 60,20,4);
      FastLED.delay(DELAY); //   takes ~4 mins @ 250
    }

  // new stuff **
//  for (int i = 0; i < NUM_LEDS; i++) {
//    leds[i] = CRGB(one
//  }
  FastLED.show();
  }

  
  fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
}

void loop() {
//  fill_solid(leds, NUM_LEDS, CRGB(60,20,4));       
//  for (int i = 0; i < 10000; i++) {
//    int random_led = random16(0, NUM_LEDS);
//    if (leds[random_led] != CRGB(0,0,0)) {
//      leds[random_led] = CRGB(0,0,0); // eventually make this fade
//                                            // fade
//      FastLED.show();
//    }
//
//  }
}
