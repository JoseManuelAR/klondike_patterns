file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testcommand ${SRCS})

TARGET_LINK_LIBRARIES(testcommand libcard libgtest libgmock)

add_test(NAME testmovement COMMAND testcommand)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++17 ${CMAKE_CXX_FLAGS}")