cmake_minimum_required(VERSION 3.13)
project(Connect4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Connect4 main.cpp board.hpp board.cpp player.hpp player.cpp computer.hpp computer.cpp)