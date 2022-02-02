cmake_minimum_required(VERSION 3.21)
project(OS_5th_Sem)

set(CMAKE_CXX_STANDARD 14)

add_executable(OS_5th_Sem main.cpp)

add_executable(FCFS CPU_Scheduling_Algorithm/FCFS.c)
add_executable(SJF CPU_Scheduling_Algorithm/SJF.c)
add_executable(RoundRobin CPU_Scheduling_Algorithm/RoundRobin.c)