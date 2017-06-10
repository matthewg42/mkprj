#include <Arduino.h>
#include <MutilaDebug.h>

void setup()
{
    Serial.begin(115200);
    delay(100);
    DBLN(F("S:setup"));

    DBLN(F("E:setup"));
}

void loop()
{
}

