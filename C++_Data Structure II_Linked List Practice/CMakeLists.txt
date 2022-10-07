cmake_minimum_required(VERSION 3.17)
project(shoppingcart)

set(CMAKE_CXX_STANDARD 14)

add_executable(shoppingcart main.cpp ItemToPurchase.cpp ItemToPurchase.h ShoppingCart.cpp ShoppingCart.h)