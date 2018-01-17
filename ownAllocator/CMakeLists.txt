cmake_minimum_required(VERSION 3.9)
project(ownAllocator)

set(CMAKE_CXX_STANDARD 17)

add_executable(ownAllocator main.cpp SmallAllocator.cpp SmallAllocator.h)