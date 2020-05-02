cmake_minimum_required(VERSION 3.15)
project(The_Walk_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(The_Walk_Game main.cpp robots/Robot.cpp robots/Robot.h robots/R2_D2.cpp robots/R2_D2.h robots/C_3PO.cpp robots/C_3PO.h robots/L3_37.cpp robots/L3_37.h Map.cpp Map.h Game.cpp Game.h Round.cpp Round.h AlongTheWay.cpp AlongTheWay.h)