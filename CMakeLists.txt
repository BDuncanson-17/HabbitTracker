cmake_minimum_required(VERSION 3.25)
project(HabbitTracker)

set(CMAKE_CXX_STANDARD 17)

add_executable(HabbitTracker main.cpp src/Habbit.cpp src/Habbit.h src/Util.cpp src/Util.h src/Weight.cpp src/Weight.h)
