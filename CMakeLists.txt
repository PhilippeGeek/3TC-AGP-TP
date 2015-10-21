cmake_minimum_required(VERSION 3.3)
project(3TC_AGP_TP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)


add_executable(
        tp2.out
        TP2/main.c TP2/utilSudoku.c TP2/main.h TP2/sudoku.c TP2/sudoku.h)

add_executable(
        tp1.out
        ${src}
        TP1/unmultiplexer.c TP1/unmultiplexer.h)