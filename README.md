# Weather_Station
This is the repo for my selfmade Weatherstation based on the ESP32 board. This repo is forked from the ESPFirmware, which was published by myself on the PrivateHomeIoT account.

## Sensors
- DHT11
- BME280
- Rain Sensor (capacative, analog)
- Soil Moisture Sensor (capacative, without electronics, analog)
- Soil Moisture Sensor (capacative, with electronics, analog)

## Pinout
- DHT11 --> 34
- BME280 --> SDA: 21, SCL: 22
- Rain Sensor --> 32
- Soil Moisture Sensor #1 --> 35
- Soil Moisture Sensor #2 --> 33

The other ports can be used as outputs or binary inputs. For more information please have a look at the ESPFirmware and PrivateHome repos published by PrivateHomeIoT.

