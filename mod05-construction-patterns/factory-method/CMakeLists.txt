cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project (factory_method1_before)
project (factory_method1_after)
project (factory_method2)

add_executable(factory_method1_before factory-method1_before.cpp)
add_executable(factory_method1_after factory-method1_after.cpp)
add_executable(factory_method2 factory-method2.cpp)