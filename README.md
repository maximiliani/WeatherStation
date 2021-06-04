# WeatherStation
This is the repo for my selfmade WeatherStation based on the ESP32 board. This repo is forked from the ESPFirmware, which was published by myself on the PrivateHomeIoT account.

## Sensors
- DHT11
- BMP280/BME280
- Rain sensor (capacative, analog)
- Soil moisture sensor (capacative, without electronics, analog)
- Soil moisture sensor (capacative, with electronics, analog)
- Battery voltage (analog)

## Pinout
| Sensor | Datapins | 3V | 
|---------|----------|----------|
|DHT11|25||
|BMP280/BME280|SDA: 21, SCL: 22|15|
|Rain|32||
|Soil #0|35||
|Soil #1|33||
|Battery|27||

