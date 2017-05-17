#include <Arduino.h>
#include <MutilaDebug.h>
#include "HeartBeat.h"

void setup()
{
    Serial.begin(115200);
    HeartBeat.begin();
    DBLN(F("E:setup"));
}

void loop()
{
    HeartBeat.update();
}

