file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testfoundation ${SRCS})

TARGET_LINK_LIBRARIES(testfoundation libcard libgtest libgmock)

add_test(NAME testfoundation COMMAND testfoundation)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++17 ${CMAKE_CXX_FLAGS}")