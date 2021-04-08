
#include "includes\Definitions.h"
#include "includes\LedManager.h"
#include "includes\TimeManager.h"
#include "includes\ButtonManager.h"


IOArray interfaceArray;
IOArray old_interfaceArray;
ButtonManager buttonManager;
TimeManager timeManager;

LedManager ledManager;

void setup()
{
    Serial.begin(9600);
    Serial.println("Program start");
    
    
    buttonManager = ButtonManager();
    buttonManager.initMuxes();
    timeManager = TimeManager();
    timeManager.setTime();

    ledManager = LedManager();
    ledManager.Setup();

    for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
    {
        old_interfaceArray.data[i] = interfaceArray.data[i];
    }
    
}

bool isAlreadyIdle = false;

void loop()
{
    
    //Read input every loop update
    buttonManager.GetButtons(&interfaceArray);

    //Check if there is any change in the input, a change means one or more buttons have been pressed
    bool inputDetected = false;
    bool pressed = false;
    for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
    {
        if (interfaceArray.data[i] == true)
        {
            inputDetected = true;
        }
        if (old_interfaceArray.data[i] != interfaceArray.data[i]){
            inputDetected = true;
            //Set last interaction
            timeManager.setTime();
        } 
    }
    
    if(timeManager.isIdle() && !isAlreadyIdle && !inputDetected){
        //Placeholder, simply light all 'constellations' for now
        //Serial.println("Setting idle");
        ledManager.IdleLeds();
        ledManager.LedShow();
        isAlreadyIdle = true;
    }
    //Check if in ACTIVE state
    else if(inputDetected == true)
    {
        //Serial.println("Setting leds");
        ledManager.SetLeds(&interfaceArray);
        ledManager.LedShow();
        isAlreadyIdle = false;
    }

    //Update the old array
    for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
    {
        old_interfaceArray.data[i] = interfaceArray.data[i];
    }
    
}