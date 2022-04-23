# BareSDK [![Build](https://github.com/DarthUdp/KernelKitCore/actions/workflows/cmake.yml/badge.svg)](https://github.com/DarthUdp/KernelKitCore/actions/workflows/cmake.yml)

Low level data structures for kernel development, these are made to be used in low level code, thus they compile under a
freestanding environment and do not need any headers other than the compiler bundled ones.

To accomplish this goal the provided structures expect to be passed allocated buffers when they need them, this gives
you the flexibility of doing allocation as is convenient for your usage, but you need to pay close attention to not use
after free for example.

# Minimum C version

This should work with any standards compliant C99 compiler that can provide the following headers:

```c
#include <bsdk_common.h>
```

It is built and tested under clang and gcc, but as stated above should work under any compiler that can provide the
mentioned headers.

If you need to support C89 you can provide a header that has the same definitions as `stdbool`, but behaviour can't be
guaranteed when doing this. 
