add_executable(initialization_cpp src/main.cpp)

add_test(NAME initialization_cpp COMMAND initialization_cpp WORKDIR "${CMAKE_BINARY_DIR}")