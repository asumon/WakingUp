  #include "FastLED.h"

  // How many leds in your strip?
  #define NUM_LEDS 8
  #define DATA_PIN 4


  // Define the array of leds
  CRGB leds[NUM_LEDS];

  void setup() { 
          FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
         }

  void loop() { 
    // Turn the LED on, then pause
    setColor();
    delay(2000);
   }

void setColor(){
   for (int i=0;i<=NUM_LEDS;i++){
    leds[i] = CRGB(255, 0, 0); // Red Color
  delay(60);
   FastLED.show();
   }
     for (int j=0;j<=NUM_LEDS;j++){
  leds[j] = CRGB(0, 255, 0); // Green Color
  delay(60);
   FastLED.show();
     }
     for (int k=0;k<=NUM_LEDS;k++){
  leds[k] = CRGB(0, 0, 255); // Blue Color
  delay(60);
   FastLED.show();
     }
     for (int l=0;l<=NUM_LEDS;l++){
  leds[l] = CRGB(255, 255, 255); // White Color
  delay(60);
   FastLED.show();
     }
     for (int m=0;m<=NUM_LEDS;m++){
  leds[m] = CRGB(170, 0, 255); // Purple Color
  delay(60);
   FastLED.show();
  }
  
  }
