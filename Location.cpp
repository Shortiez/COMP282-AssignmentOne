//
// Created by Ben Gotts on 09/04/2024.
//

#include "Location.h"

void Location::setName(string name) {
    this->name = name;
}

void Location::setDescription(string description) {
    this->description = description;
}

string Location::getName() {
    return name;
}

string Location::getDescription() {
    return description;
}

void Location::addExit(Direction direction, Location* leadToLocation) {
    switch (direction) {
        case NORTH:
            north = leadToLocation;
            break;
        case SOUTH:
            south = leadToLocation;
            break;
        case EAST:
            east = leadToLocation;
            break;
        case WEST:
            west = leadToLocation;
            break;
    }
}

map<Direction, Location*> Location::getExits() {
    map<Direction, Location*> exitsMap;

    if (north != nullptr) {
        exitsMap.insert(pair<Direction, Location*>(NORTH, north));
    }
    if (south != nullptr) {
        exitsMap.insert(pair<Direction, Location*>(SOUTH, south));
    }
    if (east != nullptr) {
        exitsMap.insert(pair<Direction, Location*>(EAST, east));
    }
    if (west != nullptr) {
        exitsMap.insert(pair<Direction, Location*>(WEST, west));
    }

    return exitsMap;
}

void Location::addMonster(Monster* monsterToSpawn) {
    monsters.push_back(monsterToSpawn);
}

void Location::delMonster(Monster* monsterToDel) {
    for (int i = 0; i < monsters.size(); i++) {
        if (monsters[i] == monsterToDel) {
            monsters.erase(monsters.begin() + i);
        }
    }
}

vector<Monster*> Location::getMonsters() {
    return monsters;
}

void Location::addItem(Item* itemToAdd) {
    if (dynamic_cast<Weapon*>(itemToAdd)) {
        weapons.push_back((dynamic_cast<Weapon*>(itemToAdd)));
    } else if (dynamic_cast<Potion*>(itemToAdd)) {
        potions.push_back((dynamic_cast<Potion*>(itemToAdd)));
    } else if (dynamic_cast<Treasure*>(itemToAdd)) {
        treasure.push_back((dynamic_cast<Treasure*>(itemToAdd)));
    }
}
void Location::addItem(Item* itemToAdd, Location* itemLocation) {
    if (dynamic_cast<Weapon*>(itemToAdd)) {
        weapons.push_back((dynamic_cast<Weapon*>(itemToAdd)));
    } else if (dynamic_cast<Potion*>(itemToAdd)) {
        potions.push_back((dynamic_cast<Potion*>(itemToAdd)));
    } else if (dynamic_cast<Treasure*>(itemToAdd)) {
        treasure.push_back((dynamic_cast<Treasure*>(itemToAdd)));
    }
}

