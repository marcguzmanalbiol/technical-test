cmake_minimum_required(VERSION 3.19)
project(prueba_tecnica_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread" )

add_executable(prueba_tecnica_cpp prueba-tecnica-code-2.cpp)