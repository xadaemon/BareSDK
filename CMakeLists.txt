cmake_minimum_required(VERSION 3.19)
project(kernelkit C)

set(CMAKE_C_STANDARD 99)
include_directories(include)

file(GLOB CSources src/*.c)
file(GLOB CHeaders include/*.h)
add_library(kernelkit STATIC ${CSources} ${CHeaders})
target_compile_options(kernelkit PUBLIC -Wall -Wextra -pedantic -Werror -O2 -ffreestanding -nostdlib -static)

add_executable(demo demo.c)
target_link_libraries(demo kernelkit)
