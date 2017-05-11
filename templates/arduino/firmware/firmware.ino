#include <Arduino.h>
#include <Heartbeat.h>

Heartbeat heartbeat(13);

void setup()
{
    Serial.begin(115200);
    heartbeat.begin();
    Serial.println(F("setup:E"));
}

void loop()
{
    heartbeat.update();
}

