cmake_minimum_required(VERSION 3.12)
project(var CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB src
        *.hpp
        *.cpp
        )

add_executable(${PROJECT_NAME} ${src})