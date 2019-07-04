cmake_minimum_required(VERSION 3.14)
project(codename)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++17 -pedantic")

include_directories(includes)

set(CMAKE_CXX_STANDARD 17)

add_executable(codename src/main.cpp
                        src/grid.cpp
                        src/word.cpp
                        src/dico.cpp
                        src/game.cpp
                        src/tools.cpp includes/position.hh src/color.cpp src/play.cpp includes/play.hh)
