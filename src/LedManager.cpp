#include "..\includes\LedManager.h"



LedManager::LedManager()
{
    
}

void LedManager::setupConstellation(int index, int start, int stop, int r, int g, int b)
{
    this->constellations[index].start = start;
    this->constellations[index].stop = stop;
    this->constellations[index].color.r = r;
    this->constellations[index].color.g = g;
    this->constellations[index].color.b = b;
}

void LedManager::Setup()
{
    //Serial.println("Setting up!");
    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed   
    IdleLeds();
    LedShow();
    
    setupConstellation(0, 0, 0, 0, 200, 0);

    setupConstellation(1, 1, 1, 200, 0, 0);

    setupConstellation(2, 2, 4, 0, 0, 200);

    idleValue[0] = 0;
    idleValue[1] = 150;
    idleValue[2] = 200;
    idleValue[3] = 50;
    idleValue[4] = 100;
}

void LedManager::SetLeds(IOArray* io_array)
{
    isIdle = false;
    for (int i = 0; i < BUTTON_AMOUNT; i++)
    {
        //Serial.print("Setting group: ");
        //Serial.println(i, DEC);
        updateGroup(i, io_array->data[i]);
    }
}

void LedManager::updateGroup(int group, bool on)
{
    if (group >= NUM_CONSTELLATIONS)
    {
        //Serial.println("Group amount too high!");
        return;
    }

    //Serial.print("Setting leds for group: ");
    //Serial.println(group, DEC);

    for (int i = constellations[group].start; i <= constellations[group].stop; i++)
    {
        //Serial.print("Setting led: ");
        //Serial.println(i, DEC);
        if (on)
        {
            //Serial.println("Led is on");
            leds[i].setRGB(constellations[group].color.r, constellations[group].color.g, constellations[group].color.b);
        }
        else
        {
            //Serial.println("Led is off");
            leds[i].setRGB(0, 0, 0);
        }
    }
}

void LedManager::LedShow()
{
    //Serial.println("Showing leds");
    if (isIdle)
    {
        IdleLeds();
    }
    FastLED.show();
}

void LedManager::IdleLeds()
{
    isIdle = true;
    for (int i; i < NUM_LEDS; i++)
    {
        Serial.println(i, DEC);
        idleValue[i] = incrementIdle(idleValue[i], 1);
        CHSV color = mapColors(idleWave(idleValue[i]));
        leds[i].setHSV(color.h, color.s, color.v);
    }
}

int LedManager::timeStep()
{

}

byte LedManager::incrementIdle(int value, byte increment)
{
    value = value + increment;
    if (value > 254)
    {
        return value - 255;
    }
    else
    {
        return value;
    }
}

CHSV LedManager::mapColors(unsigned int value)
{
    byte h = map(value, 0, 255, 150, 230);
    //byte h = map(value, 0, 255, 0, 255);
    return CHSV(h, 255, 100);
}

unsigned int LedManager::idleWave(byte value)
{
    return quadwave8(value);
}
