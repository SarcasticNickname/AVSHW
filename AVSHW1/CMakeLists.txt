# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(task1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)


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

add_executable(task01 ${SOURCE_FILES})
