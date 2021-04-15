#include "../includes/TimeManager.h"

TimeManager::TimeManager()
{
    this->latestInteraction = 0; // Protection against undefined behaviour
}

// TODO(Simon): Remove this if it's useless
TimeManager::~TimeManager()
{
    
}

// TODO(Simon): Remove this if it's useless
unsigned long TimeManager::getTime() 
{
    return this->latestInteraction;
}

void TimeManager::setTime()
{
    this->latestInteraction = millis();
}

bool TimeManager::isIdle()
{
    // TODO(Simon): Might want overflow protection
    if (millis() > (this->latestInteraction + this->idleTimeout))
    {
        return true;
    }
    else
    {
        return false;
    }
}

