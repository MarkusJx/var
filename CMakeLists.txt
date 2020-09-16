cmake_minimum_required(VERSION 3.12)
project(var CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB src
        *.hpp
        *.cpp
        )

add_executable(${PROJECT_NAME} ${src})