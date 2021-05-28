#pragma once

#define MUX_AMOUNT 1
#define BUTTON_AMOUNT 4
#define NUM_CODES 3 // Final should be 15



typedef struct{
  bool data[BUTTON_AMOUNT];
} IOArray;
