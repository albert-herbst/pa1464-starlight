#include <Arduino.h>
#include <FastLED.h>
#include "Mux.h"
#include "MuxManager.h"
#include <math.h>

// How many leds are there in your strip?
#define NUM_LEDS 5

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define LED_PIN 30
#define INPUT_PIN 41
#define CLOCK_PIN 13
//#define MUX_SIG_PIN 53
#define S0 51
#define S1 50
#define S2 49
#define S3 48


//using namespace admux;

// Define the array of leds
CRGB leds[NUM_LEDS];


//using namespace admux;


/*
PSEUDOKOD

    enum STATE { IDLE, CONFERENCE, VISITOR };
    int updateFreq;
*/

/*
  * Creates a Mux instance.
  *
  * 1st argument is the SIG (signal) pin (Arduino digital input pin 3).
  * 2nd argument is the S0-S3 (channel control) pins (Arduino pins 8, 9, 10, 11).
*/




MuxManager Mux_Manager;

void setup() { 
  
  // Uncomment/edit one of the following lines for your leds arrangement.
  // ## Clockless types ##
  Serial.begin(9600);
  Serial.println("Program start");
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed   
  
  Mux_Manager.amountOfButtons = 5;
  Mux_Manager.AddMuxes();
  
}


//BUG: For some reason leds pair up every second button
void loop(){
    
  	for (unsigned i = 0; i < MUX_AMOUNT; i++)
    {
      // CHECKS MUX  
      int16_t data;
      Serial.println("Mux_Manager.amountOfButtons: ");
      Serial.print(Mux_Manager.amountOfButtons);
      delay(500);
      for (byte j = 0; j < Mux_Manager.amountOfButtons; j++) {
        data = Mux_Manager.muxArr[i]->read(j); //Reads from channel j (returns HIGH or LOW)
        if(data == HIGH) leds[j].setRGB(100, 100, 100);
        else leds[j].setRGB(0, 0, 0);
        
        Serial.print("Push button at channel "); Serial.print(j); Serial.print(" is "); Serial.println(data == HIGH ? "is HIGH" : "is LOW");
      }
      Serial.println();
      FastLED.show();
      //delay(16);    
    }
    

    /*

    //Read Input from MUX
    För varje knapp i Mux:


    








    Om STATE == IDLE
        Kolla om någon interaction skett
            Om Conf_Switch är av:
                Sätt STATE = VISITOR
            Om Conf_Switch är på:
                Sätt STATE = CONFERENCE
        Annars:
            Gör ingenting / Idle animationer?

    Om STATE == VISITOR ELLER CONFERENCE
    
    delay(updateFreq);
    */


  /* CHECKS MUX  
  byte data;
  for (byte i = 0; i < 5; i++) {
    data = mux.read(i); //Reads from channel i (returns HIGH or LOW)
    if(data == HIGH) leds[i].setRGB(150, 150, 150);
    else leds[i].setRGB(0, 0, 0);
    
    //Serial.print("Push button at channel "); Serial.print(i); Serial.print(" is "); Serial.println(data == LOW ? "not pressed" : "pressed");
  }
  //Serial.println();
  FastLED.show();
  delay(16);
  /*

  for (int j = 0; j < 255; j++)
      {
      for (int i = 0; i < NUM_LEDS; i++)
      {      
        if(digitalRead(INPUT_PIN) == HIGH){
          leds[i].setHSV(((i*85)+j)%255, 200, 200);
          delay(2);
          FastLED.show();
        }
        else{
          leds[i].setRGB(0, sin8_avr(signof), 0);
          signof++;
          delay(2);
          FastLED.show();
        }
          
      }
    }
    */
  //Mux test()




  /*if(digitalRead(INPUT_PIN) == HIGH){
    for (int j = 0; j < 255; j++)
    {
    for (int i = 0; i < NUM_LEDS; i++)
    {      
        leds[i].setHSV(((i*85)+j)%255, 200, 200);
        delay(2);
        FastLED.show();
    }
  }
    FastLED.show();
  }
  else{
    for (int j = 0; j < 255; j++)
    {
    for (int i = 0; i < NUM_LEDS; i++)
    {      
        leds[i].setRGB(0, sin8_avr(signof), 0);
        signof++;
        delay(2);
        FastLED.show();
    }
  }
  }
  
  
  
  
  
      /*for (int i = 0; i < 255; i++)
      {
        leds[0].setRGB(i, (i+50)%255, 0);
        leds[1].setRGB(0, i, 0);
        leds[2].setRGB(0, 0, i);
        delay(200);
      FastLED.show();
      }*/
      
      
      
    
  
  /*for (int i = 0; i < NUM_LEDS; i++)
  {
    // Turn the LED on, then pause
    //leds[i] = CGRB::Green;
    for (int j = 0; j < 100; j++)
    {
      leds[i].setRGB(j, 101-j, 0);
      delay(5);
      FastLED.show();
    }
    
    
    
    delay(500);
    // Now turn the LED off, then pause
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(500);
  }
  */
  

}
