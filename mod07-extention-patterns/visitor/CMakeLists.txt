cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project (visitor1_before)
project (visitor1_after)
project (visitor2)
project (visitor3)
project (visitor4)

add_executable(visitor1_before visitor1-before.cpp)
add_executable(visitor1_after visitor1-after.cpp)
add_executable(visitor2 visitor2.cpp)
add_executable(visitor3 visitor3.cpp)
add_executable(visitor4 ConsoleApplication1.cpp)