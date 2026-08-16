#include <string>
#include <Arduino.h>

#pragma once

#define PROFILE_FILE ".current-profile"
#define PROFILE_LIST_FILE ".profile-list"
namespace profile {
    String get_profile();

    void set_profile(String profile);

    String get_profile_list();

    void remove_profile(String profile);

    std::vector<std::string> _split_list();

    void _write_split_list(std::vector<std::string> list);

    void add_profile(String profile);
}