cmake_minimum_required(VERSION 3.12)
project(test CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB test_src
        *.hpp
        *.cpp
        )

if (WIN32)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

    link_directories(lib)
endif ()

add_executable(test ${test_src})

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE gtest_maind gtestd)
else ()
    target_link_libraries(${PROJECT_NAME} PRIVATE gtest pthread)
endif ()
