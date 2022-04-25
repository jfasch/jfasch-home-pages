CMAKE_MINIMUM_REQUIRED(VERSION 3.18)
PROJECT(Toolchain-CMake-Demo)

set(CMAKE_CXX_STANDARD 11)
if (${CMAKE_COMPILER_IS_GNUCC})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror")
endif()

ADD_LIBRARY(greet hello.h hello.c hello-flexible.c)

ADD_EXECUTABLE(hello-first hello-first.c)
TARGET_LINK_LIBRARIES(hello-first greet)

ADD_EXECUTABLE(hello-second hello-second.c)
TARGET_LINK_LIBRARIES(hello-second greet)
