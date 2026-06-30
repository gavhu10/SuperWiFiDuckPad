#include <array>
#include <string>
#include "duckscript.h"


const int buttonPins[] = {12, 11, 10, 9, 8, 7, 6, 5, 4};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

// TODO: namespace
std::array<bool, numButtons> getPressed();

void checkButtons();

void setupButtons();