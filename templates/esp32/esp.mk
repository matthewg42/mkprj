# Either define ESP_MAKEFILE in the environment to be the full path 
# to where you have makeEspArduino.mk installed, or just edit it here...
ifndef ESP_MAKEFILE
	ESP_MAKEFILE := /opt/makeEspArduino/makeEspArduino.mk
endif

ifndef ESP_ROOT
	# based on instructions from the esp32 github README.md
	ESP_ROOT := $(shell grep -o "sketchbook.path=.*" $(HOME)/.arduino/preferences.txt 2>/dev/null | cut -f2- -d=)/hardware/espressif/esp32
endif

ifndef ARDUINO_LIBS
	ARDUINO_LIBS := $(shell grep -o "sketchbook.path=.*" $(HOME)/.arduino/preferences.txt 2>/dev/null | cut -f2- -d=)/libraries
endif

include $(ESP_MAKEFILE)


