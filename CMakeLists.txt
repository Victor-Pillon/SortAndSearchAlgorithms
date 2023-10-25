cmake_minimum_required(VERSION 2.8...3.13)
project(ListSorter VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp )
include_directories(${CMAKE_SOURCE_DIR}/inc/)

add_executable(ListSorter ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
