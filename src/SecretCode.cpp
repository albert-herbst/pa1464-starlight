#include "../includes/SecretCode.h"

SecretCode::SecretCode()
{
    codes[0].inputs.data[0] = true;
    codes[0].inputs.data[4] = true;

    codes[0].outputs.data[3] = true;
}

bool SecretCode::checkCode(IOArray input)
{
    for (int i = 0; i < NUM_CODES; i++)
    {
        //FIX
        if (compareIOArrays(input, codes[i].inputs))
        {
            return true;
        }
    }
    return false;
}

IOArray SecretCode::reCode(IOArray input)
{
    for (int i = 0; i < NUM_CODES; i++)
    {
        if (compareIOArrays(input, codes[i].inputs))
        {
            return codes[i].outputs;
        }
    }
    return input;
}

bool SecretCode::compareIOArrays(IOArray input1, IOArray input2)
{
    for (int i = 0; i < BUTTON_AMOUNT; i++)
    {
        if (input1.data[i] != input2.data[i])
        {
            return false;
        }
    }
    return true;
}

// Might not be used
bool SecretCode::addBooleans(bool input1, bool input2)
{
    if (input1 || input2)
    {
        return true;
    }
    else
    {
        return false;
    }
}