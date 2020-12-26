cmake_minimum_required(VERSION 3.0)

project(cpp_features VERSION 1.0 LANGUAGES C CXX)

enable_testing()

add_subdirectory(decltype_typeid)

add_subdirectory(ring_classes)

add_subdirectory(initialization_cpp)

add_subdirectory(lambdas)

add_subdirectory(lvalue_rvalue)

add_subdirectory(move_constructors)

add_subdirectory(casting)

add_subdirectory(perfect_forwarding)

add_subdirectory(bind)

add_subdirectory(smart_pointers)