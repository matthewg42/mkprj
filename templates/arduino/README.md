# Template Arduino Project

## Pre-requisites

* Install the *Arduino IDE 1.6.6* or later from the [official Arduino 
  website](https://www.arduino.cc/en/Main/Software)
* Install *Mutila* library using the library manager within the Arduino IDE, or
  by direct download from the [Mutila project page on Github]
  (https://github.com/matthewg42/Mutila)

## Building Using the Arduino IDE

This method is preferred on Windows & Mac and for casual users who just want to build
and use the project.

* Open Arduino IDE 
* Open `firmware/firmware.ino`
* Set the hardware you are using with the *Tools* → *Board* menu
* Connect board with USB cable and set the port with the *Tools* → *Port* menu
* Click the Upload button on the tool bar

## Using *make* on Linux

This is an alternative to using the Arduino IDE and may be preferred by some 
users. 

* Install [Arduino-Makefile](https://github.com/sudar/Arduino-Makefile)
* Edit the `arduino.mk` file in the project and set the include line to point
   at where you installed *Arduino-Makefile* (or set the `ARDUINO_MAKEFILE` 
   environment variable)
* Edit `firmware/Makefile` and uncomment a `BOARD_TAG` / `BOARD_SUB` for the
   hardware you're using
* In a shell, from the `firmware` directory, use the command `make upload` to 
   build and install the code

