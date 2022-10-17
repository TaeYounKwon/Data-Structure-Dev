cmake_minimum_required(VERSION 3.10)
project(shapes_example_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(shapes_example main.cpp shape.cpp shape.h ellipse.cpp ellipse.h circle.cpp circle.h triangle.cpp triangle.h isosceles.cpp isosceles.h rectangle.cpp rectangle.h squareRec.cpp squareRec.h squareRhom.cpp squareRhom.h Equilateral.cpp Equilateral.h Rhombus.cpp Rhombus.h)