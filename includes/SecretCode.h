#pragma once

#include "Definitions.h"





class SecretCode
{
    public:
        SecretCode();
        bool checkCode(IOArray* input);
        void reCode(IOArray* input);
    private:
        struct SecretCodeData
        {
            IOArray inputs;
            IOArray outputs;
        };
        bool compareIOArrays(IOArray * input1, IOArray * input2);
        bool addBooleans(bool input1, bool input2);
        struct SecretCodeData codes[NUM_CODES];

};

