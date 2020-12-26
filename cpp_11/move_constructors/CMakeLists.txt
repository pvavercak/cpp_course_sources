add_executable(move_constructors src/main.cpp)

add_test(NAME move_constructors COMMAND move_constructors WORKDIR "${CMAKE_BINARY_DIR}")