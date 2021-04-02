#include "..\includes\MuxManager.h"
#define MUX_SIG_PIN 53
#define S0 51
#define S1 50
#define S2 49
#define S3 48

MuxManager::MuxManager(unsigned amountOfButtons)
{
    //this->amountOfButtons = amountOfButtons;

    //AddMuxes();

}


MuxManager::~MuxManager()
{

}

void MuxManager::AddMuxes(){

    for (unsigned i = 0; i < MUX_AMOUNT; i++)
    {
        //admux::Mux mux(admux::Pin(START_PIN + 5*i, INPUT, admux::PinType::Digital),
        Serial.println("About to print pins");
        Serial.println(START_PIN + (5*i));
        Serial.println(START_PIN + (5*i + 1));
        Serial.println(START_PIN + (5*i + 2));
        Serial.println(START_PIN + (5*i + 3)); 
        Serial.println(START_PIN + (5*i + 4));
        delay(1000); 
     // admux::Mux mux(admux::Pin(MUX_SIG_PIN, INPUT, admux::PinType::Digital), admux::Pinset(S0, S1, S2, S3));
        admux::Mux mux(admux::Pin(START_PIN + (5*i), INPUT, admux::PinType::Digital), 
        admux::Pinset(START_PIN + (5*i + 1), START_PIN + (5*i + 2), START_PIN + (5*i + 3), START_PIN + (5*i + 4)));

        this->muxArr[i] = &mux;
    }   
    
}

