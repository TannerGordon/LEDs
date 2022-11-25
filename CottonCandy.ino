#include <FastLED.h>

#define NUM_LEDS    876
#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    876
#define BRIGHTNESS 120

//#define DESK_LIGHT false // true if desk light on

CRGB leds[NUM_LEDS];

unsigned long n;
bool first;
int jump;

void setup() {
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);
  //  Serial.begin(115200);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
  first = true;
  n = millis() / 10;
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    leds[i] = CHSV (beatsin88(3000, 175, 215, (i * 80)), 255, beatsin88(5000, 50, 180, (i * 100)));
    leds[NUM_LEDS - i] = CHSV (beatsin88(3000, 175, 215, ((NUM_LEDS - i) * 50)), 255, beatsin88(5000, 50, 180, ((NUM_LEDS - i) * 60)));
    if (i > 39) {
      trail(i);
    }

    FastLED.show();
  }

  ///// original
//  for (int i = 0; i < NUM_LEDS / 2; i += 20) {
//    for (int j = 0; j < 20; j++) {
//      leds[i + (NUM_LEDS / 2) + j] = CHSV (255, 0, 100);
//      leds[NUM_LEDS / 2 - i - j] = CHSV (255,0,100);
//    }
//    FastLED.show();
//  }

  jump = 0;
}


// Understanding beatsin88

// To change speed -> first parameter (BPM)

// To change length -> 4th param (i * ___)

// To change min/max -> 2nd/3rd param



// Colors

// CottonCandy - 175, 215
// Ocean       - 120, 170


//void sinelon()
//{
//  // a colored dot sweeping back and forth, with fading trails
//  fadeToBlackBy( leds, NUM_LEDS, 20);
//  int pos = beatsin16(13,150, 200);
//  leds[pos] += CHSV( pos, 255, 192);
//}

//bool cheese = false;

void loop() {
  bool t = false;
  n = millis() / 10;


//  if (!cheese) {
//    for (int i = 0; i < NUM_LEDS / 2; i += 20) {
//      for (int j = 0; j < 20; j++) {
////        leds[i + (NUM_LEDS / 2) + j] = CHSV (255, 0, 100);
////        leds[NUM_LEDS / 2 - i - j] = CHSV (255,0,100);
//        n = millis() / 10;
//        leds[i + (NUM_LEDS / 2) + j] = CHSV (beatsin88(3000, 175, 215, n + (unsigned long)(i * 30)), 0, beatsin88(5000, 50, 180, n + (unsigned long)(i * 50)));
//        leds[NUM_LEDS / 2 - i - j] = CHSV (beatsin88(3000, 175, 215, n + (unsigned long)(i * 30)), 0, beatsin88(5000, 50, 180, n + (unsigned long)(i * 50)));
//      }
//    FastLED.show();
//  }
//  cheese = true;
//  }


  if (jump > 254) {
    jump = 255;
    t = true;
    while (t) {
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV (beatsin88(3000, 175, 215, n + (unsigned long)(i * 30)), 255, beatsin88(5000, 50, 180, n + (unsigned long)(i * 50)));
      }
      FastLED.show();
    }
  }


  ///// original
//  for (int i = 0; i < NUM_LEDS; i++) {
//    leds[i] = CHSV (beatsin88(3000, 175, 215, n + (unsigned long)(i * 30)), jump, beatsin88(5000, 50, 180, n + (unsigned long)(i * 50)));
//  }
//  jump += 3;




  for (int i = 0; i < jump * 3; i++) {
    leds[i + (NUM_LEDS / 2) - (jump * 3 / 2)] = CHSV (beatsin88(3000, 175, 215, n + (unsigned long)(i * 30)), jump, beatsin88(5000, 50, 180, n + (unsigned long)(i * 50)));
  }
  jump += 3;


///// reverse but i don't like it
//  for (int i = NUM_LEDS; i > NUM_LEDS - (jump * 3); i--) {
//    leds[i - (NUM_LEDS / 2) + (jump * 3 / 2)] = CHSV (beatsin88(3000, 175, 215, n + (unsigned long)(i * 30)), jump, beatsin88(5000, 50, 180, n + (unsigned long)(i * 50)));
//  }
//  jump += 3;



//for (int i = 0; i < NUM_LEDS; i++) {
//    leds[i] = CHSV (beatsin88(3000, beatsin88(5000, 100, 175), beatsin88(5000, 215, 235),n + (unsigned long)(i * 50)), 255, beatsin88(5000, 50, 180, n + (unsigned long)(i * 50)));
//  }
//
//  if (DESK_LIGHT) {
//    for (int i = 0; i < 77; i++) {
//      leds[i] = CRGB(77, 77, 77);
//    }
//    for (int i = 850; i < NUM_LEDS; i++) {
//      leds[i] = CRGB(77, 77, 077);
//    }
//  }
  
//  for (int i = 0; check_off() == false; i++) {
//    int random_led = random16(0, NUM_LEDS);
//    if (leds[random_led] != CRGB(0,0,0)) {
//      leds[random_led] = CRGB(0,0,0); // eventually make this fade
//                                            // fade maybe
////      fade_to_black(random_led, 60,20,4);
//      FastLED.delay(DELAY); //   takes ~4 mins @ 250
//    }
  FastLED.show();
//}
}


void trail(int i) {
  for (int j = 0; j < 20; j++) {
    if (random(10) > 8) {
      leds[i - j - 15] = CRGB(0,0,0);
      leds[NUM_LEDS - i + j + 15] = CRGB(0,0,0);
    }
  }
  leds[i - 40] = CRGB(0,0,0);
  leds[NUM_LEDS - i + 40] = CRGB(0,0,0);
}
