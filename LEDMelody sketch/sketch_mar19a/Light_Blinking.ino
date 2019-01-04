
 # include "FastLED.h"   // FastLED library File
 # include "pitches.h"  //This library file contains all the pitch values for typical notes
 # include "melody.h"   //This Library file contains Notes and Tempo
 # define LED_COUNT 8
 # define DATA_PIN 4

 # define per_min 60000
 # define per_sec 1000


//variable Size for number storage
 unsigned long startTime;

// grab current time
 unsigned long startTime1 = millis();

//Decleare the Duration 
 unsigned long stopTime = per_min * 15;
 unsigned long stopTime1 = per_min * 20;
 unsigned long stopTime2 = per_min * 23;

 //Decleare the Array to store the Led Data
 CRGB leds[LED_COUNT];

// setup code , to run once:
 void setup() {
    
    delay(3000);
    Serial.begin(9600);
    FastLED.addLeds < NEOPIXEL, DATA_PIN > (leds, LED_COUNT);
    startTime = millis();

 }



 void loop() {
    //  main code here, to run repeatedly

    for (int x = 0; x < 4; x++)

    {
       Serial.print(x);
       switch (x)

       {
       case 0:
          colorStep();
          break;

       case 1:

          colorful();
          break;

       case 2:
          melodySong();
          break;

       case 3:
          lightStop();
          break;

       }

    }

 }

 void colorStep() {
    Serial.println("-My first pattern for 15 Min");
    //Decleare the While condition for certain amount of time 
    while ((millis() - startTime) <= stopTime) {
       for (int i = 0; i <= LED_COUNT; i++) {
          leds[i] = CRGB(255, 0, 0); // Red Color
          delay(100);
          FastLED.show();
       }
       for (int j = 0; j <= LED_COUNT; j++) {
          leds[j] = CRGB(0, 255, 0); // Green Color
          delay(100);
          FastLED.show();
       }
       for (int k = 0; k <= LED_COUNT; k++) {
          leds[k] = CRGB(0, 0, 255); // Blue Color
          delay(100);
          FastLED.show();
       }
       for (int l = 0; l <= LED_COUNT; l++) {
          leds[l] = CRGB(255, 255, 255); // White Color
          delay(100);
          FastLED.show();
       }
       for (int m = 0; m <= LED_COUNT; m++) {
          leds[m] = CRGB(170, 0, 255); // Purple Color
          delay(100);
          FastLED.show();
       }
       for (int n = 0; n <= LED_COUNT; n++) {
          leds[n] = CRGB::Yellow; // Yellow Color
          delay(100);
          FastLED.show();
       }

    }
 }

 void colorful() {
    Serial.println("-My Second Pattern for 5 min");

    while ((millis() - startTime) <= stopTime1)

    {
       //Nested for loop 
       for (int j = 255; j >= 0; j--) {
          for (int i = 0; i <= LED_COUNT; i++) {
             leds[i] = CRGB(255,j--, 255); // Fade Color
             Serial.println(j--);
             delay(30);
             FastLED.show();
          }
       }
    }
 }

 void melodySong() {

    Serial.println("-Mario Theme");
    //int size = sizeof(melody) / sizeof(int);
    while ((millis() - startTime) <= stopTime2) {

   // iterate over the notes of the melody...
       for (int thisNote = 0; thisNote < 256; thisNote++) {

          // to calculate the note duration, take one second divided by the note type.
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int noteDuration = 1000 / tempo[thisNote];

          tone(D6, melody[thisNote], noteDuration);

          // to distinguish the notes, set a minimum time between them.
          // the note's duration + 30% seems to work well:
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);

          // stop the tone playing:
          noTone(D6);

       }

    }
 }

 void lightStop() {
    Serial.println("-Stop");
    for (int f = 0; f <= LED_COUNT; ++f) {
       leds[f] = CRGB::Black;
    }
    FastLED.show();
    delay(6000);
 }
