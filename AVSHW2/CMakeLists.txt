# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(AVSHW2 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        # Headers
        rnd.h
        triangular.h
        diagonal.h
        square.h
        matrix.h
        container.h

        # Sources
        triangular.cpp
        diagonal.cpp
        square.cpp
        matrix.cpp
        container.cpp
        main.cpp
        )

add_executable(task2 ${SOURCE_FILES})
