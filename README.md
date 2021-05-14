# pa1464-okatima 

# Starlight

* [Svenska](#Svenska)
    * [Introduktion](#Introduktion)
    * [Krav](#Krav)
    * [Användning av programmet](#Användning-av-programmet)
        * [Stjärntecken](#Stjärntecken)
        * [Hemliga Koder](#Hemliga-koder)
    * [Funktioner](#Funktioner)
    * [Möjligheter](#Möjligheter)
* [English](#English)
    * [Introduction](#Introduction)
    * [Requirements](#Requirements)
    * [Program usage](#Program-usage)
        * [Constellations](#Constellations)
        * [Secret Codes](#Secret-Codes)
    * [Features](#Features)
    * [Possibilities](#Possibilities)


# Svenska
## Introduktion
Starlight är ett av koncepten som är framtagna genom ett projekt mellan en projektgrupp på BTH Karlskrona och Okatima/Kreativum. Starlight är ett koncept för att ge ett tekniskt och visuellt lyft de stjärnhimlar som finns utanför Kreanova på Kreativum. Vid ett besök på anläggningen såg vi hur stjärnhimlarna lystes upp med spotlights. Detta gjorde att det inte alltid var speciellt tydligt vilket stjärntecken som faktiskt skulle lysas upp. Vårt koncept går ut på att byta ut den nuvarande, analoga lösningen med spotlights mot en digital lösning som använder sig av individuellt adresserbara LED-lampor. 

Starlight drivs av en mikrokontroller, en Arduino. Genom att driva installationen med en Arduino så ger det en stor potential för vidareutveckling. Att göra det till mer än bara en enkel stjärnhimmel. Det har vi utnyttjat genom att implementera stöd för hemliga koder i knapparna. Detta betyder att om vissa förvalda knappar trycks ned så kommer inte dessa stjärntecken att lysa upp utan en (eller flera) andra förvalda stjärntecken kommer lysa upp istället. Det finns också ett vänteläge implementerat, vilket betyder att om inga knapptryckningar sker inom en viss tidsram så kommer animationer att spelas upp i sjtärntecknena tills nästa knapptryck sker. 

Idag är Starlight i ett konceptstadie. Men vi har redan skapat ett demo med tre funktionella stjärntecken. I detta demo finns alla de funktioner beskrivna ovan implementerade. Demot är en 3D-printad låda som projektgruppen själva har designat och byggt. 

<p align="center">
  <img src="https://i.imgur.com/1OHlyMU.png">
</p>
<center>Så här ser demot ut!</center>


## Krav
1. Arduino IDE

Programmet använder två externa bibliotek
* [Arduino-ad-mux-lib](https://github.com/stechio/arduino-ad-mux-lib)
* [FastLED](https://github.com/FastLED/FastLED)

## Användning av programmet
### Stjärntecken
För att definera ett nytt stjärntecken ska det totala antalet stjärntecken uppdateras i ledManager.h i variabeln [NUM_CONSTELLATIONS](https://github.com/albert-herbst/pa1464-okatima/blob/d36a7454aa84ac229d944279726b85aa35f4f5a7/includes/LedManager.h#L8) sedan kan det nya stjärntecknet läggas till i [LedManager::Setup](https://github.com/albert-herbst/pa1464-okatima/blob/d36a7454aa84ac229d944279726b85aa35f4f5a7/src/LedManager.cpp#L19) med funktionen setupConstellation.
### Hemliga koder
För att skapa en ny hemlig kod ska det totala antalet hemliga koder uppdateras i SecretCode.h i variabeln [NUM_CODES](https://github.com/albert-herbst/pa1464-okatima/blob/d36a7454aa84ac229d944279726b85aa35f4f5a7/includes/SecretCode.h#L5) sedan kan den nya hemliga koden läggas till i [SecretCode::SecretCode](https://github.com/albert-herbst/pa1464-okatima/blob/d36a7454aa84ac229d944279726b85aa35f4f5a7/src/SecretCode.cpp#L3) där codes\[i] är index av koden. Varje kod innehåller en inputs.data och en outputs.data där arrayen sätts till True för respektive knapp som ska vara intryckt för att aktivera koden samt knapp(ar) som ska virtuellt tryckas när koden är aktiv.
## Funktioner
Starlight har följande funktioner:
* Om en knapp trycks ner så lyses ett stjärnbild upp.
* Om ingen knapp trycks ner (eller hålls in) under en viss tid går Starlight in i ett *'vänteläge'* där an animation spelas.
    * Det går även att definiera nya stjärntecken som endast används som en hemlig kod.
* Alla LED-lampor är RGB, det går alltså att styra färgerna på dem individuellt. 

## Möjligheter
* Den hemliga koden går att använda för pussel i escape-room stil för t.ex konferensaktiviteter
* Framtida hopkoppling mellan en eller flera installationer



# English
## Introduction
Starlight is one of the proofs of concepts that have been the result of a student project with students from BTH Karlskrona and Okatima/Kreativum. Starlight is a concept for a technical and visual improvement to the night skies located outside of Kreanova at Kreativum. At a visit our group made to Kreativum we realized that spotlights were used for lighting up the constellations. This made it so that it was not always clear which constellation was supposed to light up. Our idea is to switch out the current solution to a digital one which would utilize individually addressable LED:s instead of spotlights. 

Starlight is driven by an Arduino microcontroller. By using an Arduino there is huge potential for further development of this installation, to make it more than just a night sky. We have used this opportunity to implement a secret code into the buttons of the installation. This means that if some pre-selected buttons are pressed at the same time, some other constellation is lit up instead of those whose buttons were just pressed. We have also implemented an idle mode, meaning that if no button presses are made for some time, an animation is played until a button is pressed. 

Starlight is only a proof of concept today. But we have created a demo that has three working constellations. In this demo, all of the aforementioned functionality has been implemented. The demo is a 3D-printed box that our group has designed and built. 


<p align="center">
  <img src="https://i.imgur.com/1OHlyMU.png">
</p>
<center>This is the demo!</center>

## Requirements
1. Arduino IDE

The program uses two external libraries
* [Arduino-ad-mux-lib](https://github.com/stechio/arduino-ad-mux-lib)
* [FastLED](https://github.com/FastLED/FastLED)

## Program-usage
### Constellations
To define a new constellation, the total number of constellations must be updated in ledManager.h in the variable [NUM_CONSTELLATIONS](https://github.com/albert-herbst/pa1464-okatima/blob/d36a7454aa84ac229d944279726b85aa35f4f5a7/includes/LedManager.h#L8) then the new constellation, can be added to [LedManager::Setup](https://github.com/albert-herbst/pa1464-okatima/blob/d36a7454aa84ac229d944279726b85aa35f4f5a7/src/LedManager.cpp#L19) with the setupConstellation function. 
### Secret Codes
To create a new secret code, the total number of secret codes must be updated in SecretCode.h in the variable [NUM_CODES](https://github.com/albert-herbst/pa1464-okatima/blob/d36a7454aa84ac229d944279726b85aa35f4f5a7/includes/SecretCode.h#L5) then the new secret code can be added in [SecretCode::SecretCode](https://github.com/albert-herbst/pa1464-okatima/blob/d36a7454aa84ac229d944279726b85aa35f4f5a7/src/SecretCode.cpp#L3) where codes \[i] are the index of the code. Each code contains an input.data and an outputs.data where the array is set to True for each button that must be pressed to activate the code and a button(s) that will be virtually pressed when the code is active. 
## Features
Starlight has the following features:
* If a button is pressed a constellation lights up.
* If no button is pressed (or held) for a period of time, Starlight will enter an *'idle mode* and an animation will play
    * It's also possible to define new constellations that are only part of the secret code.
* All the LED lamps are RGB, this makes it possible to control their colours individually.

## Possibilities
* The secret code functionality can be used in escape-room style activities, for example, conferences. 
* Future connections between one or more installations at Kreativum. 




