# cmake_minimum_required(VERSION <specify CMake version here>)
project(luogu)

set(CMAKE_CXX_STANDARD 17)

add_executable(luogu main.cpp)

#set(CMAKE_CXX_FLAGS "-O0 -fno-elide-constructors -pedantic-errors -ansi -Wextra -Wall -pedantic  -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations -Winit-self -std=c++17")
add_executable(ac ac.cc)
add_executable(lc lc.cc)
add_executable(lg lg.cc)
add_executable(sol lc/sol.cc)
add_executable(p1908 exam/merge_sort/p1908.cc)
add_executable(P3373 structure/seg_tree/P3373.cc)