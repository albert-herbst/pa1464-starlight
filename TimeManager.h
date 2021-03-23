#pragma once
#include <Arduino.h>

class TimeManager
{
    private:
    unsigned long latestInteraction;
    unsigned long idleTimeout;

    unsigned long getTime();

    public:
        TimeManager();
        ~TimeManager();
        
        bool isIdle();
        void setTime();
};