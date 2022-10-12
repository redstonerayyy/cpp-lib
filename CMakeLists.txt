cmake_minimum_required(VERSION 3.23)
project(cpp_algos)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_library(cpp_algos include/FastSort.hpp cpp/FastSort.cpp cpp/ArrayUtil.cpp include/ArrayUtil.hpp)

add_executable(test main.cpp cpp/FastSort.cpp cpp/ArrayUtil.cpp include/ArrayUtil.hpp)
