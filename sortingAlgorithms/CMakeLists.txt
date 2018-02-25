cmake_minimum_required(VERSION 3.9)
project(sortingAlgorithms)
set(CMAKE_CXX_STANDARD 17)
# tests
add_subdirectory(bubbleSort/tests)
add_subdirectory(selectionSort/tests)
add_subdirectory(insertionSort/tests)
add_test(testBubbleSort "/bubbleSort/tests/bubbleSortTest")
add_test(testSelectionSort "selectionSort/tests/selectionSortTest")
add_test(testInsertionSort "insertionSort/tests/insertionSortTest")
enable_testing()

add_executable(sortingAlgorithms main.cpp bubbleSort/bubbleSort.cpp selectionSort/selectionSort.h selectionSort/selectionSort.cpp insertionSort/insertionSort.cpp)
target_link_libraries(sortingAlgorithms)