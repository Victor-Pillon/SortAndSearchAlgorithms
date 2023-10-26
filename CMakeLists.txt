cmake_minimum_required(VERSION 2.8...3.13)
project(SortAndSearchAlgorithms VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set( SOURCES_DIR ${CMAKE_SOURCE_DIR}/src/)

include_directories(${CMAKE_SOURCE_DIR}/inc/)

add_executable(
    SortAndSearchAlgorithms
    ${SOURCES_DIR}/ContextListSearch.cpp
    ${SOURCES_DIR}/ContextListSort.cpp
    ${SOURCES_DIR}/ProxyListSearch.cpp
    ${SOURCES_DIR}/ProxyListSort.cpp
    ${SOURCES_DIR}/StrategyBinarySearch.cpp
    ${SOURCES_DIR}/StrategyBubbleSort.cpp
    ${SOURCES_DIR}/StrategyInsertionSort.cpp
    ${SOURCES_DIR}/StrategyLinearSearch.cpp
    ${SOURCES_DIR}/StrategySelectionSort.cpp
    ${SOURCES_DIR}/Main.cpp 
    )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
