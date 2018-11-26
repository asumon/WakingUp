#include <FastLED.h>
#include "FastLED.h"
#define NUM_LEDS 58
#define DATA_PIN D2

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setMaxRefreshRate(200);

}

void loop() {

  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[0] = CRGB(255, 255, 255);
    FastLED.show();
    delay(40);
  }

}


