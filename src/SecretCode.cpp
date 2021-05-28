#include "../includes/SecretCode.h"

SecretCode::SecretCode()
{
    for (int i = 0; i < NUM_CODES; i++)
    {
        for(int j = 0; j < BUTTON_AMOUNT; j++){
            codes[i].inputs.data[j] = false;
            codes[i].outputs.data[j] = false;
        }
    }
    //Code 1
    //Required CODE
    codes[0].inputs.data[1] = true;
    codes[0].inputs.data[2] = true;
    //Gives OUTPUT
    codes[0].outputs.data[0] = true;

    //Code 1
    //Required CODE
    codes[1].inputs.data[0] = true;
    codes[1].inputs.data[2] = true;
    codes[1].inputs.data[3] = true;
    //Gives OUTPUT
    codes[1].outputs.data[1] = true;
    
    //Code 1
    //Required CODE
    codes[2].inputs.data[0] = true;
    codes[2].inputs.data[3] = true;
    //Gives OUTPUT
    codes[2].outputs.data[1] = true;
    codes[2].outputs.data[2] = true;

}

bool SecretCode::checkCode(IOArray* input)
{
    for (int i = 0; i < NUM_CODES; i++)
    {
        //FIX
        if (compareIOArrays(input, &codes[i].inputs))
        {
            return true;
        }
    }
    return false;
}

void SecretCode::reCode(IOArray * input)
{
    for (int i = 0; i < NUM_CODES; i++)
    {
        if (compareIOArrays(input, &codes[i].inputs))
        {
            for (int j = 0; j < BUTTON_AMOUNT; j++)
            {
                input->data[j] = codes[i].outputs.data[j];
            }
        }  
    }
}

bool SecretCode::compareIOArrays(IOArray * input1, IOArray * input2)
{
    for (int i = 0; i < BUTTON_AMOUNT; i++)
    {
        if (input1->data[i] != input2->data[i])
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