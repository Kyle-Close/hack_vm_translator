#include "../include/cli.h"

int main(const int argc, char *argv[]) {
    std::vector<std::string> files = parseArgs(argc, argv);

    return 0;
}