cmake_minimum_required(VERSION 3.10)
project(inheritance_example_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(example1
        main.cpp
        rectangle.cpp
        rectangle.h
        square.cpp
        square.h point.cpp point.h)
