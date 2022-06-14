cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project(abstractfactory1-before)
project(abstractfactory1-after)
project(abstract-factory2)

add_executable(abstractfactory1-before abstract-factory1-before.cpp)
add_executable(abstractfactory1-after abstract-factory1-after.cpp)
add_executable(abstract-factory2 abstract-factory2.cpp)