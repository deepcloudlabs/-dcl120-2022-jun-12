cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project (observer)

add_executable(observer ObserverApp.cpp Observer.h Shop.h Shop.cpp Subject.h Subject.cpp DummyProduct.h DummyProduct.cpp)
