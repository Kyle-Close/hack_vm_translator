//
// Created by kyle on 2026-03-20.
//

#ifndef VMTRANSLATOR_CODEWRITER_H
#define VMTRANSLATOR_CODEWRITER_H

#include <fstream>
#include <string>
#include <vector>

#include "Parser.h"

class CodeWriter {
    std::ofstream outFile;
    std::string currentVmFileName;

public:
    explicit CodeWriter(const std::string&);
    void setFileName(const std::string&);
    void writeArithmetic(const std::string&);
    void writePushPop(CommandType, std::string&, unsigned int);
};


#endif //VMTRANSLATOR_CODEWRITER_H