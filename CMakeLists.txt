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
add_library(bsdk STATIC ${CSources} ${CHeaders})
target_compile_options(bsdk PUBLIC
        -fstrict-aliasing
        -Wall
        -Wextra
        -pedantic
        -Werror
        -O2
        -ffreestanding
        -nostdlib
        )
target_include_directories(bsdk PUBLIC include)

add_library(dynbsdk SHARED ${CSources} ${CHeaders})
target_compile_options(dynbsdk PUBLIC
        -fstrict-aliasing
        -Wall
        -Wextra
        -pedantic
        -Werror
        -O2
        -ffreestanding
        -nostdlib
        )
target_include_directories(dynbsdk PUBLIC include)

add_executable(demo demo.c)
target_link_libraries(demo bsdk)
