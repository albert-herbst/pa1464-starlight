#pragma once
#include "Definitions.h"
#include <FastLED.h>
#include "Definitions.h"

#define LED_PIN 30
#define NUM_LEDS 14
#define NUM_CONSTELLATIONS 3
#define ANIMATION_SPEED 0 // Cycles per second


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
        unsigned int idleWave(byte value);
        int timeStep();
        CHSV mapColors(unsigned int value);
        CRGB leds[NUM_LEDS];
        byte idleValue[NUM_LEDS];
        struct Constellation constellations[NUM_CONSTELLATIONS];
        bool firstIdle = true;
        long lastCycle;
        bool isIdle = false;
        byte incrementIdle(int value, byte increment);
};