#include <FastLED.h>

#define NUM_LEDS 320
#define DATA_PIN 6
CRGB leds[NUM_LEDS];


  uint8_t initialHue =0 ; //
  const uint8_t deltaHue = 255;
  const uint8_t hueDensity = 1;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Type, pin (array, NUMB_LEDS)
  FastLED.setBrightness(5);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}
void loop() {

  //fill_rainbow(leds, 320 /*led count*/, initialHue += hueDensity /*starting hue*/, deltaHue);
  //FastLED.show();
  // delay(10);

char serialValue; // data received via serial
int currentLED = 0; 
int previousLED=0; // Last LED selected


if(Serial.available()){
    serialValue=Serial.read();
    currentLED = atoi(&serialValue); // convert Char to int
    leds[previousLED] = CRGB::Black;
    leds[currentLED] = CRGB::Blue;
    FastLED.show();
    previousLED = currentLED;
    Serial.print(currentLED);
}
  
  
//   for(int dot = 0; dot < NUM_LEDS; dot++) { 
//             leds[dot] = CRGB::Blue;
//             FastLED.show();
//             // clear this led for the next time around the loop
//             leds[dot] = CRGB::Black;
//             delay(30);
//         }
  // 

}