cmake_minimum_required(VERSION 3.8)
project(ALDIs)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c operations.c operations.h)
add_executable(ALDIs ${SOURCE_FILES})