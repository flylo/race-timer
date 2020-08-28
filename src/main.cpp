#include <Arduino.h>
#include <DisplayInterface.h>
#include <PiezoBuzzer.h>
#include <TimedAction.h>
#include <MemoryFree.h>

DisplayInterface displayInterface = DisplayInterface();
// PiezoBuzzer piezoBuzzer = PiezoBuzzer();

void setup()
{
    Serial.begin(9600);
    Serial.println("initializing");
    Serial.print("freeMemory()=");
    Serial.println(freeMemory());
    displayInterface.init();
    // piezoBuzzer.init();
}

void loop()
{
    Serial.println(F("main loop:"));
    Serial.print("freeMemory()=");
    Serial.println(freeMemory());
    displayInterface.displayMsg("LOL");
    delay(1000);
    // displayLoopAction.check();
}
