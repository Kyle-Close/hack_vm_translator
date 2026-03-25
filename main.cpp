#include <iostream>

#include "cli.h"
#include "Parser.h"
#include "CodeWriter.h"

int main(const int argc, char *argv[]) {
    const std::vector<std::string> filePaths = parseArgs(argc, argv);

    if (filePaths.empty()) {
        std::cerr << "No valid file paths could be found." << std::endl;
        exit(EXIT_FAILURE);
    }

    auto cw = CodeWriter(filePaths[0]);


    unsigned int i = 0;
    for (const auto& filePath : filePaths) {
        std::string name = filePaths[i];
        // Strip directory path
        size_t slashPos = name.rfind('/');
        if (slashPos != std::string::npos) {
            name = name.substr(slashPos + 1);
        }
        // Strip .vm extension
        size_t dotPos = name.rfind('.');
        if (dotPos != std::string::npos) {
            name = name.substr(0, dotPos);
        }
        cw.setFileName(name);
        auto parser = Parser(filePath);

        while (parser.hasMoreCommands()) {
            parser.advance();
            const auto ct = parser.commandType();

            if (ct == C_ARITHMETIC) {
                cw.writeArithmetic(parser.arg1());
            } else if (ct == C_PUSH || ct == C_POP) {
                cw.writePushPop(ct, parser.arg1(), parser.arg2());
            } else if (ct == C_LABEL) {
                cw.writeLabel(parser.arg1());
            } else if (ct == C_GOTO) {
                cw.writeGoTo(parser.arg1());
            } else if (ct == C_IF) {
                cw.writeIf(parser.arg1());
            }

            else {
                std::cerr << "NOT YET IMPLEMENTED" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        i++;
    }

    return 0;
}