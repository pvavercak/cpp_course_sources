add_executable(lrvals src/main.cpp)

add_test(NAME lrvals COMMAND lrvals WORKDIR "${CMAKE_BINARY_DIR}")