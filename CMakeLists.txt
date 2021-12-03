# cmake_minimum_required(VERSION <specify CMake version here>)
project(luogu)

set(CMAKE_CXX_STANDARD 17)

add_executable(luogu main.cpp)

#set(CMAKE_CXX_FLAGS "-O0 -fno-elide-constructors -pedantic-errors -ansi -Wextra -Wall -pedantic  -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations -Winit-self -std=c++17")