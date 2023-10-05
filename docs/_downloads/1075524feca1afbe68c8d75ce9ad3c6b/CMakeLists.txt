CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(Toolchain-CMake-Demo LANGUAGES C)

ADD_LIBRARY(greet hello.h hello.c hello-flexible.c)

ADD_EXECUTABLE(hello-first hello-first.c)
TARGET_LINK_LIBRARIES(hello-first greet)

ADD_EXECUTABLE(hello-second hello-second.c)
TARGET_LINK_LIBRARIES(hello-second greet)
