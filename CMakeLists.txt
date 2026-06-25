cmake_minimum_required(VERSION 3.20)

project(Nativefin-Core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTING "Build tests" ON)

set(BUILD_CURL_EXE OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(CURL REQUIRED)
find_package(SQLite3 REQUIRED)

add_library(Nativefin-Core
        src/core.cpp
        src/core.h
        src/util.cpp
        src/util.h
        src/db.cpp
        src/db.h)

target_link_libraries(Nativefin-Core PRIVATE CURL::libcurl SQLite3::SQLite3)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()