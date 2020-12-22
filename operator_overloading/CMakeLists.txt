set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

project(${ProjectId})

add_executable(
    operator_overloading
    src/main.cpp
    src/Complex/Complex.cpp)

enable_testing()

add_test(NAME operator_overloading COMMAND operator_overloading WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
