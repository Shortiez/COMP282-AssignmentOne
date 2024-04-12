cmake_minimum_required(VERSION 3.28)
project(AssignmentOne)

set(CMAKE_CXX_STANDARD 17)

add_executable(AssignmentOne AdventureGame.cpp
        Character.cpp
        Character.h
        Item.cpp
        Item.h
        Location.cpp
        Location.h
        Character.h
        Monster.cpp
        Monster.h
        Player.cpp
        Player.h
        Potion.cpp
        Potion.h
        Weapon.cpp
        Weapon.h
        Treasure.cpp
        Treasure.h
        Direction.cpp
        Armour.cpp
        Armour.h)
