# probably works with lower versions
cmake_minimum_required(VERSION 3.23)
project(cpplib)

# modern and fast
set(CMAKE_CXX_FLAGS "-O2 -std=c++20")

# files
FILE(GLOB_RECURSE SOURCE_FILES src/cpp/*.cpp)

# stable
add_library(cpplib SHARED ${SOURCE_FILES})
target_include_directories(cpplib PRIVATE
	src/include
)

# test target
FILE(GLOB_RECURSE TEST_FILES test/cpp/*.cpp)

add_executable(testlib test/main.cpp ${TEST_FILES})
target_include_directories(testlib PRIVATE
    src/include
)

target_link_libraries(testlib PRIVATE 
    cpplib
)
