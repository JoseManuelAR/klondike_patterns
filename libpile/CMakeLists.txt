file(GLOB SRCS *.cpp)

add_library(libpile STATIC ${SRCS})

set (CMAKE_CXX_FLAGS "-g --coverage -fno-inline -Wall -std=c++14 ${CMAKE_CXX_FLAGS}")
