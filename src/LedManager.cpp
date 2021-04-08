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
}

void LedManager::SetLeds(IOArray* io_array)
{
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
    FastLED.show();
}

void LedManager::IdleLeds()
{
    for (int i; i < NUM_LEDS; i++)
    {
        Serial.println(i, DEC);
        leds[i].setRGB(10, 40, 60);
    }
}
