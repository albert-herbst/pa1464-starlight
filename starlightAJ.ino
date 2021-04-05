#include <Arduino.h>
#include "includes/Definitions.h"
#include "includes/ButtonManager.h"
#include "includes/LedManager.h"
#include "includes/TimeManager.h"



/*
PSEUDOKOD

    enum STATE { IDLE, CONFERENCE, VISITOR };
    int updateFreq;
*/

IOArray interfaceArray;
IOArray old_interfaceArray;
ButtonManager buttonManager;
//LedManager ledManager();
TimeManager timeManager;

void setup() { 
    Serial.begin(9600);
    Serial.println("Program start");
    buttonManager = ButtonManager();
    buttonManager.initMuxes();
    timeManager = TimeManager();
    timeManager.setTime();
    buttonManager.GetButtons(&interfaceArray);
    for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
    {
        old_interfaceArray.data[i] = interfaceArray.data[i];
    }    
  
}

void loop(){
    //Read input every loop update
    buttonManager.GetButtons(&interfaceArray);

    //Check if there is any change in the input, a change means one or more buttons have been pressed
    bool inputDetected = false;
    for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
    {
        if (old_interfaceArray.data[i] != interfaceArray.data[i]){
            inputDetected = true;
            //Set last interaction
            timeManager.setTime();
        } 
    }

    

    //Check if in IDLE state
    if(timeManager.isIdle()){
        Serial.println("I am idle Pog");
        //Placeholder, simply light all 'constellations' for now
        for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
        {
            //interfaceArray.data[i] = true;
        }

    }
    //Check if in ACTIVE state
    else if(inputDetected == true){
        // old_interfaceArray.data = interfaceArray.data;
        Serial.println("Setting leds lol");
        //ledManager.setLeds(&interfaceArray);
        
    }

    //Update the old array
    for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
    {
        old_interfaceArray.data[i] = interfaceArray.data[i];
    }
    
    //Kolla efter hemliga koder
    
}
