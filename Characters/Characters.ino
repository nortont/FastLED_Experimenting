



/* 
Author: Tim Norton

Date: 22/12/2022

Description:
Display characters on 8x8 SW2812B pixel array

Chipset:
Adafruit Metro Express M0
SAMD21G18A

 */

#include <FastLED.h> // https://fastled.io/docs/3.1/md__p_o_r_t_i_n_g.html
#include "xy_matrix.h"

/* Setup of LED array */
    #define NUM_LEDS 320

    #define LED_BRIGHTNESS   5
    CRGB leds[NUM_LEDS];

/* Connections */
    #define LED_MAX_POWER 13
    #define DATA_PIN 6

/* Loop timings */
    u_int32_t millisLoop1=0; // track time between event calls
    u_int32_t millisLoop2=0; // track time between event calls
    u_int32_t millisLoop3=0; // track time between event calls
    u_int16_t timeLoop1 = 500; // mS between loops for serial write
    u_int16_t timeLoop2 = 100; // mS between loops
    u_int16_t timeLoop3 = 100; // mS between loops


/* Colour settings */
    uint8_t initialHue =0 ; //
    const uint8_t deltaHue = 255;
    const uint8_t hueDensity = 1;

void setup() {
    Serial.begin(9600); // enable serial communiucation
    pinMode(LED_MAX_POWER,OUTPUT);

    pinMode(DATA_PIN,OUTPUT);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Type, pin (array, NUMB_LEDS)
    FastLED.setBrightness(LED_BRIGHTNESS);
    FastLED.setMaxPowerInMilliWatts(2000); // 20 watts or 4 amps 
    set_max_power_indicator_LED(LED_MAX_POWER); // pin to display power error on
    fill_solid(leds, NUM_LEDS, CRGB::Black); // Start with all LED's off
    FastLED.show();
}
void loop() {
    u_int16_t milliwats; // current power requirements for LEDs
    milliwats = (calculate_unscaled_power_mW(leds, NUM_LEDS)); // how much power is required to display at 255
        static int x=0;
        static int y=0; 
/* Millis() timed loop 1 
    Serial write updates
*/
    if(millis()- millisLoop1> timeLoop1){ // Test for time loop eleapsed

            Serial.print("Milli Watts needed at brightness 255 - ");
            Serial.println(milliwats);    
                   
            millisLoop1 = millis(); // update the last time we ran this loop
}


/* Millis() timed loop 2 */
    if(millis()- millisLoop2> timeLoop2){ // Test for time loop eleapsed
        uint16_t ledPositionPrevious;
        uint16_t ledPosition;
           //fill_rainbow(leds, 320 /*led count*/, initialHue += hueDensity /*starting hue*/, deltaHue);

        if(x<=39){ // are we at the end of the row?
            ledPosition = getPosition(x,y);
            ledPositionPrevious= getPosition(x-1,y);
            leds[ledPosition] = CRGB::Blue;
           if(x>0){leds[ledPositionPrevious] = CRGB::Red;}
            x=x+1;
        }
        else { // end of row so move down one
        ledPositionPrevious= getPosition(x-1,y);
        if(x>0){leds[ledPositionPrevious] = CRGB::Red;}
             x=0;
             if(y<7){ // move to next line
                 y=y+1;
             }
             else{ y=0;}
        }            
        FastLED.show(); 
        millisLoop2 = millis(); // update the last time we ran this loop
}
/* Millis() timed loop 3 */
    if(millis()- millisLoop3> timeLoop3){ // Test for time loop eleapsed

        /* do stuff here if elapsed */
        millisLoop3 = millis(); // update the last time we ran this loop
}



}