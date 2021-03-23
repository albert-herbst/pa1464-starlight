#include "MuxManager.h"
#include "Mux.h"

MuxManager::MuxManager(unsigned amountOfButtons)
{
    this->amountOfButtons = amountOfButtons;

    AddMuxes();

}


MuxManager::~MuxManager()
{

}

void MuxManager::AddMuxes(){

    for (unsigned i = 0; i < MUX_AMOUNT; i++)
    {
        admux::Mux mux(admux::Pin(22, INPUT, admux::PinType::Digital), admux::Pinset(23, 24, 25, 26));


        //admux::Mux mux(admux::Pin(START_PIN + 5*i, INPUT, admux::PinType::Digital), 
        //admux::Pinset(START_PIN + (5*i + 1), START_PIN + (5*i + 2), START_PIN + (5*i + 3), START_PIN + (5*i + 4)));

        this->muxArr[i] = mux;
    }   
    
}

