#include "../include/cli.h"

int main(const int argc, char *argv[]) {
    std::vector<std::string> filePaths = parseArgs(argc, argv);

    return 0;
}