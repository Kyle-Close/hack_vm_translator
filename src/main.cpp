#include <filesystem>
#include <iostream>

#include "../include/cli.h"
#include "../include/Parser.h"
#include "../include/CodeWriter.h"

int main(const int argc, char *argv[]) {
    const std::vector<std::string> filePaths = parseArgs(argc, argv);

    if (filePaths.empty()) {
        std::cerr << "No valid file paths could be found." << std::endl;
        exit(EXIT_FAILURE);
    }

    auto cw = CodeWriter(filePaths[0]);


    unsigned int i = 0;
    for (const auto& filePath : filePaths) {
        cw.setFileName(filePaths[i].substr(0, filePaths[i].length() - 3));
        auto parser = Parser(filePath);

        while (parser.hasMoreCommands()) {
            parser.advance();
            const auto ct = parser.commandType();

            if (ct == C_ARITHMETIC) {
                cw.writeArithmetic(parser.arg1());
            } else if (ct == C_PUSH || ct == C_POP) {
                cw.writePushPop(ct, parser.arg1(), parser.arg2());
            } else {
                std::cerr << "NOT YET IMPLEMENTED" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        i++;
    }

    return 0;
}
