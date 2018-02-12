file(GLOB SRCS *.cpp)

add_library(libview STATIC ${SRCS})

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++17 ${CMAKE_CXX_FLAGS}")
