#ifndef handleDHT_h
#define handleDHT_h

#include "Arduino.h"
#include "Adafruit_Sensor.h"
#include "Wire.h"
#include "SPI.h"
#include "DHT.h"
#include "DHT_U.h"

void setupDHT();
String getDHTTemperature();
String getDHTHumidity();

#endif