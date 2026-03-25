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
    std::string currentFn = "null";
    unsigned int branchCount = 0;
    unsigned int callCount = 0;

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
    void addSubAndOr(const std::string&);
    void negOrNot(bool isNeg);
    void branch(const std::string&);
public:
    explicit CodeWriter(const std::string&);
    void setFileName(const std::string&);
    void writeArithmetic(const std::string&);
    void writePushPop(CommandType, const std::string&, unsigned int);
    void writeLabel(const std::string &label);
    void writeGoTo(const std::string &label);
    void writeIf(const std::string &label);
    void writeFunction(const std::string &functionName, unsigned int nVars);
    void writeCall(const std::string &functionName, unsigned int nArgs);
    void writeReturn();
    void writeBootStrap();
};


#endif //VMTRANSLATOR_CODEWRITER_H