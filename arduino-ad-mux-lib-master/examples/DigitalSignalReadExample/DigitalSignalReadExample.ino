/*-
 * This example demonstrates how to read digital signals.
 *
 * It assumes there are push buttons with pullup resistors connected to the 16
 * channels of the 74HC4067 mux.
 * 
 * ------------------------------------------------------------
 * Project: arduino-ad-mux-lib
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Author: Nick Lamprianidis (adaptation by Stefano Chizzolini)
 */

// How many leds in your strip?
#define NUM_LEDS 5

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define LED_PIN 23
#define INPUT_PIN 41
#define CLOCK_PIN 13
#define MUX_SIG_PIN 53

#define MUX_SIG_PIN 53
#define S0 51
#define S1 50
#define S2 49
#define S3 48

#include <Arduino.h>
//#include "Mux.h"
#include <FastLED.h>



/*
 * Creates a Mux instance.
 *
 * 1st argument is the SIG (signal) pin (Arduino digital input pin 3).
 * 2nd argument is the S0-S3 (channel control) pins (Arduino pins 8, 9, 10, 11).
 */
//admux::Mux mux(admux::Pin(MUX_SIG_PIN, INPUT, admux::PinType::Digital), admux::Pinset(S0, S1, S2, S3));
//CRGB leds[NUM_LEDS];
void setup() {
  // Serial port initialization.
  
  //FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
  Serial.println("Program start");
}

/**
 * Reads the 16 channels and reports on the serial monitor if the corresponding
 * push button is pressed.
 */
void loop() {
  byte data;
  for (byte i = 0; i < 5; i++) {
    //data = mux.read(i) /* Reads from channel i (returns HIGH or LOW) */;

    //Serial.print("Push button at channel "); Serial.print(i); Serial.print(" is "); Serial.println(data == LOW ? "not pressed" : "pressed");
  }
  Serial.println();

  delay(1500);
}
