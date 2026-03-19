//
// Created by kyle on 2026-03-19.
//

#include "../include/cli.h"
#include "../include/StringUtils.h"

#include <iostream>

std::vector<std::string> parseArgs(const int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: VMtranslator <file.vm | directory>" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string arg = argv[1];
    Trim(arg);

    if (arg == "--help" || arg == "-h") {
        std::cout << "VMtranslator - Translates Hack VM code to Hack assembly" << std::endl << std::endl;
        std::cout << "Usage: VMtranslator <file.vm | directory>" << std::endl << std::endl;
        std::cout << "Arguments:" << std::endl << "  file.vm      A single .vm file to translate" << std::endl << "  directory    A directory containing one or more .vm files" << std::endl << std::endl;
        std::cout << "Output:" << std::endl << "  Generates a .asm file in the same location as the input" << std::endl;
        exit(EXIT_SUCCESS);
    }

    std::vector<std::string> files;

    if (!Contains(arg, '.')) { // Directory passed in
        std::cerr << "Directory passed in. NOT IMPLEMENTED." << std::endl;
        exit(EXIT_FAILURE);
    }
    else if (arg.substr(arg.length() - 3, arg.length() - 1) == ".vm") {
        files.push_back(arg);
        return files;
    }
    else {
        std::cerr << "Invalid argument: " << arg << std::endl << "--help  for more info";
        exit(EXIT_FAILURE);
    }
}
