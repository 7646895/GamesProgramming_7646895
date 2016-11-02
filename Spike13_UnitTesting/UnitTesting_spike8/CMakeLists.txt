cmake_minimum_required(VERSION 3.6)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
project(UnitTesting)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp UnitTests/UnitTests8.cpp)
add_executable(UnitTesting ${SOURCE_FILES})

add_subdirectory(UnitTests/lib/gtest-1.7.0)
include_directories(ZorkishSpike8)
add_subdirectory(ZorkishSpike8)

target_link_libraries(UnitTesting ZorkishSpike8 gtest gtest_main)




