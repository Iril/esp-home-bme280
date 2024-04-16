substitutions:
  devicename: "nodemcu-01"
  Device_Location: Room
  update_interval: 120s
  ipaddress: 10.0.0.31
  unique_id: "nodemcu-01"

esphome:
  board: nodemcuv2
  platform: ESP8266
  name: $devicename
  includes:
    - veml6075_custom_sensor.h
  libraries:
    - "Wire"
    - "https://github.com/sparkfun/SparkFun_VEML6075_Arduino_Library"
  friendly_name: "NodeMCU-01 - Room"

# Enable logging
logger:
  level: NONE

wifi:
  ssid: ssid-public
  password: password123

  manual_ip:
    # Set this to the IP of the ESP
    static_ip: $ipaddress
    # Set this to the IP address of the router. Often ends with .1
    gateway: 10.0.0.1
    # The subnet of the network. 255.255.255.0 works for most home networks.
    subnet: 255.255.254.0
    dns1: 10.0.0.1

# Enable Home Assistant API
api:
  encryption:
    key: secret_api_key

ota:
  password: secret_ota_key
