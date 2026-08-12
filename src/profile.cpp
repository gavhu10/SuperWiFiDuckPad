#include <Arduino.h>
#include <sstream>
#include <string>
#include <vector>
#include "spiffs.h"
#include "profile.h"

namespace profile
{
    String get_profile()
    {
        String contents = spiffs::readFile(PROFILE_FILE);
        if (contents == ""){
            return "default";
        }
        else {
            return contents;
        }
    }

    void set_profile(String profile) {
        spiffs::remove(PROFILE_FILE);
        spiffs::write(PROFILE_FILE, profile.c_str());
    }

    String get_profile_list() {
        return spiffs::readFile(PROFILE_LIST_FILE);
    }

    std::vector<std::string> _get_split_list() {
        std::string contents = get_profile_list().c_str();
        std::istringstream iss(contents);
        std::vector<std::string> lines;
        std::string line;

        while (std::getline(iss, line)) {
            lines.push_back(line);
        }

        return lines;
    }  
    
    void _write_split_list(std::vector<std::string> list) {
        std::string ret;

        for (const auto i: list) {
            ret += i;
            ret += "\n";
        }

        spiffs::remove(PROFILE_LIST_FILE);
        spiffs::write(PROFILE_LIST_FILE, ret.c_str());
    }

    void remove_profile(String profile) {
        std::vector<std::string> list = _get_split_list();

        auto profile_index = std::find(list.begin(), list.end(), profile.c_str());
        if (profile_index != list.end()) {
            list.erase(profile_index);
        }

        _write_split_list(list);
    }

    void add_profile(String profile) {
        std::vector<std::string> list = _get_split_list();

        if (std::find(list.begin(), list.end(), profile.c_str()) == list.end()) {
            list.push_back(profile.c_str());
        }

        _write_split_list(list);
    }

}