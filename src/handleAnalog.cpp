#include "handleAnalog.h"
#include "Arduino.h"

#define rain 32
#define soil0 35
#define soil1 33

String getSoil0Moisture(){
    int soilMoistureValue = analogRead(35);
    soilMoistureValue = 4095- soilMoistureValue;
    Serial.print("Soil0: ");
    Serial.print(soilMoistureValue);
    float soilmoisturepercent = map(soilMoistureValue, 790, 390, 0, 1000)/10;
    if(soilmoisturepercent > 100) soilmoisturepercent = 100.0;
    else if(soilmoisturepercent < 0) soilmoisturepercent = 0.0;
    Serial.print(" ");
    Serial.println((String)soilmoisturepercent + "%");
    return (String)soilmoisturepercent;
}

String getSoil1Moisture(){
    int soilMoistureValue = analogRead(soil1);
    Serial.print("Soil1: ");
    Serial.print(soilMoistureValue);
    float soilmoisturepercent = map(soilMoistureValue, 790, 390, 0, 1000)/10;
    if(soilmoisturepercent > 100) soilmoisturepercent = 100.0;
    else if(soilmoisturepercent < 0) soilmoisturepercent = 0.0;
    Serial.print(" ");
    Serial.println((String)soilmoisturepercent + "%");
    return (String)soilmoisturepercent;
}

String getRain(){
    int value = analogRead(rain);
    value = 4095-value;
    Serial.print("Rain: ");
    Serial.print(value);
    value = map(value,400,0,0,1000)/10;
    if (value > 1000) value = 1000;
    if (value < 0) value = 0;
    Serial.print(" ");
    Serial.println((String)value + "%");
    return (String)(value);
}