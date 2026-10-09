#include "LEDController.h"

LEDController::LEDController()
{
}

void LEDController::init()
{
    pinMode(BMEConstants::LED_Pin, OUTPUT);
}

void LEDController::setFrequency(float temperatureC)
{
    if (temperatureC > 50) {
        togglePeriod = 10;
    } else if (temperatureC > 45) {
        togglePeriod = 20;
    } else if (temperatureC > 40) {
        togglePeriod = 40;
    } else if (temperatureC > 35) {
        togglePeriod = 80;
    } else if (temperatureC > 30) {
        togglePeriod = 150;
    } else if (temperatureC > 25) {
        togglePeriod = 300;
    } else if (temperatureC > 20) {
        togglePeriod = 500;
    } else if (temperatureC > 15) {
        togglePeriod = 1000;
    } else if (temperatureC > 10) {
        togglePeriod = 1500;
    } else if (temperatureC > 5) {
        togglePeriod = 2000;
    } else if (temperatureC > 0) {
        togglePeriod = 3000;
    } else {
        togglePeriod = 4000;
    }
}

void LEDController::update()
{
    unsigned long now = millis();
    unsigned long timeElapsed = now - lastToggle;
    if (togglePeriod <= timeElapsed) {
        lastToggle = now;
        if (ledOn) {
            ledOn = false;
            digitalWrite(BMEConstants::LED_Pin, LOW);
        } else {
            ledOn = true;
            digitalWrite(BMEConstants::LED_Pin, HIGH);
        }
    }

}