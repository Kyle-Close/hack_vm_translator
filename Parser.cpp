//
// Created by kyle on 2026-03-19.
//

#include "Parser.h"
#include "StringUtils.h"

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
            const size_t pos = line.find('/');
            if (pos != std::string::npos) {
                line.erase(pos);
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

CommandType Parser::commandType() const {
    const auto parts = split(currentCommand);

    if (parts.empty()) {
        std::cerr << "Attempted to get command type on line with no command: " << currentCommand << std::endl;
        exit(EXIT_FAILURE);
    }

    const std::string& c = parts[0];

    if (c == "add" || c == "sub" || c == "neg" ||
        c == "eq" || c == "gt" || c == "lt" ||
        c == "and" || c == "or" || c == "not") {
        return C_ARITHMETIC;
    }
    if (parts[0] == "push") {
        return C_PUSH;
    }
    if (parts[0] == "pop") {
        return C_POP;
    }

    std::cerr << "Encountered unknown command (or command for project 8): " << c << std::endl;
    exit(EXIT_FAILURE);
}

std::string Parser::arg1() const {
    if (commandType() == C_ARITHMETIC) {
        return currentCommand;
    }

    const auto parts = split(currentCommand);
    if (parts.size() < 2) {
        std::cerr << "Attempted to get arg1 on line with less than 2 words: " << currentCommand << std::endl;
        exit(EXIT_FAILURE);
    }

    return parts[1];
}

int Parser::arg2() const {
    if (commandType() == C_PUSH || commandType() == C_POP) {
        const auto parts = split(currentCommand);
        if (parts.size() < 3) {
            std::cerr << "Attempted to get arg2 on line with less than 3 words: " << currentCommand << std::endl;
            exit(EXIT_FAILURE);
        }

        return std::stoi(parts[2]);
    }

    std::cerr << "Attempted to get arg2 on line with invalid command type: " << currentCommand << std::endl;
    exit(EXIT_FAILURE);
}