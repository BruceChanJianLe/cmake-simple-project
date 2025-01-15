cmake_minimum_required(VERSION 3.5)
project(simple_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Fetch Content Example
include(FetchContent)

FetchContent_Declare(
    csv2
    GIT_REPOSITORY https://github.com/p-ranav/csv2.git
    GIT_TAG v0.1
)

FetchContent_MakeAvailable(csv2)

# build
add_executable(example src/example.cpp)
target_link_libraries(example PRIVATE csv2)
