#include <iostream>
#include <string>

int main(const int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: VMtranslator <file.vm | directory>" << std::endl;
        exit(EXIT_FAILURE);
    }

    const std::string arg = argv[1];
    if (arg == "--help" || arg == "-h") {
        std::cout << "VMtranslator - Translates Hack VM code to Hack assembly" << std::endl << std::endl;
        std::cout << "Usage: VMtranslator <file.vm | directory>" << std::endl << std::endl;
        std::cout << "Arguments:" << std::endl << "  file.vm      A single .vm file to translate" << std::endl << "  directory    A directory containing one or more .vm files" << std::endl << std::endl;
        std::cout << "Output:" << std::endl << "  Generates a .asm file in the same location as the input" << std::endl;
        return 0;
    }

    return 0;
}