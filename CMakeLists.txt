cmake_minimum_required(VERSION 3.21)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Cards)
include_directories(Players)

add_executable(ex4
        Cards/Card.cpp
        Cards/Card.h
        Cards/Goblin.cpp
        Cards/Goblin.h
        Players/Fighter.cpp
        Players/Fighter.h
        Players/Player.cpp
        Players/Player.h
        Players/Rouge.cpp
        Players/Rouge.h
        Players/Wizard.cpp
        Players/Wizard.h
        Exception.h
        Mtmchkin.h
        test.cpp
        utilities.cpp
        utilities.h)
