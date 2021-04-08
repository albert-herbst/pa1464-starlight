#pragma once
#include <Arduino.h>

class TimeManager
{
    private:
    unsigned long latestInteraction;
    unsigned long idleTimeout = 2000;

    unsigned long getTime();

    public:
        TimeManager();
        ~TimeManager();
        
        bool isIdle();
        void setTime();
};