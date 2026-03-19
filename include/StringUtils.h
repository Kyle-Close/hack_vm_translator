//
// Created by kyle on 2026-03-19.
//

#ifndef VMTRANSLATOR_STRINGUTILS_H
#define VMTRANSLATOR_STRINGUTILS_H
#include <string>

void TrimStart(std::string& str);
void TrimEnd(std::string& str);
void Trim(std::string& str);

bool StartsWith(const std::string& str, char target);
bool Contains(const std::string& str, char target);
bool IsNumber(const std::string& str);

#endif //VMTRANSLATOR_STRINGUTILS_H