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
            contents.trim();
            return contents;
        }
    }

    void set_profile(String profile) {
        spiffs::remove(PROFILE_FILE);
        spiffs::write(PROFILE_FILE, profile.c_str());
    }

    String get_profile_list() {
        String list = spiffs::readFile(PROFILE_LIST_FILE);
        if (list == "") {
            return "\n";
        }
        return list;
    }

    std::vector<std::string> _split_list(std::string input) {
        std::istringstream iss(input);
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
        auto list = _split_list(get_profile_list().c_str());

        auto profile_index = std::find(list.begin(), list.end(), profile.c_str());
        if (profile_index != list.end()) {
            list.erase(profile_index);
        }

        _write_split_list(list);

        list = _split_list(spiffs::listDir("/").c_str());

        for (std::string const& i: list) {
            if (i.rfind(profile.c_str(), 0) == 0){
                spiffs::remove(i.c_str());
            }
        }
    }

    void add_profile(String profile) {
        std::vector<std::string> list = _split_list(get_profile_list().c_str());

        if (std::find(list.begin(), list.end(), profile.c_str()) != list.end()) {
            return;
        }

    spiffs::write(PROFILE_LIST_FILE, (profile + "\n").c_str());
    }

}