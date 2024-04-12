//
// Created by Ben Gotts on 09/04/2024.
//

#ifndef ASSIGNMENTONE_MONSTER_H
#define ASSIGNMENTONE_MONSTER_H

#include "Character.h"
#include "Item.h"
#include <vector>

using namespace std;

class Monster : public Character{
private:
    vector<Item*> loot;
public:
    Monster(string name, int hitPoints);

    vector<Item*> getLoot();
    void setLoot(vector<Item*> loot);
};


#endif //ASSIGNMENTONE_MONSTER_H
