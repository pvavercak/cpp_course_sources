add_executable(decltype_typeid src/main.cpp)

enable_testing()

add_test(NAME test_decltype_typeid COMMAND test_decltype_typeid WORKDIR "${CMAKE_BINARY_DIR}")