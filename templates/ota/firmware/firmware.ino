#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include <Update.h>
#include <MutilaDebug.h>
#include <Millis.h>
#include "EspID.h"

uint32_t LastOut = 0;

void setup() {
    Serial.begin(115200);
    DBLN(F("\n\nS:setup"));

    WiFi.mode(WIFI_STA);
    WiFi.begin(ESP_OTA_WIFI_SSID, ESP_OTA_WIFI_AUTH);

    // Must come after WiFi.begin(...)
    EspID.begin();

    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        DBLN(F("WiFi Connection ERROR"));
        delay(5000);
        DBLN(F("Rebooting"));
        ESP.restart();
    }

    ArduinoOTA.setPort(ESP_OTA_PORT);
    String hostname(F("ESP-"));
    hostname += EspID.get();
    DB(F("hostname=")); 
    DBLN(hostname);
    ArduinoOTA.setHostname(hostname.c_str());
#ifdef ESP_OTA_AUTH_MD5
    ArduinoOTA.setPasswordHash(ESP_OTA_AUTH_MD5);
#else
    ArduinoOTA.setPassword(ESP_OTA_AUTH);
#endif

    ArduinoOTA
    .onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH)
            type = F("sketch");
        else // U_SPIFFS
            type = F("filesystem");

        // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
        DB(F("OTA updating: "));
        DBLN(type);
    })
    .onEnd([]() {
        DBLN("\nOTA END");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
        DBF("OTA progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
        DBF("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) DBLN("OTA auth failed");
        else if (error == OTA_BEGIN_ERROR) DBLN("OTA begin failed");
        else if (error == OTA_CONNECT_ERROR) DBLN("OTA connect failed");
        else if (error == OTA_RECEIVE_ERROR) DBLN("OTA receive failed");
        else if (error == OTA_END_ERROR) DBLN("OTA end failed");
    });

    ArduinoOTA.begin();

    DB(F("Connected, IP address: "));
    DBLN(WiFi.localIP());
    DBLN(F("E:setup"));
}

void loop() {
    // Give OTA code a timeslice
    ArduinoOTA.handle();

    // Do something so we know we're running.
    if (DoEvery(1000, LastOut)) {
        DBF("Millis=0x%08X hi there\n", Millis());
    }
}

