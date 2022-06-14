cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project(command1-before)
project(command1-after)
project(command2)
project(command3)

add_executable(command1-before command1-before.cpp)
add_executable(command1-after command1-after.cpp)
add_executable(command2 command2.cpp)
add_executable(command3 command3.cpp)