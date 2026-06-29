#include <array>
#include "button.h"
#include <Arduino.h>


std::array<bool, numButtons> get_pressed() {
    std::array<bool, numButtons> pressed;
    int i = 0;
    for (const int pin: buttonPins) {
        pressed[i] = (digitalRead(pin) == LOW);
        ++i;
    }
}