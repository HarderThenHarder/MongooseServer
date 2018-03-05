cmake_minimum_required(VERSION 3.6)
project(MyPackage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp mongoose.c mongoose.h TcpClient.cpp TcpClient.h)
add_executable(MyPackage ${SOURCE_FILES})