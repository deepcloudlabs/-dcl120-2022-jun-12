cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project (prototype1-before)
project (prototype1-after)
project (prototype2)

add_executable(prototype1-before prototype1-before.cpp)
add_executable(prototype1-after prototype1-after.cpp)
add_executable(prototype2 prototype2.cpp)