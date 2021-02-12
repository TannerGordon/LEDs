// Nice Lighting
// Tanner Gordon
// 11/3/20

// Desc: a nice vibe that simulates regular lights


#include <FastLED.h>
#define NUM_LEDS 876
CRGB leds[876];

#define LOWLIGHT true
//#define LOWLIGHT false


//#define R 60
//#define G 20
//#define B 4

#define R 90
#define G 4
#define B 5

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
  int bright = 0;
  if (LOWLIGHT == true) {
    bright = 28;
  } else {
    bright = 100;
  }
  FastLED.setBrightness(bright);
  if (LOWLIGHT == true) {
    fill_solid(leds, NUM_LEDS, CRGB(60,20,4));
  } else {
    fill_solid(leds, NUM_LEDS, CRGB(77,22,0)); 
  }
//  fill_solid(leds, NUM_LEDS, CRGB(60,20,4)); 
//  fill_solid(leds, NUM_LEDS, CRGB(77,22,0));  
  FastLED.show();
//  int one = R;
//  int two = G;
//  int three = B;     


  

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
