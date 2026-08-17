#include <array>
#include "button.h"
#include <Arduino.h>
#include "debug.h"
#include "profile.h"

namespace button {
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
                String fileName = profile::get_profile() + String(i);
                fileName.replace(" ", "-");
                debugf("Running file %s from button\n", fileName.c_str());
                duckscript::run(fileName.c_str());
                delay(500);
            }
        }
    }

    void setupButtons() {
        for (const int pin: buttonPins) {
            pinMode(pin, INPUT_PULLUP);
        }
    }
}
