file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testtableau ${SRCS})

TARGET_LINK_LIBRARIES(testtableau libgtest libgmock)

add_test(NAME testtableau COMMAND testtableau)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++17 ${CMAKE_CXX_FLAGS}")