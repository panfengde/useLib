cmake_minimum_required(VERSION 3.23)
project(useLib)

set(CMAKE_CXX_STANDARD 17)
include_directories(./src)

option(BUILD_SHARED "build shared library" OFF)
#add_executable(useLib main.cpp)

add_library(aLib SHARED libSrc/libCode.cpp)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)#设置动态库输出目录

add_executable(useLib main.cpp)