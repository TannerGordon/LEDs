// This program is custom to my room, where each poster
// has it's own corrosponding light above it, including
// the door, walls, and space in between posters
// 
// the lights for each segment can either be static or 
// moving by changing MOVEMENT to true or false


#include <FastLED.h>

#define NUM_LEDS    876
#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    876
//#define BRIGHTNESS  60 // low light
#define BRIGHTNESS 120 // regular light

#define MOVEMENT true


CRGB leds[NUM_LEDS];

void setup() {
//  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(BRIGHTNESS < 255);

  // set master brightness control
//  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{


//  fill_solid(leds, NUM_LEDS, CRGB(10,20,100));

  int seconds = millis() / 10;
  int sec = seconds / 10;
  
  if (MOVEMENT == false) {
    seconds = 0;
  }

  poster_landscape(seconds);
  poster_japan(seconds);
  poster_monkey(seconds);
  poster_flag(seconds);

  wall1(sec);
  wall2(sec);
  wall3(sec);
  wall4(sec);
  wall5(sec);

  
  FastLED.show();
}

//////////////////    POSTERS      /////////////////////

// spans from 786 to 875
void poster_landscape(int s)
{
  int start = 786;
  int fin = 875;
//  static uint8_t hue=0;  //define hue variable
//  leds.fill_rainbow(hue++);
  for (int i = start; i < NUM_LEDS; i++) {
    leds[i] = CHSV((i - start)*3 - 20 + s, 255, BRIGHTNESS);
  }
}

// spans from 436 to 580
void poster_japan(int s)
{
  int start = 436;
  int fin = 580;
  for (int i = start; i < fin; i++) {
    int hue = (i - start)*2;
//    if (i <= 512) {
//      leds[i] = CHSV(hue + 160, 255, BRIGHTNESS);
//    }
////    leds[i] = CHSV(hue + 150, 255, BRIGHTNESS);
////    leds[512] = CRGB(0,0,0);
//    if (i >= 512) {
//      leds[i] = CHSV((hue + 150) - 20, 255, BRIGHTNESS);
//    }
    leds[i] = CHSV((i - start)*3 - 20 + s, 255, BRIGHTNESS);
  }
}

// spans from 134 to 228
void poster_monkey(int s)
{
  int start = 134;
  int fin = 228;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV((i - start)*2 + 200 + s, 255, BRIGHTNESS);
  }
}

void poster_flag(int s)
{
  int start = 0;
  int fin = 55;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i*2 + s, 255, BRIGHTNESS);
  }
}

//////////////////    WALLS      ////////////////////////
void wall1(int s)
{
  int start = 55;
  int fin = 134;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + 90 + s, 255, BRIGHTNESS);
//      leds[i] = 
  }
}

void wall2(int s)
{
  int start = 228;
  int fin = 436;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + s, 255, BRIGHTNESS);
  }
}

void wall3(int s)
{
  int start = 580;
  int fin = 621;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + 20 + s, 255, BRIGHTNESS);
  }
}

void wall4(int s)
{
  int start = 621;
  int fin = 712;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + 594 + s, 255, BRIGHTNESS);
  }

}

void wall5(int s)
{
  int start = 712;
  int fin = 786;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + s, 255, BRIGHTNESS);
  } 
}
