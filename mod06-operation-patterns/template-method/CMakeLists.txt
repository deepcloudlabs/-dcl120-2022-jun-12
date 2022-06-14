cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project (template1-before)
project (template1-after)
project (template2)

add_executable(template1-before template1-before.cpp)
add_executable(template1-after template1-after.cpp)
add_executable(template2 template2.cpp)