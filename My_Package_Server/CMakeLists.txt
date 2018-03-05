cmake_minimum_required(VERSION 3.6)
project(My_Package_Server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp mongoose.c mongoose.h TcpServer.cpp TcpServer.h server_metheod.h)
add_executable(My_Package_Server ${SOURCE_FILES})