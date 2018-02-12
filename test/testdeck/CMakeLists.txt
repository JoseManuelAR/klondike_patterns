file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testdeck ${SRCS})

TARGET_LINK_LIBRARIES(testdeck libcard libgtest libgmock)

add_test(NAME testdeck COMMAND testdeck)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++17 ${CMAKE_CXX_FLAGS}")