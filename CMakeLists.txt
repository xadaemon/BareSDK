cmake_minimum_required(VERSION 3.19)
project(kernelkit C)

set(CMAKE_C_STANDARD 99)
include_directories(core/include)

file(GLOB CSources core/src/*.c)
file(GLOB CHeaders core/include/*.h)
add_library(kernelkit STATIC ${CSources} ${CHeaders})
target_compile_options(kernelkit PUBLIC
        -fstrict-aliasing
        -Wall
        -Wextra
        -pedantic
        -Werror
        -O2
        -ffreestanding
        -nostdlib
        -static
        )

add_executable(demo demo.c)
target_link_libraries(demo kernelkit)
