cmake_minimum_required(VERSION 3.27)
project(til_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(til_cpp src/main.cpp
        src/token/token.cpp
        src/lexer/lexer.cpp)
