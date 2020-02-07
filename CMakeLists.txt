cmake_minimum_required(VERSION 3.15)

project(Me-Project2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")

add_executable(Project2 main.cpp roulette.cpp roulette.h)
add_executable(Testing testing.cpp roulette.cpp)
