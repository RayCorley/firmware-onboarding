#include <Arduino.h>
#include "BMESPIInterface.h"
#include "BMEConstants.h"
#include "LEDController.h"

void setup()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    if (!BMESPIInterfaceInstance::instance().init()) {
        digitalWrite(LED_BUILTIN, HIGH);
        while (true) {}
    } else {
        LEDControllerInstance::instance().init();
    } 
}

void loop()
{
    BMESPIInterfaceInstance::instance().update();
    LEDControllerInstance::instance().setFrequency(BMESPIInterfaceInstance::instance().getTemperature());
    LEDControllerInstance::instance().update();
}