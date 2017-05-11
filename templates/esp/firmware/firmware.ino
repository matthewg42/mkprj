#include <Arduino.h>

#define PIN D5

bool ledon = true;
unsigned long nxt = 0;

void toggle()
{
    if (millis() > nxt) {
        ledon = ! ledon;
        Serial.println(ledon);
        digitalWrite(PIN, ledon);
        nxt = millis() + 500;
    }
}

void setup()
{
    Serial.begin(115200);
    pinMode(PIN, OUTPUT);
    Serial.println(F("setup:E"));
}

void loop()
{
    toggle();
}

