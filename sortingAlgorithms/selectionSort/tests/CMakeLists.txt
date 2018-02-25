project(SelectionSortTest)
cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest 1.8.0 REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(selectionSortTest selectionSortTest.cpp ../selectionSort.cpp)
target_link_libraries(selectionSortTest ${GTEST_LIBRARIES} Threads::Threads gtest_main)