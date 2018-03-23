cmake_minimum_required(VERSION 3.9)
project(lab01Algorithms C)

set(CMAKE_C_STANDARD 11)
add_library(quickSort SHARED src/quickSort.c)
add_executable(lab01Algorithms src/main.c)
target_link_libraries(lab01Algorithms quickSort)
