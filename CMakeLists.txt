cmake_minimum_required(VERSION 3.24)
project(ProjetoDA)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjetoDA projeto/main.cpp projeto/src/information_managment/ReadData.cpp projeto/include/information_managment/ReadData.h projeto/src/graph/Graph.cpp projeto/include/graph/Graph.h projeto/src/graph/Station_Trip.cpp)
