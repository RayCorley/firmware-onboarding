#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "BMEConstants.h"
#include "LEDController.h"

void setup()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    if (!BMEI2CInterfaceInstance::instance().init()) {
        digitalWrite(LED_BUILTIN, HIGH);
        while (true) {}
    } else {
        LEDControllerInstance::instance().init();
    } 
}

void loop()
{
    BMEI2CInterfaceInstance::instance().update();
    LEDControllerInstance::instance().setFrequency(BMEI2CInterfaceInstance::instance().getTemperature());
    LEDControllerInstance::instance().update();
}