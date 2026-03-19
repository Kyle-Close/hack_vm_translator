//
// Created by kyle on 2026-03-19.
//

#include <string>
#include "../include/StringUtils.h"

void TrimStart(std::string& str) {
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

void TrimEnd(std::string& str) {
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

void Trim(std::string& str) {
    if (str.empty()) {
        return;
    }

    TrimStart(str);
    TrimEnd(str);
}

bool StartsWith(const std::string& str, const char target) {
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

bool Contains(const std::string& str, const char target) {
    if (str.find(target) != -1) {
        return true;
    }
    return false;
}

bool IsNumber(const std::string &str) {
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}
