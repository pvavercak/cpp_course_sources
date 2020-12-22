set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

project(${ProjectId})
set(CMAKE_VERBOSE_MAKEFILE TRUE)

add_executable(function_pointers src/main.cpp)
add_executable(functors src/functors.cpp)

enable_testing()

add_test(NAME function_pointers COMMAND function_pointers WORKDIR "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME functors COMMAND functors WORKDIR "${CMAKE_CURRENT_BINARY_DIR}")
