add_executable(lambdas src/main.cpp)
#target_compile_options(lambdas PUBLIC -fno-elide-constructors)

add_test(NAME lambdas COMMAND lambdas WORKDIR "${CMAKE_BINARY_DIR}")