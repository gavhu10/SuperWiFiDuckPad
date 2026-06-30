#include <array>
#include "button.h"
#include <Arduino.h>
#include "debug.h"


std::array<bool, numButtons> getPressed() {
    std::array<bool, numButtons> pressed;
    int i = 0;
    for (const int pin: buttonPins) {
        pressed[i] = (digitalRead(pin) == LOW);
        ++i;
    }
    return pressed;
}


void checkButtons() {
    auto states = getPressed();

    for (int i = 0; i < numButtons; ++i) {
        if (states[i]) {
            duckscript::run(std::to_string(i).c_str());
            delay(1000);
        }
    }
}

void setupButtons() {
    for (const int pin: buttonPins) {
        pinMode(pin, INPUT_PULLUP);
    }
}