//
// Created by Ben Gotts on 09/04/2024.
//

#ifndef ASSIGNMENTONE_WEAPON_H
#define ASSIGNMENTONE_WEAPON_H

#include <string>
#include "Item.h"
using namespace std;

class Weapon : public Item{
private:
    int power;
public:
    int getPower() const;
    void setPower(int power);

    Weapon();
    Weapon(int power);
    Weapon(string name, int power);
};


#endif //ASSIGNMENTONE_WEAPON_H
