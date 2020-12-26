add_executable(perfect_forwarding src/main.cpp)

add_test(NAME perfect_forwarding COMMAND perfect_forwarding WORKDIR "${CMAKE_BINARY_DIR}")
