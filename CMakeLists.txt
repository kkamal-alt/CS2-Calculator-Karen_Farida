cmake_minimum_required(VERSION 3.10)
project(CS2Calculator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(calculator
    calculator.cpp
    test.cpp
    expression_parser.cpp
)


