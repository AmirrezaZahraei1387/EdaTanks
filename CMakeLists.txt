cmake_minimum_required(VERSION 3.23)
project(EdaTanks_)

set(CMAKE_CXX_STANDARD 23)

add_executable(EdaTanks_ main.cpp ETCore/tank/tank_rep.h ETCore/tank/tank_contr.h)

