cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project(mediatorapp)
project(mediator_before)
project(mediator_after)

add_executable(mediatorapp MediatorApp.cpp)
add_executable(mediator_before Mediator_before.cpp)
add_executable(mediator_after Mediator_after.cpp)