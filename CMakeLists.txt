cmake_minimum_required(VERSION 4.1)
project(VMtranslator)

set(CMAKE_CXX_STANDARD 20)

add_executable(VMtranslator src/main.cpp
        src/StringUtils.cpp
        src/cli.cpp
)
