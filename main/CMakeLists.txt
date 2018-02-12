file(GLOB SRCS *.cpp)

add_executable(klondike ${SRCS})

target_link_libraries(klondike libview libcommand libgame libpile libcard)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++14 ${CMAKE_CXX_FLAGS}")
