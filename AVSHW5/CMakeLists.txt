cmake_minimum_required(VERSION 3.22)
project(AVSHW5)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")

add_executable(AVSHW5 main.cpp decypherkit.h decypherkit.cpp userinterface.h userinterface.cpp)
