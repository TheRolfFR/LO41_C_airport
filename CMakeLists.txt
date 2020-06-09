cmake_minimum_required(VERSION 3.10)
project(lo41_projet C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
add_executable(lo41_project main.c)
target_link_libraries(lo41_project m)