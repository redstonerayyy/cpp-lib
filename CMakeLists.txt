# probably works with lower versions
cmake_minimum_required(VERSION 3.23)
project(cpp_lib)

# modern and fast
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O2 -march=native")

# files
FILE(GLOB SOURCE_STABLE src/cpp/stable/*.cpp)
FILE(GLOB SOURCE_EXEPERIMENTAL src/cpp/experimental/*.cpp)

# stable
add_library(cpplibstable ${SOURCE_STABLE})
target_include_directories(cpplibstable PRIVATE
	src/include/stable
)

# experimental
add_library(cpplibexperimental ${SOURCE_EXEPERIMENTAL} ${SOURCE_STABLE})
target_include_directories(cpplibexperimental PRIVATE
	src/include/stable
	src/include/experimental
)
