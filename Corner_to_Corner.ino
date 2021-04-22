// Custom Room Design
// creates corners at each corner point in my room
// corners are a moving rainbow, extending from the middle->out
// randomly, there is a small chance that a color will 'shoot out' 
// from the corner and travel to the next corner

#include <FastLED.h>

#define NUM_LEDS    876
#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    876
#define BRIGHTNESS 120

#define CORNER1 0 
#define CORNER2 230
#define CORNER3 437
#define CORNER4 580
#define CORNER5 622
#define CORNER6 712


#define CORNER_LENGTH 25
#define NUM_TO_REVERSE 10

#define RISK 3

CRGB leds[NUM_LEDS];




void setup() {
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(BRIGHTNESS < 255);
    Serial.begin(115200);
}

void loop() {
  int num = millis() / 100;
  int corner_num = millis() / 100;

//  Serial.println(num);

//  if (num % 2 == 0) {
//    travel(19, 15, 400); 
//  }


    // for travel, make a struc that has the position and color and everytime it loops
    // we just incresae the pos by 1 and once it hits the end it deletes

//  slow_rainbow(num);
//  blue_white(num);
  corner(corner_num, CORNER1); 
  corner(corner_num, CORNER2);
  corner(corner_num, CORNER3);
  corner(corner_num, CORNER4);
  corner(corner_num, CORNER5);
  corner(corner_num, CORNER6);

  if (num == 5) {
//    leds[18] = CRGB::Yellow;
  }

    travel(CORNER_LENGTH, CORNER_LENGTH - 1, CORNER2 + 1 - CORNER_LENGTH); 
    travel(CORNER_LENGTH + CORNER2, CORNER_LENGTH - 1 + CORNER2, CORNER3 + 1 - CORNER_LENGTH); 
    travel(CORNER_LENGTH + CORNER3, CORNER_LENGTH - 1 + CORNER3, CORNER4 + 1 - CORNER_LENGTH); 
    travel(CORNER_LENGTH + CORNER4, CORNER_LENGTH - 1 + CORNER4, CORNER5 + 1 - CORNER_LENGTH); 
    travel(CORNER_LENGTH + CORNER5, CORNER_LENGTH - 1 + CORNER5, CORNER6 + 1 - CORNER_LENGTH); 
    travel(CORNER_LENGTH + CORNER6, CORNER_LENGTH - 1 + CORNER6, 877 - CORNER_LENGTH); 

//  CRGB x = leds[400];
//  leds[0] = x;
  FastLED.show();

}

 void travel(int start, int color, int arr_end) {
  if (random(100) < RISK) {
//    Serial.println(leds[start].r);
    leds[start] = leds[color];
  }
  if (leds[start].r != 0 and leds[start + 1].r != 0) {
    leds[start] = CRGB::Black;
  }

  for (int i = arr_end; i > color; i--) {
    if (leds[i].r != 0) {
      leds[i + 1] = leds[i];
      leds[i] = CRGB::Black;
    }
  }
  leds[arr_end] = CRGB::Black;
  if (leds[start + 1].r != 0) {
    leds[start] = leds[start + 1];
  }
 }



void blue_white(int s) {
//  for (float i = 0; i < NUM_LEDS; i++) {
//    leds[int(i)] = CHSV(150, (int(sin(0.05 * s)) * 100 + 145, BRIGHTNESS);
//  }
//  for (int i = 0; i < NUM_LEDS; i++) {
//    if (i % NUM_TO_REVERSE < NUM_TO_REVERSE / 2) {
//      leds[i] = CHSV(i / 30 + s, 255, BRIGHTNESS); // Hue: i / 30 + s
//    }
//  }
}

// creates slow rainbow for entire led strip
void slow_rainbow(int s) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(i / 30 + s, 255, BRIGHTNESS); // Hue: i / 30 + s
  }
}

// creates rainbow starting at corner and spreads outwards by length of CORNER_LENGTH
void corner(int s, int c) {
  for (int i = c; i < CORNER_LENGTH + c; i++) {
    leds[i] = CHSV((i - s) * 10, 255, BRIGHTNESS);
    leds[bounded(c - (i - c))] = CHSV((i - s) * 10, 255, BRIGHTNESS);
  }
}

// returns a bounded number if parameter is out of bounds of the NUM_LEDS
int bounded(int c) {
  if (c < 0) {
    return bounded(c + NUM_LEDS);
  } else if (c > NUM_LEDS) {
    return c % NUM_LEDS;
  }
  return c;
}
