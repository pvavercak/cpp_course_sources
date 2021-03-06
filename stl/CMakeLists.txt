set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

project(${ProjectId})

add_executable(vectors src/vectors.cpp)
add_executable(lists src/lists.cpp)
add_executable(maps_cli src/maps_cli.cpp)
add_executable(class_and_maps src/class_as_map_value.cpp)
add_executable(stack_queue src/stack_queue.cpp)

enable_testing()

add_test(NAME vectors COMMAND vectors WORKDIR "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME lists COMMAND lists WORKDIR "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME maps_cli COMMAND maps_cli WORKDIR "${CMAKE_CURRENT_SOURCE_DIR}/database")
add_test(NAME class_and_maps COMMAND class_and_maps WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME stack_queue COMMAND stack_queue WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
