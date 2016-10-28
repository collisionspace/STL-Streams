cmake_minimum_required(VERSION 3.6)
project(slone_project3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Utilities.cpp Utilities.h Patient.cpp Patient.h)
add_executable(slone_project3 ${SOURCE_FILES})