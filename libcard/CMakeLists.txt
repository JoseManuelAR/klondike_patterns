file(GLOB SRCS *.cpp)

add_library(libcard STATIC ${SRCS})

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++14 ${CMAKE_CXX_FLAGS}")
