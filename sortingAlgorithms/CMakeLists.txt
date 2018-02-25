cmake_minimum_required(VERSION 3.9)
project(sortingAlgorithms)
set(CMAKE_CXX_STANDARD 17)
# tests
add_subdirectory(bubbleSort/tests)
add_subdirectory(selectionSort/tests)
add_test(testBubbleSort "/bubbleSort/tests/bubbleSortTest")
add_test(testSelectionSort "selectionSort/tests/selectionSortTest")
enable_testing()

add_executable(sortingAlgorithms main.cpp bubbleSort/bubbleSort.cpp selectionSort/selectionSort.h selectionSort/selectionSort.cpp)
target_link_libraries(sortingAlgorithms)