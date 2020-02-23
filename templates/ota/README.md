# Template OTA Arduino Project

## Pre-requisites

* Install the Arduino IDE 1.8.5 or later from [the offical website]
  (https://www.arduino.cc/en/Main/Software)
* Install Esp32 libraries by following instructions from the [git repo]
  (https://github.com/espressif/arduino-esp32)

## Building Using the Arduino IDE

This method is preferred on Windows & Mac and for casual users who just want to 
build and use the project.

* Open Arduino IDE 
* Open `firmware/firmware.ino`
* Set the board you are using with *Tools* [menu] → *Board*
* Connect board with USB cable 
* Set the port with the *Tools* [menu] → *Port*
* Click the Upload button on the tool bar

## Using *make* 

This is an alternative build system which may suit some users.

* Clone the [git repo for makeEspArduino]
  (https://github.com/plerup/makeEspArduino.git)
* Set these environment variables:

```bash
export ESP_MAKEFILE=/path/to/makeEspArduino/makeEspArduino.mk
ESP_OTA_AUTH=yourotapassword
ESP_OTA_PORT=3232
ESP_OTA_WIFI_AUTH=yourwifipass
ESP_OTA_WIFI_SSID=yourwifissid
```

* First time, upload using `make upload`
* Watch serial output for IP address of ESP, e.g. *192.168.1.104*; then 
  subsequent uploads can be perfomed using:

```
make ota ESP_PORT=$ESP_OTA_PORT ESP_PWD=$ESP_OTA_AUTH ESP_ADDR=192.168.1.104
```

