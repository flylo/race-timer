#include <Arduino.h>
#include <DisplayInterface.h>
#include <PiezoBuzzer.h>
#include <TimedAction.h>
#include <MemoryFree.h>

#define Rec 0      //Light sensor output
#define Laser 2    //Laser module 


DisplayInterface displayInterface = DisplayInterface();
bool detection;
// PiezoBuzzer piezoBuzzer = PiezoBuzzer();

void setup()
{
    Serial.begin(9600);
    Serial.println("initializing");
    Serial.print("freeMemory()=");
    Serial.println(freeMemory());
    displayInterface.init();
    pinMode(Laser, OUTPUT);
    digitalWrite(Laser, HIGH); //Turning on the laser
    displayInterface.displayMsg("pwnage");
    // piezoBuzzer.init();
}

void loop()
{
    Serial.println(F("main loop:"));
    Serial.print("freeMemory()=");
    Serial.println(freeMemory());
    short Detect = analogRead(Rec);            //Constanly reading the module value
    if(Detect < 500)              //The Max value is 760, if someone passes it goes below that (every value lower than 700 can do the work)
        detection = true;          //The detection is triggered
        displayInterface.displayMsg("WOWOWOW");
}
