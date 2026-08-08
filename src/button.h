#include <array>
#include <string>
#include "duckscript.h"

#pragma once

const int buttonPins[] = {12, 9, 6, 11, 8, 5, 10, 7, 4};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

namespace button {
    std::array<bool, numButtons> getPressed();

    void checkButtons();

    void setupButtons();
}