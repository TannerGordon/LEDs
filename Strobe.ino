#include "FastLED.h"
#include <pixeltypes.h>

// Strobe
// Tanner Gordon
// December 17, 2020

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    876
#define BRIGHTNESS  200

#define DELAY 200

#define CONSTANT_COLOR true



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
//  Serial.begin(115200);
}

void loop()
{
  fill_solid(leds, NUM_LEDS, CRGB(random8(BRIGHTNESS), random8(BRIGHTNESS), random8(BRIGHTNESS)));
  delay(DELAY);
  FastLED.show();
  
  if (CONSTANT_COLOR == true) {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.show();
    delay(DELAY);
  
    fill_solid(leds, NUM_LEDS, CRGB::Green);
    FastLED.show();
    delay(DELAY);
  
    fill_solid(leds, NUM_LEDS, CRGB::Blue);
    FastLED.show();
    delay(DELAY);
  
    fill_solid(leds, NUM_LEDS, CRGB::Cyan);
    FastLED.show();
    delay(DELAY);
  
    fill_solid(leds, NUM_LEDS, CRGB::Magenta);
    FastLED.show();
    delay(DELAY);
  
    fill_solid(leds, NUM_LEDS, CRGB::FireBrick);
    FastLED.show();
    delay(DELAY);
  
    fill_solid(leds, NUM_LEDS, CRGB::Aqua);
    FastLED.show();
    delay(DELAY);
  
    fill_solid(leds, NUM_LEDS, CRGB::Gold);
    FastLED.show();
    delay(DELAY);
  
    fill_solid(leds, NUM_LEDS, CRGB::MidnightBlue);
    FastLED.show();
    delay(DELAY);
  
    fill_solid(leds, NUM_LEDS, CRGB::Peru);
    FastLED.show();
    delay(DELAY);
  }
  
}
