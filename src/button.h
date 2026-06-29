#include <array>



const int buttonPins[] = {12, 11, 10, 9, 8, 7, 6, 5, 4};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);


std::array<bool, numButtons> get_pressed();