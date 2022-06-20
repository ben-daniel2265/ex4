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
        Players/Rogue.cpp
        Players/Rogue.h
        Players/Wizard.cpp
        Players/Wizard.h
        Exception.h
        Mtmchkin.h
        Mtmchkin.cpp
        test.cpp
        utilities.cpp
        utilities.h
        main.cpp)
