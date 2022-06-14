cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project (builder1)
project (builder2)
project (builder3)

add_executable(builder1 builder1.cpp)
add_executable(builder2 builder2.cpp)
add_executable(builder3 builder3.cpp)