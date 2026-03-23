cmake_minimum_required(VERSION 3.14)
project(VMtranslator)

set(CMAKE_CXX_STANDARD 14)

add_executable(VMtranslator main.cpp
        StringUtils.cpp
        cli.cpp
        Parser.cpp
        Parser.h
        CodeWriter.cpp
        CodeWriter.h
)
