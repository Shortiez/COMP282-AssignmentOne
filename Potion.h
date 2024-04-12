//
// Created by Ben Gotts on 09/04/2024.
//

#ifndef ASSIGNMENTONE_POTION_H
#define ASSIGNMENTONE_POTION_H

#include <string>
#include "Item.h"
using namespace std;

class Potion : public Item{
private:
    int strength;
public:
    int getStrength() const;
    void setStrength(int strength);

    Potion();
    Potion(int strength);
    Potion(string name, int strength);
};


#endif //ASSIGNMENTONE_POTION_H
