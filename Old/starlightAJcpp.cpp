
#include "../includes/Definitions.h"

#include "../includes/TimeManager.h"



//using namespace admux;


/*
PSEUDOKOD

    enum STATE { IDLE, CONFERENCE, VISITOR };
    int updateFreq;
*/

/*
  * Creates a Mux instance.
  *
  * 1st argument is the SIG (signal) pin (Arduino digital input pin 3).
  * 2nd argument is the S0-S3 (channel control) pins (Arduino pins 8, 9, 10, 11).
*/
IOArray interfaceArray();
IOArray old_interfaceArray();

TimeManager timeManager();

void setup() { 
    
    timeManager.setTime();
    for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
    {
        interfaceArray.data[i] = false;
    }

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
        //Placeholder, simply light all 'constellations' for now
        for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
        {
            interfaceArray.data[i] = true;
        }

    }
    //Check if in ACTIVE state
    else if(inputDetected == true){
        ledManager.setLeds(&interfaceArray);
    }
    
    //Kolla efter hemliga koder
    
}
