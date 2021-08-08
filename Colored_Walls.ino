#include <FastLED.h>

#define NUM_LEDS    876
#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    876
//#define BRIGHTNESS  60 // low light
#define BRIGHTNESS 120 // regular light

#define MOVEMENT true

bool reverse = false;


CRGB leds[NUM_LEDS];



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
  int bright = 255;

  // for debugging purposes:
//  Serial.println(bright, DEC);
  // serial.print goes negative at 3276 sec
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
