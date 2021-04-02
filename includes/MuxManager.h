#pragma once
#include "..\lib\arduino-ad-mux-lib-master\src\Mux.h"
#include "Definitions.h"

#define START_PIN 22
/*
//Norra HALVKLOTET
#define MUX_AMOUNT 3
//SÖDRA HALVKLOTET
#define MUX_AMOUNT 4
*/
//Testning


class MuxManager
{
private:
    //Member Variables
   

    //Member Functions

    

public:
    unsigned amountOfButtons;
    MuxManager(unsigned amountOfButtons = 0);
    ~MuxManager();
    admux::Mux* muxArr[MUX_AMOUNT];
    void AddMuxes();
};