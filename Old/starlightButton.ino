#include <Arduino.h>
#include "includes\ButtonManager.h"
#include <FastLED.h>

#define LED_PIN 30

#define NUM_LEDS 5

CRGB leds[NUM_LEDS];

ButtonManager buttonManager;

IOArray interface;

void setup()
{
    //Serial.begin(9600);
    //Serial.println("Program start");
    buttonManager = ButtonManager();
    buttonManager.initMuxes();
    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
    //FastLED.showColor(CRGB(0,255,0));
    //delay(200);
    //FastLED.showColor(CRGB(0,0,0));
}

void loop()
{
    buttonManager.GetButtons(&interface);
    for (int i = 0; i < BUTTON_AMOUNT; i++)
    {
        if (interface.data[i])
        {
            //Serial.print("LED ON: ");
            //Serial.println(i);
            leds[i].setRGB(0,255,0);
        }
        else
        {
            //Serial.print("LED OFF");
            //Serial.println(i);
            leds[i].setRGB(0,0,0);
        }
    }
    FastLED.show();
    //delay(1000);
}