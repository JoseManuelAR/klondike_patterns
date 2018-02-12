file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testboard ${SRCS})

TARGET_LINK_LIBRARIES(testboard libcard libgtest libgmock)

add_test(NAME testboard COMMAND testboard)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++17 ${CMAKE_CXX_FLAGS}")