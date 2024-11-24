cmake_minimum_required(VERSION 3.29)
project(quoridor4 C)

set(CMAKE_C_STANDARD 11)

add_executable(quoridor4 main.c
        sauvegarde.c
        sauvegarde.h)
