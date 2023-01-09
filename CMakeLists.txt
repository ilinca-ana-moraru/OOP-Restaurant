cmake_minimum_required(VERSION 3.23)
project(tema3)

set(CMAKE_CXX_STANDARD 14)

add_executable(tema3 main.cpp product.cpp product.h IOstream.h IOstream.cpp dish.h dish.cpp drink.cpp drink.h menu.cpp menu.h exceptions.cpp exceptions.h user_interface.cpp user_interface.h id_generator.h IdGenerator.cpp maximum_template.h facade.h facade.cpp)
