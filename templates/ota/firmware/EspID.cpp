#include <stdio.h>
#include <MutilaDebug.h>

#if defined(ARDUINO_ARCH_ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ARDUINO_ARCH_ESP32)
#include <WiFi.h>
#else
#error EspID is only supported on ESP8266 and ESP32 platforms
#endif

#include "EspID.h"

EspID_ EspID;

void EspID_::begin()
{
    byte mac[6];
    WiFi.macAddress(mac);
    DB("MAC: ");
    DB(mac[0],HEX);
    DB(":");
    DB(mac[1],HEX);
    DB(":");
    DB(mac[2],HEX);
    DB(":");
    DB(mac[3],HEX);
    DB(":");
    DB(mac[4],HEX);
    DB(":");
    DBLN(mac[5],HEX);
    snprintf(_id, ESPID_LENGTH, "%02X%02X%02X", mac[3], mac[4], mac[5]);
}

