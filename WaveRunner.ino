#include <FastLED.h>

#define NUM_LEDS    876
#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    876
#define BRIGHTNESS 120

#define DESK_LIGHT false // true if desk light on

CRGB leds[NUM_LEDS];

unsigned long n;
bool first;

void setup() {
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);
//    Serial.begin(115200);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
  first = true;
  n = millis() / 10;
//  for (int i = 0; i < NUM_LEDS / 2; i++) {
//    leds[i] = CHSV (beatsin88(3000, 175, 215, (i * 80)), 255, beatsin88(5000, 50, 180, (i * 100)));
//    leds[NUM_LEDS - i] = CHSV (beatsin88(3000, 175, 215, ((NUM_LEDS - i) * 50)), 255, beatsin88(5000, 50, 180, ((NUM_LEDS - i) * 60)));
//    FastLED.show();
//  }
}


#define MINS 15

#define DELAY_NUM 55
#define DELAY (DELAY_NUM * MINS)

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

// get two numbers
// slowly transition from curr to two nums
// do this by
// 
bool bj = false;
  int doggy = 120;
  int style = 170;

void loop() {
  n = millis() / 10;
  int counter = n % 1000;
  bool beginNow = false;
  int r1 = 0;
  int r2 = 0;
  
  if (n < 100) {
    beginNow = true;
  }
  if (beginNow) {
    r1 = random(0, 200);
    r2 = r1 + 50;
  }
//  int doggy = 120;
//  int style = 170;
  Serial.println(n);
  // uncomment this v
  for (int i = 0; i < NUM_LEDS; i++) {
    if (n < 500) {
    leds[i] = CHSV (beatsin88(3000, 120, 170, n + (unsigned long)(i * 30)), 255, beatsin88(5000, 50, 180, n + (unsigned long)(i * 50)));
  } else {
    bj = true;

    leds[i] = CHSV (beatsin88(3000, doggy, style, n + (unsigned long)(i * 30)), 255, beatsin88(5000, 50, 180, n + (unsigned long)(i * 50)));
  }
  
  }
if (bj) {
  doggy = doggy + 1;
  style++;
  Serial.println(doggy);
}

  
//for (int i = 0; i < NUM_LEDS; i++) {
//    leds[i] = CHSV (beatsin88(3000, beatsin88(5000, 100, 175), beatsin88(5000, 215, 235),n + (unsigned long)(i * 50)), 255, beatsin88(5000, 50, 180, n + (unsigned long)(i * 50)));
//  }

  if (DESK_LIGHT) {
    for (int i = 0; i < 77; i++) {
      leds[i] = CRGB(77, 77, 77);
    }
    for (int i = 850; i < NUM_LEDS; i++) {
      leds[i] = CRGB(77, 77, 077);
    }
  }
  
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
