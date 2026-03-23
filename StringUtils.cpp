//
// Created by kyle on 2026-03-19.
//

#include <string>
#include "StringUtils.h"

#include <algorithm>
#include <vector>
#include <sstream>

void trimStart(std::string& str) {
    if (str.empty()) {
        return;
    }

    int i = 0;
    while (i <= str.length() - 1 && std::isblank(str[i])) {
        i++;
    }

    if (i > 0) {
        str.erase(0, i);
    }
}

void trimEnd(std::string& str) {
    if (str.empty()) {
        return;
    }

    size_t i = str.length() - 1;
    size_t count = 0;
    while (count < str.length() && std::isblank(str[i])) {
        i--;
        count++;
    }

    if (count > 0) {
        str.erase(str.length() - count, count);
    }
}

void trim(std::string& str) {
    if (str.empty()) {
        return;
    }

    trimStart(str);
    trimEnd(str);

    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
}

bool startsWith(const std::string& str, const char target) {
    if (str.empty()) {
        return false;
    }

    for (int i = 0; i <= str.length() - 1; i++) {
        if (!std::isblank(str[i])) {
            if (str[i] == target) {
                return true;
            }
            return false;
        }
    }
    return false;
}

bool contains(const std::string& str, const char target) {
    if (str.find(target) != -1) {
        return true;
    }
    return false;
}

bool isNumber(const std::string &str) {
    auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}

std::vector<std::string> split(const std::string &str) {
    // variable to store token obtained from the original string
    std::string s;

    // constructing stream from the string
    std::stringstream ss(str);

    // declaring vector to store the string after split
    std::vector<std::string> v;

    while (getline(ss, s, ' ')) {
        // store token string in the vector
        v.push_back(s);
    }

    return v;
}