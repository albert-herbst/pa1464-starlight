#pragma once
#include "Definitions.h"
#include <FastLED.h>
#include "Definitions.h"

#define LED_PIN 30
#define NUM_LEDS 5
#define NUM_CONSTELLATIONS 3

struct Constellation
{
    int start;
    int stop;
    CRGB color;
};

class LedManager{
    public:
        LedManager();
        void SetLeds(IOArray* io_array);
        void IdleLeds();
        void LedShow();
        void Setup();
    private:
        void updateGroup(int i, bool on);
        void setupConstellation(int index, int start, int stop, int r, int g, int b);
        
        CRGB leds[NUM_LEDS];
        struct Constellation constellations[NUM_CONSTELLATIONS];
};