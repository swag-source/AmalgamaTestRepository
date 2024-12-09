cmake_minimum_required(VERSION 3.10)
project(amalgamaTest)

set(CMAKE_CXX_STANDARD 23)

add_executable(amalgamaTest main.cpp Unit.cpp Army.cpp
        Civilization.cpp
        Civilization.h)

