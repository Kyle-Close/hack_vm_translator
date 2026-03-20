//
// Created by kyle on 2026-03-19.
//

#include "../include/Parser.h"
#include "../include/StringUtils.h"

#include <fstream>
#include <iostream>

Parser::Parser(const std::string &filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Unable to open vm file: " << filePath << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line)) {
        trim(line);

        if (!startsWith(line, '/') && !line.empty()) {
            if (const size_t pos = line.find('/'); pos != -1) {
                line.erase(pos, line.length() - 1);
            }
            lines.push_back(line);
        }
    }

    if (lines.empty()) {
        std::cerr << "VM file provided contains no commands. Please provide a valid file." << std::endl;
        exit(EXIT_FAILURE);
    }
}

bool Parser::hasMoreCommands() const {
    return currentCommandIndex < lines.size();
}

void Parser::advance() {
    currentCommand = lines[currentCommandIndex]; // Set current command
    setCurrentCommandIndex(currentCommandIndex + 1); // Increment index for next time
}

CommandType Parser::commandType() {
    // TODO
}

std::string Parser::arg1() {
    // TODO
}

std::string Parser::arg2() {
    // TODO
}
