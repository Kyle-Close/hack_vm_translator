//
// Created by kyle on 2026-03-20.
//

#include "../include/CodeWriter.h"
#include <fstream>


CodeWriter::CodeWriter(const std::string &outFileName) : outFile(outFileName) {}

void CodeWriter::setFileName(const std::string &fn) {
    currentVmFileName = fn;
}

void CodeWriter::writeArithmetic(const std::string &command) {

}

void CodeWriter::writePushPop(CommandType commandType, std::string &segment, unsigned int index) {
    // push constant 17

    // @17
    // D=A

    // @SP -> RAM[0] (M=258)
    // A=M
    // M=D

    // @SP
    // M=M+1


    // ---

    // push argument 1 (same template for argument, local, this, and that)

    // @ARG
    // D=M
    // @1
    // A=D+A
    // D=M

    // @SP
    // A=M
    // M=D

    // @SP
    // M=M+1

    // ---

    // push local 5

    // @LCL
    // D=M
    // @5
    // A=D+A
    // D=M

    // @SP
    // A=M
    // M=D

    // @SP
    // M=M+1

    // ---

    // push static 3 (static RAM is from 16-255 - remember variables in asm start here)
    // 3 -> vmFileName.3

    // @vmFileName.3 -> RAM[16]
    // D=M (D = whatever was in RAM[16])

    // @SP
    // A=M
    // M=D

    // @SP
    // M=M+1

    // ---

    // push temp 4

    // @9 (5 base addr + 4)
    // D=M

    // @SP
    // A=M
    // M=D

    // @SP
    // M=M+1

    // ---

    // pop local 2

    // Load local address into general space
    // @LCL
    // D=M (D = 1015)
    // @2
    // D=D+A
    // @R13
    // M=D (R13 = 1017)

    // Store value @ top of stack in D
    // @SP
    // A=M-1
    // D=M (Store 19 in D)

    // Decrement stack pointer
    // @SP
    // M=M-1

    // Load top stack value into local + 2
    // @R13
    // A=M
    // M=D

    // ---


}
