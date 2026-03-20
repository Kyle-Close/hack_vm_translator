#include <iostream>

#include "../include/cli.h"
#include "../include/Parser.h"

int main(const int argc, char *argv[]) {
    std::vector<std::string> filePaths = parseArgs(argc, argv);

    for (const auto& filePath : filePaths) {
        auto parser = Parser(filePath);
    }

    return 0;
}
