//
// Created by kyle on 2026-03-19.
//

#ifndef VMTRANSLATOR_PARSER_H
#define VMTRANSLATOR_PARSER_H
#include <string>
#include <vector>

enum CommandType {
    C_ARITHMETIC,
    C_PUSH,
    C_POP,
    C_LABEL,
    C_GOTO,
    C_IF,
    C_FUNCTION,
    C_RETURN,
    C_CALL
};

class Parser {
    std::vector<std::string> lines;
    std::string currentCommand;
    unsigned int currentCommandIndex = 0;
public:
    void setCurrentCommand(const std::string &cmd) { currentCommand = cmd; }
    void setCurrentCommandIndex(const unsigned int i) {currentCommandIndex = i; }

    explicit Parser(const std::string &filePath);
    bool hasMoreCommands() const;
    void advance();
    CommandType commandType();
    std::string arg1();
    std::string arg2();
};


#endif //VMTRANSLATOR_PARSER_H