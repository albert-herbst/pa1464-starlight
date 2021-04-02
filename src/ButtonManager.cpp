#include <Arduino.h>
#include "..\includes\ButtonManager.h"


ButtonManager::ButtonManager()
{

}

void ButtonManager::initMuxes()
{
    for (int i = 0; i < MUX_AMOUNT; i++)
    {
        Serial.print("Init MUX: "); 
        Serial.println(i);
        admux::MuxPin signalPin = admux::MuxPin(START_PIN + (5*i), INPUT, admux::PinType::Digital);
        admux::Pinset channelPins = admux::Pinset(START_PIN + (5*i + 1), START_PIN + (5*i + 2), START_PIN + (5*i + 3), START_PIN + (5*i + 4));
        admux::Mux mux = admux::Mux(signalPin, channelPins);
        muxArr[i] = mux;
    }
}

void ButtonManager::GetButtons(IOArray * io_array)
{
    for (int i = 0; i < MUX_AMOUNT; i++)
    {
        if ((BUTTON_AMOUNT - (16 * i)) >= 16)
        {
            Serial.println("First if");
            readMux(&muxArr[i], io_array, 16, 16*i);
        }
        else
        {
            Serial.println("Else");
            readMux(&muxArr[i], io_array, BUTTON_AMOUNT-(16*i), 16*i);
        }
    }
}

void ButtonManager::readMux(admux::Mux * mux, IOArray * io_array, int to_Read, int start_index)
{
    Serial.println("Reading buttons");
    Serial.print(to_Read);
    Serial.println(" to read");
    Serial.print(start_index);
    Serial.println(" start index");
    for (int i = 0; i < to_Read; i++)
    {
        
        // bool result = ((*mux).read(i) == HIGH) ? true : false;
        bool result = false;
        uint8_t readInt = mux->read(i);
        if (readInt == HIGH)
        {
            result = true;
        }
        else 
        {
            result = false;
        }

        Serial.print("i is: ");
        Serial.print(i, DEC);
        Serial.print("READ VALUE IS: ");
        Serial.println(readInt);
        Serial.println();
        Serial.println(result, BIN);
        io_array->data[start_index + i] = result;
        delay(50);
    }
}