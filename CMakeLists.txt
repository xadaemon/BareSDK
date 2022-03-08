cmake_minimum_required(VERSION 3.19)
project(
        BareSDK
        VERSION 1.1.0
        DESCRIPTION "Baremetal Utility SDK"
        HOMEPAGE_URL "https://github.com/DarthUdp/BareSDK"
        LANGUAGES C
)

set(CMAKE_C_STANDARD 99)

file(GLOB CSources source/*.c)
file(GLOB CHeaders include/*.h)
add_library(bareSDK STATIC ${CSources} ${CHeaders})
target_compile_options(bareSDK PUBLIC
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
target_include_directories(bareSDK PUBLIC include)

add_executable(demo demo.c)
target_link_libraries(demo bareSDK)
