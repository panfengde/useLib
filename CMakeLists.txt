cmake_minimum_required(VERSION 3.23)
project(useLib)

set(CMAKE_CXX_STANDARD 17)
include_directories(./src)

add_executable(useLib
        main.cpp)
