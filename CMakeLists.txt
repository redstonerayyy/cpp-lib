cmake_minimum_required(VERSION 3.23)
project(cpp_algos)

#set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_library(cpp_algos cpp/RadixSort.cpp cpp/DataStructureUtils.cpp)

target_compile_features(cpp_algos PRIVATE cxx_std_20)

add_executable(test main.cpp)

target_compile_features(test PRIVATE cxx_std_20)

target_link_libraries(test PRIVATE cpp_algos)
