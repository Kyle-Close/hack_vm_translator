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

}
