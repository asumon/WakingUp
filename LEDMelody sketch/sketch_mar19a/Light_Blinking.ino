 #include "FastLED.h" 
 #include "pitches.h"
 #define LED_COUNT 8
 #define DATA_PIN 4


#define per_min    60000
#define per_sec    1000


unsigned long stopTime =per_min * 1;
unsigned long startTime=millis();
unsigned long  startTime1=millis();
unsigned long stopTime1 =per_min * 1;


CRGB leds[LED_COUNT];




void setup() {
  // put your setup code here, to run once:
  delay(3000);
   Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_COUNT);
 // startTime1=millis();
  

}

int speed=90;  //higher value, slower notes
//Mario main theme melody
int melody[] = {
 NOTE_C6, NOTE_D6,NOTE_E6, NOTE_F6, NOTE_G6,0, NOTE_E6, NOTE_C6,0,NOTE_G6,0,NOTE_F6,NOTE_D6,0,
  NOTE_F6,0, NOTE_D6, NOTE_B5,0,NOTE_F6,0,NOTE_E6,NOTE_C6,0,
  NOTE_G5,0,NOTE_C6,0,NOTE_F6,0,NOTE_E6,NOTE_G6,NOTE_C6,0,
  NOTE_E6,NOTE_F6,NOTE_E6,NOTE_F6,NOTE_E6,NOTE_F6,NOTE_E6,NOTE_C6,NOTE_D6,0,
  NOTE_C6, NOTE_D6,NOTE_E6, NOTE_F6, NOTE_G6,0, NOTE_E6, NOTE_C6,0,NOTE_G6,0,NOTE_F6,NOTE_D6,0,
  NOTE_F6,0, NOTE_D6, NOTE_B5,0,NOTE_F6,0,NOTE_E6,NOTE_C6,0,
  NOTE_A5,0,NOTE_A6,0,NOTE_G6,NOTE_F6,NOTE_E6,NOTE_F6,NOTE_G6,0,NOTE_C6,NOTE_C6,0,
  NOTE_E6,NOTE_F6,NOTE_E6,NOTE_C6,NOTE_F6,NOTE_E6,NOTE_C6,NOTE_A6,NOTE_G6,0,
  NOTE_G5,NOTE_G5,NOTE_F6,NOTE_E6,NOTE_D6,NOTE_E6,NOTE_C6,0,0,

  NOTE_C6,NOTE_B5,NOTE_C6,NOTE_G5,0,
  NOTE_C6,NOTE_B5,NOTE_C6,NOTE_E6,0,
  NOTE_F6,NOTE_E6,NOTE_D6,NOTE_C6,NOTE_F6,NOTE_F6,NOTE_E6,NOTE_D6,NOTE_C6,NOTE_C6,NOTE_D6,NOTE_D6,0,
  NOTE_C6,NOTE_B5,NOTE_C6,NOTE_G5,0,
  NOTE_C6,NOTE_B5,NOTE_C6,NOTE_G6,0,
  NOTE_F6,NOTE_F6,NOTE_F6,NOTE_F6,NOTE_F6,NOTE_E6,NOTE_D6,NOTE_F6,0,
  NOTE_C6,NOTE_D6,NOTE_F6,NOTE_E6,NOTE_E6,NOTE_E6,NOTE_D6,NOTE_C6,NOTE_E6,0,
  NOTE_A5,NOTE_B5,NOTE_C6,NOTE_D6,NOTE_A5,NOTE_A5,NOTE_B5,NOTE_C6,NOTE_D6,NOTE_C6,NOTE_G6,0,

  NOTE_C6, NOTE_D6,NOTE_E6, NOTE_F6, NOTE_G6,0, NOTE_E6, NOTE_C6,0,NOTE_G6,0,NOTE_F6,NOTE_D6,0,
  NOTE_F6,0, NOTE_D6, NOTE_B5,0,NOTE_F6,0,NOTE_E6,NOTE_C6,0,
  NOTE_G5,0,NOTE_C6,0,NOTE_F6,0,NOTE_E6,NOTE_G6,NOTE_C6,0,
  NOTE_E6,NOTE_F6,NOTE_E6,NOTE_F6,NOTE_E6,NOTE_F6,NOTE_E6,NOTE_C6,NOTE_D6,0,
  NOTE_C6, NOTE_D6,NOTE_E6, NOTE_F6, NOTE_G6,0, NOTE_E6, NOTE_C6,0,NOTE_G6,0,NOTE_F6,NOTE_D6,0,
  NOTE_F6,0, NOTE_D6, NOTE_B5,0,NOTE_F6,0,NOTE_E6,NOTE_C6,0,
  NOTE_A5,0,NOTE_A6,0,NOTE_G6,NOTE_F6,NOTE_E6,NOTE_F6,NOTE_G6,0,NOTE_C6,NOTE_C6,0,
  NOTE_E6,NOTE_F6,NOTE_E6,NOTE_C6,NOTE_F6,NOTE_E6,NOTE_C6,NOTE_A6,NOTE_G6,0,
  NOTE_G5,NOTE_G5,NOTE_F6,NOTE_E6,NOTE_D6,NOTE_E6,NOTE_C6,0,0,
};

//Mario main them tempo
int tempo[] = {
  
    8, 8, 8, 8,8,10,8,8,10,8,10,4,8,2,
    8,10,8,8,10,8,10,4,8,2,
    8,10,8,10,8,10,4,8,4,6,
    8,8,8,8,8,8,8,8,4,4,
    8, 8, 8, 8,8,10,8,8,10,8,10,4,8,2,
    8,10,8,8,10,8,10,4,8,2,
    8,10,8,10,8,8,8,8,4,10,8,8,4,
    8,8,8,8,8,8,8,8,2,4,
    8,8,8,8,8,8,6,1,4,

    4,4,6,2,5,
    4,4,6,2,5,
    4,4,4,8,4,8,4,4,4,2,8,2,1,
    4,4,6,2,5,
    4,4,6,2,5,
    8,8,8,8,8,8,8,4,4,
    8,8,8,4,4,8,8,8,2,4,
    4,4,4,8,4,8,4,8,8,8,1,4,

    8, 8, 8, 8,8,10,8,8,10,8,10,4,8,2,
    8,10,8,8,10,8,10,4,8,2,
    8,10,8,10,8,10,4,8,4,6,
    8,8,8,8,8,8,8,8,4,4,
    8, 8, 8, 8,8,10,8,8,10,8,10,4,8,2,
    8,10,8,8,10,8,10,4,8,2,
    8,10,8,10,8,8,8,8,4,10,8,8,4,
    8,8,8,8,8,8,8,8,2,4,
    8,8,8,8,8,8,6,1,4,
};




void loop() {
  // put your main code here, to run repeatedly:


for (int x = 0; x < LED_COUNT; x++)

{
   Serial.print(x);
    switch (x)
   
    {
        case (0):
        {
          
        colorStep();
              break;
            
        }
        case (1):
        
        {
       colorful();
         break;
         
        }
         case (2):
        {
         melodySong();
         break;
            
         }
          case (3):
        {
        lightStop();
         break;
         
        }
    }


}



}


void colorStep(){
  Serial.println("-Color Step for 10 Min");
  while ((millis() - startTime) < stopTime)
 {
 
    for (int i=0;i<=LED_COUNT;i++){
    leds[i] = CRGB(255, 0, 0); // Red Color
    delay(100);
     FastLED.show();
   }
     for (int j=0;j<=LED_COUNT;j++){
  leds[j] = CRGB(0, 255, 0); // Green Color
 delay(100);
   FastLED.show();
     }
     for (int k=0;k<=LED_COUNT;k++){
  leds[k] = CRGB(0, 0, 255); // Blue Color
  delay(100);
   FastLED.show();
     }
     for (int l=0;l<=LED_COUNT;l++){
  leds[l] = CRGB(255, 255, 255); // White Color
  delay(100);
   FastLED.show();
     }
     for (int m=0;m<=LED_COUNT;m++){
  leds[m] = CRGB(170, 0, 255); // Purple Color
  delay(100);
    FastLED.show();
  }
  for (int n=0;n<=LED_COUNT;n++){
  leds[n] = CRGB::Yellow; // Yellow Color
  delay(100);
  FastLED.show();
  }
    }
    colorful();
}



void colorful(){
  Serial.println("-Light for Colorful");
 // while ((millis() - startTime1) < stopTime1){
 for( int colorStep=255; colorStep >= 0; colorStep-- ) {
  for (int cf = 0; cf <= LED_COUNT; cf++){
 leds[cf] = CHSV(colorStep++,255,255);
    delay(50);
   FastLED.show();
//}
}
}
}

void melodySong() {

  
    Serial.println("-Mario Theme");
    //int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < 256; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
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



void lightStop(){
  Serial.println("-Stop");
  for(int f=0;f<LED_COUNT;++f){
    leds[f] = CRGB::Black;
    }
    FastLED.show();
    delay(600000);
  }

