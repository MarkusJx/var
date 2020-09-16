cmake_minimum_required(VERSION 3.12)
project(test CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB test_src
        *.hpp
        *.cpp
        )

if (DEFINED ENV{GITHUB_ACTIONS})
  if (WIN32)
    link_directories("D:/gtest/lib")
    include_directories("D:/gtest/include")
  elseif (APPLE)
    link_directories("/usr/local/lib")
    include_directories("/usr/local/include")
  endif ()
else ()
  if (WIN32)
    link_directories(lib)
  endif ()
endif ()

if (WIN32)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
endif ()

add_executable(test ${test_src})

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main gtest)
else ()
    target_link_libraries(${PROJECT_NAME} PRIVATE gtest pthread)
endif ()
