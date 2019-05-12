cmake_minimum_required(VERSION 3.13)
project(CircularList)

set(CMAKE_CXX_STANDARD 14)

add_executable(CircularList main.cpp CircularList.h CircularList.cpp Teacher.cpp Teacher.h Menu.h Menu.cpp)