cmake_minimum_required(VERSION 3.29)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

add_executable(TicTacToe main.cpp
        Controller.h
        Controller.cpp
        View.h
        View.cpp
        Board.h
        Board.cpp
        Board.cpp)
