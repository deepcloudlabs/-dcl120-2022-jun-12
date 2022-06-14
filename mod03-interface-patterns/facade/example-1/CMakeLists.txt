cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project (facadeapp)

add_executable(facadeapp FacadeApp.cpp Electrical_Department.h Electrical_Department.h Facilities_Department.h Facilities_Department.cpp FacilitiesFacade.h MIS_Department.h MIS_Department.cpp)
