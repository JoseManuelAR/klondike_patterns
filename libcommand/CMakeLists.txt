file(GLOB SRCS *.cpp)

add_library(libcommand STATIC ${SRCS})

target_link_libraries(libcommand stdc++fs)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-inline -Wall -std=c++14 ${CMAKE_CXX_FLAGS}")
