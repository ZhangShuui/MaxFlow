cmake_minimum_required(VERSION 3.20)
project(MaxFlow)

set(CMAKE_CXX_STANDARD 14)

add_executable(MaxFlow "Ford Fulkerson.cpp" Dinic.cpp "push relabel.cpp" flight.cpp napkin.cpp)
