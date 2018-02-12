cmake_minimum_required(VERSION 3.2)

project(Klondike)

enable_testing()

include_directories ("${CMAKE_SOURCE_DIR}")
include_directories ("${CMAKE_SOURCE_DIR}/main")
include_directories ("${CMAKE_SOURCE_DIR}/test")

add_subdirectory(main)
add_subdirectory(test)
add_subdirectory(libcard)
add_subdirectory(libcommand)
add_subdirectory(libgame)
add_subdirectory(libview)
add_subdirectory(libpile)
