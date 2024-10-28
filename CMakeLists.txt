cmake_minimum_required(VERSION 3.29)
project(COMP2510_Lab6 C)

set(CMAKE_C_STANDARD 99)

add_executable(COMP2510_Lab6 main.c
        student.h
        student.c
        studentIO.c
        studentIO.h
        main.h)
