#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
    delay(100);
    Serial.println(F("S:setup"));

    Serial.println(F("E:setup:"));
}

void loop()
{
}

