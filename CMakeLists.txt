cmake_minimum_required(VERSION 3.19)
project(kernelkit C)

set(CMAKE_C_STANDARD 99)
include_directories(include)

add_library(kernelkit STATIC src/ringbuffer.c include/ringbuffer.h src/stack.c include/stack.h src/util.c src/qeue.c include/qeue.h include/endianness_helpers.h src/endianness_helpers.c)
target_compile_options(kernelkit PUBLIC -Wall -Wextra -pedantic -Werror -O2 -ffreestanding -nostdlib -static)

add_executable(demo demo.c)
target_link_libraries(demo kernelkit)
