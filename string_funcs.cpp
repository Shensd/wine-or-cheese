#include "string_funcs.h"

std::vector<std::string> split(std::string str, char delim) {
    std::vector<std::string> arr;
    std::string temp;

    for(unsigned int i = 0; i < str.size(); i++) {
        if(str.at(i) == delim) {
            if(temp != "") {
                arr.push_back(temp);
                temp = "";
            }
        } else {
            temp += str.at(i);
        }
    }
    if(temp != "") {
        arr.push_back(temp);
    }

    return arr;
}

std::string join(std::vector<std::string> str, char paste) {
    std::string end;
    for(unsigned int i = 0; i < str.size(); i++) {
        end += str.at(i);
        if(i != str.size()) {
            end += paste;
        }
    }
    return end;
}
