cmake_minimum_required(VERSION 3.20)
project(VMtranslator)

set(CMAKE_CXX_STANDARD 20)

add_executable(VMtranslator src/main.cpp
        src/StringUtils.cpp
        src/cli.cpp
        src/Parser.cpp
        include/Parser.h
)
