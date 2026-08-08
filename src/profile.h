#include <string>
#include <Arduino.h>

#pragma once

#define PROFILE_FILE ".current-profile"
namespace profile {
    String get_profile();

    void set_profile(String profile);
}