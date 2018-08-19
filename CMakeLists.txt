cmake_minimum_required(VERSION 3.9)
project(list C)

set(CMAKE_C_STANDARD 99)

add_executable(list main.c include/list.h src/list.c)