cmake_minimum_required(VERSION 3.5)
project(DebuggerUse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(DebuggerUse ${SOURCE_FILES})