//
// Created by Ben Gotts on 09/04/2024.
//

#ifndef ASSIGNMENTONE_LOCATION_H
#define ASSIGNMENTONE_LOCATION_H

#include <string>
#include <map>
#include "Direction.cpp"
#include "Monster.h"
#include "Item.h"
#include "Weapon.h"
#include "Potion.h"
#include "Treasure.h"

using namespace std;

class Location {
private:
    string name;
    string description;

    Location* north;
    Location* south;
    Location* east;
    Location* west;

    vector<Monster*> monsters;

public:
    vector<Weapon*> weapons;
    vector<Potion*> potions;
    vector<Treasure*> treasure;

    string getName();
    string getDescription();
    void setName(string name);
    void setDescription(string description);

    void addExit(Direction direction, Location* leadToLocation);
    map<Direction, Location*> getExits();

    void addMonster(Monster* monsterToSpawn);
    void delMonster(Monster* monsterToDel);
    vector<Monster*> getMonsters();

    void addItem(Item* itemToAdd);
    virtual void addItem(Item* itemToAdd, Location* itemLocation);
};


#endif //ASSIGNMENTONE_LOCATION_H
