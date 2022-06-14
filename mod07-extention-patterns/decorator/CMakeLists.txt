cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project (decorator_before)
project (decorator_after)
project (decorator2)

add_executable(decorator_before decorator_before.cpp)
add_executable(decorator_after decorator_after.cpp)
add_executable(decorator2 decorator2.cpp)