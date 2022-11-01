cmake_minimum_required(VERSION 3.24)
project(cop4534_p4)

set(CMAKE_CXX_STANDARD 14)

add_executable(cop4534_p4 main.cpp)

file(COPY items.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})