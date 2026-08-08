#include <Arduino.h>
#include "spiffs.h"
#include "profile.h"

namespace profile {
    String get_profile() {
            String contents = spiffs::readFile(PROFILE_FILE);
            if (contents == "") {
                return "default";
            } else {
                return contents;
            }
    }

    void set_profile(String profile) {
            spiffs::write(PROFILE_FILE, profile.c_str());
    }
}