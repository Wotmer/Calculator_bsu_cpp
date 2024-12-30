cmake_minimum_required(VERSION 3.29)
project(calc)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(calc
        src/main.cpp
        src/calculator.cpp
        src/expression_parser.cpp
        src/utils.cpp
)

add_executable(test_calc
        tests/test_expression_parser.cpp
        src/calculator.cpp
        src/expression_parser.cpp
        src/utils.cpp
)