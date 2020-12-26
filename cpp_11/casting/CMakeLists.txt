add_executable(casting src/main.cpp)

add_test(NAME casting COMMAND casting WORKDIR "${CMAKE_BINARY_DIR}")