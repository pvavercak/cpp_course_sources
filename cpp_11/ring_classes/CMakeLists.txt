add_executable(ring_classes src/main.cpp)

add_test(NAME ring_classes COMMAND ring_classes WORKDIR "${CMAKE_BINARY_DIR}")