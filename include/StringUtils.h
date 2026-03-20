//
// Created by kyle on 2026-03-19.
//

#ifndef VMTRANSLATOR_STRINGUTILS_H
#define VMTRANSLATOR_STRINGUTILS_H
#include <string>

void trimStart(std::string& str);
void trimEnd(std::string& str);
void trim(std::string& str);

bool startsWith(const std::string& str, char target);
bool contains(const std::string& str, char target);
bool isNumber(const std::string& str);

#endif //VMTRANSLATOR_STRINGUTILS_H