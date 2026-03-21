//
// Created by kyle on 2026-03-20.
//

#include "../include/CodeWriter.h"
#include <fstream>
#include <format>
#include <iostream>


CodeWriter::CodeWriter(const std::string &outFileName) : outFile(outFileName) {}

void CodeWriter::setFileName(const std::string &fn) {
    currentVmFileName = fn;
}

void CodeWriter::writeArithmetic(const std::string &command) {

}

void CodeWriter::writePushPop(const CommandType commandType, const std::string &segment, const unsigned int index) {
    switch (commandType) {
        case C_PUSH:
            if (segment == "constant") {
                pushConstant(index);
                break;
            } else if (segment == "argument" || segment == "local" || segment == "this" || segment == "that") {
                pushArgLclThisThat(segment, index);
                break;
            } else if (segment == "static") {
                pushStatic(index);
                break;
            } else if (segment == "temp") {
                pushTemp(index);
                break;
            } else if (segment == "this" || segment == "that") {
                pushThisOrThat(index);
                break;
            } else {
                std::cerr << "Invalid segment on C_PUSH command: " << segment << std::endl;
                exit(EXIT_FAILURE);
            }
        default:
            std::cerr << "Invalid command type sent to writePushPop: " << commandType << std::endl;
            exit(EXIT_FAILURE);
    }
}

void CodeWriter::writeLine(const std::string &line) {
    outFile << line << std::endl;
}

void CodeWriter::pushConstant(const unsigned int index) {
    writeLine(std::format("@{}", index));
    writeLine("D=A");
    writeLine("@SP");
    writeLine("A=M");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("M=M+1");
}

void CodeWriter::pushArgLclThisThat(const std::string &seg, unsigned int index) {
    std::string segSymbol;
    if (seg == "argument") {
        segSymbol = "ARG";
    } else if (seg == "local") {
        segSymbol = "LCL";
    } else if (seg == "this") {
        segSymbol = "THIS";
    } else if (seg == "that") {
        segSymbol = "THAT";
    }

    writeLine(std::format("@{}", segSymbol));
    writeLine("D=M");
    writeLine(std::format("@{}", index));
    writeLine("A=D+A");
    writeLine("D=M");
    writeLine("@SP");
    writeLine("A=M");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("M=M+1");
}

void CodeWriter::pushStatic(unsigned int index) {
    writeLine(std::format("@{}.{}", currentVmFileName, index));
    writeLine("D=M");
    writeLine("@SP");
    writeLine("A=M");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("M=M+1");
}

void CodeWriter::pushTemp(const unsigned int index) {
    writeLine(std::format("@{}", 5 + index));
    writeLine("D=M");
    writeLine("@SP");
    writeLine("A=M");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("M=M+1");
}

void CodeWriter::pushThisOrThat(const unsigned int index) {
    writeLine(std::format("@{}", index == 0 ? 3 : 4));
    writeLine("D=M");
    writeLine("@SP");
    writeLine("A=M");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("M=M+1");
}
