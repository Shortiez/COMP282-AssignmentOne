//
// Created by Ben Gotts on 09/04/2024.
//

#include "Monster.h"

Monster::Monster(string name, int hitPoints) {
    this->name = name;
    this->hitPoints = hitPoints;
}

vector<Item *> Monster::getLoot() {
    return loot;
}

void Monster::setLoot(vector<Item *> loot) {
    this->loot = loot;
}

