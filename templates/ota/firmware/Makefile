# Compile options
BUILD_EXTRA_FLAGS += -DDEBUG

# Get OTA details from environment (so we don't have to 
# commit them to public repositories when we publish code.
BUILD_EXTRA_FLAGS += -DESP_OTA_WIFI_SSID=\"$(ESP_OTA_WIFI_SSID)\"
BUILD_EXTRA_FLAGS += -DESP_OTA_WIFI_AUTH=\"$(ESP_OTA_WIFI_AUTH)\"
BUILD_EXTRA_FLAGS += -DESP_OTA_PORT=$(ESP_OTA_PORT)
BUILD_EXTRA_FLAGS += -DESP_OTA_AUTH=\"$(ESP_OTA_AUTH)\"

# Supported speeds: 921600 460800 230400 115200 57600 9600
#UPLOAD_SPEED = 921600

# Set for your hardware
# For NodeMCU 0.9 (ESP-12 Module)
#BOARD = nodemcu

# For NodeMCU 1.0 (ESP-12E Module)
#BOARD = nodemcuv2

# For Node32-S (ESP32):
#CHIP = esp32
#BOARD = node32s

# For Wemos Lolin 32
CHIP = esp32
BOARD = lolin32
UPLOAD_SPEED=115200

include ../esp.mk

