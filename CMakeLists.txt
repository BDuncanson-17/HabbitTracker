cmake_minimum_required(VERSION 3.25)
project(HabbitTracker)

set(CMAKE_CXX_STANDARD 17)

add_executable(HabbitTracker main.cpp src/HabitUtilities.cpp src/HabitUtilities.h src/DataTypes.cpp src/DataTypes.h)
