cmake_minimum_required(VERSION 3.0)

project(przeszukiwanie) #  <--- w nawiasie nazwa programu

include_directories(inc)

 
file(GLOB SRC src/*.cpp)


add_executable(${CMAKE_PROJECT_NAME} ${SRC})

