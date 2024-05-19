cmake_minimum_required(VERSION 3.28)
project(SuperTicTacToe)

set(CMAKE_CXX_STANDARD 20)

add_executable(SuperTicTacToe src/main.cpp
        src/board_mechanics/board.hh
        src/board_mechanics/board.cc
        src/users/player.hh
        src/users/player.cc)