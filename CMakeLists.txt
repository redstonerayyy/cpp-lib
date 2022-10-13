cmake_minimum_required(VERSION 3.23)
project(cpp_algos)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_library(cpp_algos cpp/RadixSort.cpp cpp/VectorUtil.cpp)

add_executable(test main.cpp)

target_link_libraries(test PRIVATE cpp_algos)
