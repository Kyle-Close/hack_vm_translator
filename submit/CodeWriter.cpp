//
// Created by kyle on 2026-03-20.
//

#include "CodeWriter.h"
#include <fstream>
#include <iostream>


CodeWriter::CodeWriter(const std::string &outFileName) : outFile(outFileName.substr(0, outFileName.rfind('.')) + ".asm") {}

void CodeWriter::setFileName(const std::string &fn) {
    currentVmFileName = fn;
}

void CodeWriter::writeArithmetic(const std::string &command) {
    if (command == "add" || command == "sub" ||
        command == "and" || command == "or") {
        addSubAndOr(command);
    } else if (command == "neg" || command == "not") {
        negOrNot(command == "neg");
    } else if (command == "eq" || command == "gt" || command == "lt") {
        branch(command);
    } else {
        std::cerr << "Invalid command passed to writeArithmetic: " << command << std::endl;
        exit(EXIT_FAILURE);
    }
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
            } else if (segment == "pointer") {
                pushPointer(index);
                break;
            } else {
                std::cerr << "Invalid segment on C_PUSH command: " << segment << std::endl;
                exit(EXIT_FAILURE);
            }
        case C_POP:
            if (segment == "argument" || segment == "local" || segment == "this" || segment == "that") {
                popArgLclThisThat(segment, index);
                break;
            } else if (segment == "static") {
                popStatic(index);
                break;
            } else if (segment == "temp") {
                popTemp(index);
                break;
            } else if (segment == "pointer") {
                popPointer(index);
                break;
            } else {
                std::cerr << "Invalid segment on C_POP command: " << segment << std::endl;
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
    writeLine("@" + std::to_string(index));
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

    writeLine("@" + segSymbol);
    writeLine("D=M");
    writeLine("@" + std::to_string(index));
    writeLine("A=D+A");
    writeLine("D=M");
    writeLine("@SP");
    writeLine("A=M");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("M=M+1");
}

void CodeWriter::pushStatic(unsigned int index) {
    writeLine("@" + currentVmFileName + "." + std::to_string(index));
    writeLine("D=M");
    writeLine("@SP");
    writeLine("A=M");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("M=M+1");
}

void CodeWriter::pushTemp(const unsigned int index) {
    writeLine("@" + std::to_string( 5 + index));
    writeLine("D=M");
    writeLine("@SP");
    writeLine("A=M");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("M=M+1");
}

void CodeWriter::pushPointer(const unsigned int index) {
    writeLine("@" + std::to_string(index == 0 ? 3 : 4));
    writeLine("D=M");
    writeLine("@SP");
    writeLine("A=M");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("M=M+1");
}

void CodeWriter::popArgLclThisThat(const std::string &seg, const unsigned int index) {
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

    writeLine("@" + segSymbol);
    writeLine("D=M");
    writeLine("@" + std::to_string(index));
    writeLine("D=D+A");
    writeLine("@R13");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("A=M-1");
    writeLine("D=M");
    writeLine("@SP");
    writeLine("M=M-1");
    writeLine("@R13");
    writeLine("A=M");
    writeLine("M=D");
}

void CodeWriter::popStatic(const unsigned int index) {
    writeLine("@SP");
    writeLine("A=M-1");
    writeLine("D=M");
    writeLine("@SP");
    writeLine("M=M-1");
    writeLine("@" + currentVmFileName + "." + std::to_string(index));
    writeLine("M=D");
}

void CodeWriter::popTemp(const unsigned int index) {
    writeLine("@SP");
    writeLine("A=M-1");
    writeLine("D=M");
    writeLine("@SP");
    writeLine("M=M-1");
    writeLine("@" + std::to_string(5 + index));
    writeLine("M=D");
}

void CodeWriter::popPointer(const unsigned int index) {
    writeLine("@SP");
    writeLine("A=M-1");
    writeLine("D=M");
    writeLine("@SP");
    writeLine("M=M-1");
    writeLine("@" + std::to_string(index == 0 ? 3 : 4));
    writeLine("M=D");
}

void CodeWriter::addSubAndOr(const std::string &command) {
    std::string op;
    if (command == "add") {
        op = "+";
    } else if (command == "sub") {
        op = "-";
    } else if (command == "and") {
        op = "&";
    } else if (command == "or") {
        op = "|";
    } else {
        std::cerr << "Invalid command passed to addSubAndOr: " << command << std::endl;
        exit(EXIT_FAILURE);
    }

    writeLine("@SP");
    writeLine("A=M-1");
    writeLine("D=M");
    writeLine("@SP");
    writeLine("M=M-1");
    writeLine("A=M-1");
    if (command == "sub") {
        writeLine("D=M" + op + "D");
    } else {
        writeLine("D=D" + op + "M");
    }
    writeLine("M=D");
}

void CodeWriter::negOrNot(const bool isNeg) {
    std::string op = isNeg ? "-" : "!";
    writeLine("@SP");
    writeLine("A=M-1");
    writeLine("M=" + op + "M");
}

void CodeWriter::branch(const std::string &command) {
    std::string jmpOp;
    if (command == "eq") {
        jmpOp = "JEQ";
    } else if (command == "gt") {
        jmpOp = "JGT";
    } else if (command == "lt") {
        jmpOp = "JLT";
    }

    writeLine("@SP");
    writeLine("A=M-1");
    writeLine("D=M");
    writeLine("@SP");
    writeLine("M=M-1");
    writeLine("A=M-1");
    writeLine("D=M-D");
    writeLine("@BRANCH_TRUE_" + std::to_string(branchCount));
    writeLine("D;" + jmpOp);
    writeLine("@SP");           // added
    writeLine("A=M-1");         // added
    writeLine("M=0");
    writeLine("@END_" + std::to_string(branchCount));
    writeLine("0;JMP");
    writeLine("(BRANCH_TRUE_" + std::to_string(branchCount) + ")");
    writeLine("@SP");           // added
    writeLine("A=M-1");         // added
    writeLine("M=-1");
    writeLine("(END_" + std::to_string(branchCount) + ")");
    branchCount++;
}