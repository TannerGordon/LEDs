#include <FastLED.h>

#define NUM_LEDS    876
#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    876
//#define BRIGHTNESS  60 // low light
#define BRIGHTNESS 120

#define MOVEMENT true

bool reverse = false;


CRGB leds[NUM_LEDS];
//CRGBArray<NUM_LEDS> leds;


void setup() {
//  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(BRIGHTNESS < 255);

  // set master brightness control
//  FastLED.setBrightness(BRIGHTNESS);
Serial.begin(115200);
//  bool reverse = false;
}

void loop()
{


//  fill_solid(leds, NUM_LEDS, CRGB(10,20,100));

  int seconds = millis() / 30; // was 10
  int sec = seconds / 15;      // was 10
//  int bright = 255 - seconds / 20;
//  bright = sin(bright);

//  int bright = seconds % 5;
//  if (bright == 5) {
//    reverse = true;
//  }
//  if (reverse == true) {
//    bright = 5 - bright;
//    reverse = false;
//  }
//  bright = bright * 10;
//  bright = 255 - bright;
  int bright = 255;
//  Serial.println(bright, DEC);

  // shit goes negative at 3276 sec
  // so 327600 milliseconds
  
  if (MOVEMENT == false) {
    seconds = 0;
  }

  wall1(sec, bright);
  wall2(sec, bright);
  wall3(sec, bright);
  wall4(sec, bright);
  wall5(sec, bright);
  wall6(sec, bright);
  
  FastLED.show();
}

//////////////////    POSTERS      /////////////////////
// I do not use these in this program, these are used in "Colored Walls"

// spans from 786 to 875
void poster_landscape(int s, int bright)
{
  int start = 786;
  int fin = 875;
//  static uint8_t hue=0;  //define hue variable
//  leds.fill_rainbow(hue++);
  for (int i = start; i < NUM_LEDS; i++) {
    leds[i] = CHSV((i - start)*3 - 20 + s, bright, BRIGHTNESS);
  }
}

// spans from 436 to 580
void poster_japan(int s, int bright)
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
    leds[i] = CHSV((i - start)*3 - 20 + s, bright, BRIGHTNESS);
  }
}

// spans from 134 to 228
void poster_monkey(int s, int bright)
{
  int start = 134;
  int fin = 228;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV((i - start)*2 + 200 + s, bright, BRIGHTNESS);
  }
}

void poster_flag(int s, int bright)
{
  int start = 0;
  int fin = 55;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i*2 + s, bright, BRIGHTNESS);
  }
}

//////////////////    WALLS      ////////////////////////
void wall1(int s, int bright)
{
  int start = 0;
  int fin = 232;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + 0 + s, bright, BRIGHTNESS);
//      leds[i] = 
  }
}

void wall2(int s, int bright)
{
  int start = 232;
  int fin = 437;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + 50 + s, bright, BRIGHTNESS);
  }
}

void wall3(int s, int bright)
{
  int start = 437;
  int fin = 580;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + 80 + s, bright, BRIGHTNESS);
  }
}

void wall4(int s, int bright)
{
  int start = 580;
  int fin = 621;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + 0 + s, bright, BRIGHTNESS);
  }

}

void wall5(int s, int bright)
{
  int start = 621;
  int fin = 712;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + 130 + s, bright, BRIGHTNESS);
  } 
}

void wall6(int s, int bright)
{
  int start = 712;
  int fin = NUM_LEDS;
  for (int i = start; i < fin; i++) {
    leds[i] = CHSV(i/2 + 40 + s, bright, BRIGHTNESS);
  } 
}

// other functions - unused

//  static uint8_t hue=0;  //define hue variable
//  leds.fill_rainbow(hue++);

//anjali@diesellabs.com
//ask question
