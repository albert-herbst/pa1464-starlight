#pragma once
#include "Definitions.h"
#include "..\Mux.h"
#define START_PIN 22

class ButtonManager
{

    public:
        ButtonManager();
        void initMuxes();
        void GetButtons(IOArray* io_array);
    private:
        admux::Mux muxArr[MUX_AMOUNT];
        void readMux(admux::Mux * mux, IOArray * io_array, int to_Read, int start_index);
};