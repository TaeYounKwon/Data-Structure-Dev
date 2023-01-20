cmake_minimum_required(VERSION 3.10)
project(postfix-tempest0211-master)

set(CMAKE_CXX_STANDARD 14)

add_executable(main.cpp evaluator.cpp evaluator.h)