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

    void writeLine(const std::string&);
    void pushConstant(unsigned int);
    void pushArgLclThisThat(const std::string&, unsigned int);
    void pushStatic(unsigned int);
    void pushTemp(unsigned int);
    void pushPointer(unsigned int);
    void popArgLclThisThat(const std::string&, unsigned int);
    void popStatic(unsigned int);
    void popTemp(unsigned int);
    void popPointer(unsigned int);
public:
    explicit CodeWriter(const std::string&);
    void setFileName(const std::string&);
    void writeArithmetic(const std::string&);
    void writePushPop(CommandType, const std::string&, unsigned int);
};


#endif //VMTRANSLATOR_CODEWRITER_H