#pragma once
#include "Mux.h"


#define START_PIN 22
/*
//Norra HALVKLOTET
#define MUX_AMOUNT 3
//SÖDRA HALVKLOTET
#define MUX_AMOUNT 4
*/
//Testning
#define MUX_AMOUNT 1

class MuxManager
{
private:
    //Member Variables
   

    //Member Functions

    void AddMuxes();

public:
    unsigned amountOfButtons;
    MuxManager(unsigned amountOfButtons);
    ~MuxManager();
    admux::Mux muxArr[MUX_AMOUNT];
};