cmake_minimum_required(VERSION 2.8)
project(zombie)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES zombie.cpp)
add_executable(zombie ${SOURCE_FILES})