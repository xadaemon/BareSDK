cmake_minimum_required(VERSION 3.19)
project(kernelkit C)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Wall -Wextra -pedantic -Werror -O2 -ffreestanding -nostdlib -static)
include_directories(include)

add_library(src/ringbuff.c include/ringbuff.h)