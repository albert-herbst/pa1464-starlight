#include "../includes/Definitions.h"
#include <iostream>

void printArr(IOArray* io_array){
    for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
    {
        std::cout << "InOut.data index " << i << ": " << io_array->data[i] << std::endl;
    }
    
}




class Input{


    public:
    void GetButtons(IOArray* io_array){
        for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
        {
            io_array->data[i] = true;
        }
        
    }
};

class Output{
    public:
    void SetLeds(IOArray* io_array){
        for (unsigned i = 0; i < BUTTON_AMOUNT; i++)
        {
            io_array->data[i] = false;
        }
        
    }

};


int main(int argc, char const *argv[])
{
    IOArray InOut;
    Input buttonManager;
    Output ledManager;
    std::cout << "---Garbage Data, array has not been modifed!!!" << std::endl;
    printArr(&InOut);
    buttonManager.GetButtons(&InOut);
    std::cout << "---Everything should be TRUE" << std::endl;
    printArr(&InOut);
    ledManager.SetLeds(&InOut);
    std::cout << "---Everything should be FALSE" << std::endl;
    printArr(&InOut);


    return 0;
}

